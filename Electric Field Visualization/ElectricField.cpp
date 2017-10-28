//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "ElectricField.h"

ElectricField::ElectricField(RenderWindow *_window)
{
	width = 300; height = 300;
	V.resize(width, height);
	image.create(width, height);
	texture.create(width, height);
	V.setScale(2);
	sprite.setScale(V.getScale(), V.getScale());

	window = _window;
	p.push_back(Particle(1, Vector2f(55, 120), 10, window));
	p.push_back(Particle(1, Vector2f(120, 77), -10, window));
	p.push_back(Particle(1, Vector2f(120, 120), -5, window));
	p.push_back(Particle(1, Vector2f(100, 25), 5, window));
	p.push_back(Particle(1, Vector2f(150, 32), 15, window));
	p.push_back(Particle(1, Vector2f(100, 178), -15, window));

	for (int i(0); i < 20; i++) iso.push_back(Isoline(0.01+i/20.0, window));
}

void ElectricField::update(double dt)
{
	for (int i(0); i < p.size(); i++) p[i].F = Vector2f(0,0);
	for (int i(0); i < p.size(); i++)
	{
		for (int j(i+1); j < p.size(); j++)
		{
			p[i].F = (100000000.f*p[i].C*p[j].C / pow(max(Distance(p[i].X, p[j].X),1.f), 3)) * (p[i].X - p[j].X);
			p[j].F = (100000000.f*p[i].C*p[j].C / pow(max(Distance(p[i].X, p[j].X),1.f), 3)) * (p[j].X - p[i].X);
		}
	}
	for (int i(0); i < p.size(); i++)
	{
		p[i].F -= p[i].V*100.f;
		p[i].update(dt,V);
		p[i].checkBound(Vector2f(width,height));
	}

	for (int x(0); x < width; x++)
	{
		for (int y(0); y < height; y++)
		{
			V.set(x, y, 0);
			for (int i(0); i < p.size(); i++)
			{
				V.set(x, y, V.get(x,y)+p[i].C / Distance(Vector2f(x,y), p[i].X));
			}
		}
	}
	for (int i(0); i < iso.size(); i++) iso[i].marchingSquares(V);
}

void ElectricField::draw()
{
	for (int x(0); x < width; x++)
	{
		for (int y(0); y < height; y++)
		{
			image.setPixel(x, y, HSVColor(max(min(200-abs(V.get(x,y))*150,360.f),0.f), 100, 100).RGB());
		}
	}
	texture.update(image);
	sprite.setTexture(texture);
	window->draw(sprite);
	for (int i(0); i < iso.size(); i++) iso[i].draw();
	for (int i(0); i < p.size(); i++) p[i].draw();
}