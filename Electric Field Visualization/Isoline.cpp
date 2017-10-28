//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "Isoline.h"

Isoline::Isoline(float const& _threshold, RenderWindow *_window)
{
	threshold = _threshold;

	window = _window;

	sample_size = 1;

	isolines.setPrimitiveType(Lines);
}

void Isoline::marchingSquares(Matrix const& field)
{
	size = Vector2f(field.getCol(), field.getRow());
	sample_size = 2;

	threshold_field.resize(size.x, size.y);
	scale = field.getScale();

	for (int i(0); i < size.x; i += sample_size)
	{
		for (int j(0); j < size.y; j += sample_size)
		{
			if (abs(field.get(i, j)) > threshold) threshold_field.set(i, j, 1);
			else threshold_field.set(i, j, 0);
		}
	}

	isolines.clear();

	for (int i(0); i < size.x - 1; i += sample_size)
	{
		for (int j(0); j < size.y - 1; j += sample_size)
		{

			int r = (int)threshold_field.get(i, j + sample_size) << 0 |
				(int)threshold_field.get(i + sample_size, j + sample_size) << 1 |
				(int)threshold_field.get(i + sample_size, j) << 2 |
				(int)threshold_field.get(i, j) << 3;

			float a = abs(field.get(i, j + sample_size));
			float b = abs(field.get(i + sample_size, j + sample_size));
			float c = abs(field.get(i + sample_size, j));
			float d = abs(field.get(i, j));

			Vector2f A(0, 0), B(0, 0), C(0, 0), D(0, 0);

			switch (r)
			{
			case 0: case 15:
				break;
			case 1: case 14:
				A = Vector2f(i, j) + Vector2f(0, sample_size - sample_size*(a - threshold) / (a - d));
				B = Vector2f(i, j) + Vector2f(sample_size - sample_size*(threshold - b) / (a - b), sample_size);
				break;
			case 2: case 13:
				A = Vector2f(i, j) + Vector2f(sample_size - sample_size*(b - threshold) / (b - a), sample_size);
				B = Vector2f(i, j) + Vector2f(sample_size, sample_size - sample_size*(b - threshold) / (b - c));
				break;
			case 3: case 12:
				A = Vector2f(i, j) + Vector2f(0, sample_size - sample_size*(a - threshold) / (a - d));
				B = Vector2f(i, j) + Vector2f(sample_size, sample_size - sample_size*(b - threshold) / (b - c));
				break;
			case 4: case 11:
				A = Vector2f(i, j) + Vector2f(sample_size, sample_size - sample_size*(threshold - b) / (c - b));
				B = Vector2f(i, j) + Vector2f(sample_size - sample_size*(c - threshold) / (c - d), 0);
				break;
			case 5:
				A = Vector2f(i, j) + Vector2f(0, sample_size - sample_size*(a - threshold) / (a - d));
				B = Vector2f(i, j) + Vector2f(sample_size - sample_size*(c - threshold) / (c - d), 0);
				C = Vector2f(i, j) + Vector2f(sample_size - sample_size*(b - threshold) / (b - a), sample_size);
				D = Vector2f(i, j) + Vector2f(sample_size, sample_size - sample_size*(b - threshold) / (b - c));
				break;
			case 6: case 9:
				A = Vector2f(i, j) + Vector2f(sample_size - sample_size*(b - threshold) / (b - a), sample_size);
				B = Vector2f(i, j) + Vector2f(sample_size - sample_size*(c - threshold) / (c - d), 0);
				break;
			case 7: case 8:
				A = Vector2f(i, j) + Vector2f(0, sample_size - sample_size*(a - threshold) / (a - d));
				B = Vector2f(i, j) + Vector2f(sample_size - sample_size*(c - threshold) / (c - d), 0);
				break;

			case 10:
				A = Vector2f(i, j) + Vector2f(0, sample_size - sample_size*(threshold - a) / (d - a));
				B = Vector2f(i, j) + Vector2f(sample_size - sample_size*(b - threshold) / (b - a), sample_size);
				C = Vector2f(i, j) + Vector2f(sample_size, sample_size - sample_size*(b - threshold) / (b - c));
				D = Vector2f(i, j) + Vector2f(sample_size - sample_size*(threshold - c) / (d - c), 0);
				break;

			}
			Color color(0, 0, 0, 100);
			A *= scale;	B *= scale; C *= scale; D *= scale;
			if (A != Vector2f(0, 0)) isolines.append(Vertex(A, color));
			if (B != Vector2f(0, 0)) isolines.append(Vertex(B, color));
			if (C != Vector2f(0, 0)) isolines.append(Vertex(C, color));
			if (D != Vector2f(0, 0)) isolines.append(Vertex(D, color));
		}
	}
}

void Isoline::draw()
{
	window->draw(isolines);
}