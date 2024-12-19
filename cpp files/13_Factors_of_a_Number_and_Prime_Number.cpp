#include<iostream>
using namespace std;

int main(){
    int n, fac_count=1;
    cout<<"Enter a natural number: ";
    cin>>n;
    if(n>0)
    {
        for (int i = 1; i <= n/2; i++)
        {
            if (n%i==0)
            {
                cout<<i<<", ";
                fac_count++;
            }
        }
        if (n!=1)
            cout<<n<<" are the factors."<<endl<<endl;
        else
            cout<<"1 is the only factor."<<endl<<endl;
        

        if (fac_count == 1)
            cout<<"1 is neither prime nor composite.";
        else if (fac_count == 2)
            cout<<n<<" is a prime number.";
        else
            cout<<n<<" is a composite number.";
    }
    else
        cout<<"Invalid number.";
        
        cout<<endl<<endl;
return 0;
}