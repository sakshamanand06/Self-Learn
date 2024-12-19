#include<iostream>
using namespace std;

class rectangle{
// Private can only be accessed within the class whether in private or public but not outside it.
private:
    int priv_l;
public:
    int l, b;
    int area(){
        return l*b;
    }
    int perimeter(){
        return l+b+l+b;
    }
};
int main(){
    rectangle r1, r2;
    // each object made has its own length, breadth and whatever else u have put in the class. so a function which sets length as 5 will do it only for the object its called for.
    r1.l = 5;
    r1.b =10;
    r2.l = 15;
    r2.b = 8;
    // cout<<r1.area()<<endl;

    // pointers in OOPS
    rectangle r;
    rectangle* p = &r;
    p->l = 4; // same as r.l = 4;
    p->b = 2;
    cout<<p->area()<<" + "<<p->perimeter()<<" = "<<r.area() + r.perimeter();

    // object creation in heap
    rectangle* h = new rectangle;
    h->l = 9;
    h->b = 1;

    // private vs public
    rectangle pvp;
    // pvp.priv_l; // priv_l is private so cant be accessed, and thats why we have getXXX(accessor functions) and setXXX(mutator functions) functions collectively called as property functions
    // we do this to prevent data mishandling, u can pass negative length by pvp.priv_l = -5; but u cant do it if we make a setLength function which first checks if its valid then sets it, so we make data as private so users cant access and functions as public cuz they should be the only things accessible to a user.
    // by "u" and "user", i mean the code outside the class, this is all done so that data cant be mishandled by code outside the class

    cout<<endl<<endl;
return 0;
}