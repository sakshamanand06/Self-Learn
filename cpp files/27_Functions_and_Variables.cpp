#include<iostream>
using namespace std;
int glob = 10; // Global variable, can be accessed in any function.

// Call by address:
void swapp(int* x, int* y){ // formal parameters are int* x and int* y.
    glob; // no error cuz its global
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// Linear search using functions
int searchh(int S[], int len, int key){
    glob; // no error cuz its global
    
    for (int i = 0; i < len; i++)
    {
        if (S[i] == key)
            return i;
    }
    return -1;
    
}
// Return by address function
int* rba(int n){
    int* p = new int[10];
    for (int i = 1; i <= 10; i++)
        p[i-1] = n*i;
    return p;
}
// Static Variables
void svb(){
    glob; // no error cuz its global

    static int v = 0;
    int a = 0;
    v++;a++;
    cout<<"v is: "<<v<<", a is: "<<a<<endl;
}
int main(){
    glob; // no error cuz its global

    // swapping:
    int x = 10, y = 20;
    cout<<x<<" "<<y<<endl;
    swapp(&x, &y); // actual parameters are &x and &y
    cout<<x<<" "<<y<<endl;

    // linear search
    // int A[]{1, 5, 3, 2, 56, 60, 20};
    // cout<<searchh(A, 7, 20);

    // static variable
    // svb();svb();

    cout<<endl<<endl;
// You can call by reference but it copies the entire function code in main() where its called, simply by adding & in formal parameters, everything including actual parameters remain the same.

    int m; cout<<"Enter no. for mul. table: "; cin>>m;
    int* multable = rba(m); // multable points to the function rba().
    for(int i = 0; i < 10; i++)
        cout<<multable[i]<<endl;

return 0;
}