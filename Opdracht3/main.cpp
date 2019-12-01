#include <iostream>
#include <fstream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "image.hpp"
#include "drawable.hpp"
#include "action.hpp"
#include "factory.hpp"

drawable* read( std::ifstream & input){
	sf::Vector2f position;
	std::string name;
	sf::Color color;
	sf::Vector2f size;
	std::string sizef;
	std::string pic;
	
	input >> position >> name;
	
	if( name == "CIRCLE" ){
		input >> color >> sizef;
	return new ball( position, std::stof(sizef), color);
	} else if( name == "RECTANGLE" ){
		input >> color >> size;
	return new wall( position, size, color );
   	} else if( name == "PICTURE" ){
   		input >> pic;
      	return new image( pic, position );
	} else if( name == "" ){
      	throw end_of_file();
	}

   throw unknown_shape( name );
}

void write( std::ofstream & output, std::string s ){
	output.open("objects.txt", std::ios_base::app);
	output << s << std::endl;
	output.close();
}

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	pad pad1{ 	sf::Vector2f{ 310.0, 230.0 }, sf::Vector2f{ 20.0, 20.0 }};

	std::array< drawable *, 1 > objects = { &pad1 };

	action actions[] = {
		action( sf::Keyboard::Left,  	[&](){ pad1.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, 	[&](){ pad1.move( sf::Vector2f( +3.0,  0.0 )); }),
		action( sf::Keyboard::Up,    	[&](){ pad1.move( sf::Vector2f(  0.0, -3.0 )); }),
		action( sf::Keyboard::Down,  	[&](){ pad1.move( sf::Vector2f(  0.0, +3.0 )); })
	};
	
	/*(50,60) CIRCLE blue 10
(10,10) RECTANGLE red (30,40)
(110, 50) PICTURE ball.jpg*/



	std::vector<drawable *> object;
	std::ofstream output;
	write(output, "(70,80) CIRCLE green 16");
	{
		std::cout<<"reading\n";
		std::ifstream input( "objects.txt" );
		try{
			for(;;){
				object.push_back(read( input ));
			}
		}catch( std::exception & problem ){
			std::cout << problem.what();
		}
	}
	
	

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();

		for( auto & p : objects ){
        	p->draw( window );
      	}
		
		for( auto & p : object ){
        	p->draw( window );
			if( p->getHold()){
				p->jump(sf::Mouse::getPosition( window ));
			}
			if(sf::Mouse::isButtonPressed( sf::Mouse::Left )){
				
				sf::Vector2f pos = window.mapPixelToCoords(sf::Mouse::getPosition( window ));
				std::cout<< pos.x << " : " << pos.y << "\n";
				
				if( p->getHold()){
					std::cout<<"release\n";
					p->setHold(0);
				}
				
				if( p->contains(pos) ){
					if(!p->getHold()){
						p->setHold(1);
					} 
					
					std::cout<<"jumping\n";
					
					p->jump( pos ); 
					}
				}
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