// Currently last game win check function with pl is only made for 2 players

#include<SFML/Graphics.hpp>
#include<unistd.h>
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
        if(chek) return chek;
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
        if(chek) return chek;
    }

    // First Diagonal Check
    for(int i=0; i<size*size; i += size+1)
    {
        if(gamestate[i] == gamestate[0] && gamestate[0] != 0) chek = true;
        else{
            chek = false;
            break;
        }
    }
    if(chek) return chek;
    // Second Diagonal Check
    for(int i=2; i<=size; i++)
    {
        if(gamestate[i*(size-1)] == gamestate[size-1] && gamestate[size-1] != 0) chek = true;
        else{
            chek = false;
            break;
        }
    }
    return chek;
}

int main()
{
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

    bool menu = true;
    // menu=false;

    reset:
    int player = 1; // first player(1 means X)
    int can_play = -1; // can play anywhere in start

    // declaring and initialising all values of the 2d gamestate array
    int* gamestate[order*order];
    for(int i=0; i<order*order; i++){
        gamestate[i] = new int[order*order+2];
        for(int j=0; j<order*order+2; j++)
            gamestate[i][j] = 0;
    }
    // second last index is for storing game state - win(player no.), tie(-1) or ongoing(0)
    // last index is to store no. of valid moves for checking if game is tied or not
    int plwins[players+1]; // no. of ties(plwins[0]) and player wins[1-players]
    for(int i=0; i<=players; i++)
        plwins[i] = 0;
    int gfin = 0; // no. of games finished
    int mx = 0; // max no. in the plwins
    int mxi = 0; // index of mx
    bool rep; // if mx repeats
    // Colors
    Color obg(10, 10, 40, 255); // Dark Midnight Blue // outer game background
    Color ibg(112, 128, 144, 255); // Slate Gray // inner board background
    // Color ibg(Color::Transparent);
    Color ogrid(210, 180, 80, 255); // Pale Gold // outer gridlines
    Color igrid(178, 34, 34, 255); // Firebrick // inner gridlines

    // Game graphics
    RectangleShape ogridlines(Vector2f(game.getSize().x, ogridt));
    ogridlines.setFillColor(ogrid);
    
    RectangleShape board(Vector2f(100,100));
    board.setFillColor(ibg);
    RectangleShape shadow(board.getSize());
    shadow.setFillColor(Color::White);
    
    RectangleShape igridlines(Vector2f(board.getSize().x, igridt));
    igridlines.setFillColor(igrid);

    Texture t;
    if(!t.loadFromFile("Mushroom.png")) cout<<"error loading texture";

    RectangleShape X(Vector2f(5.0f, 5.0f));
    X.setTexture(&t);
    X.setFillColor(Color::Red);
    RectangleShape O(Vector2f(5.0f, 5.0f));
    O.setTexture(&t);
    O.setFillColor(Color::Blue);
    RectangleShape P(Vector2f(5.0f, 5.0f));
    P.setTexture(&t);
    P.setFillColor(Color::Green);
    RectangleShape D(Vector2f(5.0f, 5.0f));
    D.setFillColor(Color(112, 128, 144, 255));
    // CircleShape O(5.0f);
    // O.setTexture(&t);
    // O.setFillColor(Color::Red);

    RectangleShape tokens[] = {D, X, O, P};

    // < for menu
    RectangleShape resume(Vector2f(200.0f, 50.0f));
    resume.setOrigin(Vector2f(resume.getLocalBounds().width/2, resume.getLocalBounds().top/2));
    resume.setPosition(Vector2f(game.getSize().x/2, game.getSize().y/2));

    RectangleShape play(Vector2f(200.0f, 50.0f));
    play.setOrigin(Vector2f(play.getLocalBounds().width/2, play.getLocalBounds().top/2));
    play.setPosition(Vector2f(game.getSize().x/2, game.getSize().y/2+100.0));

    // for menu >

    Font familyft;

    if(!familyft.loadFromFile("Purisa-Bold.ttf"))
    cout<<"error"<<endl;

    Text state;
    state.setFont(familyft);
    state.setFillColor(Color::Red);


    Text playt;
    playt.setFont(familyft);
    playt.setString("Play");
    playt.setFillColor(Color::Black);
    Text resumet;
    resumet.setFont(familyft);
    resumet.setString("Continue");
    resumet.setFillColor(Color::Black);


    Text pl;
    bool won = false;
    pl.setFont(familyft);
    pl.setFillColor(Color::Cyan);
    string p1, p2, p3;

    Vector2u win_size; // windows size
    Vector2f offset, board_size;


    menuing:
    if(menu){
    while(game.isOpen())
    {
        game.clear(ibg);
        Event minu;
        while(game.pollEvent(minu)){
            switch(minu.type){
                case Event::MouseButtonPressed:
                if(play.getGlobalBounds().contains(Vector2f(Mouse::getPosition(game)))){
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        menu = false;
                        goto reset;
                    }
                }
                else if(resume.getGlobalBounds().contains(Vector2f(Mouse::getPosition(game)))){
                    if(Mouse::isButtonPressed(Mouse::Left)){
                        goto gaming;
                    }
                }
                break;
                
                case Event::MouseMoved:
                if(play.getGlobalBounds().contains(Vector2f(Mouse::getPosition(game))))
                        play.setFillColor(Color::Red);
                else if(resume.getGlobalBounds().contains(Vector2f(Mouse::getPosition(game))))
                        resume.setFillColor(Color::Red);
                else{
                    play.setFillColor(Color::White);
                    resume.setFillColor(Color::White);
                }
                break;
                
                case Event::Closed:
                game.close();
                break;
                case Event::Resized:
                View visibleA(FloatRect(0,0, minu.size.width, minu.size.height));
                game.setView(visibleA);
                break;
            }
        }
        
        // play.setPosition(Vector2f(10.0, 10.0));
        // play.setSize(Vector2f(0.5*game.getSize().x, 0.5*game.getSize().y));
        playt.setOrigin(playt.getLocalBounds().getSize().x/2, playt.getLocalBounds().getSize().y/2);
        playt.setPosition(Vector2f(play.getGlobalBounds().getPosition().x + play.getLocalBounds().getSize().x/2.0, play.getGlobalBounds().getPosition().y + play.getLocalBounds().getSize().y/2.0));
        resumet.setOrigin(resumet.getLocalBounds().getSize().x/2, resumet.getLocalBounds().getSize().y/2);
        resumet.setPosition(Vector2f(resume.getGlobalBounds().getPosition().x + resume.getLocalBounds().getSize().x/2.0, resume.getGlobalBounds().getPosition().y + resume.getLocalBounds().getSize().y/2.0));

        game.draw(play);
        game.draw(resume);
        game.draw(playt);
        game.draw(resumet);
        game.display();
        // cout<<Mouse::getPosition(game).x<<endl;
    }
    }
    else{
    gaming:
    while(game.isOpen())
    {
        game.clear(obg);
        win_size = game.getSize(); // to only call getSize once for optimization

        Event interacted;
        while(game.pollEvent(interacted))
        {
            switch(interacted.type)
            {
                case Event::Closed:
                game.close();
                break;

                case Event::MouseButtonPressed:
                if(Mouse::isButtonPressed(Mouse::Left))
                {
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

                    // inside inner box?
                    if((index >= 0 && index<order) && (indey >= 0 && indey<order))
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
                                    gamestate[ondexy][indexy] = player;
                                    if(wincheck(gamestate[ondexy], order))
                                    {
                                        // display(gamestate[ondexy], order);
                                        // cout<<"Player "<<player<<" won."<<endl;
                                        gamestate[ondexy][order*order] = player;
                                        plwins[player]++; gfin++;
                                    }
                                    player = (player%players)+1; // next player
                                    
                                    // Tie check
                                    if(++gamestate[ondexy][order*order+1] == order*order)
                                    if(Mouse::isButtonPressed(Mouse::Middle)){
                                        // display(gamestate[ondexy], order);
                                        cout<<"Tied"<<endl;
                                        gamestate[ondexy][order*order] = -1;
                                        plwins[0]++; gfin++;
                                    }
                                    // free reign if next move's outer box is finished
                                    if(gamestate[indexy][order*order]) can_play = -1;
                                    // locked choice if its not
                                    else can_play = indexy;
                                }
                            }
                        }
                        else // no free reign
                        {
                            if(ondexy == can_play) // when no free reign, inside correct outer box?
                            goto valid_outer_box;
                            else cout<<"Locked board."<<endl;
                        }
                    }
                    else cout<<"Outside board"<<endl;
                }
                else if(Mouse::isButtonPressed(Mouse::Right))
                {
                    for(int i=0; i<order*order; i++) delete[] gamestate[i];
                    ++order;
                    menu = false;
                    goto reset;
                }
                else{
                    menu = true;
                    goto menuing;
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
            board_size = board.getSize();

            // for second columns and forward center after gridlines
            if(i%order) offset = Vector2f((win_size.x/order - board_size.x + ogridt)/2, (win_size.y/order - board_size.y + ogridt)/2);
            // for first column center without gridlines
            else offset = Vector2f((win_size.x/order - board_size.x)/2, (win_size.y/order - board_size.y)/2);

            board.move(offset);
            shadow.setSize(board_size + Vector2f(10.0f, 10.0f));
            shadow.setPosition(board.getPosition());
            if(can_play == -1) game.draw(shadow);
            else if(i == can_play) game.draw(shadow);
            
            game.draw(board);

            for(int j=1; j<order; j++)
            {
                // Horizontal grid in boards
                igridlines.setPosition(board.getPosition().x, board.getPosition().y + (j*(board_size.y/order)));
                igridlines.setSize(Vector2f(board_size.x, igridt));
                game.draw(igridlines);

                // Vertical grid in boards
                igridlines.setPosition(board.getPosition().x + (j*(board_size.x/order)), board.getPosition().y);
                igridlines.setSize(Vector2f(igridt, board_size.y));
                game.draw(igridlines);
            }

            for(int j=0; j<order*order;j++)
            {
                // if(gamestate[i][j] != 0)
                // {
                    siz = min(board_size.x/order - 5.0f, board_size.y/order - 5.0f);
                    tokens[gamestate[i][j]].setSize(Vector2f(siz, siz));
                    tokens[gamestate[i][j]].setPosition(((i%order)*(game.getSize().x/order)) + ((j%order)*(board_size.x/order)), ((i/order)*(game.getSize().y/order)) + ((j/order)*(board_size.y/order)));
                    tokens[gamestate[i][j]].move(offset);
                    // Centering inside the smallest box
                    tokens[gamestate[i][j]].setOrigin(tokens[gamestate[i][j]].getSize().x/2, tokens[gamestate[i][j]].getSize().y/2);
                    if(j%order) tokens[gamestate[i][j]].move((board_size.x/order+igridt)/2, (board_size.y/order+igridt)/2);
                    else tokens[gamestate[i][j]].move((board_size.x/order)/2, (board_size.y/order)/2);
                    game.draw(tokens[gamestate[i][j]]);
                // }
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
        state.setString(to_string(player));
        game.draw(state);
        
        if(gfin == order*order)
        {
            for(int i = 1; i<=players; i++)
            {
                if(mx<plwins[i])
                {
                    mx = plwins[i];
                    mxi = i;
                    rep = false;
                }
                else if(mx == plwins[i]) rep = true;
            }
            p1 = "Player ";
            p2 = to_string(mxi);
            p3 = " Won";
            pl.setString(p1+p2+p3);
            if(rep) pl.setString("Its a Draw");

            pl.setCharacterSize(50);
            pl.setOrigin(pl.getLocalBounds().width/2, pl.getLocalBounds().height/2);
            pl.setPosition(game.getSize().x/2, game.getSize().y/2);

            game.clear(Color::Black);
            game.draw(pl);
            game.display();
            sleep(5);
            game.close();
        }
        game.display();
    }
    }
    for(int i=0; i<order*order; i++) delete []gamestate[i];

    return 0;
}