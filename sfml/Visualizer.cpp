#include<iostream>
#include<SFML/Graphics.hpp>
#include<random>
#include<unistd.h>

int main(){
    // Random number generation
    std::random_device rd;
    std::mt19937 gen(rd());
    // std::mt19937 gen(42);
    std::uniform_int_distribution<> dist(50,400);
    int size = 150;
    int arr[size];
    for(int i=0; i<size; i++) arr[i] = dist(gen);
    // for(int i=0; i<size; i++) std::cout<<arr[i]<<" ";


    sf::RenderWindow visualizer(sf::VideoMode(640, 480), "Bubble Sort Visualiser");
    visualizer.setPosition(sf::Vector2i(400,200));
    sf::Event interacted;

    sf::RectangleShape rect[size];
    int i = -1, j=-1;
    bool sort = false;
    while(visualizer.isOpen()){
        visualizer.clear(sf::Color::Black);

        while(visualizer.pollEvent(interacted)){
            switch(interacted.type){
                case sf::Event::Closed:
                std::cout<<'\n';
                // for(int i=0; i<size; i++) std::cout<<arr[i]<<' ';
                visualizer.close();
                break;

                case sf::Event::MouseLeft:
                sort = true;
                break;
                
                case sf::Event::Resized:
                sf::View visibleA(sf::FloatRect(0,0, interacted.size.width, interacted.size.height));
                visualizer.setView(visibleA);
                break;
            }
        }
        if(i!=size-1 && sort){
            if(i<size-1) i++;
            if(j<size-i) j++;
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            if(j!=size-i-1) i--;
            else j=-1;
        }
        // for(int l=0; l<size; l++) std::cout<<arr[l]<<" ";
        // std::cout<<std::endl;
        for(int k=0; k<size; k++){
            rect[k].setSize(sf::Vector2f(visualizer.getSize().x/size,float(arr[k])));
            // rect[k].setFillColor(sf::Color(0, 0, 0, 255));
            rect[k].setFillColor(sf::Color::White);
            rect[k].setPosition(sf::Vector2f(k*visualizer.getSize().x/size,visualizer.getSize().y-float(arr[k])));
        }
        for(int k=0; k<size;k++) visualizer.draw(rect[k]);
        visualizer.display();
        // sleep(1);
        // for(int i=0; i<size-1; i++){
        //     for(int j=0; j<size-i-1; j++){
        //         if(arr[j]>arr[j+1]){
        //             int temp;
        //             temp = arr[j];
        //             arr[j] = arr[j+1];
        //             arr[j+1] = temp;
        //             rect[j].setFillColor(sf::Color::Red);
        //             for(int k=0; k<size; k++){
        //                 rect[k].setSize(sf::Vector2f(visualizer.getSize().x/size,float(arr[k])));
        //                 // rect[k].setFillColor(sf::Color(0, 0, 0, 255));
        //                 rect[k].setFillColor(sf::Color::White);
        //                 rect[k].setPosition(sf::Vector2f(k*visualizer.getSize().x/size,visualizer.getSize().y-float(arr[k])));
        //             }
        //             for(int k=0; k<size;k++) visualizer.draw(rect[k]);
        //             visualizer.display();
        //             visualizer.clear(sf::Color::Black);
        //             // sleep(1);
        //         }
        //     }
        // }
        // for(int i=0; i<size;i++) visualizer.draw(rect[i]);
        // visualizer.display();
    }

}