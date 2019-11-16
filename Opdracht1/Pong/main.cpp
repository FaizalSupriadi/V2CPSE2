#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}
	
	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	storage<wall, 4> walls;
	
	ball my_ball{ sf::Vector2f{ 320.0, 240.0 } };
	pad pad1{ sf::Vector2f{ 540.0, 200.0  } };
	pad pad2{ sf::Vector2f{ 100.0, 200.0  } };
	
	
	walls.add( new wall{  sf::Vector2f{ 0.0, 0.0 },  sf::Vector2f{ 640.0, 10.0} } ); //top
	walls.add( new wall{  sf::Vector2f{ 0.0, 0.0 },  sf::Vector2f{ 10.0, 480.0} } ); // left
	walls.add( new wall{  sf::Vector2f{ 630.0, 0.0 },  sf::Vector2f{ 640.0, 480.0} } ); // right
	walls.add( new wall{  sf::Vector2f{ 0.0, 470.0 },  sf::Vector2f{ 640.0, 480.0} } ); // bot


	action actions[] = {
		//action( sf::Keyboard::Left,  [&](){ pad1.move( sf::Vector2f( -1.0,  0.0 )); }),
		//action( sf::Keyboard::Right, [&](){ pad.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ pad1.move( sf::Vector2f(  0.0, -4.0 )); }),
		action( sf::Keyboard::Down,  [&](){ pad1.move( sf::Vector2f(  0.0, +4.0 )); }),
		
		action( sf::Keyboard::W,    [&](){ pad2.move( sf::Vector2f(  0.0, -4.0 )); }),
		action( sf::Keyboard::S,  [&](){ pad2.move( sf::Vector2f(  0.0, +4.0 )); }),
		
		action( sf::Mouse::Left,     [&](){ pad1.jump( sf::Mouse::getPosition( window )); }),
		action( [&](){return 1;}, [&](){ my_ball.move(); }),
		action( [&](){ if(my_ball.getBounds().intersects( pad1.getBounds() ) || my_ball.getBounds().intersects( pad2.getBounds() ) ){ return 1; } return 0; }, 
			    [&](){ my_ball.collision(); })
	};
	
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		for( auto p : walls ){
			p->draw(window);
			if(my_ball.getBounds().intersects( p->getBounds() )){
				my_ball.collision();
			}
		}
		my_ball.draw( window );
		pad1.draw( window );
		pad2.draw( window );
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

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

