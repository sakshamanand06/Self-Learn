#include<iostream>
#include<fstream>
using namespace std;

class Item{
public:
    int price, quantity;
    string name;
    Item(string n = "Noname", int p = 0, int q = 0){
        name = n; price = p; quantity = q;
    }
    friend istream& operator>>(istream &i, Item &t);
    friend ostream& operator<<(ostream &o, Item &i);
    // The above two were to overload cin and cout, to display and enter items in this program itself, we can decorate it anyway we want
    friend ifstream& operator>>(ifstream &i, Item &t);
    friend ofstream& operator<<(ofstream &o, Item &i);
    // The above two are to overload ofstream and ifstream objects(i.e. wtf and rff in this case), when writing in file we dont need to decorate as we wont open it, rtf will, and so any unnessary string will only get in its way, and we wont even be able to properly and easily read from files so we only store direct raw data in the file and read that
};

istream& operator>>(istream &i, Item &t){
    cout<<"Enter Item name, price and quantity: ";
    i>>t.name>>t.price>>t.quantity;
    return i;
}
ostream& operator<<(ostream &o, Item &i){
    o<<"Item Name is: "<<i.name<<", Price is: "<<i.price<<" and Quantity is "<<i.quantity<<"."<<endl<<endl;
    return o;
}

ifstream& operator>>(ifstream &i, Item &t){
    i>>t.name>>t.price>>t.quantity;
    return i;
}
ofstream& operator<<(ofstream &o, Item &i){
    o<<i.name<<endl<<i.price<<endl<<i.quantity;
    return o;
}

int main(){
    int items;
    cout<<"Enter number of items: ";
    cin>>items;
    Item I[items];
    ofstream wtf("data.txt"); // Write To File(wtf)
    for(int i = 0; i<items; i++){
        cin>>I[i];
        wtf<<I[i].name<<endl<<I[i].price<<endl<<I[i].quantity;
        cout<<endl;
    }
    cout<<endl;
    wtf.close();

    ifstream rff("data.txt"); // Read From File(rff)
    while(!rff.eof()){
        Item temp;
        rff>>temp;
        cout<<temp;
    }
}