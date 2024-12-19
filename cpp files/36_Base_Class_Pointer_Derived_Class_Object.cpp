#include<iostream>
using namespace std;

class base{
public:
    void fun1(){cout<<"fun1() ";}
};

class derived: public base{
public:
    void fun2(){cout<<"fun2() ";}
};

int main(){
    base b;
    b.fun1();
    // b.fun2(); // obv error
    derived d;
    d.fun1();
    d.fun2(); // obv no errors
    base *p = &b; // base pointer pointing to base object
    p->fun1();
    // p->fun2(); // again obv error
    derived *q = &d; // derived pointer pointing to derived object
    q->fun1();
    q->fun2(); // again obv no errors

    // derived *db = &b; // derived pointer pointing to base object, gives errors as the pointer has fun2() but the base class object b doesnt.
    
    // u cant point to a basic car saying its adv cuz it doesnt have those adv features(meaning u cant have an adv(or derived) pointer to basic class which is why it gave errors)

    base *bd = &d; // base pointer pointing to derived object
    bd->fun1();
    // bd->fun2(); // even tho derived class object d has fun2(), the pointer is of base class which doesnt have it, so this gives errors.

    // u can point to an advanced car saying its a basic car(meaning u can make a basic pointer to adv class) but when u say that it means u only know about basic cars and so basic features, so u can use basic features(meaning u can only call and access base class members not adv features(or derived class))

    cout<<endl<<endl;
return 0;
}