//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "FieldLine.h"

FieldLine::FieldLine(RenderWindow *_window)
{
	VA.setPrimitiveType(LinesStrip);
	window = _window;
}

void FieldLine::update(Vector2f pos, Matrix const& field)
{
	VA.clear();
	Color color = Color::Color(0,0,0,100);
	Vector2f X = pos;
	Vector2f grad;
	
	for (int i(0); i < 100; i++)
	{
		VA.append(Vertex(X*(float)field.getScale(), color));
		grad = Vector2f((field.get(X.x+1, X.y)- field.get(X.x-1, X.y))/2.0, (field.get(X.x, X.y+1)- field.get(X.x, X.y-1))/2.0);
		X -= grad / Norm(grad) * 5.f;
		if (field.get(X.x, X.y) < -1) i = 100;
	}
}

void FieldLine::draw()
{
	window->draw(VA);
}