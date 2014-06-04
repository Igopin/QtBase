/* Problem manager source file */

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtWidgets>
#include <QMessageBox>
#include "defines.h"
#include "problemmanager.h"

#include "prob_lae.h"
#include "solvelae.h"

#include "prob_slae.h"
#include "solveslae.h"


PROBLEMMANAGER::PROBLEMMANAGER(QObject *parent) :
  QObject(parent)
{
}

/***************************************************************************************
 * FUNCTIONS                                                                           *
 ***************************************************************************************/

/* Parse matrix string function */
VEC ParseString( const char *str )
{
  int i = 0, j = 0;
  char num[64];
  VEC res;

  while(str[i] != 0)
  {
    if (str[i] != ' ')
      num[j++] = str[i];
    else
    {
      num[j] = 0, j = 0;
      res.push_back(atof(num));
    }
    i++;
  }

  if (j != 0)
  {
    num[j] = 0;
    res.push_back(atof(num));
  }

  return res;
} /* End of 'ParseString' function */

/* Numbers to string function */
QString NumbersToStr( double *arr, int size )
{
  QString res;

  for (int i = 0; i < size - 1; i++)
  {
    res.append(QString::number(arr[i]));
    res += QChar(' ');
  }
  res.append(QString::number(arr[size - 1]));
  return res;
} /* End of 'NumbersToStr' function */

/* VEC to (double *) */
double * VecToArr( VEC v )
{
  int size = v.size();
  double *arr = new double [size];

  for (int i = 0; i < size ; i++)
  {
    arr[i] = v[i];
  }
  return arr;
} /* End of 'NumbersToStr' function */

/* Create new LAE problem */
QDialog * PROBLEMMANAGER::OpenLAE( QString problem_name, STATE state )
{
  PROB_LAE *new_lae = new PROB_LAE(this, problem_name);
  SOLVELAE *solve_dialog = new SOLVELAE((QWidget *)this->parent());

  switch (state)
  {
  case NEW:
    break;
  case EXIST:
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req;
    double a, b, c, res;

    req.sprintf("SELECT prob_id FROM prob WHERE "
                "prob_name = '%s' and prob_type = 'LAE';",
                qPrintable(problem_name));
    query.exec(req);
    query.first();
    int prob_id = query.value(0).toInt();

    req.clear();
    req.sprintf("SELECT * FROM lae WHERE p_id = %i;", prob_id);
    query.exec(req);
    query.first();

    a = query.value(2).toDouble();
    b = query.value(3).toDouble();
    c = query.value(4).toDouble();
    new_lae->SetABC(a, b, c);
    solve_dialog->InitParams(a, b, c);

    if (!query.value(5).isNull())
    {
      res = query.value(5).toDouble();

      new_lae->SetRes(res);
      solve_dialog->NewRes(res);
    }
    break;
  }

  /* Connect dialog with problem */
  connect(solve_dialog, SIGNAL(NewParams(double,double,double)),
                      new_lae, SLOT(NewParams(double,double,double)));

  connect(new_lae, SIGNAL(NewRes(double)), solve_dialog, SLOT(NewRes(double)));

  problem_list.push_back(new_lae);
  solve_dialog->SetDialogName(problem_name);

  emit ProblemOpened(problem_name);
  return solve_dialog;
} /* End of 'NewLAE' function */

/* Save LAE in database function */
bool PROBLEMMANAGER::SaveLAE( QString problem_name )
{
  QSqlDatabase db = QSqlDatabase::database();
  QSqlQuery query(db);
  QString req;

  /* Create new problem in database */
  req.sprintf("INSERT INTO prob VALUE(NULL, '%s', '%s');", qPrintable(problem_name), "LAE");
  if(!query.exec(req))
    return false;

  /* Get added problem id */
  int prob_id;
  req.clear();
  req.sprintf("SELECT prob_id FROM prob WHERE "
              "prob_name = '%s' and prob_type = 'LAE';",
              qPrintable(problem_name));

  query.exec(req);
  query.first();
  prob_id = query.value(0).toInt();
  double a, b, c, res;

  /* Get data to save */
  QList<PROBLEM *>::Iterator it;
  for (it = problem_list.begin(); it != problem_list.end(); it++)
  {
    if ((*it)->GetProblemType() == SLAE && (*it)->GetProblemName() == problem_name)
    {
      a = ((PROB_LAE *)*it)->GetA();
      b = ((PROB_LAE *)*it)->GetB();
      c = ((PROB_LAE *)*it)->GetC();
      res = ((PROB_LAE *)*it)->GetRes();
      break;
    }
  }

  /* Save LAE */
  req.clear();
  req.sprintf("INSERT INTO lae VALUE(%s, %i, %g, %g, %g, %g);",
              "NULL", prob_id, a, b, c, res);

  if(!query.exec(req))
    return false;


  return true;
} /* End of 'SaveLae' funciton */


