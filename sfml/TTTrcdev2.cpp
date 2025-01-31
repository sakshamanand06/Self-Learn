// Added X/O and player 3, positioning and centering
// Added game logic for inner games and lock/unlock mechanism for the boards

#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

void display(int gamestate[], int size){
    for(int i=0; i<size*size; i++)
    {
        if(gamestate[i] == 0) cout<<'#';
        else if(gamestate[i] == 1) cout<<'X';
        else if(gamestate[i] == 2) cout<<'O';
        else cout<<gamestate[i];
        if(i%size == size-1) cout<<endl;
    }
}

bool wincheck(int gamestate[], int size){
    bool chek = false;

    // Row check
    for(int r = 0; r<size*size; r += size)
    {
        for(int i=1; i<size; i++)
        {
            if(gamestate[r+i] == gamestate[r] && gamestate[r] != 0) chek = true;
            else{
                chek = false;
                break;
            }
        }
        if(chek){
            // display(gamestate, size);
            return chek;
        }
    }

    // Column check
    for(int c = 0; c<size; c++)
    {
        for(int i=1; i<size; i++)
        {
            if(gamestate[c+(i*size)] == gamestate[c] && gamestate[c] != 0) chek = true;
            else{
                chek = false;
                break;
            }
        }
        if(chek){
            // display(gamestate, size);
            return chek;
        }
    }

    // First Diagonal Check
    for(int i=0; i<size*size; i += size+1){
        if(gamestate[i] == gamestate[0] && gamestate[0] != 0) chek = true;
        else
        {
            chek = false;
            break;
        }
    }
    if(chek){
        // display(gamestate, size);
        return chek;
    }
    // Second Diagonal Check
    for(int i=2; i<=size; i++){
        if(gamestate[i*(size-1)] == gamestate[size-1] && gamestate[size-1] != 0) chek = true;
        else{
            chek = false;
            break;
        }
    }
    if(chek){
        // display(gamestate, size);
        return chek;
    }
    return chek;
}

void play(int gamestate[], int size, int players, int& player, int indexy){
    gamestate[indexy] = player;
    if(wincheck(gamestate, size))
    {
        display(gamestate, size);
        cout<<"Player "<<player<<" won."<<endl;
        gamestate[size*size] = player;
        player = (player%players)+1;
        return;
    }
    player = (player%players)+1;
    
    // Tie check
    if(++gamestate[size*size+1] == size*size)
    {
        gamestate[size*size] = -1;
        display(gamestate, size);
        cout<<"Tied"<<endl;
    }
}


