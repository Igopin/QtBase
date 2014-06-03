/* Matrix class header file */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <math.h>
#include "defines.h"

/* Support matrix class */
class MATRIX
{
private:
  double **matr;  // Matrix

  int
    rows,         // Number of rows
    columns;      // Number of columns

  /* Init matrix array */
  void Init( int r, int c );

  /* Erase matrix array */
  void Destroy( void );
public:

  /* Copy constructor */
  MATRIX ( void );

  /* Copy constructor */
  MATRIX ( const MATRIX &other );

  /* Default constructor */
  MATRIX( int _rows, int _columns );

  /* Vector  constructor */
  MATRIX( QVector<VEC> vec_arr, int num_vecs );

  /* Create unit matrix */
  MATRIX & ToUnit( void );

  /* Inverse matrix */
  MATRIX Inverse( void );

  /* Get number of rows */
  int GetRows( void ) const;

  /* Get number of columns */
  int GetColumns( void ) const;

  /* Operator [] */
  double * operator[]( unsigned int index ) const;

  /* Operator = */
  MATRIX& operator=( const MATRIX &other );

  /* Destructor */
  ~MATRIX(){Destroy();};
};

/* Multiply matrix operator */
MATRIX operator*(  const MATRIX&, const MATRIX& );

/* Multiply vector on matrix operator */
VEC operator*( const VEC&, const MATRIX& );

/* Multiply matrix on vector operator */
VEC operator*( const MATRIX&, const VEC& );

/* Multiply number on matrix operator */
MATRIX operator*( const double, const MATRIX& );

#endif /* _MATRIX_H_ */

/* END OF 'matrix.h' FILE */