/* Create new SLAE problem */
QDialog * PROBLEMMANAGER::OpenSLAE( QString problem_name, STATE state )
{
  PROB_SLAE *new_slae = new PROB_SLAE(this, problem_name);
  SOLVESLAE *solve_dialog = new SOLVESLAE((QWidget *)this->parent());

  switch (state)
  {
  case NEW:
    //new_slae->set
    break;
  case EXIST:
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString req;

    req.sprintf("SELECT prob_id FROM prob WHERE "
                "prob_name = '%s' and prob_type = 'SLAE';",
                qPrintable(problem_name));
    query.exec(req);
    query.first();
    int prob_id = query.value(0).toInt();

    /* Get SLAE matrix */
    int num_of_vectors = 0;
    QVector<VEC> vec_arr;

    query.clear();
    req.sprintf("SELECT * FROM slae_matr WHERE p_id = %i ORDER BY slae_string_id;", prob_id);
    query.exec(req);

    while(query.next())
    {
      vec_arr.push_back(ParseString(qPrintable(query.value(2).toString())));
      num_of_vectors++;
    }

    MATRIX m(vec_arr, num_of_vectors);
    new_slae->SetMatrix(m);

    /* Get SLAE vectors */
    query.clear();
    req.sprintf("SELECT * FROM slae_vecs WHERE p_id = %i;", prob_id);
    query.exec(req);

    query.first();

    VEC vec_b, vec_res;
    vec_b = ParseString(qPrintable(query.value(1).toString()));
    new_slae->SetBVec(vec_b);
    solve_dialog->InitParams(m, vec_b);

    if (!query.value(2).isNull())
    {
      vec_res = ParseString(qPrintable(query.value(2).toString()));
      new_slae->SetResVec(vec_res);
      solve_dialog->NewRes(vec_res);
    }
    break;
  }

  solve_dialog->SetDialogName(problem_name);

  /* Connect dialog with problem */
  connect(solve_dialog, SIGNAL(NewParams(const MATRIX&, const VEC&)),
                      new_slae, SLOT(NewParams(const MATRIX&, const VEC&)));

  connect(new_slae, SIGNAL(NewRes(const VEC&)), solve_dialog, SLOT(NewRes(const VEC&)));

  /* Push problem to problem list */
  problem_list.push_back(new_slae);

  emit ProblemOpened(problem_name);
  return solve_dialog;
} /* End of 'OpenSLAE' function */

/* Save SLAE in database function */
bool PROBLEMMANAGER::SaveSLAE( QString problem_name )
{
  QSqlDatabase db = QSqlDatabase::database();
  QSqlQuery query(db);
  QString req;

  /* Create new problem in database */
  req.sprintf("INSERT INTO prob VALUE(NULL, '%s', '%s');", qPrintable(problem_name), "SLAE");

  QMessageBox::critical((QWidget *)this->parent(), problem_name, req);

  if(!query.exec(req))
    return false;

  /* Get added problem id */
  int prob_id;
  req.clear();
  req.sprintf("SELECT prob_id FROM prob WHERE "
              "prob_name = '%s' and prob_type = 'SLAE';",
              qPrintable(problem_name));

  QMessageBox::critical((QWidget *)this->parent(), problem_name, req);

  if(!query.exec(req))
    return false;
  query.first();
  prob_id = query.value(0).toInt();

  MATRIX matr;
  VEC b, res;

  /* Get data to save */
  QList<PROBLEM *>::Iterator it;
  for (it = problem_list.begin(); it != problem_list.end(); it++)
  {
    if ((*it)->GetProblemType() == SLAE && (*it)->GetProblemName() == problem_name)
    {
      matr = ((PROB_SLAE *)*it)->GetMatrix();
      b = ((PROB_SLAE *)*it)->GetBVec();
      res = ((PROB_SLAE *)*it)->GetBVec();
      break;
    }
  }

  /* Save data to database */
  QString sup_str;
  int size = matr.GetRows();
  req.clear();

  for (int i = 0; i < size; i++)
  {
    sup_str = NumbersToStr(matr[i], size);
    req.sprintf("INSERT INTO slae_matr VALUE(%i, %i, '%s');", prob_id, i, qPrintable(sup_str));

    QMessageBox::critical((QWidget *)this->parent(), problem_name, req);
    if(!query.exec(req))
      return false;
    sup_str.clear();
  }
  req.clear();

  QString res_str;
  /* Save matrix vectors */
  if (res.isEmpty())
    res_str.append("NULL");
  else
    res_str.append(NumbersToStr(VecToArr(res), size));

  req.sprintf("INSERT INTO slae_vecs VALUE(%i, '%s', '%s');",
              prob_id, NumbersToStr(VecToArr(b), size).toLocal8Bit().data(),
              res_str.toLocal8Bit().data());
  QMessageBox::critical((QWidget *)this->parent(), problem_name, req);
  if(!query.exec(req))
    return false;

  return true;
} /* End of 'SaveSALE' function */

