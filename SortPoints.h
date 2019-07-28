#if !defined (SORTPOINTS_H)
#define SORTPOINTS_H

#include "Point.h"
#include "Compare.h"

class SortPoints 
{
   private:
      static void mergeSort(Point** sort, Compare<Point>* comp, int first, int last);
      static void merge(Point** sort, Compare<Point>* comp, int first, int mid, int last);

   public:
      static Point** sortPoints(Point** data, int numData, Compare<Point>* comp);
};

#endif