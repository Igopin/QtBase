/* New problem dialog source file */

#include <QSqlDatabase>
#include <QMessageBox>
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

/* Get database name function */
QString NEWPROBDIALOG::DatabaseName() const
{
  if (isDefault)
    return QString(tr("problems"));
  return ui->editDatabase->text();
} /* End of 'DatabaseName' function */

/* Get user name function */
QString NEWPROBDIALOG::UserName() const
{
  if (isDefault)
    return QString(tr("root"));
  return ui->editUsername->text();

} /* End of 'UserName' function */

/* Get password name function */
QString NEWPROBDIALOG::Password() const
{
  if (isDefault)
    return QString("incodewetrust");
  return ui->editPassword->text();

} /* End of 'Password' function */

/* Get host name name function */
QString NEWPROBDIALOG::HostName() const
{
  if (isDefault)
    return QString("localhost");
  return ui->editHostname->text();
} /* End of 'HostName' function */

/* Exit button clicked */
void NEWPROBDIALOG::on_exitButton_clicked()
{
  this->accept();
} /* End of 'on_exitButton_clicked' function */

/* Check box processing */
void NEWPROBDIALOG::on_checkBox_clicked( bool checked )
{
  isDefault = checked;
  ui->connGroupBox->setEnabled(checked ? false : true);
}  /* End of 'on_checkBox_clicked' function */


/* Start button processing */
void NEWPROBDIALOG::on_startButton_clicked()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

  db.setHostName(HostName());
  db.setDatabaseName(DatabaseName());
  db.setUserName(UserName());
  db.setPassword(Password());
  if (db.open())
  {
    QMessageBox::information(this, QString("Information"), QString("Connection succesfull!"));
    emit Connected(DatabaseName());
  }
  else
    QMessageBox::critical(this, QString("Information"), QString("Connection failed!"));
  accept();
} /* End of 'on_startButton_clicked()' function */

void NEWPROBDIALOG::accept()
{
  this->close();
}
/* END OF 'newprobdialog.cpp' FILE */
