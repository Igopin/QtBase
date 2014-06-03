#include <QMessageBox>
#include "solvelae.h"
#include "ui_solvelae.h"

SOLVELAE::SOLVELAE(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SOLVELAE)
{
  ui->setupUi(this);
}

/* Init params function */
void SOLVELAE::InitParams( double a, double b, double c )
{
  QString num;
  num.sprintf("%g", a);
  ui->a_line_edit->setText(QString(num));

  num.sprintf("%g", b);
  ui->b_line_edit->setText(QString(num));

  num.sprintf("%g", c);
  ui->c_line_edit->setText(QString(num));
} /* END OF 'InitParams' FUNCTION */

/* New result slot */
void SOLVELAE::NewRes( double res )
{
  QString num;
  num.sprintf("%lf", res);
  ui->res_line_edit->setText(num);
} /* End of 'NewRes' function */

void SOLVELAE::Show( QString name, PROBLEM_TYPE problem_type )
{
  if ((this->problem_name == name) && (problem_type == LAE))
    this->show();
}

void SOLVELAE::on_prob_button_solve_clicked()
{
  emit NewParams(ui->a_line_edit->text().toDouble(),
                 ui->b_line_edit->text().toDouble(),
                 ui->c_line_edit->text().toDouble());
}

void SOLVELAE::on_prob_done_button_clicked()
{
  this->hide();
}

void SOLVELAE::SetDialogName( QString problem_name )
{
  this->setWindowTitle(problem_name);
  this->problem_name = problem_name;
}

SOLVELAE::~SOLVELAE()
{
  delete ui;
}
