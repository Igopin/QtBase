#include "defines.h"

QString PRTOSTR( const PROBLEM_TYPE &t )
{
  switch(t)
  {
  case LAE:
    return QString("LAE");
  case SLAE:
    return QString("SLAE");
  case ODE:
    return QString("ODE");
  default:
    return NULL;
  }
}

PROBLEM_TYPE STRTOPR( const QString &str )
{

  if (str == QString("LAE"))
    return LAE;
  if (str == QString("SLAE"))
    return SLAE;
  if (str == QString("ODE"))
    return ODE;

  return SOMETHING;
}
