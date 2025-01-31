#include<SFML/Graphics.hpp>
#include<unistd.h>
#include<iostream>
using namespace sf;
using namespace std;

void display(int s[], int size){
    cout<<endl;
    for(int i=0; i<size*size; i++)
    {
        if(s[i] == 1) cout<<'X';
        else if(s[i] == 2) cout<<'O';
        else cout<<'#';
        if(i%size == size-1) cout<<endl;
    }
    cout<<endl;
}

bool play(int game[], int size, int player, int choice){
    if(choice>=0 && choice<size*size)
    {
        if(game[choice] == 0)
        {
            game[choice] = player;
            return true;
        }
        else if(choice<0 || choice>(size*size)-1){
            cout<<"Invalid, try again.";
            return false;
        }
        else
        {
            cout<<"Already filled, try again.";
            return false;
        }
    }
    return false;
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


int main(){
    int size = 3, players = 2;
    int state[size*size] = {};
    int player = 1;


    int rown, coln, crown, ccoln;
    float rf = 0.8;
    Vector2f pos, offset;

    RenderWindow TTT(VideoMode(500,500), "Tic Tac Toe");
    TTT.setPosition(Vector2i(500, 100));

    while(TTT.isOpen())
    {
        TTT.clear(Color::White);
        int wizx = TTT.getSize().x;
        int wizy = TTT.getSize().y;
        wizx /= size;
        wizy /= size;

        RectangleShape hline(Vector2f(wizx, 2.0f));
        hline.setFillColor(Color::Black);
        RectangleShape vline(Vector2f(2.0f, wizy));
        vline.setFillColor(Color::Black);

        RectangleShape X(Vector2f(rf*(wizx/(size+1)), rf*(wizy/(size+1))));
        X.setOrigin(Vector2f(rf*((wizx/(size+1))/2), rf*((wizy/(size+1))/2)));
        X.setFillColor(Color::Blue);
        // X.setPosition(pos);

        CircleShape O(min(rf*(wizx/(2*size)), rf*(wizy/(2*size))));
        O.setFillColor(Color::Transparent);
        O.setOrigin(Vector2f(min(rf*(wizx/(2*size)), rf*(wizy/(2*size))), min(rf*(wizx/(2*size)), rf*(wizy/(2*size)))));
        O.setOutlineColor(Color::Red);
        O.setOutlineThickness(2.0f);
        // O.setPosition(pos);


        Event event;
        while(TTT.pollEvent(event))
        {
            switch(event.type){
                case Event::Closed:
                TTT.close();
                break;

                case Event::MouseButtonPressed:
                crown = ((event.mouseButton.y-offset.y)/(wizy/size))+1;
                ccoln = ((event.mouseButton.x-offset.x)/(wizx/size))+1;

                if(play(state, size, player, (size*(crown-1)) + (ccoln-1))){
                    rown = crown;
                    coln = ccoln;
                    offset.x = (coln-1)*((TTT.getSize().x)/3);
                    offset.y = (rown-1)*((TTT.getSize().y)/3);
                    if(wincheck(state, size)){
                        cout<<"Player "<<player<<" won.";
                        TTT.close();
                    }
                    player = (player%players) + 1;
                }
                break;

                case Event::Resized:
                FloatRect visibleA(0,0, event.size.width, event.size.height);
                TTT.setView(View(visibleA));

                // pos = Vector2f(coln*(event.size.width/size)-(event.size.width/(2*size)), rown*(event.size.height/size)-(event.size.height/(2*size)));
                break;
            }
        }
        // Set position of grid lines
        for(int i = 1; i<size; i++)
        {
            hline.setPosition(Vector2f(0.0f, i*(wizy/size)));
            hline.move(offset);
            TTT.draw(hline);
            vline.setPosition(Vector2f(i*(wizx/size), 0.0f));
            vline.move(offset);
            TTT.draw(vline);
        }

        // Set position of player tokens
        for(int i=0; i<size*size; i++)
        {
            pos = Vector2f(((i%size)+1)*(wizx/size)-(wizx/(2*size)), ((i/size)+1)*(wizy/size)-(wizy/(2*size)));
            X.setPosition(pos);
            O.setPosition(pos);
            X.move(offset);
            O.move(offset);
            if(state[i] == 1) TTT.draw(X);
            else if(state[i] == 2) TTT.draw(O);
        }

        TTT.display();
    }

    cout<<endl<<endl;
return 0;
}