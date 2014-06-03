/* Solve SLAE dialog header file */

#ifndef SOLVELAE_H
#define SOLVELAE_H

#include <QDialog>
#include "defines.h"

namespace Ui {
  class SOLVELAE;
}

class SOLVELAE : public QDialog
{
  Q_OBJECT

private:
  Ui::SOLVELAE *ui;
  QString problem_name;
public:
  explicit SOLVELAE(QWidget *parent = 0);

  void SetDialogName( QString );

  void InitParams( double, double, double );

  ~SOLVELAE();
signals:
  void NewParams(double, double, double);

public slots:
  void NewRes( double );

  /* Show current dialog */
  void Show( QString, PROBLEM_TYPE );

private slots:
  void on_prob_button_solve_clicked();
  void on_prob_done_button_clicked();
};

#endif // SOLVELAE_H

/* END OF 'solveslae.h' FUNCTION */
