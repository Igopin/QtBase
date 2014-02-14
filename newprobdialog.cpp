/* New problem dialog source file */

#include "newprobdialog.h"
#include "ui_newprobdialog.h"

/* Default Qt constructor */
NEWPROBDIALOG::NEWPROBDIALOG(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::NEWPROBDIALOG)
{
  ui->setupUi(this);
} /* End of constructor */

/* Default Qt destructor */
NEWPROBDIALOG::~NEWPROBDIALOG()
{
  delete ui;
} /* End of Qt destructor */

/* END OF 'newprobdialog.cpp' FILE */
