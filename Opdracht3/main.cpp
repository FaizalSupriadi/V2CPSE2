/*#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>*/

#include <iostream>
#include <functional>
#include <array>
#include <fstream>
#include <string>
#include <exception>
#include <memory>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "line.hpp"
#include "image.hpp"
#include "drawable.hpp"
#include "action.hpp"
#include "factory.hpp"

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	std::vector<drawable *> object;	
	{
		std::cout<<"reading\n";
		std::ifstream input( "objects.txt" );
		std::string s;
    	while(std::getline(input, s)){
			try{
				std::istringstream iss(s);
				object.push_back(read( iss ));
			}catch( std::exception & e ){
				std::cout<< "The problem: " << e.what() << "\n";
			}
		}
	}
	
	action actions[] = {
		action( sf::Mouse::Left, 		[&](){ for( auto & p : object ){ if( p->contains(window.mapPixelToCoords(sf::Mouse::getPosition( window )))){ if( !p->getHold()){ p->setHold(1);}}}}),
		action( sf::Mouse::Right, 		[&](){ for( auto & p : object ){ if( p->getHold()){ std::cout<<"release\n"; p->setHold(0); }} }),
		action( [&](){ for( auto & p : object ){ if( p->getHold()){ std::cout<<"jump\n";p->jump(sf::Mouse::getPosition( window )); write(p->getId(),p->getPosition());}}}),										
	};
	
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();

		for( auto & p : object ){
        	p->draw( window );
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