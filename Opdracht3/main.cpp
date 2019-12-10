#include <iostream>
#include <fstream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "line.hpp"
#include "image.hpp"
#include "drawable.hpp"
#include "action.hpp"
#include "factory.hpp"

drawable* read( std::ifstream & input){
	sf::Vector2f position,size;
	sf::Color color;
	int rotation;
	int id;
	std::string name,sizef, pic;

	
	input >> id >> position >> name;
	std::cout<< id<<" : " << name <<"\n";
	if( name == "CIRCLE" ){
		input >> color >> sizef;
	return new ball( position, std::stof(sizef), color, id);
	} else if( name == "RECTANGLE" ){
		input >> color >> size;
	return new wall( position, size, color, id );
   	} else if( name == "PICTURE" ){
   		input >> pic;
    return new image( pic, position, id );
	}else if( name == "LINE" ){
		input >> color >> rotation;
	return new line( position, rotation, color, id);
	}else if( name == "" ){
      	throw end_of_file();
	}

   throw unknown_shape( name );
}
/*
	Standard
	0 (50,60) CIRCLE blue 10
	1 (10,10) RECTANGLE red (10, 10)
	2 (110, 50) PICTURE Slimeball.png*/
void write(int id, std::string position ){
	std::string identity,pos,name,c,d;
	std::ifstream input("objects.txt");
	std::ofstream tmp("tmp.txt");
	while(true){
		
		input >> identity; 
		if(input.eof()){break;}	
		input >> pos >> name >> c;
		
		if(c.find(".png") == std::string::npos){ input >> d; }else{d = "";}
		
		std::cout <<identity << " : "<< id<<"\n";
		
		if( identity == std::to_string(id) ){
			std::cout<<"verified\n";
			tmp << identity << " " << position << " "<< name<< " " << c<< " " << d<< std::endl;
		}else{	
			tmp << identity << " " << pos << " "<< name<< " " << c<< " " << d<< std::endl;
		}		
	}
	
	std::rename("tmp.txt", "objects.txt");
}

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	pad pad1{ 	sf::Vector2f{ 310.0, 230.0 }, sf::Vector2f{ 20.0, 20.0 }};

	std::array< drawable *, 1 > objects = { &pad1 };



	std::vector<drawable *> object;
	
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
	
	action actions[] = {
		action( sf::Keyboard::Left,  	[&](){ pad1.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, 	[&](){ pad1.move( sf::Vector2f( +3.0,  0.0 )); }),
		action( sf::Keyboard::Up,    	[&](){ pad1.move( sf::Vector2f(  0.0, -3.0 )); }),
		action( sf::Keyboard::Down,  	[&](){ pad1.move( sf::Vector2f(  0.0, +3.0 )); }),
		action( sf::Mouse::Left, 		[&](){ for( auto & p : object ){ if( p->contains(window.mapPixelToCoords(sf::Mouse::getPosition( window )))){ if( !p->getHold()){ p->setHold(1);}}}}),
		action( sf::Mouse::Right, 		[&](){ for( auto & p : object ){ if( p->getHold()){ std::cout<<"release\n"; p->setHold(0); }} }),
		action( [&](){ for( auto & p : object ){ if( p->getHold()){ std::cout<<"jump\n";p->jump(sf::Mouse::getPosition( window )); write(p->getId(),p->getPosition());}}}),										
	};
	
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