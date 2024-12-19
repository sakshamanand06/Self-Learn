#include<iostream>
using namespace std;

int divs(int a, int b){
    if(b==0){
        throw string("Error: Division by zero");
    }
    else if(a==0){ // just to demonstrate multiple catches
        throw 0;
    }
    else if(a<0 || b<0){
        throw 1.5;
    }
    return a/b;
}

int main(){
    try
    {
        int num1, num2;
        cout<<"Enter two numbers: ";
        cin>>num1>>num2;
        int d=divs(num1, num2);
        cout<<"Division: "<<d;
    }
    catch(string s)
    {
        cout<<s;
    }
    catch(int i)
    {
        cout<<"Division: "<<i;
    }
    catch(...) // this is catch all, it will catch any remaining exceptions not caught by above statements, in this case the double value 1.5
    {
        cout<<"An unknown error occurred.";
    }

    cout<<endl<<endl;
return 0;
}