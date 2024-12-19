#include<iostream>
using namespace std;

void displayGame(char** grid, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout<<grid[i][j];
        }
        cout<<endl;

    }
}
bool is_rcvalid(int r, int c, int size){
    return (r>0 && r<=size && c>0 && c<=size);
}

bool play(char** grid, int size, int player, char token, char def)
{
    int i, j;
    cout<<"Enter row and column number for player "<<player<<": ";
    cin>>i>>j;

    if(is_rcvalid(i, j, size))
    {
        if(grid[i-1][j-1] == def)
            grid[i-1][j-1] = token;
        else
        {
            cout<<"Already filled, enter another."<<endl<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Invalid, try again."<<endl<<endl;
        return false;
    }
    return true;
}

bool winCheck(char** grid, int size, char def){
    bool win;
    // First Diagonal Check
    if(grid[0][0] != def){
        win = true;
        for(int i = 0; i<size; i++){
            if(grid[i][i]!=grid[0][0]){
                win = false;
            }
        }
        if(win)
            return win;
    }
    // Second Diagonal Check
    if(grid[0][size-1] != def){
        win = true;
        for(int i=0; i<size; i++){
            if(grid[i][size-i-1]!=grid[0][size-1]){
                win = false;
            }
        }
        if(win)
            return win;
    }
    // Checking rows
    for(int i=0; i<size; i++){
        if(grid[i][0] != def){
            win = true;
            for(int j=0; j<size; j++){
                if(grid[i][j]!=grid[i][0]){
                    win = false;
                }
            }
            if(win)
                return win;
        }
    }
    // Checking columns
    for(int i=0; i<size; i++){
        if(grid[0][i]!=def){
            win = true;
            for(int j=0; j<size; j++){
                if(grid[j][i]!=grid[0][i]){
                    win = false;
                }
            }
            if(win)
                return win;
        }
    }
    return false;
}

int main(){
    cout<<endl;
    int size, players;
    char def;
    while(true)
    {
    cout<<"Enter size of board: "; cin>>size;
    if(size<=2){cout<<"Error, please enter a size greater than 2."; continue;}

    cout<<"Enter number of players: "; cin>>players;
    if(players<=1){cout<<"Error, players cannot be less than 2."; continue;}
    
    cout<<"Enter default token(which represents the board): "; cin>>def;
    break;
    }
    char* token = new char[players+1];
    token[0] = {def};
    for(int i=1; i<=players; i++){
        cout<<"Enter token for player "<<i<<": ";
        cin>>token[i];
    }
    char** grid = new char*[size];
    for(int i = 0; i<size; i++)
        grid[i] = new char[size];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            grid[i][j] = token[0];
        }
    }
    displayGame(grid, size);

    int player = 1;
    while(true)
    {
        bool update = play(grid, size, player, token[player], token[0]);
        displayGame(grid, size);

        if(winCheck(grid, size, token[0])){
            cout<<"Player "<<player<<" won.";
            break;
        }
        else if(update){
            player = (player%players)+1;
            bool tie = true;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    if(grid[i][j] == token[0])
                        tie = false;
                }
            }
            if(tie){
            cout<<"Tie";
            break;
            }
        }
    }

    for(int i = 0; i<size; i++)
        delete[] grid[i];
    delete[] grid;

    cout<<endl<<endl;
return 0;
}