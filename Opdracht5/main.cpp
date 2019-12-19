#include <iostream>
#include <fstream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "image.hpp"
#include "drawable.hpp"
#include "action.hpp"
#include "command.hpp"
#include "gameLogic.hpp"

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	auto roster = image( "roster.png", sf::Vector2f{30,70}, sf::Vector2f{0.5,0.5} );
	auto undo = image( "undo.png", sf::Vector2f{470,200}, sf::Vector2f{0.2,0.2} );
	std::vector< drawable * > object;	
	std::vector<command* > steps;
	makeBoard(object);
	bool butterEgg=1;
	action actions[] = {
		action( sf::Mouse::Left, 		[&](){ for( auto & p : object ){ if( p->contains(window.mapPixelToCoords(sf::Mouse::getPosition( window )))&&p->getSpriteInt()){steps.push_back(new command(p));butterEgg = steps.back()->execute(butterEgg);}}}),
		action( sf::Mouse::Left, 		[&](){ if( undo.contains(window.mapPixelToCoords(sf::Mouse::getPosition( window )))&&steps.size()>0){ steps.back()->back();steps.pop_back();butterEgg = !butterEgg;}}),
	};	
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		roster.draw(window);
		undo.draw(window);
		for( auto & p : object ){
        	p->draw( window );
      	}
		if(gameState(object)){        
			steps.clear(); 
			object.clear();
			makeBoard(object);                 
			butterEgg = 0;                        
			                       
      }

		window.display();

		sf::sleep( sf::milliseconds( 10 ));

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