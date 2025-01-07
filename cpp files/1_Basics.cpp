#include<iostream>

// cout is console out
using namespace std;
// to not write std:: everytime
int main(){
    string name;
    int a;
    // std::cout<<"Hello World!";
    // :: is scope resolution operator
    // << is insertion operator. it inserts the string into cout
    // >> is extraction operator.
    // "" is for string and '' is for letter(character)
// ----------------------------------------------------------------
    // cin>>name>>a;
    // getline(cin, name);
    // getline can get strings with spaces while direct cin will only get the first word. if getline gets 'hi helo', cin will get 'hi'
    // cout<<"Tis ur name: "<<name;

    // cin can also get multiple values at once like cin>>x>>y;, if u enter "2 3" in console then it automatically takes x=2 and y=3, the space helps distinguish
// ----------------------------------------------------------------
    // char b=65;
    // b=65 is equivalent to b = 'A', both will print A only.
    // cout<<b;
    // typecasting:
    cout<<"Enter no. to half: ";
    int flt;
    cin>>flt;
    cout<<float(flt)/2<<endl;

    return 0;
}
