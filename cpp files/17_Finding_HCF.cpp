#include<iostream>
using namespace std;

int hcf(int a, int b){
    while(a!=b)
    {
    if(a>b)
    a -= b;
    else
    b -= a;
    }
    return a;
}

int main(){
    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    while (a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    // cout<<"HCF is "<<a<<endl;
    cout<<"hcf() is "<<hcf(a,b);

    cout<<endl<<endl;
return 0;
}