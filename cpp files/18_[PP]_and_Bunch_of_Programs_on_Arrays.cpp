#include<iostream>
using namespace std;

int main(){
    // int A[]={1,3,5,7}; // same as int A[]{1,3,5,7}, no need for '=' operator
    // int sum=0;
    // for (int x:A)
    // {
    //     sum+=x;
    // }
    // cout<<sum;

    // for accessing array, arrayname[index] works the same as index[arrayname]
    // for eg- A[2] is same as 2[A], or A[i] and i[A] in for loop

//  PP - Custom array maker:
    int size;
    cout<<"Enter size: ";
    cin>>size;
    int T[size];
    for (int i=0; i<size; i++)
    {
        cout<<"Enter number for index "<<i<<": "<<endl;
        cin>>T[i];
    }

//  Print created array:
    cout<<"Your array is: {";
    for(int x=0;x<size;x++)
        {
        if(x+1==size)
            cout<<T[x]<<"} \n\n";
        else
            cout<<T[x]<<", ";
        }

//  PP - Enter indices of array to add only those numbers:
    int sum=0, terms, term;
    cout<<"How many numbers do you want to add?(repeatable index): ";
    cin>>terms;
    char choice;
    
    if(terms==size)
    {
        while(1)
        {
            cout<<"Do you want to add all elements of the array?(y/n) ";
            cin>>choice;
            if(choice=='y')
            {
                for(int x:T)
                    sum+=x;
                break;
            }
            else if(choice=='n')
                break;
            else
                cout<<"Error, please enter only y or n. "<<endl;
                continue;
        }    
    }
    
    if(terms!=size || choice=='n')
    {
        for (int i = 0; i < terms; i++)
        {
            cout<<"Enter index number: "<<endl;
            cin>>term;
            if (term>=size)
            {
                cout<<"Error: Index exceeded array size, try again."<<endl<<endl;
                i--;
                continue;
            }
            else
                sum+=T[term];
        }
    }
        cout<<"Sum is: "<<sum<<endl;

//  Maximum number in the array:
    // int max=T[0];
    // for(int x:T)
    // {
    //     if(x>max)
    //     max=x;
    // }
    // cout<<"Maximum number is: "<<max;

//  Linear Search:
    // int key;
    // cout<<"Enter key: ";
    // cin>>key;
    // bool search=false;
    // for(int i=0;i<size;i++)
    // {
    //     if(T[i]==key)
    //     {
    //         cout<<"Index of key is: "<<i<<endl;
    //         search = true;
    //     }
    //     else if(i+1==size && search==false)
    //         cout<<"Key not found in array.";
    // }

    cout<<endl<<endl;
return 0;
}