/* SLAE class header file */
#ifndef _SLAE_H_
#define _SLAE_H_

#include "defines.h"
#include "problem.h"
#include "matrix.h"

class PROB_SLAE : public PROBLEM
{
  Q_OBJECT
private:
 MATRIX matr;
 VEC b, res;
public:
  explicit PROB_SLAE(QObject *parent = 0, QString name = 0);

  /* Set params */
  void SetMatrix( const MATRIX& );
  void SetBVec( const VEC& );
  void SetResVec( const VEC& );

  /* Get Params */
  MATRIX & GetMatrix( void );
  VEC & GetBVec( void );
  VEC & GetResVec( void );

  void Solve( void );
signals:
  void NewRes( const VEC &v_res );

public slots:
  void NewParams( const MATRIX &matr, const VEC &b_vec );

};

#endif /* _SLAE_H_ */
