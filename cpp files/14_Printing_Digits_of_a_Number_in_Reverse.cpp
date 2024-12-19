#include<iostream>
using namespace std;

    
int main(){
// My Solution: This preserves the number in n but 2 variables used.
    int n, i = 1;
    cout<<"Enter a number: ";
    cin>>n;
    while(n%i!=n)
    {
        cout<<(n/i)-((n/(10*i))*10)<<endl;
        i*=10;
    }

// Sir solution: Finally n becomes 0 but only 1 variable used.
    // int n;
    // cout<<"Enter a number: ";
    // cin>>n;
    // while(n!=0)
    // {
    //     cout<<n%10<<endl;
    //     n = n/10;
    // }
    cout<<"n is "<<n;

    cout<<endl<<endl;
return 0;
}