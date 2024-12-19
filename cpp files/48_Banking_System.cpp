

// DO AFTER LEARNING LIL DSA



#include<iostream>
using namespace std;

class Account{
private:
    int bal, accno;
    string f_name, l_name;
    static int accounts;
public:
    
};
int Account::accounts = 1;

void menu(){
    int choice;
        cout<<"1. Open an Account"<<endl;
        cout<<"2. Balance Enquiry"<<endl;
        cout<<"3. Deposit"<<endl;
        cout<<"4. Withdraw"<<endl;
        cout<<"5. Close an Account"<<endl;
        cout<<"6. Show all Accounts"<<endl;
        cout<<"7. Quit"<<endl<<endl;
        cout<<"Enter an option: "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"lol"<<endl;
            menu();
            break;

            case 2:

            case 7:
            break;

        }

}

int main(){
    menu();
    // while(1){
    //     if(choice == 1){

    //     }
    //     else if(choice == 2){

    //     }
    //     else if(choice == 3){

    //     }
    //     else if(choice == 4){

    //     }
    //     else if(choice == 5){

    //     }
    //     else if(choice == 6){

    //     }
    //     else if(choice == 7){

    //     }
    //     else{
    //         cout<<"Invalid choice.";
    //     }
    // }

    cout<<endl<<endl;
return 0;
}