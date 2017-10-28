//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "Particle.h"

Particle::Particle()
{
	m = 1;
}
Particle::Particle(float mass, Vector2f position, float charge, RenderWindow *_window)
{
	m = mass;
	X = position;
	C = charge;

	window = _window;
	if(C>0) for (int i(0); i < 20; i++) fl.push_back(FieldLine(window));
}

void Particle::update(float const& dt, Matrix const& field)
{
	A = F / m;

	Xp = X;
	X = X + V*dt + 0.5f*A*pow(dt, 2);
	V = (X - Xp) / dt;

	for (int i(0); i < fl.size(); i++) fl[i].update(rotatePoint(X + Vector2f(10, 0), X, i / (float)fl.size() * 360), field);
}
void Particle::checkBound(Vector2f bound)
{
	if (X.x < 0) { X = Xp; V.x = -V.x; }
	if (X.x > bound.x) { X = Xp; V.x = -V.x; }
	if (X.y < 0) { X = Xp; V.y = -V.y; }
	if (X.y > bound.y) { X = Xp; V.y = -V.y; }
}
void Particle::draw()
{
	for (int i(0); i < fl.size(); i++) fl[i].draw();
}
