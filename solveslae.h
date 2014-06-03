/* Solve SLAE dialog header file */

#ifndef _SOLVESLAE_H_
#define _SOLVESLAE_H_

#include <QDialog>
#include "defines.h"
#include "matrix.h"

namespace Ui {
  class SOLVESLAE;
}

class SOLVESLAE : public QDialog
{
  Q_OBJECT

private:
  Ui::SOLVESLAE *ui;
  QString problem_name;

public:
  explicit SOLVESLAE(QWidget *parent = 0);
  ~SOLVESLAE();

  void InitParams( const MATRIX&, const VEC& );
  void SetDialogName( const QString );

signals:
  void NewParams( const MATRIX&, const VEC& );

public slots:
  /* New params */
  void NewRes( const VEC& );

  /* Show this dialog */
  void Show( QString, PROBLEM_TYPE );

private slots:
  /* Push 'Solve' button slot */
  void on_solve_button_clicked();
  void on_done_bitton_clicked();
};

#endif // SOLVESLAE_H

/* END OF 'solveslae.h' FILE */
