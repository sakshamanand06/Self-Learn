#include<iostream>
using namespace std;
int main(){
    // anything except 0 is treated as true, be it 1 or 15 doesnt matter, only 0 is false
/*
    if (15){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
*/
    int age;
    cout<<"Enter age(b/w 1 and 100): ";
    cin>>age;

    if((age>0 && age<=12) || (age >= 50 && age<=100)){
    // if((age>0 && age<=100) && !(age>12 && age<50)){
    // ! is NOT operator, both 'if' conditions give exact same results
    cout<<"Eligible";
}
    else
    cout<<"Not Eligible or invalid age";
    return 0;
}