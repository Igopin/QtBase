/* Problem class source file */
#include "problem.h"

PROBLEM::PROBLEM(QObject *parent) :
  QObject(parent)
{
}

/* Get problem type function */
PROBLEM_TYPE PROBLEM::GetProblemType( void )
{
  return this->problem_type;
} /* End of 'GetProblemType' function */


/* Get problem name function */
QString PROBLEM::GetProblemName( void )
{
  return this->problem_name;
} /* End of 'GetProblemName' function */

/* END OF 'problem.cpp' FILE */
