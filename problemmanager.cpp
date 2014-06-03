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



PROBLEMMANAGER::PROBLEMMANAGER(QObject *parent) :
  QObject(parent)
{
}

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

/* Create new LAE problem */
QDialog * PROBLEMMANAGER::OpenLAE( QString problem_name )
{
  PROB_LAE *new_lae = new PROB_LAE(this, problem_name);
  SOLVELAE *solve_dialog = new SOLVELAE((QWidget *)this->parent());
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

  /* Connect dialog with problem */
  connect(solve_dialog, SIGNAL(NewParams(double,double,double)),
                      new_lae, SLOT(NewParams(double,double,double)));

  connect(new_lae, SIGNAL(NewRes(double)), solve_dialog, SLOT(NewRes(double)));

  problem_list.push_back(new_lae);
  solve_dialog->SetDialogName(problem_name);

  emit ProblemOpened(problem_name);
  return solve_dialog;
} /* End of 'NewLAE' function */

/* Create new SLAE problem */
QDialog * PROBLEMMANAGER::OpenSLAE( QString problem_name )
{
  PROB_SLAE *new_slae = new PROB_SLAE(this, problem_name);
  SOLVESLAE *solve_dialog = new SOLVESLAE((QWidget *)this->parent());
  QSqlDatabase db = QSqlDatabase::database();
  QSqlQuery query(db);
  QString req;

  req.sprintf("SELECT prob_id FROM prob WHERE "
              "prob_name = '%s' and prob_type = 'SLAE';",
              qPrintable(problem_name));
  query.exec(req);
  query.first();
  int prob_id = query.value(0).toInt();


   solve_dialog->SetDialogName(problem_name);
  /***************************************************************************************
   * Get SLAE matrix                                                                     *
   ***************************************************************************************/
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

  /***************************************************************************************
   * Get SLAE vectors                                                                    *
   ***************************************************************************************/
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

  /***************************************************************************************
   * Connect dialog with problem                                                         *
   ***************************************************************************************/
  connect(solve_dialog, SIGNAL(NewParams(const MATRIX&, const VEC&)),
                      new_slae, SLOT(NewParams(const MATRIX&, const VEC&)));

  connect(new_slae, SIGNAL(NewRes(const VEC&)), solve_dialog, SLOT(NewRes(const VEC&)));


  /***************************************************************************************
   * Push problem to problem list                                                        *
   ***************************************************************************************/

  problem_list.push_back(new_slae);

  emit ProblemOpened(problem_name);
  return solve_dialog;
} /* End of 'OpenSLAE' function */

/* Open problem slot */
void PROBLEMMANAGER::OpenProblem(PROBLEM_TYPE problem_type, QString problem_name)
{
  QDialog *solve_dialog;

  switch (problem_type)
  {
  case LAE:
    solve_dialog = OpenLAE(problem_name);
    break;
  case SLAE:
    solve_dialog = OpenSLAE(problem_name);
    break;
  case ODE:
    break;
  case SOMETHING:
    break;
  }

  emit GetSolveDialog(solve_dialog);
} /* End of 'OpenProblem' slot */


/* END OF 'problemmanager.cpp' FILE */
