//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include "Matrix.h"
#include "Particle.h"
#include "Isoline.h"
#include "FieldLine.h"
#include "Utility.h"
#include "HSVColor.h"

class ElectricField
{
public:
	ElectricField(RenderWindow *_window);

	void update(double dt);

	void draw();

private:
	int width, height;
	Matrix V;

	RenderWindow *window;
	Image image;
	Texture texture;
	Sprite sprite;

	vector<Particle> p;

	vector<Isoline> iso;
};

