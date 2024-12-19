#include<iostream>
using namespace std;

#define b 10 // b->10 preprocessor directives/macros wherever b is present in the program, compiler will replace it with 10 before compilation
#define sqr(s) (s*s) // sqr(5) -> 25, so cout<<sqr(5); becomes cout<<25;
#define msg(m) #m // msg(hi) -> "hi", so cout<<msg(hi); becomes cout<<"hi";

#ifndef ndef // only define if its not already defined
    #define ndef 10
#endif

namespace cust1{
    void f1(){cout<<"cust1"<<endl;}
};

namespace cust2{
    void f1(){cout<<"cust2"<<endl;}
};


class Demo{
public:
    int x = 5;
    int y = 20;
    void display(){
        cout<<++x<<" <-class-> "<<y<<endl;
    }
    void displayLocked()const // this restricts this function from modifying members of class
    {
        // cout<<++x<<" <-classL-> "<<y<<endl; // shows error
        cout<<x<<" <-classL-> "<<y<<endl;
    }
};

void fun(const int &r, int &s){ // these can change the actual variables, to prevent that we can use const
    // r++; //shows error as it is declared constant
    s++; // can do it
    cout<<r<<" <-fun-> "<<s<<endl;
    
}

int main(){
    const int a = 10;
    // a++; // shows error, constant modifiers cannot be modified.
    // cout<<b+5<<endl; // replaces b with 10 and outputs 15 cuz of #define

    int c = 20;
    int* ptr = &c;
    ++*ptr;
    cout<<"C is: "<<c<<endl; //increased the value of c

    int c1 = 25;
    const int* ptr1 = &c1; // read from right to left, pointer to a integer constant, so it can read c1 but not modify it.
    // int const* ptr1 = &c1; // same thing, pointer to a constant integer
    // cout<<++*ptr1; // this gives error as it cant write
    cout<<*ptr1<<endl; // but this works as it can still read

    int c2 = 30;
    ptr1 = &c2;
    // ++*ptr1; // this still gives error cuz the lock is on pointer's permission to write not the variable's data itself, u can still modify both c1 and c2 directly, but u cant using this pointer to constant integer

    int* const ptr2 = &c1;
    // ptr2 = &c2; // this gives error as now the pointer itself is constant, so it cant change or point to smth else
    cout<<++*ptr2<<endl; // it cant point to smth else but it can modify the value

    const int* const ptr3 = &c1;
    // int const * const ptr3 = &c1; // same as above
    // Now this is a constant pointer to a constant integer, u cant modify the value via pointer or change the pointer to smth else, but u can still do c1++ i.e. modify c1's value

    Demo d;
    d.display(); // returns 6 <-class-> 20, it can update x
    d.displayLocked(); // shows error if u try to modify value of members of class inside this function but it can still read the values

    int p = 3, q = 4;

    fun(p, q); // call by reference makes the function inline, meaning the function will be copied over this place in machine code, but if we want some variables to not change we can set them as const in function definition
    
    cout<<":"<<sqr(sqr(2)) + 5<<":"<<endl; // sqr(sqr(2)) + 5 -> sqr(4) + 5 -> 16 + 5 = 21
    string ms = msg(yo yo bro); // same as ms = "yo yo bro"
    cout<<ms<<endl;

    // f1(); // it isnt global but in namespace
    cust1::f1(); // it calls f1() from cust1 namespace
    cust2::f1(); // it calls f1() from cust2 namespace

    using namespace cust1;
    f1(); // now by default calls cust1's f1()
    cust1::f1(); // can still do this
    cust2::f1(); // to call f1() from cust2
    using namespace cust2; // doesnt change the default. instead confuses the compiler si the next line gives error
    // f1();
    cust1::f1(); cust2::f1(); // can still do these both



    cout<<endl<<endl;
return 0;
}