#include<iostream>
using namespace std;

int main(){
    // pointer can be used to create an array in heap rather than stack
    int *p = new int[5]{1,2,3,4,5};
    // accessing the array:
    cout<<p[1]; // the only way to access it is through the pointer.

    // this array is made in heap and wont be deleted on its own
    delete []p; // deletes the array and deallocates memory allocated while creating it

    p = nullptr; // will reset the pointer
    // if you do this before deleting, the memory in heap wont be deallocated nor accessible since pointer was the only way to access it and you reseted it
    // this is called memory leak, since that memory will be wasted now as you cant either use or delete it

    // when a pointer points to a memory already deleted then its called dangling pointer
    // for eg- 
    int *q = new int[2]{5,43};
    delete []q;
    // now q is a dangling pointer since the array it pointed has been deleted and its still pointing to it. so cout<<q will give the address of q[0] and *q will give garbage value.
    q=nullptr;

    cout<<endl<<endl;
return 0;
}