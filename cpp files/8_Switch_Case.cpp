#include<iostream>
using namespace std;

int main(){
    switch (2)
    {
    case 1:
    cout<<"1"<<endl;
    break;

    case 'b':
    cout<<"2"<<endl;
    break;

    default:
    cout<<"Invalid"<<endl;
        break;
    }

// In switch case not every case is checked one by one, it directly jumps to the appropriate case and runs the code inside so it is faster than else if ladder, also without break the next case will run automatically and it will keep running until it encounters a break statement. Default is when expression inside switch doesnt match any case.

// Switch and case expressions can be integer or a char or a mix.

return 0;
}