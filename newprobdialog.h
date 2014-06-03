/* New problem dialog header file */

#ifndef _NEWPROBDIALOG_H_
#define _NEWPROBDIALOG_H_

#include <QDialog>
#include "defines.h"

/* UI dialog namespace */
namespace Ui {
  class NEWPROBDIALOG;
}

/* New problem dialog Qt class */
class NEWPROBDIALOG : public QDialog
{
  Q_OBJECT
private:
  Ui::NEWPROBDIALOG *ui;

  bool isDefault; // Default connection settings flag

public:

  /* Main default constructor */
  explicit NEWPROBDIALOG(QWidget *parent = 0);

  /* Get database name function */
  PROBLEM_TYPE ProblemType() const;

  /* Get database name function */
  QString DatabaseName() const;

  /* Get user name function */
  QString UserName() const;

  /* Get passsword name function */
  QString Password() const;

  /* Get host name name function */
  QString HostName() const;

  /* Class destructor */
  ~NEWPROBDIALOG();
private slots:
  /* Exit button clicked */
  void on_exitButton_clicked();

  /* Check box processing */
  void on_checkBox_clicked( bool checked );

  /* Start button procrssing */
  void on_startButton_clicked();

  void accept();
signals:
  /* Current database name signal */
  void Connected(QString);
};

#endif // _NEWPROBDIALOG_H_

/* END OF 'newprobdialog.h' FILE */
