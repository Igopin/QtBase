#ifndef _PROBLEMMANAGER_H_
#define _PROBLEMMANAGER_H_

#include <QObject>
#include <QDialog>
#include <QStringList>
#include "problem.h"
#include "defines.h"

class PROBLEMMANAGER : public QObject
{
  Q_OBJECT
private:
  QList<PROBLEM *> problem_list;

  /* Create new LAE problem */
  QDialog * OpenLAE( QString, STATE );

  /* Create new SLAE problem */
  QDialog * OpenSLAE( QString, STATE );

  /* Save LAE in database function */
  bool SaveLAE( QString );

  /* Save SLAE in database function */
  bool SaveSLAE( QString );

  /* Check existing problem name */
  bool IsExist( QString, PROBLEM_TYPE );
public:
  explicit PROBLEMMANAGER(QObject *parent = 0);

signals:
  /* Get Problem signal */
  void GetProblemsList(QStringList, QStringList);

  /* Problem opened signal */
  void ProblemOpened(QString);

  /* Get SOLVELAE dialog pointer */
  void GetSolveDialog(QDialog *);

  /* Saving problme status */
  void Saved( bool );

public slots:
  /* Set problem slot */
  void SetProblemsList( PROBLEM_TYPE );

  /* Open problem slot */
  void OpenProblem( PROBLEM_TYPE, QString, STATE );

  /* Save problem slot */
  void SaveProblem( PROBLEM_TYPE, QString );


};

#endif // _PROBLEMMANAGER_H_
