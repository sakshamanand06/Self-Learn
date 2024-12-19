#include<iostream>
using namespace std;

template<class T> // this is a template class now, float, int, double, string, anything will work.
class Stack{
    int top;
    int size;
    T* stk;
public:
    Stack(int s)
    {
        top = -1;
        size = s;
        stk = new T[size];
    }
    void push(T x);
    T pop();
    void display(){
        for(int i = 0; i<size; i++){
            cout<<stk[i]<<endl;
        }
    }
};

template<class K> // gotta do it for every new block
void Stack<K>::push(K x){
    if(top == size - 1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    stk[++top] = x;
    cout<<x<<" pushed into stack"<<endl;
}

template<class T> // the 'T' doesnt matter, can be any other letter
T Stack<T>::pop(){
    if(top == -1){
        // cout<<"Stack Underflow"<<endl;
        T r;
        return r;
    }
    else
    {
    T x = stk[top--];
    // T r;
    return x;
    }
}

int main(){
    // Stack<float> s(5);
    // s.push(11.9f);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // cout<<s.pop()<<endl<<endl;

    // Stack<string> s2(3);
    // s2.push("apple");
    // s2.push("banana");
    // s2.push("pears");
    // s2.pop();
    // s2.push("pineapple");
    // cout<<s2.pop()<<endl;
    // cout<<s2.pop()<<endl;
    // cout<<s2.pop()<<endl;
    // cout<<s2.pop()<<endl;
    // s2.display();

    Stack<int> s3(3);
    s3.push(6);
    s3.push(60);
    s3.push(4);
    s3.push(1);
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    cout<<s3.pop()<<endl;
    s3.push(7);
    s3.display();

    cout<<endl<<endl;
return 0;
}