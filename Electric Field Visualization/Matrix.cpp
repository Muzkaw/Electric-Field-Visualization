//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "Matrix.h"

Matrix::Matrix() 
{
	col = 0 ;
	row = 0 ;
	coeff.clear() ;
	scale = 1 ;
}
Matrix::Matrix(int const& _col, int const& _row, int const &_scale) 
{
	col = _col ;
	row = _row ;
	resize(col, row) ;
	scale = _scale ;
}
float Matrix::get(int const& i, int const& j) const
{
	if(i>0 && i <row && j>0 && j<row)
		return coeff[i+(j-1)*col] ;
	else return 0 ;
}
void Matrix::set(int const& i, int const& j, float const& _coeff)
{
	if(i>0 && i <row && j>0 && j<row)
		coeff[i+max(j-1,0)*col] = _coeff ;
}
void Matrix::resize(int const& _col, int const& _row)
{
	col=_col ;
	row=_row ;
	coeff.resize(col*row,0) ;
}
int Matrix::getRow() const
{
	return row ;
}
int Matrix::getCol() const
{
	return col ;
}
void Matrix::setScale(int const& _scale)
{
	scale = _scale ;
}
int Matrix::getScale() const
{
	return scale ;
}


Matrix operator+(Matrix const& m1, Matrix const& m2)
{
	Matrix result(m1) ;
	for(int i(0) ; i < m1.getCol() ; i++) 
	{
		for(int j(0) ; j < m1.getCol() ; j++) 
		{
			result.set(i,j, m1.get(i,j)+m2.get(i,j)) ;
		}
	}
	return result ;
}
Matrix operator-(Matrix const& m1, Matrix const& m2)
{
	Matrix result(m1) ;
	for(int i(0) ; i < m1.getCol() ; i++) 
	{
		for(int j(0) ; j < m1.getCol() ; j++) 
		{
			result.set(i,j, m1.get(i,j)-m2.get(i,j)) ;
		}
	}
	return result ;
}
Matrix operator*(Matrix const& m, float k)
{
	Matrix result(m) ;
	for(int i(0) ; i < m.getCol() ; i++) 
	{
		for(int j(0) ; j < m.getCol() ; j++) 
		{
			result.set(i,j, m.get(i,j)*k) ;
		}
	}
	return result ;
}
Matrix operator/(Matrix const& m, float k)
{
	Matrix result(m) ;
	for(int i(0) ; i < m.getCol() ; i++) 
	{
		for(int j(0) ; j < m.getCol() ; j++) 
		{
			result.set(i,j, m.get(i,j)/k) ;
		}
	}
	return result ;
}

