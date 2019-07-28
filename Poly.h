#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Poly
{
   private:
      int max_power;
      int degree;
      double* coeffs;

   public:
      Poly(int max_power);
      ~Poly();

      int getDegree();

      double getCoeff(int power);
      void setCoeff(int power, double coeff);

      double evaluate(double x,double y);
      Poly* multiply(Poly* other);
      static Poly* multiply(Poly* one, Poly* two);

      void displayPoly();
     
};
Poly::Poly(int m_p)  
{
   max_power = 3;
   if (m_p >= 0)
   {
      max_power = m_p;
   }

   coeffs = new double[max_power + 1];  //array of doubles

   for (int i = 0; i <= max_power; i++)
   {
      coeffs[i] = 0.0;
   }

   degree = 0;
   max_power = max_power;
}

Poly::~Poly()
{
   delete[] coeffs; 
}

int Poly::getDegree()
{
   return degree;
}

double Poly::getCoeff(int power)
{
   if (power > max_power || power < 0) return 0;

   return coeffs[power];
}

void Poly::setCoeff(int power, double cf)
{
   if (power > max_power || power < 0) return;

   coeffs[power] = cf;

   if (power >= degree)
   {
      degree = power;
   }
}

double Poly::evaluate(double x,double y)
{
   double result = getCoeff(degree);
   
   for (int i = degree - 1; i >= 0; i--)
   {
      result = result * x;
      result = result + getCoeff(i);
   }

   return result + y;
}

Poly* Poly::multiply(Poly* other)
{
   double TOL = .00001;

   int n = getDegree();
   int m = other->getDegree();

   Poly* temp = new Poly(n + m);

   for (int i = 0; i <= n; i++) //loop over coeffs
   {
      for (int j = 0; j <= m; j++)  //loop over second coeffs
      {
         double coeff_i = getCoeff(i);
         double coeff_j = other->getCoeff(j);
         if (fabs(coeff_i) > TOL && fabs(coeff_j) > TOL)
         {
            int power = i + j;
            double coeff = temp->getCoeff(power);
            temp->setCoeff(power, coeff + (coeff_i * coeff_j));
         }
      }
   }

   return temp;
}

void Poly::displayPoly()
{
   double TOL = .00001;
   int degree = getDegree();

   cout << getCoeff(degree) << "x^" << degree;
   for (int i = degree - 1; i >= 0; i--)
   {
      double coeff = getCoeff(i);
      if (fabs(coeff) > TOL)
      {
         cout << " + " << coeff << "x^" << i << " ";
      }
   }
   cout << endl;
}


