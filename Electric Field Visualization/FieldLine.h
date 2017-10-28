//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace sf;

class FieldLine
{
public:
	FieldLine(RenderWindow *_window);

	void update(Vector2f pos, Matrix const& field);
	void draw();

private:
	float length;
	VertexArray VA;
	RenderWindow *window;
};

