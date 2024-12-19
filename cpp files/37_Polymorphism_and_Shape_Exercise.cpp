#include<iostream>
using namespace std;

class base{
public:
    void fun(){cout<<"fun of base"<<endl;}
    virtual void fun2(){cout<<"fun2 of base"<<endl;}
    virtual void fun3() = 0;
    void fun4(); // this is a virtual function(its not defined outside using scope resolution). not pure cuz it isnt set to 0, if a class has this and concrete functions then u can create an object of that class altho u cant call this type of virtual functions, but if there's even one purely virtual function(fun() = 0) then u cant create its object 
};

class derived: public base{
public:
    void fun(){cout<<"fun of derived"<<endl;} // this is called function overridding
    void fun2(){cout<<"fun2 of derived"<<endl;}
    void fun3(){cout<<"fun3 of derived"<<endl;}

};

// Exercise:
class shape{ // purpose of this class is to generalise rectangle and circle calling them both shapes. this inheritance is providing nothing for rectangle or circle class except the necessity to create area and perimeter classes. Its only use is for polymorphism.
public:
    virtual int area() = 0;
    virtual int perimeter() = 0;
};

class rectangle: public shape{
private:
    int l,b;

public:
    rectangle(int a, int b){
        l = a;
        this->b = b;
    }
    int area(){return l*b;}
    int perimeter(){return 2*(l+b);}
};
class circle:public shape{
private:
    int r;
public:
    circle(int a){
        r = a;
    }
    int area(){return 3.14*r*r;}
    int perimeter(){return 2*3.14*r;}
};

int main(){
    base *b = new derived();

    // b->fun(); // prints fun of base
    // b->fun2(); // prints fun of derived, cuz fun2 was made virtual in base class.
    // if fun2 in base isnt needed, then its body is also useless and so we remove the body, like in fun3 and set it to 0, now this fun3 is called purely virtual function and it must be overridden by derived classes, and since base class contains purely virtually functions, u cant make its objects

    //if a base class has only concrete functions(defined body) then for derived classes, its use is for reusability.
    // if a base class has both concrete and purely virtual functions then its use is both reusability and to achieve polymorphism, also its an abstract class
    // if a base class has only purely virtual functions then its only use is to achieve polymorphism and its called an abstract class, the exercise has one such function called shape

    // shape s; // gives errors as this is an abstract class, cant create its objects, and if a derived class doesnt override any purely virtual function of parent class then its an error

    // Runtime Polymorphism:
    shape *s = new rectangle(4,5);
    cout<<"Area of rectangle "<<s->area()<<endl;
    cout<<"Perimeter of rectangle "<<s->perimeter()<<endl;
    delete s;
    s = new circle(6);
    cout<<"Area of circle "<<s->area()<<endl;
    cout<<"Perimeter of circle "<<s->perimeter()<<endl;

    // the same s->area() is showing area of rectangle and also circle, this is polymorphism, similarly for s->perimeter(), its showing perimeter of both rectangle and circle, this "same line different execution" is polymorphism

    cout<<endl<<endl;
return 0;
}