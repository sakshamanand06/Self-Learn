#include<iostream>
using namespace std;

int main(){
    cout<<"Enter an year: ";
    int year;
    cin>>year;
    if((year%4==0 && year%100!=0) || year%400==0)
        cout<<year<<" is a leap year.";
    else
        cout<<year<<" is not a leap year.";

    cout<<endl<<endl;
return 0;
}