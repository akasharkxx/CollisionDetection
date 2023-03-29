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
	float epsilon = 0.0001f;
	return std::abs((distance(A.PointOne, B) + distance(A.PointTwo, B)) - distance(A.PointOne, A.PointTwo)) < epsilon;
}

bool LineCircleCollision(Line A, Circle B)
{
	bool CollidesPoint1 = CirclePointCollision(B, A.PointOne);
	bool CollidesPoint2 = CirclePointCollision(B, A.PointTwo);

	if (CollidesPoint1 || CollidesPoint2)
	{
		return true;
	}

	int x1 = A.PointOne.x;
	int x2 = A.PointTwo.x;
	int xk = B.center.x;
	int y1 = A.PointOne.y;
	int y2 = A.PointTwo.y;
	int yk = B.center.y;

	float u = ((xk - x1) * (x2 - x1) + (yk - y1) * (y2 - y1)) / pow((distance(A.PointOne, A.PointTwo)), 2);

	float x = x1 + u * (x2 - x1);
	float y = y1 + u * (y2 - y1);

	Point P;
	P.x = x;
	P.y = y;

	if (!LinePointCollision(A, P))
	{
		return false;
	}
	else
	{
		return CirclePointCollision(B, P);
	}
}

bool PointRectangelCollision(Point P, Rectangle R)
{
	if (P.x >= R.corner.x && P.x <= R.corner.x + R.width && P.y >= R.corner.y && P.y <= R.corner.y + R.height)
	{
		return true;
	}

	return false;
}

int main()
{
	Point A(5, 4);
	Point B(4, 5);
	Point A1(-4, -5);
	Circle C(A, 2);
	Circle C1(A1, 2);
	Circle D(B, 3);
	Line L(A, B);

	std::cout << PointCollision(A, B) << std::endl;
	std::cout << CirclePointCollision(C, B) << std::endl;
	std::cout << CircleCircleCollision(C, D) << std::endl;
	std::cout << LineCircleCollision(L, C) << std::endl;
	std::cout << LineCircleCollision(L, C1) << std::endl;

	std::cin.get();
}