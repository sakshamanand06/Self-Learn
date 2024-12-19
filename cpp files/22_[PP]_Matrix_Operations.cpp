



// WIP - Continue after learning functions.






#include<iostream>
using namespace std;

int main(){
    // string choice;
    int order;
    // while(true)
    // {
    // cout<<"Do you want to perform on single matrix or double?(s/d): ";
    // // cin>>choice;
    // getline(cin, choice);
    // if(choice=="s")
    // {
    //     cout<<"Transpose or Inverse?(t/i): ";
    //     getline(cin, choice);
    //     while(true)
    //     {
    //         if(choice=="t")
    //         {
    //             cout<<"Enter order of matrix: ";
    //             cin>>order;
    //         }
    //     }
    //     break;
    // }

    // else if(choice=="d")
    // {
    int i,j,x,y;
    while(true)
    {
    cout<<"Enter number of rows and columns of first matrix.";
    cin>>i>>j;
    cout<<"Enter numbaer of rows and columns of second matrix.";
    cin>>x>>y;

    if(j!=x)
        cout<<"Invalid dimensions of matrices, try again."<<endl;
    else
        break;
    }

    int A[i][j];
    int B[x][y];
    int C[i][y];

    cout<<"Enter values for first matrix: ";
    for(auto& a:A)
        for(auto& b:a)
            cin>>b;

    cout<<"Enter values for second matrix: ";
    for(auto& a:B)
        for(auto& b:a)
            cin>>b;
    
    cout<<"The two matrices are: "<<endl;
    for(auto& a:A)
    {
        for(auto& b:a)
            cout<<b<<" ";
        cout<<endl;
    }
    cout<<endl<<"and"<<endl<<endl;
    for(auto& a:B)
    {
        for(auto& b:a)
            cout<<b<<" ";
        cout<<endl;
    }

    for(int k = 0; k<i; k++)
    {
        for(int l = 0; l<y; l++)
        {
            C[k][l] = 0; // essential otherwise it has garbage value
            for (int c = 0; c < j; c++)
                C[k][l] += A[k][c] * B[c][l];
            
        }
    }

    cout<<endl<<"Product matrix is: "<<endl;
    for(auto& a:C)
    {
        for(auto& b:a)
            cout<<b<<" ";
        cout<<endl;
    }


    cout<<endl<<endl;
return 0;
}
    // for(int c=0; c<i; c++)
    // {
    //     for(int d=0; d<j; d++)
    //     {
    //         cout<<A[c][d]+B[c][d]<<" ";
    //     }
    //     cout<<endl;
    // }
        // break;
    // }
    // else
    // {
    //     cout<<endl<<"Invalid input."<<endl;
    //     continue;
    // }
    // }