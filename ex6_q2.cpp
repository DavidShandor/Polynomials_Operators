#include "Polynomial.h"

int main()
{
 
	Polynomial<int> poly_int1;
	Polynomial<int> poly_int2;
	Polynomial<int> poly_int3;
 
	Polynomial<double> poly_double1;
	Polynomial<double> poly_double2;
 	Polynomial<double> poly_double3;

    printf("int polynom \n");
    poly_int1[0] = 4;
    poly_int1[4] = 9;
    cout << poly_int1 << endl;

    poly_int2[1] = 4; 
    poly_int2[2] = 9;
    cout << poly_int2 << endl;

    poly_int3 = poly_int1 + poly_int2;
    cout << poly_int3 << endl;

    poly_int3 += poly_int1;
    cout << poly_int3 << endl;

    poly_int3 *= poly_int1;
    cout << poly_int3 << endl;

    printf("\ndouble polynom \n");
   
    poly_double1[1] = 3.5;
    poly_double1[3] = 4.5;
    cout << poly_double1 << endl;
   
    poly_double2[1] = 4.0;
    poly_double2[2] = 9.0;
    cout << poly_int2 << endl;
    
  
    poly_double3 = poly_double1 * poly_double2;
    cout << poly_double3 << endl;

    poly_double3 = poly_double1 - poly_double2;
    cout << poly_double3 << endl;

    poly_double3 = poly_double1 + poly_double2;
    cout << poly_double3 << endl;

    poly_double3 += poly_double1;
    cout << poly_double3 << endl;

    poly_double3 *= poly_double1;
    cout << poly_double3 << endl;

    poly_double3 -= poly_double1;
    cout << poly_double3 << endl;
  
    return 0;
}

