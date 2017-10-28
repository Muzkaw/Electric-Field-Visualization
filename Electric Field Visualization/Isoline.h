//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace sf;

class Isoline
{
public:
	Isoline(float const& _threshold, RenderWindow *_window);
	void marchingSquares(Matrix const& field);
	void draw();

private:

	int sample_size;
	float threshold;

	Matrix threshold_field;
	Vector2f size;
	float scale;

	VertexArray isolines;

	RenderWindow *window;
};

