#include<iostream>
using namespace std;

// patterns are made using matrix like function, similar to my fancade tic tac toe game.

int main(){
    int counter=1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i+j>=3)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
        
    }
    

    cout<<endl<<endl;
return 0;
}