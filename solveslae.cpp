/* Solve SLAE dialog header file */

#include "setdimdialog.h"
#include "solveslae.h"
#include "ui_solveslae.h"

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


/* Set tables size slot */
void SOLVESLAE::SetTablesSize( int size )
{
  int old_size = ui->matrix_table_widget->rowCount();

  ui->matrix_table_widget->setColumnCount(size);
  ui->matrix_table_widget->setRowCount(size);

  ui->b_column_table_widget->setColumnCount(1);
  ui->b_column_table_widget->setRowCount(size);

  if (old_size < size)
  {
    QString num;
    QTableWidgetItem *item;
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {

        if (i < old_size && j < old_size)
          continue;

        if (i == j)
          num.sprintf("%g", 1.0);
        else
          num.sprintf("%g", 0.0);
        item = new QTableWidgetItem(num);
        ui->matrix_table_widget->setItem(i, j, item);
      }
      num.sprintf("%g", 0.0);
      item = new QTableWidgetItem(num);
      ui->b_column_table_widget->setItem(i, 0, item);
    }
  }

} /* End of 'SetTablesSize' slot */

/* Push 'Solve' button slot */
void SOLVESLAE::on_solve_button_clicked()
{
  int rows = ui->matrix_table_widget->rowCount(),
      columns = ui->matrix_table_widget->columnCount();
  MATRIX matr(rows, columns);
  VEC vec_b(rows);

  bool is_empty, is_digit;
  int num;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      is_empty = (ui->matrix_table_widget->item(i, j))->text().isEmpty();
      num = (ui->matrix_table_widget->item(i, j))->text().toDouble(&is_digit);
      if (is_digit && !is_empty)
        matr[i][j] = num;
      else
      {
        QMessageBox::critical(this, QString("Error!"),
          QString("Incorrect input!\nElements must be numbers!"));
        return;
      }
    }
  }

  for (int i = 0; i < rows; i++)
  {
    is_empty = (ui->b_column_table_widget->item(i, 0))->text().isEmpty();
    num = (ui->b_column_table_widget->item(i, 0))->text().toDouble(&is_digit);
    if (is_digit)
      vec_b[i] = num;
    else
    {
      QMessageBox::critical(this, QString("Error!"),
        QString("Incorrect input!\nAll items must be field!"));
      return;
    }
  }

  emit NewParams(matr, vec_b);
} /* End of 'on_solve_button_clicked' slot */


/* Push 'Done' button slot */
void SOLVESLAE::on_done_bitton_clicked()
{
  this->hide();
}  /* End of 'on_done_button_clicked' slot */

/* Set dimension button processing */
void SOLVESLAE::on_set_dim_button_clicked()
{
  SETDIMDIALOG sdd(this, ui->matrix_table_widget->rowCount());

  connect(&sdd, SIGNAL(NewSize(int)), SLOT(SetTablesSize(int)));

  sdd.exec();
} /* End of 'on_set_dim_button_clicked' slot */

/* Destructor */
SOLVESLAE::~SOLVESLAE()
{
  delete ui;
} /* End of destructor */

/* END OF 'solveslae.cpp' FILE */
