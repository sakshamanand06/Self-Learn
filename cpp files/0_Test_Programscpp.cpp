#include<iostream>
#include<fstream>
using namespace std;
// Bubble sort
void swapp(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void bsort(int arr[], int n){
    for(int i = 0; i<n; i++) cout << arr[i] <<" ";
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]) swapp(arr[j], arr[j+1]);
        }
    }
    cout<<'\n';
    for(int i = 0; i<n; i++) cout << arr[i] <<" ";
    cout<<'\n';
    cout<<'\n';
}


int main(){
    int x;
    cin>>x;

    cout<<"\n\n";
return 0;
}