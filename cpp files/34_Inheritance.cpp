#include<iostream>
using namespace std;

class rectangle{
private:
    int l, b;
public: // all these constructors and functions will be inherited to the cubiod class.
    rectangle(int l = 0, int b = 0){
        this->l = l;
        this->b = b;
    }
    rectangle(rectangle& r){
        this->l = r.l;
        this->b = r.b;
    }

    void setLength(int l){this->l = l;}
    void setBreadth(int b){this->b = b;}
    int getLength(){return l;}
    int getBreadth(){return b;}
    int area(){return l*b;}
    int perimeter(){return 2*(l+b);}
    bool isRegular(){return l == b;} // checks if its square.
};

class cuboid :public rectangle{
private:
    int h;
public:
    cuboid(int h = 1){this->h = h;}
    cuboid(int a, int b, int c):rectangle(a, b){
        h = c;
        // a and b automatically go to rectangle's constructor.
    }

    void setHeight(int h){this->h = h;}
    int getHeight(){return h;}

    int Volume()
    {
        return getLength()*getBreadth()*h;
        // A child class cannot access private members of parent class, only public and protected members. so l*b*h will give errors for l and b are private.
    }

    bool isRegular(){
        return (getLength() == getBreadth()) && (getBreadth() == h);
        // checks if its cube. It has same name as the one in rectangle class but an object of cuboid will call this function only, since it looks for functions in its own class first.
    }
};

int main(){
    // By default, with no arguments, first parent and then child classes default constructors are called when creating an object
    // If arguments are given then first parent calss default constructor will be called then child class parameterized constructors will be called.
    // If you want to call a parameterized constructor of parent class, you have to make a separate constructor in derived class, parameterized constructor of parent class will be called first then parameterized of child class
    // here by call, i mean executed, they might be called in a different order

    rectangle r();
    
    cuboid c(3, 3, 3);
    cout<<"l is: "<<c.getLength()<<endl;
    cout<<"b is: "<<c.getBreadth()<<endl;
    cout<<"h is: "<<c.getHeight()<<endl;
    cout<<c.Volume()<<" "<<c.isRegular()<<endl;

    // rectangle r(3, 3);
    // cout<<"l is: "<<r.getLength()<<endl;
    // cout<<"b is: "<<r.getBreadth()<<endl;
    // cout<<r.area()<<" "<<r.perimeter()<<" "<<r.isRegular()<<endl;

    // both are calling same name isRegular() functions and still works.

    cout<<endl<<endl;
return 0;
}