/* Problem browser QT class source file */

#include <QtWidgets>
#include <QSqlDatabase>
#include <QStringList>
#include "probbrowser.h"
#include "ui_probbrowser.h"
#include "newprobdialog.h"


/* Default Qt constructor */
PROBBROWSER::PROBBROWSER(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PROBBROWSER)
{
  ui->setupUi(this);
  QStringList problem_types;

  problem_types.push_back(QString("LAE"));
  problem_types.push_back(QString("SLAE"));
  problem_types.push_back(QString("ODE"));

  ui->problem_type_combo_box->addItems(problem_types);
} /* End of constructor */



/***************************************************************************************
 * FUNCTIONS                                                                           *
 ***************************************************************************************/

/***************************************************************************************
 * SLOTS                                                                               *
 ***************************************************************************************/


/****** PRIVATE ******/


/* Choose curent problem combo box slot */
void PROBBROWSER::on_problem_type_combo_box_currentIndexChanged(const QString &problem_type )
{
  emit NeedProblemsList(STRTOPR(problem_type));
} /* End of 'on_problem_type_combo_box_currentIndexChanged' slot */

/* Open button processing slot */
void PROBBROWSER::on_open_problem_button_clicked()
{
  emit OpenProblem(STRTOPR(ui->problem_type_combo_box->currentText()),
                   ui->current_problem_combo_box->currentText(),
                   EXIST);
} /* End of 'on_open_problem_button_clicked' slot */

/* Edit problem button slot */
void PROBBROWSER::on_prob_edit_button_clicked()
{
  emit ShowDialog(ui->opened_problem_combo_box->currentText(),
                  STRTOPR(ui->problem_type_combo_box->currentText()));
} /* End of 'on_prob_edit_button_clicked' slot */

/* Open problem button processing function */
void PROBBROWSER::on_new_problem_button_clicked()
{
  bool ok;
  QString problem_name = QInputDialog::getText(this, tr("Choose problem name"),
    tr("Problem name:"), QLineEdit::Normal, QDir::home().dirName(), &ok);

  if (ok && !problem_name.isEmpty())
    emit OpenProblem(STRTOPR(ui->problem_type_combo_box->currentText()),
                     problem_name,
                     NEW);

} /* End of 'on_new_problem_button_clicked' function */

/* Save problem to base */
void PROBBROWSER::on_save_problem_button_clicked()
{
  QString name = ui->opened_problem_combo_box->currentText();
  if (!name.isEmpty())
    emit SaveProblem(STRTOPR(ui->problem_type_combo_box->currentText()),
                     ui->opened_problem_combo_box->currentText());
} /* End of 'on_save_problem_button_clicked' slot */


/****** PUBLIC ******/

/* Menu item "About" processing function */
void PROBBROWSER::About( void )
{
  QMessageBox::about(this, tr("About"), tr("Tambov's wolf is you brother!"));
} /* End of 'About' function */

/* Menu item "New Problem" processing function */
void PROBBROWSER::Connect( void )
{
  NEWPROBDIALOG npd(this);
  connect(&npd, SIGNAL(Connected(QString)),
                SLOT(Connected(QString)));

  npd.exec();
} /* End of 'About' function */

/* Connection processing slot */
void PROBBROWSER::Connected( QString db_name )
{
  this->show();  
  ui->current_base_label->setText(db_name);
  emit NeedProblemsList(STRTOPR(ui->problem_type_combo_box->currentText()));
} /* End of 'Connected' slot */

/* Get current problem */
void PROBBROWSER::GetProblemsList( QStringList db_prob_list, QStringList op_prob_list )
{
  if (!db_prob_list.isEmpty())
  {
    ui->current_problem_combo_box->clear();
    ui->current_problem_combo_box->addItems(db_prob_list);

    ui->opened_problem_combo_box->clear();
    ui->opened_problem_combo_box->addItems(op_prob_list);
  }
  else
    QMessageBox::critical(this, QString("Error"), QString("Problem list is empty"));
} /* End of 'GetProblemList' slot */

/* Problem opened slot */
void PROBBROWSER::ProblemOpened( QString problem_name )
{
  ui->opened_problem_combo_box->addItem(problem_name, 0);
  ui->opened_problem_combo_box->update();
} /* End of 'ProblemOpened' slot */

/* Set problem dialog */
void PROBBROWSER::SetDialog( QDialog * solve_dialog )
{
  connect(this, SIGNAL(ShowDialog(QString, PROBLEM_TYPE)),
    solve_dialog, SLOT(Show(QString, PROBLEM_TYPE)));
} /* End of 'SetLAEDialog' slot */

/* Problem saving status */
void PROBBROWSER::Saved( bool is_save )
{
  if (is_save)
    emit NeedProblemsList(STRTOPR(ui->problem_type_combo_box->currentText()));
} /* End of 'Saved' slot */

/* Default Qt destructor */
PROBBROWSER::~PROBBROWSER()
{
  delete ui;
} /* End of Qt destructor */

/* END OF 'probbrowser.cpp' FILE */

