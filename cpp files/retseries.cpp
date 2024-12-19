#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a, r, l;
    cin>>a>>r>>l;
    vector<int> arr;
    if(a>0 && r>0){
        while(l>a){
            arr.push_back(a);
            a *= r;
        }
    }
    cout<<"{";
    for(int i = 0; i < arr.size(); i++){
        if(i + 1 != arr.size()) cout<<arr[i]<<", ";
        else cout<<arr[i]<<"}";
    }

    cout<<endl<<endl;
return 0;
}