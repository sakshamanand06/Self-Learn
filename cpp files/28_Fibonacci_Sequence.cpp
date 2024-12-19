#include<iostream>
using namespace std;

int fib(int numb){
    if (numb == 1)
    return 0;
    else if (numb == 2)
    return 1;
    else
    return fib(numb - 1) + fib(numb-2);
}

int main(){
    //without recursions
    int ind;
    cout<<"Enter number of numbers: ";
    cin>>ind;
    int num[ind];

    for(int i = 0; i < ind; i++)
    {
        if (i == 0)
            num[0] = 0;
        else if(i == 1)
            num[1] = 1;
        else
            num[i] = num[i-1] + num[i-2];
        cout<<num[i]<<" ";
    }
    
    // with recursions.
    cout<<endl<<"Till 5 is: "<<fib(5);

    cout<<endl<<endl;
return 0;
}