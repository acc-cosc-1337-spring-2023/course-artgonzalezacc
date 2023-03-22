//main
#include <iostream>
#include<memory>
#include<vector>
#include "shape.h"
#include "line.h"
#include "circle.h"
/*
Create a Shape pointer of type Line
Create vector of Shape pointers
iterate with auto
*/

int main() 
{
	Shape* shape;//create dynamic memory

	shape = new Line();//create dynamic memory
	shape->draw();
	delete shape;

	shape = new Circle();
	shape->draw();
	delete shape;


	return 0;
}