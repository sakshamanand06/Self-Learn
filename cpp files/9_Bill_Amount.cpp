#include<iostream>
using namespace std;

int main(){
    int total_amount, final_amount;
    float discount;
    cout<<"Total Amount: ";
    cin>>total_amount;
    
    if(total_amount>0 && total_amount<100)
        discount = 0;
    else if(total_amount>=100 && total_amount<500)
        discount = 10;
    else if(total_amount>=500)
        discount = 20;
    else
        cout<<"Invalid amount.";
    
    if(discount == 0 || discount == 10 || discount == 20)
    {
        final_amount = total_amount - (total_amount * (discount/100));
        cout<<"Your discount is: "<<discount<<"%\n"<<"Your final amount is: "<<final_amount;
    }
    cout<<endl<<endl;
return 0;
}