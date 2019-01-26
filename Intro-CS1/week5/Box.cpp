/**********************************************************************************
 ** Author: Erin Alltop
 ** Date: 2/1/16
 ** Description: A program that takes the length, width, and height of a box and
 ** calculates the volume and surface area.
 ** Box.cpp
 ***********************************************************************************/

#include "Box.hpp"
#include <iostream>
using namespace std;

//default constructor to initialize variables to 1
Box::Box()

{
	Height = 1.0;
	Width = 1.0;
	Length = 1.0;
}

//constructor
Box::Box(double hei, double wid, double len)
{
	Height = hei;
	Width = wid;
	Length = len;
}

//get Height
double Box::setHeight(double hei)
{
	return hei;
}

//get Width
double Box::setWidth(double wid)
{
	return wid;
}

//get Length
double Box::setLength(double len)
{
	return len;
}

//get Volume
double Box::getVolume()
{
	double Volume = Height * Width * Length;
	return Volume;
}

//get Surface Area
double Box::getSurfaceArea()
{
	double SurfaceArea = 2 * (Length * Width) + (Length * Height) + (Width * Height);
	return SurfaceArea;
}

