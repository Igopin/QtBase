/* SLAE class source file */
#include "prob_slae.h"
#include <QMessageBox>

PROB_SLAE::PROB_SLAE(QObject *parent, QString name) :
  PROBLEM(parent)
{
  this->problem_name = name;
  this->problem_type = SLAE;
}


void PROB_SLAE::SetMatrix( const MATRIX &m )
{
  this->matr = m;
}

void PROB_SLAE::SetBVec( const VEC &b )
{
  this->b = b;
}

void PROB_SLAE::SetResVec( const VEC &res )
{
  this->res = res;
}

void PROB_SLAE::Solve( void )
{
  MATRIX m_inv(matr.Inverse());
  res = m_inv * b;
  QString s;
  s.sprintf("%g %g %g", b[0], b[1], b[2]);
  QMessageBox::about(NULL, QString("AAA"), s);
  s.clear();
  s.sprintf("%g %g %g", res[0], res[1], res[2]);
  QMessageBox::about(NULL, QString("AAA"), s);
}


void PROB_SLAE::NewParams( const MATRIX &matr, const VEC &b_vec )
{
  this->matr = matr;
  this->b = b_vec;
  Solve();
  emit NewRes(this->res);
}

/* END OF 'slae.h' FILE */
