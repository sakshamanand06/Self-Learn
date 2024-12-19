#include<iostream>
using namespace std;

class your; // compiler should know this class exists, but you cant make the entire class here as when this class tries to make an object of 'my' class, it will fail as 'my' class isn't declared yet.
// class your{}; // this will throw error as this will lead to redeclaration of the class.

class my{
private: int a = 6;
public:
    int b = 10;
    friend void glob(); // tells the compiler this function doesn't belong to this class(no scope resolution) but is still a friend and should be able to access private and protected members of this class

    friend your; // altho this makes 'your' class a friend but still compiler doesnt know about the existence of this class yet since it reads line by line so we have to declare this class before 'my' class.
};
void glob(){ // this is a global function but if you want it to access private and protected members of a class upon object, then make it a friend inside that class.
    my x;
    cout<<x.a<<endl;
}

class your{ // this is not an inherited class but a global class and if you want it to access private and protected members of another class upon object, then make it a friend inside that class.
private: int c = 15;
public:
    int d = 20;
    void display(){
        my m;
        cout<<"\" "<<m.a<<" \""<<endl;
    }
    // a=5; this throws error as 'a' doesnt belong to this class, even tho its a member of 'my' class, this shows a friend class can only access upon object.
};

int main(){
    your y;
    y.display();
    glob();

    cout<<endl<<endl;
return 0;
}