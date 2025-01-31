#include<iostream>
using namespace std;

void display(int s[], int size){
    for(int i=0; i<size*size; i++)
    {
        if(s[i] == 1) cout<<'X';
        else if(s[i] == 2) cout<<'O';
        else cout<<'#';
        if(i%size == size-1) cout<<endl;
    }
}

bool wincheck(int s[], int size){
    bool chek = false;

    // Row check
    for(int r = 0; r<size*size; r += size)
    {
        for(int i=1; i<size; i++)
        {
            if(s[r+i] == s[r] && s[r] != 0) chek = true;
            else{
                chek = false;
                break;
            }
        }
        if(chek){
            display(s, size);
            return chek;
        }
    }

    // Column check
    for(int c = 0; c<size; c++)
    {
        for(int i=1; i<size; i++)
        {
            if(s[c+(i*size)] == s[c] && s[c] != 0) chek = true;
            else{
                chek = false;
                break;
            }
        }
        if(chek){
            display(s, size);
            return chek;
        }
    }

    // First Diagonal Check
    for(int i=0; i<size*size; i += size+1){
        if(s[i] == s[0] && s[0] != 0) chek = true;
        else
        {
            chek = false;
            break;
        }
    }
    if(chek){
        display(s, size);
        return chek;
    }
    // Second Diagonal Check
    for(int i=2; i<=size; i++){
        if(s[i*(size-1)] == s[size-1] && s[size-1] != 0) chek = true;
        else{
            chek = false;
            break;
        }
    }
    if(chek){
        display(s, size);
        return chek;
    }
    return chek;
}

int play(int game[], int size, int players, int& player, int choice){
    // 0 is some error occured
    // 1 is move played successfully
    // 2 is game won
    if(choice<0 || choice>(size*size)-1){ // checks choice validity
        cout<<"Invalid, try again."<<endl;
        return 0;
    }
    else if(game[choice] == 0) // checks move validity
    {
        game[choice] = player;
        if(wincheck(game, size)){
            cout<<"Player "<<player<<" won."<<endl;
            return 2;
        }
        player = (player%players)+1;
        return 1;
    }
    else
    {
        cout<<"Already filled, try again."<<endl;
        return 0;
    }
}

void func(int game[]){
    for(int i = 0; i<3; i++){
        cin>>game[i];
    }
}

int main(){
    int size = 3, choice, player = 1, players = 2, tiecount = 0;
    int state[size*size] = {};
    int playy, won = 0;
    cout<<endl;

    while(true)
    {
        display(state, size);
        cin>>choice;
        playy = play(state, size, players, player, choice);
        switch(playy){
        case 0:
        continue;

        case 1:
        tiecount++;
        break;

        case 2:
        won = 1;
        break;        
        }
        if(won) break;
        
        if(tiecount == size*size){
            display(state, size);
            cout<<"Game tied.";
            break;
        }
    }
    cout<<endl<<endl;
return 0;
}