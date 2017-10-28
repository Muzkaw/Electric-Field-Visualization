//This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "HSVColor.h"

HSVColor::HSVColor()
{
	h = 0;
	s = 0;
	v = 0;
}
HSVColor::HSVColor(float const& hue, float const& saturation, float const& value)
{
	h = hue;
	s = saturation / 100.f;
	v = value / 100.f;
}

Color HSVColor::RGB()
{
	double r, g, b;
	int hi = (int)(h / 60.f);
	double f = h / 60.f - hi;
	double l = v*(1 - s);
	double m = v*(1 - f*s);
	double n = v*(1 - (1 - f)*s);

	switch (hi)
	{
	case 0: r = v; g = n; b = l; break;
	case 1: r = m; g = v; b = l; break;
	case 2: r = l; g = v; b = n; break;
	case 3: r = l; g = m; b = v; break;
	case 4: r = n; g = l; b = v; break;
	case 5: r = v; g = l; b = m; break;
	}

	return Color(255.f*r, 255.f*g, 255.f*b);
}
