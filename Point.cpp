#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;

Point::Point() : CompareTo<Point>()
{
   x = 0;
   y = 0;
}

Point::Point(double xx, double yy) : CompareTo<Point>()
{
   x = xx;
   y = yy;
}

Point::~Point()
{
}

void Point::setX(double xx)
{
   x = xx;
}

void Point::setY(double yy)
{
   y = yy;
}

double Point::getX()
{
   return x;
}

double Point::getY()
{
   return y;
}

void Point::printPoint()
{
   cout << "( " << x << " , " << y << " )";
   cout << endl;
}

int Point::compareTo(Point* point)
{
   double TOL = .000001;
   double comp = getX() - point->getX();
   int val;

   if (fabs(comp) < TOL)
   {
      val = 0;
   }
   else if (comp < 0)
   {
      val = -1;
   }
   else
   {
      val = 1;
   }

   return val;
}
