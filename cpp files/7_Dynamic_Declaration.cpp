#include<iostream>
using namespace std;

int main(){
    // dynamic declaration is basically global and local variable, any local variable local to a "block"(characterised by curly brackets {}) is deleted from the memory after block ends

int a = 10;

if (a < 20)
{
    int i = 50;
    cout<<a<<endl;
}
// cout<<i; gives a declaration error as 'i' was declared in the if block and after if block ended the variable was also deleted. 

// cout<<a<<endl; // this works because a was declared outside if block

// if we want to use 'a' in condition for if but thats the only use it has and we want to delete it afterwards, we can enclose the whole thing in an empty block like so:
{
int b = 10;

if (b<20)
{
    int j = 10;
}
}
// cout<<b; this will give same declaration error as the block in which 'b' was declared has ended, b is a local variable in that empty block
// Its  worth noting that while u cant access a local variable outside its block or scope, u can still edit a variable which is outside the block inside the block.
return 0;
}