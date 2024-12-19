#include<iostream>
using namespace std;

int main(){
/*
    int day;
    cout<<"Give day number.";
    cin>>day;
    if (day==1)
    {
        cout<<"Mon"<<endl;
    }
    else if (day==2)
    {
        cout<<"Tue"<<endl;
    }
    
    // If 2 is entered then the compiler exits here only, doesn't check the bottom condition because its under else of the above if of else if.
    
    else if (day==2)
        cout<<"Tue again"<<endl;

    // both syntax are correct, without brackets it only assumes one line(i.e. untill ;) to be inside it so if you want multiple lines then use {}
    
    else if (day==3)
        cout<<"Wed"<<endl;
    else if (day==4) cout<<"Thu"<<endl; // even this is correct.
    else if (day==5)
        cout<<"Fri"<<endl;
    // if user enters 5, it will check all the above conditions since all the bottom conditions are inside top one only, else if is just a short for
    // else
    //     if()  

    else
        cout<<"Invalid input."<<endl;

*/

/*
Short Circuit:-
    if(condition 1 && condition 2)
    if condition 1 is false, then it wont check for condition 2 cuz it doesnt need to, so any operation like ++i in condition 2 wont be executed
    similarly for
    if(condition 1 || condition 2)
    if condition 1 is true, it wont check condition 2 cuz it aint needed
*/

int a = 10, b = 5, c = 3;

if (a<b && ++c>b)
{
    cout<<a<<" "<<b<<" "<<c<<endl;
}
// if (a>b && ++c>b)
// {
//     cout<<a<<" "<<b<<" "<<c<<endl;
// }

    cout<<a<<" "<<b<<" "<<c<<endl;

return 0;
}