/* Matrix class source file */

#include <QMessageBox>
#include <stdlib.h>
#include "matrix.h"

/* Default constructor */
MATRIX::MATRIX() : matr(NULL)
{
} /* End of default constructor */

/* Init matrix array */
void MATRIX::Init( int r, int c )
{
  rows = r, columns = c;

  matr = new double* [r];
  for (int i = 0; i < r; i++)
    matr[i] = new double [c];

} /* End of 'Init' function */

/* Erase matrix array */
void MATRIX::Destroy( void )
{
  if (matr != NULL)
  {
    for (int i = 0; i < rows; i++)
      if (matr[i] != NULL)
        delete matr[i];
    delete matr;
  }
}

/* Copy constructor */
MATRIX::MATRIX( const MATRIX &other )
{
  Init(other.GetRows(), other.GetColumns());

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      matr[i][j] = other.matr[i][j];
}

/* Default constructor */
MATRIX::MATRIX( int _rows = 1, int _columns = 1 )
{
  Init(_rows, _columns);
}

/* Default constructor */
MATRIX::MATRIX( QVector<VEC> vec_arr, int num_vecs )
{
  int vec_size = vec_arr[0].size();

  Init(vec_size, num_vecs);
  for (int i = 0; i < num_vecs; i++)
    for (int j = 0; j < num_vecs; j++)
      matr[i][j] = vec_arr[i][j];
}

/* Create unit matrix */
MATRIX & MATRIX::ToUnit( void )
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      matr[i][j] = (i == j) ?  1 : 0;

  return *this;
} /* End of 'ToUnit' function */

/* Inverse matrix */
MATRIX MATRIX::Inverse( void )
{
  int num;
  double temp;
  MATRIX m(*this), E(rows, columns);
  E.ToUnit();

  if (rows != columns)
    return (*this);

  num = rows;
  for (int k = 0; k < num ; k++)
  {
    temp = m[k][k];
    for (int j = 0; j < num; j++)
    {
      m[k][j] /= temp;
      E[k][j] /= temp;
    }

    for (int i = k + 1; i < num; i++)
    {
      temp = m[i][k];
      for (int j = 0; j < num; j++)
      {
        m[i][j] -= m[k][j] * temp;
        E[i][j] -= E[k][j] * temp;
      }
    }
  }

  for (int k = num - 1; k > 0; k--)
    for (int i = k - 1; i >= 0; i--)
    {
      temp = m[i][k];

      for (int j = 0; j < num; j++)
      {
        m[i][j] -= m[k][j] * temp;
        E[i][j] -= E[k][j] * temp;
      }
    }

  for (int i = 0; i < num; i++)
    for (int j = 0; j < num; j++)
      m[i][j] = E[i][j];

  return MATRIX(m);
} /* End of 'Inverse' function */


/* Get number of rows */
int MATRIX::GetRows( void ) const
{
  return this->rows;
}

/* Get number of columns */
int MATRIX::GetColumns( void ) const
{
  return this->columns;
}

/* Operator [] */
double * MATRIX::operator[]( unsigned int index ) const
{
  return matr[index];
}

/* Operator = */
MATRIX& MATRIX::operator=( const MATRIX &other )
{

  if (this->matr != NULL)
  {
    if (this->columns != other.columns || this->rows != other.rows)
    {
      Destroy();
      Init(other.GetRows(), other.GetColumns());
    }
  }
  else
    Init(other.GetRows(), other.GetColumns());

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      matr[i][j] = other.matr[i][j];

  return *this;
} /* End of '=' operator */


/* Multiply vector on matrix operator */
VEC operator*( const VEC &lvec, const MATRIX &rmatr )
{
  int
    vec_size = lvec.size(),
    matr_columns = rmatr.GetColumns();
  double sum;
  VEC res(matr_columns);

  if (vec_size != rmatr.GetRows())
    return res;

  for (int i = 0; i < matr_columns; i++)
  {
    sum = 0;
    for (int j = 0; j < vec_size; j++)
      sum += lvec[j] * rmatr[j][i];
    res[i] = sum;
  }

  return res;
} /* End of operator */

/* Multiply matrix on vector operator */
VEC operator*( const MATRIX &lmatr, const VEC &rvec )
{
  int
    vec_size = rvec.size(),
    matr_rows = lmatr.GetRows();
  double sum;
  VEC res(matr_rows);

  if (vec_size != lmatr.GetColumns())
    return res;

  for (int i = 0; i < matr_rows; i++)
  {
    sum = 0;
    for (int j = 0; j < vec_size; j++)
      sum += lmatr[i][j] * rvec[j];
    res[i] = sum;
  }

  return res;
} /* End of operator */

MATRIX operator*( const MATRIX &right, const MATRIX &left )
{
  double sum;
  int i, j, k,
    res_rows = right.GetRows(),
    res_columns = left.GetColumns();
  MATRIX res(res_rows, res_columns);

  for (i = 0; i < res_rows; i++)
  {
    for (j = 0; j < res_columns; j++)
    {
      sum = 0;
      for (k = 0; k < res_rows; k++)
        sum += right[i][k] * left[k][j];
      res[i][j] = sum;
    }
  }
  return res;
} /* End of operator '*' */

/* Multiply number on matrix operator */
MATRIX operator*( const double num, const MATRIX &rmatr )
{
  MATRIX res(rmatr);
  int
    columns = res.GetColumns(),
    rows = res.GetRows();

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      res[i][j] *= num;
  return res;
} /* End of operator */


/* Multiply number on matrix operator */
MATRIX operator*( const MATRIX &lmatr, const double num )
{
  MATRIX res(lmatr);
  int
    columns = res.GetColumns(),
    rows = res.GetRows();

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      res[i][j] *= num;
  return res;
} /* End of operator */

/* END OF 'matrix.cpp' FILE */
