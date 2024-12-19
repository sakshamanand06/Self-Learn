#include<iostream>
using namespace std;

int main(){
    // int A[2][3]={{5,3,1},{2,4,6}};
    int A[2][3];
    int B[2][3]={{-1,2,-3},{0,1,-2}};

    // for(int i=0; i<2; i++)
    // {
    //     for(int j=0; j<3; j++)
    //         cout<<A[i][j]+B[i][j]<<" ";
    //     cout<<endl;
    // }

    for(auto& x:A)
    {
        for(auto& y:x)
        {
            cin>>y;
        }
    }
    for(auto& x:A)
    {
        for(auto& y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
return 0;
}