/* Check existing problem_name */
bool PROBLEMMANAGER::IsExist( QString problem_name, PROBLEM_TYPE problem_type )
{
  QList<PROBLEM *>::Iterator it;
  for (it = problem_list.begin(); it != problem_list.end(); it++)
  {
    if ((*it)->GetProblemType() == problem_type &&
        (*it)->GetProblemName() == problem_name)
      return true;
  }
  return false;
} /* End of 'IsExist' fucntion */


/***************************************************************************************
 * SLOTS                                                                               *
 ***************************************************************************************/

/* Set problem list slot */
void PROBLEMMANAGER::SetProblemsList(PROBLEM_TYPE ProblemType)
{
  QSqlDatabase db = QSqlDatabase::database();
  QSqlQuery query(db);
  QString req;
  QStringList db_prob_list, op_prob_list;

  switch(ProblemType)
  {
  case LAE:
    req.sprintf("SELECT prob_name FROM prob WHERE prob_type = 'LAE';");
    break;
  case SLAE:
    req.sprintf("SELECT prob_name FROM prob WHERE prob_type = 'SLAE';");
    break;
  case ODE:
    req.sprintf("SELECT prob_name FROM prob WHERE prob_type = 'ODE';");
    break;
  case SOMETHING:
    QMessageBox::critical(NULL, QString("WTF"), QString("Are you kidding me??"));
    break;
  }
  query.exec(req);

  while(query.next())
    db_prob_list.push_back(query.value(0).toString());

  QList<PROBLEM *>::Iterator it;
  for (it = problem_list.begin(); it != problem_list.end(); it++)
  {
    if ((*it)->GetProblemType() == ProblemType)
      op_prob_list.push_back((*it)->GetProblemName());
  }

  if (!db_prob_list.isEmpty())
    emit GetProblemsList(db_prob_list, op_prob_list);

} /* End of 'SetProblemList' function */

/* Open problem slot */
void PROBLEMMANAGER::OpenProblem(PROBLEM_TYPE problem_type, QString problem_name, STATE state )
{
  QDialog *solve_dialog;

  if (IsExist(problem_name, problem_type))
  {
    QMessageBox::critical((QWidget *)this->parent(), QString("Warning!"),
      QString("Problem whit this name already exist!\nChoose another name!"));
    return;
  }

  switch (problem_type)
  {
  case LAE:
    solve_dialog = OpenLAE(problem_name, state);
    break;
  case SLAE:
    solve_dialog = OpenSLAE(problem_name, state);
    break;
  case ODE:
    break;
  case SOMETHING:
    break;
  }

  emit GetSolveDialog(solve_dialog);
} /* End of 'OpenProblem' slot */


/* Save problem slot */
void PROBLEMMANAGER::SaveProblem( PROBLEM_TYPE problem_type, QString problem_name )
{

  bool is_saved;
  QSqlDatabase db = QSqlDatabase::database();
  QSqlQuery query(db);
  QString req;

  req.sprintf("SELECT ISEXIST('%s', '%s')", qPrintable(problem_name), qPrintable(PRTOSTR(problem_type)));
  query.exec(req);

  query.first();

  if (query.value(0).toInt() == TRUE)
  {
    QMessageBox::critical((QWidget *)this->parent(), QString("Warning!"),
      QString("Problem whit this name already exist in database!\nChoose another name!"));
    return;
  }

  switch (problem_type)
  {
  case LAE:
    break;
  case SLAE:
    is_saved = SaveSLAE(problem_name);
    break;
  case ODE:
    break;
  case SOMETHING:
    break;
  }

  if (is_saved)
  {
    QMessageBox::information((QWidget *)this->parent(), QString("Done!"),
      QString("Problem saved!"));
  }
  else
  {
    QMessageBox::critical((QWidget *)this->parent(), QString("Error!"),
      QString("Problem don't saved!"));
  }

  emit Saved(is_saved);
} /* End of 'SaveProblem' function */


/* END OF 'problemmanager.cpp' FILE */

