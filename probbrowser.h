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
public:
  /* Main default constructor */
  explicit PROBBROWSER( QWidget *parent = 0 );

  ~PROBBROWSER();

signals:
  /* Request problem list signal */
  void NeedProblemsList( PROBLEM_TYPE );

  /* Open problem signal */
  void OpenProblem( PROBLEM_TYPE, QString );

  /* Edit dialog dignal */
  void NeedEditDialog( PROBLEM_TYPE, QString );

  /* Show dialog */
  void ShowDialog( QString, PROBLEM_TYPE );

public slots:
  /* Menu "About" item processing */
  void About( void );

  /* Menu "New problem" item processing */
  void NewProb( void );

  /* Connection processing slot */
  void Connected( QString );

  /* Get current problem */
  void GetProblemsList( QStringList, QStringList );

  /* Problem opened slot */
  void ProblemOpened( QString );

  /* Set problem dialog */
  void SetDialog( QDialog * );

private slots:

  /* Choose curent problem combo box slot */
  void on_problem_type_combo_box_currentIndexChanged(const QString &arg1);

  /* Open button processing slot */
  void on_open_problem_button_clicked();

  /* Edit problem button slot */
  void on_prob_edit_button_clicked();
private:
   Ui::PROBBROWSER *ui;
};

#endif // _PROBBROWSER_H_

/* END OF 'probbrowser.h' FILE */
