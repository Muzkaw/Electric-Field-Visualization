/*********************************************************************

This file is part of Electric Field Visualization (GNU GPL) - https://www.youtube.com/user/Muzkaw.

Electric Field Visualization is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Electric Field Visualization is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Electric Field Visualization. If not, see <http://www.gnu.org/licenses/>.

Electric Field Visualization codded by Muzkaw : https://www.youtube.com/user/Muzkaw
You need to link SFML 2.0 or above to run the program

********************************************************************/

#include <SFML/Graphics.hpp>
#include "ElectricField.h"

using namespace std;
using namespace sf;

int main()
{
	ContextSettings aa; aa.antialiasingLevel = 4;
	RenderWindow window(VideoMode(600, 600, 32), "Window",Style::Default,aa);

	ElectricField E(&window);

	while (window.isOpen())
	{
		E.update(0.0001);

		window.clear();
		E.draw();
		window.display();
	}

}