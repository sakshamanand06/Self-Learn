#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, num, sum=0, rev=0;
    cout<<"Enter a number: ";
    cin>>n;
    num=n;
    while(n>0)
    {
        sum += pow((n%10),3);
        rev = (rev*10) + (n%10);
        n = n/10;
    }
    if (sum==num)
        cout<<num<<" is an Armstrong number."<<endl;
    else
        cout<<num<<" is not an Armstrong number."<<endl;

    cout<<"Reverse of "<<num<<" is "<<rev<<" and so ";
    if (rev==num)
        cout<<num<<" is a palindrome."<<endl;
    else
        cout<<num<<" is not a palindrome."<<endl;

    cout<<endl<<endl;
return 0;
}