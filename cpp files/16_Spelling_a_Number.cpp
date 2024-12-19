#include<iostream>
using namespace std;

int main(){
    int n, num, rev=0;
    cout<<"Enter a number: ";
    cin>>n;
    num=n;
    while(n>0)
    {
        rev = (rev*10) + (n%10);
        n = n/10;
    }

    while(rev>0)
    {
        switch (rev%10)
        {
        case 1:
            cout<<"One ";
            break;
        case 2:
            cout<<"Two ";
            break;
        case 3:
            cout<<"Three ";
            break;
        case 4:
            cout<<"Four ";
            break;
        case 5:
            cout<<"Five ";
            break;
        case 6:
            cout<<"Six ";
            break;
        case 7:
            cout<<"Seven ";
            break;
        case 8:
            cout<<"Eight ";
            break;
        case 9:
            cout<<"Nine ";
            break;
        case 0:
            cout<<"Zero ";
            break;
        default:
            break;
        }
        rev = rev/10;
    }
    cout<<endl<<endl;
return 0;
}