#include<iostream>
using namespace std;
/* 
Any data member is same as function member i.e. a function in private can only be accessed in class, not called in any outside function. That is why we write functions in public, so that they can be called in int main().

Only the original class can access its own private members.
A child class can access protected and public members of parent class.
An object of a class can only access public members of its class.
A child class can be inherited publicly, protectedly or privately, which means how the members access change when they are inherited to child classes.

Private members are always private so we wont talk about them.
Publicly inheriting will keep protected as protected and public as public members.
Protectedly inheriting will keep protected of Parent as protected of Child, and public of Parent as protected of Child.
Privately inheriting will keep protected of Parent as private of Child, and public of Parent as private of Child.

 */
class Parent{ // a, b ,c accessible inside class.
private:
    int a = 1;
protected:
    int b = 2;
public:
    int c = 3;
    void display(){
        cout<<"Value of a: "<<a<<endl;
        cout<<"Value of b: "<<b<<endl;
        cout<<"Value of c: "<<c<<endl;
    }
    // everything is accessible in the same class.
};

// public inheritance means b remains protected in child class and c remains public, so we can access both in the grandchild class.
class childp : public Parent{ // b, c, d, e, f accessible inside class.
private:
    int d = 10;
protected:
    int e = 20;
public:
    int f = 30;
};
class grandchildp : public childp{ // b, c, e, f, m, n, o accessible inside class.
private:
    int m = 100;
protected:
    int n = 200;
public:
    int o = 300;
};


class childpp : protected Parent{ // b, c, g, h, i accessible inside class.
private:
    int g = 11;
protected:
    int h = 21;
public:
    int i = 31;
};
class grandchildpp : public childpp{ // b, c, h, i, p, q, r accessible inside class.
private:
    int p = 110;
protected:
    int q = 210;
public:
    int r = 310;
};


class childppp : private Parent{ // b, c, j, k, l accessible inside class.
private:
    int j = 12;
protected:
    int k = 22;
public:
    int l = 32;
};
class grandchildppp : public childppp{ // k, l, s, t, u accessible inside class.
private:
    int s = 120;
protected:
    int t = 220;
public:
    int u = 320;
};


int main(){
    Parent p;
    // p.a; // p.a not accessible, private member of class
    // p.b; // p.b not accessible, protected member of class
    // p.c; // p.c accessible, public member of class

    childp cp; // publicly inherited.
    // cp.a; // not accessible, private member of Parent
    // cp.b; // not accessible, protected member of Parent came as protected member of Child
    // cp.c; // accessible, public member of Parent

    childpp cpp; // protectedly inherited.
    // cpp.a; // not accessible, private member of Parent
    // cpp.b; // not accessible, protected member of Parent came as protected member of Child
    // cpp.c; // not accessible, public member of Parent became protected member of Child

    childppp cppp; // privately inherited.
    // cppp.a; // not accessible, private member of Parent
    // cppp.b; // not accessible, protected member of Parent became private member of Child
    // cppp.c; // not accessible, public member of Parent became private member of Child

    cout<<endl<<endl;
return 0;
}