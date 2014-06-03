#ifndef _LAE_H_
#define _LAE_H_

#include "problem.h"

class PROB_LAE : public PROBLEM
{
  Q_OBJECT
private:
  double a, b, c, res;
public:
  explicit PROB_LAE(QObject *parent = 0, QString name = 0);

  void SetABC( double, double, double );
  void SetRes( double );
  void Solve( void );
public slots:
  void NewParams(double, double, double);
signals:
  void NewRes(double);

};

#endif /* _LAE_H_ */


