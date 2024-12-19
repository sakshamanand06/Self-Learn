#include<iostream>
using namespace std;

class student{
private:
    int roll;
    string name;
    int phy_marks, chem_marks, math_marks;

public:
    student(){cout<<"Details can't be empty.";}
    student(int, string, int, int, int);
    int marksTotal();
    string grade();
};


int main(){
    student s1(10, "John", 50, 10, 10);
    cout<<s1.grade();

    cout<<endl<<endl;

return 0;
}

student::student(int roll, string n, int pm, int cm, int mm){
    this->roll = roll; name = n; phy_marks = pm; chem_marks = cm; math_marks = mm;
} // this->roll means the int roll of the object, not of the function.
int student::marksTotal(){
    return phy_marks+chem_marks+math_marks;
}
string student::grade(){
    if (marksTotal()>=(0.6*300))
    return "A grade";
    else if(marksTotal()>=(0.4*300) && marksTotal()<(0.6*300))
    return "B grade";
    else
    return "C grade";
}