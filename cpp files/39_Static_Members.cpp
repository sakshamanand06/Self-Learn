#include<iostream>
using namespace std;

// Only one instance of static member is created and shared by all objects.

class student{
public:
    int roll;
    string name;
    static int admNo; // this belongs to the class itself, not to any object, if one object changes it then it will change for all the other objects as well
    student(string n){
        name = n;
        admNo++;
        roll = admNo;        
    }

    static int st(){
        // return roll; // throws error cuz roll is not static and thus specific to an object and we have not told any object here
        return admNo; // a static function can only access static varibles 
    }
};

int student::admNo=0; // required as per syntax

int main(){
    student s1("john");
    student s2("jane");
    student s3("jim");
    cout<<s1.name<<" - Roll - "<<s1.roll<<endl;
    cout<<s2.name<<" - Roll - "<<s2.roll<<endl;
    cout<<s3.name<<" - Roll - "<<s3.roll<<endl;
    cout<<"Total Students - "<<student::admNo<<endl; // since static member admNo belongs to class, it can be accessed directly from class without any object too using scope resolution operator


    cout<<endl<<endl;
return 0;
}