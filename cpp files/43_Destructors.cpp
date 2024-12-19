#include<iostream>
using namespace std;

class Destroy{
public:
    int *p;
    static int objNo;
    Destroy(){
        cout<<objNo<<". Constructor called"<<endl;
        
        p = new int(10); // memory created in heap
    }
    ~Destroy(){
        cout<<objNo<<". Destructor called"<<endl;
        objNo++;

        delete []p; // without this, it'd be memory leak, u must deallocate any memory allocated by constructor inside destructor.
    }
    // ~Destroy(int x){} // error, destructors cant be overloaded like constructors nor can take parameters
};
int Destroy::objNo=1; // for static member

void fun1(){
    Destroy da;
}

void fun2(){
    Destroy* p = new Destroy();
    delete p; // without this, destructor wont be called as the object is made in heap
}

int main(){
    {
    fun1();
    Destroy la;
    /*
        Output is:
        Constructor called
        Destructor called
        Constructor called


        Destructor called
        
        This is bcuz the object of fun() is made and destroyed instantly, while for object 'la' made inside main(), its destroyed after curly brackets end, and so the bottom two endl's are printed before destroying the object, u can prevent this by doing {Destroy la}, in this case its instantly created and destroyed and output will be as intended. Basically local variable are destroyed after their block(i.e. curly brackets they are in) ends.
    */
    cout<<endl<<endl;
    }

    fun2();

return 0;
}