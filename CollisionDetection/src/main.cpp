#include <iostream>

#include "CollisionShapes.h"


float distance(Point A, Point B)
{
	return std::sqrt(std::pow((A.x - B.x), 2) + std::pow((A.y - B.y), 2));
}

bool PointCollision(Point A, Point B)
{
	float epsilon = 0.0001f;
	return std::abs(A.x - B.x) <= epsilon && std::abs(A.y - B.y) <= epsilon;
}

bool CirclePointCollision(Circle A, Point B)
{
	return distance(A.center, B) <= A.radius;
}

bool CircleCircleCollision(Circle A, Circle B)
{
	return distance(A.center, B.center) <= A.radius + B.radius;
}

bool RectRectCollision(Rectangle A, Rectangle B)
{
	return (A.corner.x < B.corner.x + B.width) &&
		(A.corner.x + A.width > B.corner.x) &&
		(A.corner.y < B.corner.y + B.height) &&
		(A.corner.y + A.height > B.corner.y);
}

// TODO : Add buffer to remove jerkyness in collision
bool LinePointCollision(Line A, Point B)
{
	return (distance(A.PointOne, B) + distance(A.PointTwo, B)) == distance(A.PointOne, A.PointTwo);
}

int main()
{
	Point A(5, 4);
	Point B(4, 5);
	Circle C(A, 5);
	Circle D(B, 3);

	std::cout << PointCollision(A, B) << std::endl;
	std::cout << CirclePointCollision(C, B) << std::endl;
	std::cout << CircleCircleCollision(C, D) << std::endl;

	std::cin.get();
}