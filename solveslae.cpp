/* Solve SLAE dialog header file */

#include "solveslae.h"
#include "ui_solveslae.h"
#include <QMessageBox>

SOLVESLAE::SOLVESLAE(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SOLVESLAE)
{
  ui->setupUi(this);
}

/* Init dialog params */
void SOLVESLAE::InitParams( const MATRIX &matr, const VEC &vec_b )
{
  int
    rows = matr.GetRows(),
    columns = matr.GetColumns();
  QTableWidgetItem *item;
  QString num;

  ui->matrix_table_widget->setColumnCount(columns);
  ui->matrix_table_widget->setRowCount(rows);

  ui->b_column_table_widget->setColumnCount(1);
  ui->b_column_table_widget->setRowCount(vec_b.size());

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      num.sprintf("%g", matr[i][j]);
      item = new QTableWidgetItem(num);
      ui->matrix_table_widget->setItem(i, j, item);
    }
  }

  for (int i = 0; i < rows; i++)
  {
    num.sprintf("%g", vec_b[i]);
    item = new QTableWidgetItem(num);
    ui->b_column_table_widget->setItem(i, 0, item);
  }

} /* End of 'InitParams' function */

/* Set dialog name funciton */
void SOLVESLAE::SetDialogName( QString problem_name )
{
  this->setWindowTitle(problem_name);
  this->problem_name = problem_name;
} /* End of 'SetDialogName' function */

/* Show this dialog */
void SOLVESLAE::Show( QString name, PROBLEM_TYPE problem_type )
{
  if ((this->problem_name == name) && (problem_type == SLAE))
    this->show();
} /* End of 'Show' slot */


/* Set new result params */
void SOLVESLAE::NewRes( const VEC& v_res )
{
  int
    v_size = v_res.size();
  QTableWidgetItem *item;
  QString num;

  ui->result_column_table_widget->setColumnCount(1);
  ui->result_column_table_widget->setRowCount(v_size);

  for (int i = 0; i < v_size; i++)
  {
    num.sprintf("%g", v_res[i]);
    item = new QTableWidgetItem(num);
    ui->result_column_table_widget->setItem(i, 0, item);
  }
} /* End of 'NewRes' slot */

/* Destructor */
SOLVESLAE::~SOLVESLAE()
{
  delete ui;
} /* End of destructor */

/* Push 'Solve' button slot */
void SOLVESLAE::on_solve_button_clicked()
{
  int rows = ui->matrix_table_widget->rowCount(),
      columns = ui->matrix_table_widget->columnCount();
  MATRIX matr(rows, columns);
  VEC vec_b(rows);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      matr[i][j] = (ui->matrix_table_widget->item(i, j))->text().toDouble();

  QMessageBox::about(NULL, QString("AAA"), QString("Matrix load"));
  for (int i = 0; i < rows; i++)
    vec_b[i] = (ui->b_column_table_widget->item(i, 0))->text().toDouble();

  QString s;
  s.sprintf("%g %g %g", vec_b[0], vec_b[1], vec_b[2]);
  QMessageBox::about(NULL, QString("AAA"), s);


  emit NewParams(matr, vec_b);
} /* End of 'on_solve_button_clicked' slot */


/* Push 'Done' button slot */
void SOLVESLAE::on_done_bitton_clicked()
{
  this->hide();
}  /* End of 'on_done_button_clicked' slot */

/* END OF 'solveslae.cpp' FILE */

