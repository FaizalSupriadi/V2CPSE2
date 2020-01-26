#include <iostream>
#include <fstream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "image.hpp"
#include "drawable.hpp"
#include "action.hpp"
#include "command.hpp"
#include "gameSetup.hpp"

int main( int argc, char *argv[] ){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	auto roster = image( "roster.png", sf::Vector2f{30,50}, sf::Vector2f{0.6,0.6} );
	auto undoPic = image( "undo.png", sf::Vector2f{470,200}, sf::Vector2f{0.1,0.1} );
	std::array< image *,9 > objects;	
	std::vector<command* > undoList;
	makeBoard(objects);
	bool butterEgg=1; // decides whether the butter or egg needs to be drawn

action actions[] = {
		// Undo
      action( sf::Mouse::Left,  [&](){ if(undoPic.contains(window.mapPixelToCoords(sf::Mouse::getPosition( window )))  && undoList.size() > 0){ 
          undoList.back()->undo(); undoList.pop_back();  if(butterEgg){butterEgg = 0;}else{butterEgg = 1;}} }),
      // Add to undo list
      action( sf::Mouse::Left,  [&](){ for(auto & p : objects){ if(p->contains( window.mapPixelToCoords(sf::Mouse::getPosition( window )))&& p->getSprite() == "black.png"){ 
          if(butterEgg){ undoList.push_back(new command(p, "egg.png")); butterEgg = 0; }else{ undoList.push_back(new command(p, "butter.png")); butterEgg = 1; } undoList.back()->execute(); } } }),
  };
		
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		roster.draw(window);
		undoPic.draw(window);
		for( auto & p : objects ){
        	p->draw( window );
      	}
		

		window.display();

		if(gameCheck(objects)){        
			makeBoard(objects);               
       		butterEgg = 0;
        	undoList.clear();                                             
			                       
      	}

		//sf::sleep( sf::milliseconds( 10 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;

}