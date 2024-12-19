#include<iostream>
using namespace std;

//ENUMERATOR

// enum is used to define a group of constants at once
enum companies {poco, xiaomi, oneplus, apple, samsung};
// by default poco = 0, xiaomi = 1 and so on till samsung = 4
// same as const int poco; and doing so on for each, enum can do it at once
// enum companies (poco = 1, xiaomi, oneplus, apple = 10, samsung);
// p is 1, x is 2, o is 3, a is 10, s is 11
// After defining it, companies has become our custom datatype now

// TYPEDEF

// We can rename built-in datatypes using typedef for better readability of code too
typedef int marks;

int main(){

    companies com = oneplus;
    cout<<com;
    // com = 0 wont work, cuz its not in the enum we defined above, any variable of companies datatype can only take on values we defined above. Also com++ wont work cuz its a constant

    // cout<<com;
    marks m1,m2,m3;
    // now m1,m2,m3 are integers, but we can easily know they are marks even if we dont give meaningful names to them
    cout<<endl<<endl;
    return 0;
}