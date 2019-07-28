#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
//#include "Matrix.h"
#include "poly.h"
#include "PolyRegression.h"
#include "PolyInterpolation.h"
using namespace std;


int main(){

	//read the points from the file
	fstream inFile("Prob20-48.txt"); //attempt to to open file
	if (!inFile){
		cerr << "Error opening file: " << "Prob20-48.txt" << endl;
		exit(EXIT_FAILURE);

	}

	//Read the numbers of points and the points 
	int n;
	int m = 3;
	inFile >> n;
	double x[n];
	double y[n];
	//read the points
	for (int i = 0; i < n; ++i){
		inFile >> x[i] >> y[i];
	}
	//done with the file 
	inFile.close(); 
//=====================================================
	//decleare new PolyRegression
	PolyRegression* PR = new PolyRegression(x,y,n);
	double* coff=PR->regression(m);
	cout << "coffients:" << endl;
	Poly* p1 = new Poly(m);
    for(int o=0;o<m;o++){
 		cout<<"a[" << o <<"]:  "<<coff[o]<<endl;
    	p1->setCoeff(o,-(coff[o]));


	} 
	cout << "\nequation:" << endl;
	p1->displayPoly();
	double syx = PR->syx(p1);
	cout<< "\n\nsyx: " <<syx<< endl;
	double r2 = PR->r2(p1);
	cout << "R2: "<<r2 << endl;
	double r = sqrt(r2);
	cout << "R: "<<r << endl <<endl;
	double* con=PR->confidence(p1);
	for(int i=0;i<m;i++){
		cout <<"95 confidence for coeff: " << i << ": +/- "<<con[i]<<endl;
	}

	PolyInterpolation* PI = new PolyInterpolation(x,y,n);
	double result = PI->interpolateNewton(m,7.5);
	cout <<"\n\n\nInterpolation result for 7.5 is : "<< result <<endl;
	

}



