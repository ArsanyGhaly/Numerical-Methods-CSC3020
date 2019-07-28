#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class PolyInterpolation
{
   private:
      int n;
      double xi[10];
      double yi[10];
      int degree;

   public:
      PolyInterpolation(double x[], double y[],int size);
      ~PolyInterpolation();
      double interpolateNewton(int degree, double value);
      double pt(int i, double value);   
};


PolyInterpolation::PolyInterpolation(double x[], double y[],int size) 
{
   n = size;
 
   for (int i=0;i<n;i++){
      xi[i] =x[i];   
      yi[i] =y[i];  
      
      }

}

PolyInterpolation::~PolyInterpolation()
{
}


double PolyInterpolation::pt(int i, double value) 
{ 
   double pro = 1; 
   for (int j = 0; j < i; j++) { 
      pro = pro * (value - xi[j]); 
   } 
   return pro; 
} 




double PolyInterpolation::interpolateNewton(int degree, double value)
{ 

      double temp[10][10];
      for(int i=0;i<n;i++){
         temp[i][0] = yi[i];
      }

      for (int i = 1; i < n; i++) { 
         for (int j = 0; j < n - i; j++) { 
            temp[j][i] = (temp[j][i-1] - temp[j + 1][i-1]) / (xi[j] - xi[i + j]); 
         } 
      }

      /*cout<<"show the table:" <<endl;
      for (int i = 0; i < n; i++) { 
         for (int j = 0; j < n - i; j++) { 
            cout <<temp[i][j] << "\t "; 
         } 
         cout << "\n"; 
      }
      */

      double sum = temp[0][0]; 

      for (int i = 1; i < n; i++) { 
      sum = sum + (pt(i, value) * temp[0][i]); 
      } 
     return sum;  
   
} 
