#include<iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
public:
    Rectangle(int l = 0, int b = 0){ // constructor which sets default values
        setLength(l);
        setBreadth(b);
        // length = l; breadth = b; // this is not preferred as it does not prevent data mishandling and we already have function for checking the data validity so we can just call those functions
    }
    Rectangle(Rectangle& r1){ // copy constructor, makes a copy of any object passed to it
        length = r1.length;
        breadth = r1.breadth;
    }
    void setLength(int l){  // these two are mutators
        if (l>=0)
        length = l;
        else{
        length = 0;
        cout<<"Invalid length given.";
        }
    }
    void setBreadth(int b){
        if (b>=0)
        breadth = b;
        else{
        breadth = 0;
        cout<<"Invalid breadth given.";
        }
    }
    int getLength(){return length;}    // these two are accessors
    int getBreadth(){return breadth;}

    int area(){return length*breadth;}  // these two are facilitators
    int perimeter(){return 2*(length+breadth);}

    int isSquare(){  // this is enquiry or inspector(can be bool too)
        return length == breadth;
    }
    // ~Rectangle(); this is a destructor
};

int main(){
    Rectangle r1;
    Rectangle r2(10,5);
    cout<<r1.getLength()<<" "<<r1.getBreadth()<<endl;
    cout<<r2.getLength()<<" "<<r2.getBreadth()<<endl;
    Rectangle r3(r2); // copies r2's attributes to r3 due to the copy constructor, r2 is passed to &rect(pass by reference), rect becomes another name for r2 and attributes of r3(since we are creating that object) is set to rect's or r2's attributes
    cout<<r3.getLength()<<" "<<r3.getBreadth()<<endl;
    
    Rectangle r4(5,5);
    cout<<r3.isSquare()<<", "<<r4.isSquare();

    cout<<endl<<endl;
return 0;
}