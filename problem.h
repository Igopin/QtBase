/* Problem class header file */

#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include <QObject>
#include "defines.h"

class PROBLEM : public QObject
{
  Q_OBJECT
protected:
  QString problem_name;
  PROBLEM_TYPE problem_type;
public:
  explicit PROBLEM(QObject *parent = 0);

  /* Solve problem virtual function */
  //virtual double Solve() = 0;

  /* Get problem type function */
  PROBLEM_TYPE GetProblemType( void );

  /* Get problem name function */
  QString GetProblemName( void );
signals:

public slots:

};

#endif // _PROBLEM_H_

/* END OF 'problem.h' FILE */
