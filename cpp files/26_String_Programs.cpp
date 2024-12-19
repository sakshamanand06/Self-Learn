// INCOMPLETE


#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"Enter: ";
    getline(cin, s);

    // Length of string:
    // int len = 0;
    // for (int i = 0; s[i] != 0; i++)
    //     len++;
    // cout<<"Length of string is: "<<len;

    // Changing UPPER to lower case:
    // for (int i = 0; s[i] != 0; i++)
    //     s[i] += 32;
    // cout<<"String is: "<<s;

    //Checking and changing to uppercase:
    // for (int i = 0; s[i] != 0; i++)
    // {
    //     if (s[i] >= 97 && s[i] <= 122)
    //         s[i] += -32;
    // }
    // cout<<s;

    int words = 1, vowels = 0, consonants = 0, irregular = 0;
    for(int i = 0; s[i] != 0; i++)
    {
        if(s[i] == ' ' && s[i+1] != ' ')
            words++;
        else if(!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && s[i] != 32)
            irregular++;
        else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowels++;
        else
            consonants++;
    }
    cout<<"Words: "<<words<<", vowels: "<<vowels<<", consonants: "<<consonants<<" and irregulars: "<<irregular;
    

    // int usrname = s.find('@');
    // cout<<s.substr(0,usrname);

    cout<<endl<<endl;
return 0;
}