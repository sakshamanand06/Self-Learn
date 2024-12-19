#include<iostream>
using namespace std;

int main(){

// Sum of first n no.s:
    int n, sum=0;
    cout<<"Enter a number: ";
    cin>>n;

    for (int i = 1; i <= n; i++)
    {
        cout<<"Adding "<<i<<": "<<sum<<" + "<<i<<" = "<<sum+i<<endl;
        sum = sum+i;
    }
    cout<<"Sum of first "<<n<<" natural numbers is: "<<sum;

// Factorial:
    // int n, product=1;
    // cout<<"Enter a number: ";
    // cin>>n;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<"Multiplying "<<i<<": "<<product<<" * "<<i<<" = "<<product*i<<endl;
    //     product *= i;
    // }
    // cout<<"\nFactorial of "<<n<<" is: "<<n<<"! = "<<product;


    cout<<endl<<endl;
return 0;
}