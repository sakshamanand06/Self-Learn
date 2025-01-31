#include<SFML/Graphics.hpp>
#include<unistd.h>
#include<iostream>
using namespace sf;
using namespace std;

int main(){
    RenderWindow TTT(VideoMode(300,300), "Bouncing mushroom.");
    Texture mushroomTexture;
    mushroomTexture.loadFromFile("Mushroom.png");

    Sprite mushroom(mushroomTexture);
    Vector2u size = mushroomTexture.getSize();

    mushroom.setOrigin(size.x / 2, size.y / 2);
    Vector2f increment(1.0f, 0.1f);
    int temp = 0, count = 0;
    while(TTT.isOpen())
    {
        int wizx = TTT.getSize().x;
        int wizy = TTT.getSize().y;

        Event event;
        while(TTT.pollEvent(event))
        {
            switch(event.type){
                case Event::Closed:
                TTT.close();
                break;

                case Event::MouseButtonPressed:
                if(Mouse::getPosition(TTT).y < wizy/3) cout<<"Top ";
                else if((Mouse::getPosition(TTT).y > wizy/3) && (Mouse::getPosition(TTT).y < (2*wizy)/3)) cout<<"Middle ";
                else if(Mouse::getPosition(TTT).y > (2*wizy)/3) cout<<"Bottom ";

                if(Mouse::getPosition(TTT).x < wizx/3) cout<<"Left"<<endl;
                else if((Mouse::getPosition(TTT).x > wizx/3) && (Mouse::getPosition(TTT).x < (2*wizx)/3)) cout<<"Middle"<<endl;
                else if(Mouse::getPosition(TTT).x > (2*wizx)/3) cout<<"Right"<<endl;
                break;

                case Event::Resized:
                FloatRect visibleA(0,0, event.size.width, event.size.height);
                TTT.setView(View(visibleA));
                break;
            }
        }

        if((mushroom.getPosition().x + (size.x / 2) > wizx && increment.x > 0) || (mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
        increment.x = -increment.x;

        if((mushroom.getPosition().y + (size.y / 2) > wizy && increment.y > 0) || (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
        increment.y = -increment.y;

        mushroom.setPosition(mushroom.getPosition() + increment);
        TTT.clear(Color::White);

        RectangleShape rect1(Vector2f(wizx/3, wizy));
        rect1.setFillColor(Color::Transparent);
        rect1.setOrigin(wizx/6, wizy/2);
        rect1.setPosition(Vector2f(wizx/2, wizy/2));
        rect1.setOutlineColor(Color::Black);
        rect1.setOutlineThickness(5.0f);
        TTT.draw(rect1);
        rect1.setSize(Vector2f(wizx, wizy/3));
        rect1.setOrigin(wizx/2, wizy/6);
        TTT.draw(rect1);

        TTT.draw(mushroom);
        TTT.display();
    }
}