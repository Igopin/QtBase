/* LAE solving class source file */

#include <QMessageBox>
#include "prob_lae.h"

PROB_LAE::PROB_LAE(QObject *parent, QString name) :
  PROBLEM(parent)
{
  this->problem_name = name;
  this->problem_type = LAE;
}


void PROB_LAE::SetRes( double res )
{
  this->res = res;
}

void PROB_LAE::SetABC( double a, double b, double c )
{
  this->a = a;
  this->b = b;
  this->c = c;
}

void PROB_LAE::NewParams( double a, double b, double c )
{
  SetABC(a, b, c);
  Solve();
  emit NewRes(this->res);
}


void PROB_LAE::Solve( void )
{
  res = - (c + b) / a;
}

/* END OF 'lae.cpp' FUNCTION */
