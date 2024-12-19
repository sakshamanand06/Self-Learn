#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int row[t];
    int col[t];
    for(int i=0; i<t; i++)
        cin>>row[i]>>col[i];

    // maximum between rows and columns
    int maxrc;
    for(int i=0; i<t; i++)
    {
        maxrc = max(row[i], col[i]);
        if(row[i]==col[i]){
            cout<<row[i]*(row[i]-1)+1;
        }
        else if(maxrc%2 == 0)
            cout<<maxrc*maxrc-(col[i]-1)-(maxrc-row[i]);
        else
            cout<<maxrc*maxrc-(row[i]-1)-(maxrc-col[i]);
        cout<<endl;
    }
return 0;
}
    
/* 
    int L, R, count = 0, minop = 0;
    cin>>L>>R;
    int l = L;
    while(l>0)
    {
        l /= 3;
        count++;
    }
    minop += count;
    for(int i=L; i<=R; i++){
        minop += count;
        if(i%3 == 0 && i!=L)
        {
            count++;
        }
    }
    cout<<minop;
    cout<<endl; */
