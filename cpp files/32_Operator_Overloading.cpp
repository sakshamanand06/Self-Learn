#include<iostream>
using namespace std;

class complex{
private:
    int real, img;
public:
    complex(int r=0, int i=0) {real=r; img=i;} // default parameterized constructor
    int getReal(){return real;}
    int getImg(){return img;}

    complex operator+(complex& x){ // taking reference in formal parameters is generally better as it doesnt create a new object cuz a new object will call its own constructors and all
        int r=real + x.real;
        int i=img + x.img;
        return complex(r,i);
    }
    friend complex operator-(complex c1,complex c2); // the private members of the class will be inaccessible if this is not declared, this tells the compiler that the function outside the class is a friend function.
    friend ostream& operator<<(ostream& o, complex& c); // Overloading << operator so that cout<<c1; prints 3 + 4i
    // the assignment operator(<<) takes two arguments which are c1 and output stream(cout)
    friend istream& operator>>(istream& i, complex& c); // same as above but for cin
};
// another method for operator overloading using friend function, since its a friend, it doesnt belong to the class and so we dont need to use scope resolution operator and the function works slightly differently too.
complex operator-(complex c1, complex c2){
    complex temp;
    temp.real=c1.real - c2.real;
    temp.img=c1.img - c2.img;
    return temp;
}

ostream& operator<<(ostream& o, complex& c){
    o<<c.real<<" + "<<c.img<<"i";
    return o;
}
// void operator<<(ostream& o, complex& c)
// this works fine too, but the reason we use ostream and return o is so that we can chain the operator like cout<<c1<<c2; or cout<<c<<endl; the "return o" return smth like cout so that it become cout c1, cout c2 and so on, so without that return, we can only use one cout at a time, and o is of the type "ostream" so thats the return type of this function. 

istream& operator>>(istream& i, complex& c){
    cout<<endl<<"Enter real and imaginary parts: ";
    i>>c.real>>c.img;
    return i;
}
// void istream& operator>>(istream& i, complex& c) also works but we return for the same reasons given for cout above

int main(){
    complex c1(3,4), c2(5,3), c3, c4;
    c3 = c1 + c2; // same as c3 = c1.operator+(c2);
    // c3 = c1.operator+(c2);

    // cout<<c3; // same as operator<<(cout, c3);
    // operator<<(cout, c3);

    cout<<"("<<c1<<") + ("<<c2<<") = ("<<c3<<")";
    cin>>c4;
    // operator>>(cin, c4); // again both are same
    cout<<c4;

    cout<<endl<<endl;
return 0;
}