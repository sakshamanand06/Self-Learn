// Displaying the game and detecting region of mouseclick

#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

int main(){

    RenderWindow game(VideoMode(600, 600), "Tic Ta Tac");
    game.setPosition(Vector2i(500, 200));
    // o - outer, i - inner
    
    float ogridt = 4.0f, igridt = 2.0f; // thickness
    int order = 5; // order of tic tac toe matrix
    int index, indey;
    int ondex, ondey;
    
    // Colors
    Color obg(10, 10, 40, 255); // Dark Midnight Blue
    Color ibg(112, 128, 144, 255); // Slate Gray
    Color ogrid(210, 180, 80, 255); // Pale Gold
    Color igrid(178, 34, 34, 255); // Firebrick

    RectangleShape ogridlines(Vector2f(game.getSize().x, ogridt));
    ogridlines.setFillColor(ogrid);
    
    RectangleShape board(Vector2f(100,100));
    board.setFillColor(ibg);
    
    RectangleShape igridlines(Vector2f(board.getSize().x, igridt));
    igridlines.setFillColor(igrid);

    Vector2u win_size;
    Vector2f offset;

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

                ondex = interacted.mouseButton.y/(win_size.y/order);
                ondey = interacted.mouseButton.x/(win_size.x/order);

                index = int(interacted.mouseButton.y - offset.y - ((ondex)*(win_size.y/order)));
                index = (index>=0 ? index/int(board.getSize().y/order) : -1);
                indey = int(interacted.mouseButton.x - offset.x - ((ondey)*(win_size.x/order)));
                indey = (indey>=0 ? indey/int(board.getSize().x/order) : -1);

                if((index>=0 && index < order) && (indey>=0 && indey < order)) cout<<"("<<ondex<<", "<<ondey<<") -> "<<index<<", "<<indey<<endl;

                break;

                case Event::Resized:
                View visibleA(FloatRect(0,0, interacted.size.width, interacted.size.height));
                game.setView(visibleA);
                break;

            }
        }

        for(int i=0; i<order*order; i++){
            board.setSize(Vector2f(win_size.x/(order+1), win_size.y/(order+1)));
            board.setPosition(Vector2f((i%order)*(win_size.x/order), (i/order)*(win_size.y/order)));

            // for first column center without gridlines
            if(i%order == 0) offset = Vector2f((win_size.x/order - board.getSize().x)/2, (win_size.y/order - board.getSize().y)/2);
            // for rest center after gridlines
            else offset = Vector2f((win_size.x/order - board.getSize().x + ogridt)/2, (win_size.y/order - board.getSize().y + ogridt)/2);

            board.move(offset);
            game.draw(board);

            for(int j=1; j<order; j++){
                // Horizontal grid in boards
                igridlines.setPosition(Vector2f(board.getPosition().x, board.getPosition().y + (j*(board.getSize().y/order))));
                igridlines.setSize(Vector2f(board.getSize().x, igridt));
                game.draw(igridlines);

                // Vertical grid in boards
                igridlines.setPosition(Vector2f(board.getPosition().x + (j*(board.getSize().x/order)), board.getPosition().y));
                igridlines.setSize(Vector2f(igridt, board.getSize().y));
                game.draw(igridlines);
            }
        }
        for(int i = 1; i<order; i++)
        {
            ogridlines.setSize(Vector2f(win_size.x, ogridt));
            ogridlines.setPosition(Vector2f(0.0f, i*(win_size.y/order)));
            game.draw(ogridlines);
            ogridlines.setSize(Vector2f(ogridt, win_size.y));
            ogridlines.setPosition(Vector2f(i*(win_size.x/order), 0.0f));
            game.draw(ogridlines);
        }

        game.display();
    }
}
