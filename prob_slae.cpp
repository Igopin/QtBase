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

MATRIX & PROB_SLAE::GetMatrix( void )
{
  return this->matr;
}

VEC & PROB_SLAE::GetBVec( void )
{
  return this->b;
}

VEC & PROB_SLAE::GetResVec( void )
{
  return this->res;
}

void PROB_SLAE::Solve( void )
{
  MATRIX m_inv(matr.Inverse());
  res = m_inv * b;
}


void PROB_SLAE::NewParams( const MATRIX &matr, const VEC &b_vec )
{
  this->matr = matr;
  this->b = b_vec;
  Solve();
  emit NewRes(this->res);
}

/* END OF 'slae.h' FILE */
