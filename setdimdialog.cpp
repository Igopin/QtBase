#include "setdimdialog.h"
#include "ui_setdimdialog.h"

SETDIMDIALOG::SETDIMDIALOG(QWidget *parent, int tab_size) :
  QDialog(parent), ui(new Ui::SETDIMDIALOG)
{
  ui->setupUi(this);

  table_size = tab_size;
  QString title;
  title.sprintf("Current dimension: %i", tab_size);
  this->setWindowTitle(title);
}

void SETDIMDIALOG::on_change_button_clicked()
{
  bool is_digit;
  int new_size, num;

  num = ui->spinBox->text().toUInt(&is_digit);
  if (!is_digit)
    return;

  if (ui->increase_radio_button->isChecked())
    new_size = table_size + num;
  else if (ui->reduce_radio_button->isChecked())
  {
    int tmp = table_size - num;
    new_size = (tmp > 0) ? tmp : 1;
  }
  else if (ui->set_radio_button->isChecked())
    new_size = num;

  emit NewSize(new_size);
  this->close();
}

void SETDIMDIALOG::on_exit_button_clicked()
{
  this->close();
}

SETDIMDIALOG::~SETDIMDIALOG()
{
  delete ui;
}

