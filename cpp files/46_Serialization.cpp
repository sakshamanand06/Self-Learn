#include<iostream>
#include<fstream>
using namespace std;

class Student{
public:
    int roll;
    string name, branch;
    Student(int r = 0, string n = "Noname", string b = "Dropout"){
        setData(r, n, b);
    }
    void setData(int r, string n, string b){
        if(r>0) roll = r; else {r=0;return;}
        name = n;
        branch = b;
    }
    friend ofstream& operator<<(ofstream &o, Student &s);
    friend ifstream& operator>>(ifstream &i, Student &s);
    // Keep in mind that these are file IO streams, the cout cin are belong to different streams known as ostream and istream.
};

ofstream& operator<<(ofstream &o, Student &s){
    o<<s.roll<<endl<<s.name<<endl<<s.branch<<endl;
    return o;
}
ifstream& operator>>(ifstream &i, Student &s){
    int ro;
    string na, br;
    i>>ro;
    i>>na;
    i>>br;
    s.setData(ro, na, br);
    return i;
}


int main(){
    // ofstream ofs("pformat.txt");
    // // Student s1(5, "S", "CSE");
    // Student s1(5, "hi", "hello");
    // ofs<<s1;
    // ofs.close();

    Student s2;
    ifstream ifs("pformat.txt");
    ifs>>s2;
    cout<<s2.roll<<endl<<s2.branch<<endl<<s2.name;
    ifs.close();
    
    cout<<endl<<endl;
return 0;
}