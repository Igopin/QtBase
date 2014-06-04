/* Problem browser header file */

#ifndef _PROBBROWSER_H_
#define _PROBBROWSER_H_

#include <QWidget>
#include <QStringList>
#include "defines.h"
#include "solvelae.h"

/* Widget namespace */
namespace Ui {
  class PROBBROWSER;
}

/* Probbrowser */
class PROBBROWSER: public QWidget
{
  Q_OBJECT
private:
   Ui::PROBBROWSER *ui;

public:
  /* Main default constructor */
  explicit PROBBROWSER( QWidget *parent = 0 );

  ~PROBBROWSER();

signals:
  /* Request problem list signal */
  void NeedProblemsList( PROBLEM_TYPE );

  /* Open problem signal */
  void OpenProblem( PROBLEM_TYPE, QString, STATE );

  /* Edit dialog signal */
  void NeedEditDialog( PROBLEM_TYPE, QString );

  /* Show dialog signal */
  void ShowDialog( QString, PROBLEM_TYPE );

  /* Create new problem signal */
  void NewProblem( PROBLEM_TYPE );

  /* Save new problem */
  void SaveProblem( PROBLEM_TYPE, QString );
public slots:
  /* Menu "About" item processing */
  void About( void );

  /* Menu "Connect" item processing */
  void Connect( void );

  /* Connection processing slot */
  void Connected( QString );

  /* Get current problem */
  void GetProblemsList( QStringList, QStringList );

  /* Problem opened slot */
  void ProblemOpened( QString );

  /* Set problem dialog slot */
  void SetDialog( QDialog * );

  /* Problem saving status */
  void Saved( bool );
private slots:

  /* Choose curent problem combo box slot */
  void on_problem_type_combo_box_currentIndexChanged(const QString &arg1);

  /* Open button processing slot */
  void on_open_problem_button_clicked();

  /* Edit problem button slot */
  void on_prob_edit_button_clicked();

  /* Open problem button processing slot */
  void on_new_problem_button_clicked();

  /* Save problem to base */
  void on_save_problem_button_clicked();
};

#endif // _PROBBROWSER_H_

/* END OF 'probbrowser.h' FILE */
