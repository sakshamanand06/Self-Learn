#include<iostream>
using namespace std;

int main(){
    int A[10]={6,8,13,17,20,22,25,28,30,35};
    int l=0,h=9,mid,key,comparisons=0;
    cout<<"Enter key: ";
    cin>>key;
    int count = 0;
    while(true)
    {
        mid=(l+h)/2;
        if(l<=h)
        {
            comparisons++;
            if(A[mid]<key)
            {
                l=mid+1;
                continue;
            }
            else if(A[mid]>key)
            {
                h=mid-1;
                continue;
            }
            else
            {
                cout<<"Index of key is: "<<mid;
                break;
            }
        }
        else
        {
            cout<<"Couldn't find the key.";
            break;
        }
    }
    cout<<endl<<"Total comparisons: "<<comparisons;
    cout<<endl<<endl;

return 0;
}