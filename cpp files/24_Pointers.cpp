#include<iostream>
using namespace std;

int main(){
    int x = 10;
    // int *y = &x;
    // * while declaration means y is a pointer variable not a data variable like x
    // actually int * is the datatype, just like int or char
    // & means address
    // pointer only contains addresses not values, so p = &a works but not p = a
    
    // datatype of pointer is int*, or it can be called datatype of addresses, so if you want to initialize a pointer using directly address, do it like:
    // int *r = (int*)0x7ffe2044d804; // i.e. u have to typecast to 'address' datatype

    int A[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    // just A is the base address of the array, same as &A[0] and so p=A or p=&A[0] are the same.
    // when a pointer points to an element of array, p++ moves it to the next index and p-- to the previous one, p = p+2 and p = p-2 work similarly.
    // difference of two pointers pointing to elements of the same array gives the difference in their indexes
    // so after int *p = &A[1]; int *q = &A[3]; p-q results in -2 and q-p is 2
    int *p = &A[1]; int *q = &A[3];
    // cout<<p-q<<endl;


    // Dereferencing:
    // after a pointer is already declared and initialized, * is used for dereferencing it
    // *p would now mean value of element in A[1] which is 6, and p+1 points to the next element in the array which is 7 and so *(p+1) results in 7
    // deferencing works like the following: (read left to right, whatever comes first happens first)
    // *p returns 20
    // *(p+1) returns 30
    // *p returns 20     //p doesnt change what its pointing to
    // *(p++) returns 20     //p is deferenced before it moves to the next element
    // *p returns 30     //p has changed what it was pointing to and moved right by 1
    // *(++p) returns 40     //p moves to the next element first then its deferenced
    // *p returns 40     //p doesnt change what its pointing to cuz its already incremented
    // *++p returns 50     //p moves to the next element first then its deferenced
    // *p returns 50     //p has already moved
    // ++*p returns 51     //p is deferenced first then its value is increased, the value in actual array is increased
    // *p++ returns 51     //p is deferenced first then moved
    // *p returns 60     //p had already been moved by above statement
    
    cout<<*p<<*(p+1)<<*p<<*(p++)<<*p<<*(++p)<<*p<<endl<<*++p<<*p<<++*p<<*p++<<*p<<endl;
    
    // After ++*p, the value in array is changed from 50 to 51
    for(int x:A){
        cout<<x<<" ";
    } // outputs 10 20 30 40 51 60 70 80

    // p = nullptr; // makes the pointer point to nothing or resets it or empties the pointer variable or makes it value 0

    // Pointers pointing to pointers:
    // just like int * is the datatype for pointer, int ** is the datatype for a pointer which points to another pointer variable and so on it goes.
    // for eg-
    int v = 60;
    int *a = &v; // now 'a' stores address of 'v' and *a stores 60
    int *w = &*a; // now 'w' stores address of *a which is 'v', so its the same as 'a' now, pointing to the same variable 'v', both cout<<a and cout<<w will return same thing
    
    int **b = &a; // 'a' is of the datatype (int *) and 'b' is of the datatype (int **)
    // now 'b' points to pointer variable 'a', *b will return 'a' or &v or address of 'v'
    // **b which is same as *(*b) which is same as *(a) since *b = a and *a = 60 so **b = 60 and so **b will return 60

    int ***c = &b; // and it can go on as much as you want ig.
/*
    // Each line of the same block below returns the same value.
    
    cout<<"c is: "<<c<<endl;
    cout<<"&b is: "<<&b<<endl<<endl;

    cout<<"*c is: "<<*c<<endl;
    cout<<"b is: "<<b<<endl;
    cout<<"&a is: "<<&a<<endl<<endl;

    cout<<"**c is: "<<**c<<endl;
    cout<<"*b is: "<<*b<<endl;
    cout<<"a is: "<<a<<endl;
    cout<<"&v is: "<<&v<<endl<<endl;

    cout<<"***c is: "<<***c<<endl;
    cout<<"**b is: "<<**b<<endl;
    cout<<"*a is: "<<*a<<endl;
    cout<<"v is: "<<v<<endl<<endl;
*/

    // int *p, int* p, int * p, int*p all are the same, so from now one i will use int* for the datatype

    // Reference is alias of a variable. Similar to pointer(int*), reference is decalred with (int&), and it works exactly like the original, it also doesnt consume memory since its just another name for the same thing.
    // Also once set, reference cant be changed to another variable.
    int& k = x;
    // now k and x are the same thing
    

    cout<<endl<<endl;
return 0;
}