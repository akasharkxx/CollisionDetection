#pragma once

#include <cmath>

struct Point
{
	float x, y;

	Point() : x(0), y(0) {}
	Point(float _x, float _y) : x(_x), y(_y) {}
};

struct Circle
{
	Point center;
	float radius;

	Circle() : center(Point(0, 0)), radius(0) {}
	Circle(Point _center, float _radius) :
		center(_center), radius(_radius) {}
};

struct Rectangle
{
	Point corner;
	float width;
	float height;

	Rectangle() : corner(Point(0, 0)), width(1), height(1) {}

	Rectangle(Point _corner, float _width, float _height) :
		corner(_corner), width(_width), height(_height) {}
};

struct Line
{
	Point PointOne;
	Point PointTwo;

	Line() : PointOne(Point(0, 0)), PointTwo(Point(0, 1)) {}
	Line(Point Point1, Point Point2) : PointOne(Point1) , PointTwo(Point2) {}
};