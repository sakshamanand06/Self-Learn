#include<iostream>
#include<cmath>

using namespace std;
int main(){
/*
    // Area of a triangle
    int base, height;
    cout<<"Give the base and height of triangle(in m): ";
    cin>>base>>height;
    int area = (base*height)/2;
    cout<<"Area of the triangle is: "<<area<<" sq. metres.";
*/

    // Roots of a quadratic equation
    int a,b,c,r1,r2;
    cout<<"Enter coefficients of x^2, x and the constant in order: ";
    cin>>a>>b>>c;
    r1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    r2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    cout<<"The roots are: "<<r1<<" and "<<r2;

    return 0;
}