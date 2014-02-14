/* New problem dialog header file */

#ifndef _NEWPROBDIALOG_H_
#define _NEWPROBDIALOG_H_

#include <QDialog>

/* UI dialog namespace */
namespace Ui {
  class NEWPROBDIALOG;
}

/* New problem dialog Qt class */
class NEWPROBDIALOG : public QDialog
{
  Q_OBJECT

public:

  /* Main default constructor */
  explicit NEWPROBDIALOG(QWidget *parent = 0);

  ~NEWPROBDIALOG();

private slots:

    void onOnExitButtonClicked(){reject();}

private:
  Ui::NEWPROBDIALOG *ui;
};

#endif // _NEWPROBDIALOG_H_

/* END OF 'newprobdialog.h' FILE */
