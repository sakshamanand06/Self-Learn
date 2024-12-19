#include<iostream>
using namespace std;

/*
    for ((1) initialisation; (2) condition; (3) updation)
    {
        (4) process;
    }
    the loop runs in the following order-> 1, 2, 4, 3, 2, 4, 3,..until 2 is false and it exits.
    (3) can be i++; i=i+1; i=i+2; i=i*2; or any such thing

    (1) - optional, u can initialise a variable outside the loop as well, the syntax becomes: 
    int i = 0;
    for(;(2);(3))
    {
    (4);
    }
    
    we can remove (3) as well and do it inside the loop:
    int i = 0;
    for(;(2);)
    {
    (4);
    (3);
    }
    
    OR
    
    for(;(2);)
    {
    (4);
    i++; //(3)
    }

    we can remove (2) as well:
    int i = 0;
    for(;;)
    {
    (4);
    (3);
    if(!(2))
        break;
    }
    we can omit some of these too and it will become an infinite loop depending on what we omitted.
    for eg if we omit condition, then it will always run, or if we omit upgradation and condition is true, then also it will become infinite loop as condition will never become false
*/
int main(){
    cout<<"Enter a number: ";
    int num;
    cin>>num;
    for (int i = 1; i <= 10; i++)
    {
        cout<<num<<" x "<<i<<" = "<<num*i<<endl;
    }
    

    cout<<endl<<endl;
return 0;
}