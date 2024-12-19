#include<iostream>
using namespace std;

class Parent{
public:
    Parent(){
        cout<<"Parent Constructor Called"<<endl;
    }
    // ~Parent(){
    //     cout<<"Parent Destructor Called"<<endl;
    // }

    virtual ~Parent(){
        cout<<"Parent Destructor Called"<<endl;
    }
};

class Child: public Parent{
public:
    Child(){
        cout<<"Child Constructor Called"<<endl;
    }
    ~Child(){
        cout<<"Child Destructor Called"<<endl;
    }
};

void fun1(){
    Parent p;
}
void fun2(){
    Child c;
    // Constructor of parent called first then child's constructor
    // Destructor of child called first then parent's destructor
}
void fun3(){
    Parent *pc = new Child(); // reminder: Used for runtime polymorphism, base class pointer derived class object
    delete pc; // by default doesnt call Child destructor, cuz compiler treats this object as a Parent class object and thus doesnt call Child's destructor
    // can be prevented by using virtual before Parent's destructor, making it a virtual destructor

}

int main(){
    fun1();
    cout<<"--------------------------"<<endl;
    fun2();
    cout<<"--------------------------"<<endl;
    fun3();
    
    cout<<endl<<endl;
return 0;
}