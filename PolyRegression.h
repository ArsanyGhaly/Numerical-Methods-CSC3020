#include <iostream>
#include <string>
#include <cmath>
#include "Matrix.h"

using namespace std;

class PolyRegression
{
   private:
      int n;
      double xi[10];
      double yi[10];
      int degree;

   public:
      PolyRegression(double x[], double y[],int size);
      ~PolyRegression();
      double sum_array(double x[],int n, int p);
      double sum_y(double x[],double y[],int n,int p);
      double* regression(int degree);
      double syx(Poly* poly);
      double r2(Poly* poly);
      double* confidence(Poly* poly);
      
     
};
PolyRegression::PolyRegression(double x[], double y[],int size) 
{
   n = size;
   cout << "num of points: "<< n <<endl;
   for (int i=0;i<n;i++){
      xi[i] =x[i];   
      yi[i] =y[i];  
      cout << xi[i] << "  " <<yi[i] <<endl;
}

}

PolyRegression::~PolyRegression()
{
}


double PolyRegression::sum_array(double x[],int n, int p){
   double sum = 0.0;
   double temp[n];
   for(int i =0;i<n;i++){
      temp[i] = pow(x[i],p);
   }
   for(int i =0;i<n;i++){
      sum+= temp[i];
   }
return sum;
}


double PolyRegression::sum_y(double x[],double y[],int n,int p){
   double sum = 0.0;
   double temp[n];
   for(int i =0;i<n;i++){
      temp[i] = pow(x[i],p) * y[i];
   }
   for(int i =0;i<n;i++){
      sum += temp[i];
   }
return sum;
}

double* PolyRegression::regression(int degree)
{
   degree = degree;
   //1-calculate y sum
   double y_sum=sum_array(yi,n,1);
   
   //create new 2d array
   double** temp =  new double*[degree];
      for(int i = 0; i < n; ++i )
      {
          temp[i]  = new double[degree];
      }
   //construct the augmain matrix
   for(int i=0;i<=degree;i++)
   {
         for(int j=0;j<degree;j++)
         {
            if(i == 0 && j== 0){
               temp[0][0] = n;
            }else{
            temp[i][j] = sum_array(xi,n,(i+j));
         }
            if(i == degree && j== 0){
               temp[degree][0] = y_sum;
            }else{
               temp[degree][j] =sum_y(xi,yi,n,j);
            }
         } 
         
   } 

// start solving for the coffs a^-1B =x
Matrix m1 = Matrix(degree,degree);
Matrix* m2 =new  Matrix(degree,1);     

for (int i =0;i<degree;i++){
      for (int j =0;j<degree;j++){ 
         m1.setElement (j+1,i+1,temp[i][j]);
         m2->setElement(j+1,1, temp[degree][j]);
}
}
cout << "matrix x" << endl;
m1.displayMatrix();  
cout << "matrix y" << endl;
m2->displayMatrix();  
Matrix* m3 = m1.inverse();
Matrix* m4 = m3->multiply(m2);

double* coff = new double[degree];

for(int o=0;o<degree;o++){
   coff[o] = m4->getElement((o+1),1);
} 
 return coff;

}

double PolyRegression::syx(Poly* poly){
   double sr =0.0;
   for(int i =0;i<n;i++){
      sr += pow(poly->evaluate(xi[i],yi[i]),2);
   }

   double syx= sqrt(sr/(n-(3)));
return syx;
}

double PolyRegression::r2(Poly* poly){
   double sr =0.0;
   for(int i =0;i<n;i++){
      sr += pow(poly->evaluate(xi[i],yi[i]),2);
   }
   double y_sum = sum_array(yi,n,1);
   double ydach = y_sum / n;
   double s = 0.0;
   for(int i=0;i<n;i++){
      s +=pow((yi[i]-ydach),2);
   }


double r2 = (s - sr)/s;
return r2;
}

double* PolyRegression::confidence(Poly* poly){
         double y_sum=sum_array(yi,n,1);
         double ydach = y_sum / n;

         double x_sum=sum_array(xi,n,1);
         double xdach = x_sum / n;
         
         double sy = 0.0;
         double sx = 0.0;
         for(int i=0;i<n;i++){
            sy +=pow((yi[i]-ydach),2);
            sx +=pow((xi[i]-xdach),2);
         }

         double sdy = sqrt(sy/(n-2));
         double sdx = sqrt(sx/(n-2));

         double* con = new double[degree];
         
         for (int i =0;i<degree;i++){
            double s,c1 =0.0;
           s =(1/n)+((pow((poly->getCoeff(i) - xdach),2))/((n-1)*sdx*sdx));
           c1 = 1.96*sdy*sqrt(s);
            con[i] = c1;
      }
         
return con;
 }
