/* Set matrix dimension dialog header file */
#ifndef _SETDIMDIALOG_H_
#define _SETDIMDIALOG_H_

#include <QDialog>

namespace Ui {
  class SETDIMDIALOG;
}

class SETDIMDIALOG : public QDialog
{
  Q_OBJECT

private:
  Ui::SETDIMDIALOG *ui;
  int table_size;
signals:
  void NewSize( int );
public:
  explicit SETDIMDIALOG(QWidget *parent = 0, int tab_size = 1);

  ~SETDIMDIALOG();

private slots:
  void on_change_button_clicked();
  void on_exit_button_clicked();
};

#endif // _SETDIMDIALOG_H_

/* END OF 'setdimdialog.h' FILE */
