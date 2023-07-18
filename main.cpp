#include <iostream>
#include <cmath>

int subtract(int x, int y){
  return x-y;
}
int multiply(int x, int y){
  return x*y;
}
int divide(int x, int y){
  return x/y;
}


class Circle
{
  public:
    int radius;

    double area(){
      return pow(radius,2) * M_PI;
    }
};

class Point
{
  public:
    double x;
    double y;
    Point(double x, double y){
      this->x=x;
      this->y=y;
    }
    double distance_to_origin(){
      double dist = sqrt(pow(x,2)+pow(y,2));
      return dist;
    }
    double distance_to_point(Point obj){
      double dist = sqrt(pow(x-obj.x,2)+pow(y-obj.x,2));
      return dist;
    }
};

class Line{
  public:
  Point p1;
  Point p2;
  double length(){
    return(p1.distance_to_point(p2));
  }
};



int main()
{
  //std::cout << "Swati Sriram, 115" << std::endl;

  //int x = 5;
  //int y = 7;
  //int z = 20;
  //int w = 10;
  //std::cout << "The sum of " << x << " , " << y << ", " << z <<  ", and " << w <<  " is " << x + y + z + w << std::endl;
  //std::cout << "The subtraction/multiplication/division of x an y is " <<subtract(x,y)<< " , " <<multiply(x,y)<< " , and " << divide(x,y)<< std::endl;

  // Circle c;
  // c.radius = 2;
  // std::cout <<"The area of the circle with a radius of 2 is " << c.area() << std::endl;
  Point p(1, 2);
  Point q(0.2, 0.5);
  std::cout <<q.distance_to_point(p)<< std::endl;
  return 0;
  Line l;
  l.p1 = (1,2);
  l.p2 = (0.2, 0.5);
  std::cout <<l.length()<< std::endl;
}
