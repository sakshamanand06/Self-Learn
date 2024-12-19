#include<iostream>
using namespace std;

class Ratno{
private:
    int p, q;
public:
    // Ratno(int p=1, int q=1) {this->p = p/hcf(p,q); this->q = q/hcf(p,q);}
    Ratno(int p=1, int q=1){this->p = p; this->q = q;}

    void setP(int p){this->p = p;}
    void setQ(int q){this->q = q;}
    int getP(){return p;}
    int getQ(){return q;}

    // friend Ratno operator+(Ratno r1, Ratno r2);
    friend ostream& operator<<(ostream& o, Ratno r);

    
    Ratno operator+(Ratno& r1){
        int n = (p*r1.q) + (q*r1.p);
        int d = q*r1.q;
        // Ratno r(n, d);
        // r.simplify(); // this line simplifies the fraction but its ur choice to do it or not, using hcf method worked too but it was hard to select whether to simplify or not, now u just call this function on the object and it simplifies it, also creates a new object with same members and returns it
        return Ratno(n, d).simplify();
    }

    // int hcf(int a, int b){
    //     a = abs(a);
    //     b = abs(b);
    //     while(a!=b)
    //     {
    //     if(a>b)
    //     a -= b;
    //     else
    //     b -= a;
    //     }
    //     return a;
    // }

    Ratno simplify(){
        int a = abs(p);
        int b = abs(q);
        while(a!=b)
        {
        if(a>b)
        a -= b;
        else
        b -= a;
        }
        p /= a;
        q /= b; // doesnt make a difference if its 'a' or 'b'
        return Ratno(p, q);
    }
    // u can do the same thing as above using void too, but stuff like cout<<c1.simplify() wont work as it wont return anything, but with this current function both r1.simplify(); cout<<r1 and cout<<r1.simplify work. The function updates the object members as well as returns an object of the same data values. 
};

// Ratno operator+(Ratno r1, Ratno r2){
//     return Ratno((r1.p*r2.q)+(r2.p*r1.q), (r1.q*r2.q));
// }


ostream& operator<<(ostream& o, Ratno r){
    // r.simplify();
    o<<r.getP()<<"/"<<r.getQ()<<" ";
    return o;
}

int main(){
    Ratno r1(2,10), r2(8,10), r3;
    r3 = r1 + r2;
    cout<<r1<<r2<<r3;

    // r1.simplify();
    // cout<<r1;

    cout<<endl<<endl;
return 0;
}