int main(){

    RenderWindow game(VideoMode(500, 500), "Tic Tac Tac");
    game.setPosition(Vector2i(500, 200));
    // o - outer, i - inner
    int index, indey, indexy;
    int ondex, ondey, ondexy;

    float ogridt = 4.0f; // thickness of outer gridlines
    float igridt = 2.0f; // thickness of inner gridlines
    int players = 2; // total number of players
    int order = 3; // order of tic tac toe matrix
    float siz;

    reset:
    int player = 1; // first player(1 means X)
    int can_play = -1; // can play anywhere in start

    // declaring and initialising all values of the 2d gamestate array
    int* gamestate[order*order];
    for(int i=0; i<order*order; i++){
        gamestate[i] = new int[order*order+2];
    }
    // second last index is for storing game win(player no.), tie(-1) or ongoing(0)
    // last index is to store no. of valid moves for checking if game is tied or not
    for(int i=0; i<order*order; i++){
        for(int j=0; j<order*order+2; j++)
            gamestate[i][j] = 0;
    }
    // Colors
    Color obg(10, 10, 40, 255); // Dark Midnight Blue // outer game background
    Color ibg(112, 128, 144, 255); // Slate Gray // inner board background
    Color ogrid(210, 180, 80, 255); // Pale Gold // outer gridlines
    Color igrid(178, 34, 34, 255); // Firebrick // inner gridlines

    RectangleShape ogridlines(Vector2f(game.getSize().x, ogridt));
    ogridlines.setFillColor(ogrid);
    
    RectangleShape board(Vector2f(100,100));
    board.setFillColor(ibg);
    RectangleShape shadow(board.getSize());
    shadow.setFillColor(Color::White);
    
    RectangleShape igridlines(Vector2f(board.getSize().x, igridt));
    igridlines.setFillColor(igrid);


    RectangleShape X(Vector2f(5.0f, 5.0f));
    CircleShape O(5.0f);
    O.setFillColor(Color::Red);

    Font familyft;

    if(!familyft.loadFromFile("Purisa-Bold.ttf"))
    cout<<"error"<<endl;

    Text state;
    state.setFont(familyft);
    state.setFillColor(Color::Red);

    Vector2u win_size; // windows size
    Vector2f offset, board_size;

    while(game.isOpen())
    {
        game.clear(obg);
        win_size = game.getSize();

        Event interacted;
        while(game.pollEvent(interacted))
        {
            switch(interacted.type)
            {
                case Event::Closed:
                game.close();
                break;

                case Event::MouseButtonPressed:
                if(Mouse::isButtonPressed(Mouse::Left)){
                // calculating ondex/y
                ondex = interacted.mouseButton.x/(win_size.x/order);
                ondey = interacted.mouseButton.y/(win_size.y/order);
                // calculating index
                index = int(interacted.mouseButton.x - offset.x - ((ondex)*(win_size.x/order)));
                index = (index>=0 ? index/int(board.getSize().x/order) : -1);
                // calculating indey
                indey = int(interacted.mouseButton.y - offset.y - ((ondey)*(win_size.y/order)));
                indey = (indey>=0 ? indey/int(board.getSize().y/order) : -1);
                // calculating i/ondexy
                indexy = (indey*order)+index;
                ondexy = (ondey*order)+ondex;

                if((index >= 0 && index<order) && (indey >= 0 && indey<order))
                // inside inner box?
                {
                    if(can_play == -1) // free reign?
                    {
                        if(gamestate[ondexy][order*order]) // game already finished?
                        cout<<"Game already finished."<<endl;
                        else
                        valid_outer_box:
                        {
                            if(gamestate[ondexy][indexy]) // inner box already filled?
                                cout<<"Already filled box."<<endl;
                            else // a valid move is made
                            {
                                play(gamestate[ondexy], order, players, player, indexy);
                                if(gamestate[indexy][order*order]) // next move's outer box is finished?
                                can_play = -1; // free reign if it is
                                else can_play = indexy; // locked choice if its not
                            }
                        }
                    }
                    else
                    {
                        if(ondexy == can_play) // when no free reign, inside correct outer box?
                        goto valid_outer_box;
                        else cout<<"Locked board."<<endl;
                    }
                }
                else cout<<"Outside board"<<endl;
                }
                else
                {
                    for(int i=0; i<order*order; i++){
                        delete[] gamestate[i];
                    }
                    ++order;
                    goto reset;
                }
                break;

                case Event::Resized:
                View visibleA(FloatRect(0,0, interacted.size.width, interacted.size.height));
                game.setView(visibleA);
                break;
            }
        }

        for(int i=0; i<order*order; i++)
        {
            board.setSize(Vector2f(win_size.x/(order+1), win_size.y/(order+1)));
            board.setPosition((i%order)*(win_size.x/order), (i/order)*(win_size.y/order));
            // board_size = board.getSize();

            // for second columns and forward center after gridlines
            if(i%order) offset = Vector2f((win_size.x/order - board.getSize().x + ogridt)/2, (win_size.y/order - board.getSize().y + ogridt)/2);
            // for first column center without gridlines
            else offset = Vector2f((win_size.x/order - board.getSize().x)/2, (win_size.y/order - board.getSize().y)/2);

            board.move(offset);
            shadow.setSize(board.getSize() + Vector2f(10.0f, 10.0f));
            shadow.setPosition(board.getPosition());
            if(can_play == -1) game.draw(shadow);
            else if(i == can_play) game.draw(shadow);
            
            game.draw(board);

            for(int j=1; j<order; j++)
            {
                // Horizontal grid in boards
                igridlines.setPosition(board.getPosition().x, board.getPosition().y + (j*(board.getSize().y/order)));
                igridlines.setSize(Vector2f(board.getSize().x, igridt));
                game.draw(igridlines);

                // Vertical grid in boards
                igridlines.setPosition(board.getPosition().x + (j*(board.getSize().x/order)), board.getPosition().y);
                igridlines.setSize(Vector2f(igridt, board.getSize().y));
                game.draw(igridlines);
            }

            // X.setSize(Vector2f(board.getSize().x/order - 10.0, board.getSize().y/order - 10.0));

            for(int j=0; j<order*order;j++)
            {
                switch(gamestate[i][j])
                {
                    case 1:
                    siz = min(board.getSize().x/order - 5.0f, board.getSize().y/order - 5.0f);
                    X.setSize(Vector2f(siz, siz));
                    X.setPosition(((i%order)*(game.getSize().x/order)) + ((j%order)*(board.getSize().x/order)), ((i/order)*(game.getSize().y/order)) + ((j/order)*(board.getSize().y/order)));
                    X.move(offset);
                    X.setFillColor(Color::Blue);
                    // Centering inside the smallest box
                    X.setOrigin(X.getSize().x/2, X.getSize().y/2);
                    if(j%order) X.move((board.getSize().x/order+igridt)/2, (board.getSize().y/order+igridt)/2);
                    else X.move((board.getSize().x/order)/2, (board.getSize().y/order)/2);
                    game.draw(X);
                    break;

                    case 2:
                    O.setRadius(min(((board.getSize().x/order)/2) - 2.0f, (board.getSize().y/order)/2) - 2.0f);
                    // At top left corner of inner box's smaller box
                    O.setPosition(((i%order)*(game.getSize().x/order)) + ((j%order)*(board.getSize().x/order)), ((i/order)*(game.getSize().y/order)) + ((j/order)*(board.getSize().y/order)));
                    O.move(offset);
                    // Centering inside the smallest box
                    O.setOrigin(O.getRadius(), O.getRadius());
                    if(j%order) O.move((board.getSize().x/order+igridt)/2, (board.getSize().y/order+igridt)/2);
                    else O.move((board.getSize().x/order)/2, (board.getSize().y/order)/2);
                    game.draw(O);
                    break;
                    case 3:
                    X.setPosition(((i%order)*(game.getSize().x/order)) + ((j%order)*(board.getSize().x/order)), ((i/order)*(game.getSize().y/order)) + ((j/order)*(board.getSize().y/order)));
                    X.move(offset);
                    X.setFillColor(Color::Green);
                    game.draw(X);
                    break;
                }
            }
        }
        for(int i = 1; i<order; i++)
        {
            ogridlines.setSize(Vector2f(win_size.x, ogridt));
            ogridlines.setPosition(0.0f, i*(win_size.y/order));
            game.draw(ogridlines);
            ogridlines.setSize(Vector2f(ogridt, win_size.y));
            ogridlines.setPosition(i*(win_size.x/order), 0.0f);
            game.draw(ogridlines);
        }
        switch(player){
            case 1:
            state.setString("X");
            break;
            case 2:
            state.setString("O");
            break;
            default:
            state.setString(to_string(player));
            break;
        }
        game.draw(state);

        game.display();
    }
    for(int i=0; i<order*order; i++){
        delete[] gamestate[i];
    }
    return 0;
}