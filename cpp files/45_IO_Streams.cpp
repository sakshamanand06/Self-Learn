#include<iostream>
#include<fstream> // library for input output streams to file
using namespace std;

int main(){
    // To Write:
    ofstream ofs("iocheck.txt", ios::trunc); // ofstream is a class and we made an object ofs of that class, now this object ofs is associated with the file iocheck.txt, whatever u write will be dropped into iocheck.txt
    // by default when u write something into the file it will remove anything written in "iocheck.txt" or truncate it and write new stuff to it, this is the ios::trunc mode, another mode is ios::app to append instead of truncating
    // if iocheck exists, it will open that, if it doesnt exist then it will create that file

    ofs<<"Cheking"<<endl; // remember, << operator takes two arguments, one is output stream and another is the string "Cheking", now we used cout before which is an output stream for printing to console, but now we are changing the output stream to ofs, and ofs is associated with iocheck.txt and hence the << operator will insert "Cheking" into ofs or write "Cheking" into iocheck.txt
    ofs<<"Wont be written newly."<<endl; // the ios::trunc doesnt mean it will write entirely new things everytime u do this, it means it will entirely new things when u re-run the program.
    ofs<<5;
    ofs.close(); // The stream will be closed regardless of this when object goes out of scope but it is a good practice to close it

    // To Read:
    // ifstream ifs("iocheck.txt"); // ifstream is a class used for reading, the file must exist
    ifstream ifs;
    ifs.open("iocheck.txt"); // same as above one liner
    if(!ifs.is_open()){ // ifs.is_open() or simply ifs returns true if the file is open, it wont be open if it doesnt exist and so will return false if file doesnt exist.
        cout<<"File doesnt exist";
    }
    string tra, la;
    int x;
    getline(ifs, tra);
    getline(ifs, la);
    ifs>>x;
    cout<<tra<<endl<<la<<endl<<x;
    // Reading works same way as cin and getline, for cin, two different strings are divided by space or newline, for getline they r divided by newline, variable datatypes must be written in order, so we defined certain orders or formats for file like .jpg or .txt, so the code already knows which data it will get first and which one second
    cout<<endl<<dec<<163;


    cout<<endl<<endl;
return 0;
}