//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include "Utility.h"

using namespace std ;
using namespace sf ;

class Matrix
{
public:
	Matrix() ;
	Matrix(int const& _col, int const& _row, int const &_scale) ;
	float get(int const& i, int const& j) const ;
	void set(int const& i, int const& j, float const& _coeff) ;
	void resize(int const& _col, int const& _row) ;
	int getRow() const ;
	int getCol() const ;
	void setScale(int const& _scale) ;
	int getScale() const ;

private:
	vector<float> coeff ;
	int col ;
	int row ;
	int scale ;
};

Matrix operator+(Matrix const& m1, Matrix const& m2) ;
Matrix operator-(Matrix const& m1, Matrix const& m2) ;
Matrix operator*(Matrix const& m, float const& k) ;
Matrix operator/(Matrix const& m, float const& k) ;