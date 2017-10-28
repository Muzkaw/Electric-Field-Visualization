//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include "FieldLine.h"

using namespace std;
using namespace sf;

class Particle // class that manages particles following the Newton's law
{
public:

	Particle();
	Particle(float mass, Vector2f position, float charge, RenderWindow *_window);

	void update(float const& dt, Matrix const& field);
	void checkBound(Vector2f bound);

	void draw();

	float m; //mass (kg)
	float C;

	Vector2f F; //force
	Vector2f X, Xp; //position
	Vector2f V; //speed
	Vector2f A; //acceleration

	vector<FieldLine> fl;

	RenderWindow *window;
};
