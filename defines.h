#ifndef _DEFINES_H_
#define _DEFINES_H_

#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QString>


#define DBG(str_1, str2) QMessageBox::critical(NULL, QString(str_1), QString(str_2));

typedef enum
{
  LAE,
  SLAE,
  ODE,
  SOMETHING
} PROBLEM_TYPE;

typedef QVector<double> VEC;

QString PRTOSTR( const PROBLEM_TYPE &t );

PROBLEM_TYPE STRTOPR( const QString &str );

#endif /* _DEFINES_H_ */
