#include "SortPoints.h"

Point** SortPoints::sortPoints(Point** data, int numData, Compare<Point>* comp)
{
   Point** sorted = new Point*[numData];
   for (int i = 0; i < numData; i++)
   {
      sorted[i] = data[i];
   }

   mergeSort(sorted, comp, 0, numData - 1);
   return sorted;
}

void SortPoints::mergeSort(Point** sort, Compare<Point>* comp, int first, int last) 
{
   if (first < last) 
   {
      int mid = (first + last)/2;   
      mergeSort(sort, comp, first, mid);  
      mergeSort(sort, comp, mid + 1, last);  
      merge(sort, comp, first, mid, last);
   } 
}  

void SortPoints::merge(Point** sort, Compare<Point>* comp, int first, int mid, int last) 
{
   Point** temp = new Point*[last - first + 1];
    
   // initialize the local indexes to indicate the subarrays
   int first1 = first;    // beginning of first subarray
   int last1  = mid;      // end of first subarray
   int first2 = mid + 1;  // beginning of second subarray
   int last2  = last;     // end of second subarray

   // while both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = 0;                    

   while ((first1 <= last1) && (first2 <= last2)) 
   {
      if (comp->compare(sort[first1], sort[first2]) <= 0)  //careful here for stable sorting
      {
         temp[index] = sort[first1];
         first1++;
      }
      else 
      {
         temp[index] = sort[first2];
         first2++;
      }  

      index++;
   } 

   // finish off the nonempty subarray

   // finish off the first subarray, if necessary
   while (first1 <= last1) 
   {
      temp[index] = sort[first1];
      first1++;
      index++;
   }  

   // finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      temp[index] = sort[first2];
      first2++;
      index++;
   }  

   // copy the result back into the original array
   for (index = 0; index <= last - first; index++) 
   {
      sort[index + first] = temp[index];
   }  

   delete[] temp;
}

