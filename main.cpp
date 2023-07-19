#include <iostream>
#include <cmath>
#include <vector>

int subtract(int x, int y)
{
  return x - y;
}
int multiply(int x, int y)
{
  return x * y;
}
int divide(int x, int y)
{
  return x / y;
}

class Circle
{
private:
  int radius;

public:
  int getRadius()
  {
    return radius;
  }
  double area()
  {
    return pow(radius, 2) * M_PI;
  }
};

class Point
{
private:
  double x;
  double y;

public:
  Point()
  {
    this->x = 0.0;
    this->y = 0.0;
  }
  Point(double x, double y)
  {
    this->x = x;
    this->y = y;
  }
  double getX()
  {
    return x;
  }
  double getY()
  {
    return y;
  }
  double distance_to_origin()
  {
    double dist = sqrt(pow(x, 2) + pow(y, 2));
    return dist;
  }
  double distance_to_point(Point &obj)
  {
    double dist = sqrt(pow(x - obj.x, 2) + pow(y - obj.x, 2));
    return dist;
  }
};

class Line
{
private:
  Point p1;
  Point p2;

public:
  Line(Point &p1, Point &p2)
  {
    this->p1 = p1;
    this->p2 = p2;
  }
  Point getP1()
  {
    return p1;
  }
  Point getP2()
  {
    return p2;
  }
  double length()
  {
    return (p2.distance_to_point(p1));
  }
  double distance_to_point(Point &p3)
  {
    double slope = (p1.getY() - p2.getY()) / (p1.getX() - p2.getX());
    double c = p1.getY() - p1.getX() * slope;
    double line[] = {p1.getY() - p2.getY(), p1.getX() - p2.getX(), c * (p1.getX() - p2.getX())};
    double d = abs(line[0] * p3.getX() + line[1] * p3.getY() + line[2]) / sqrt(pow(line[0], 2) + pow(line[1], 2));
    return d;
  }
};

class Triangle
{
private:
  Point p_1;
  Point p_2;
  Point p_3;

public:
  Triangle(Point &p_1, Point &p_2, Point &p_3)
  {
    this->p_1 = p_1;
    this->p_2 = p_2;
    this->p_3 = p_3;
  }
  Point getP_1()
  {
    return p_1;
  }
  Point getP_2()
  {
    return p_2;
  }
  Point getP_3()
  {
    return p_3;
  }
  double area()
  {
    double area = 0.5 * (p_1.getX() * (p_2.getY() - p_3.getY()) + p_2.getX() * (p_3.getY() - p_1.getY()) + p_3.getX() * (p_1.getY() - p_2.getY()));
    return area;
  }
};

class Polygon
{
private:
  std::vector<Point> points;

public:
  Polygon(std::vector<Point> &points)
  {
    this->points = points;
  }
  std::vector<Point> getPoints()
  {
    return points;
  }
  double area()
  {
    double area = 0.0;
    for (int i = 0; i < points.size() - 2; i++)
    {
      area += Triangle(points[0], points[i + 1], points[i + 2]).area();
    }
    return area;
  }
};
int main()
{
  // std::cout << "Swati Sriram, 115" << std::endl;

  // int x = 5;
  // int y = 7;
  // int z = 20;
  // int w = 10;
  // std::cout << "The sum of " << x << " , " << y << ", " << z <<  ", and " << w <<  " is " << x + y + z + w << std::endl;
  // std::cout << "The subtraction/multiplication/division of x an y is " <<subtract(x,y)<< " , " <<multiply(x,y)<< " , and " << divide(x,y)<< std::endl;

  // Circle c;
  // c.radius = 2;
  // std::cout <<"The area of the circle with a radius of 2 is " << c.area() << std::endl;
  Point p(1, 2);
  Point q(0.2, 0.5);
  Point r(0.5, 0.2);
  std::cout << q.distance_to_point(p) << std::endl;
  Line l(p, q);
  std::cout << l.length() << std::endl;
  std::cout << l.distance_to_point(r) << std::endl;
  Triangle t(p, q, r);
  std::cout << t.area() << std::endl;
  return 0;
}
