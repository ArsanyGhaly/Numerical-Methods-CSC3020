#if !defined (POINT_H)
#define POINT_H

#include "CompareTo.h"

class Point : public CompareTo<Point>
{
   private:
      double x;
      double y;
     
   public:
      Point();
      Point(double x, double y);
      ~Point();
      void setX(double x);
      void setY(double y);
      void printPoint();
      double getX();
      double getY();
      int compareTo(Point* obj);
};

#endif
