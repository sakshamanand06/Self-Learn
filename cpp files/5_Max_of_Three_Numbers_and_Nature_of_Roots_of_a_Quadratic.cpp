#include<iostream>

using namespace std;

int main(){
    int a,b,c;
    cout<<"Enter three numbers: "<<endl;
    cin>>a>>b>>c;
    if (a>b && a>c)
    {
        cout<<a<<" is greatest.";
    }
    else
    {
        // This is called nested if
        // checking b>a is not needed, for verification make cases.
        if (b>c)
        {
            cout<<b<<" is greatest.";
        }
        else
        {
            cout<<c<<" is greatest.";
        }
        
    }
    cout<<endl;
/* The following else if is just a short version of the above used nested if else only
    else if (b>c)
    {
        cout<<"B is greatest.";
    }
    else
    {
        cout<<"C is greatest.";
    }
*/

    int d = b*b - 4*a*c;
    if(d>0)
    {
        cout<<"Roots are real and distinct.";
    }
    else if(d==0)
    {
        cout<<"Roots are real and equal.";
    }
    else
    {
        cout<<"Roots are imaginary.";
    }

return 0;
}