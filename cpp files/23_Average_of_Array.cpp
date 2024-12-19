#include<iostream>
using namespace std;

int main(){
    int size, sum = 0, i = 0;
    cout<<"Enter size: ";
    cin>>size;
    int M[size];

    cout<<"Enter elements. "<<endl;
    for(auto& x:M)
    {
        i++;
        cout<<i<<". Enter number: ";
        cin>>x;
        sum += x;
    }
    cout<<"Average of elements in the array is "<<float(sum)/size;

    cout<<endl<<endl;
return 0;
}