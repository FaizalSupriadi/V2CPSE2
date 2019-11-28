#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "action.hpp"

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	
	storage<wall, 4> walls;
	
	ball my_ball{ sf::Vector2f{ 320.0, 220.0 } };
	pad pad1{ sf::Vector2f{ 540.0, 200.0  } };
	pad pad2{ sf::Vector2f{ 100.0, 200.0  } };
	
	
	walls.add( new wall{  sf::Vector2f{ 0.0, 0.0 },  sf::Vector2f{ 640.0, 10.0} } ); //top
	walls.add( new wall{  sf::Vector2f{ 0.0, 0.0 },  sf::Vector2f{ 10.0, 480.0} } ); // left
	walls.add( new wall{  sf::Vector2f{ 630.0, 0.0 },  sf::Vector2f{ 640.0, 480.0} } ); // right
	walls.add( new wall{  sf::Vector2f{ 0.0, 470.0 },  sf::Vector2f{ 640.0, 10.0} } ); // bot


	action actions[] = {
		
		action( sf::Keyboard::Up,    [&](){ pad1.move( sf::Vector2f(  0.0, -8.0)); }),
		action( sf::Keyboard::Down,  [&](){ pad1.move( sf::Vector2f(  0.0, +8.0 )); }),
		
		action( sf::Keyboard::W,    [&](){ pad2.move( sf::Vector2f(  0.0, -8.0 )); }),
		action( sf::Keyboard::S,  [&](){ pad2.move( sf::Vector2f(  0.0, +8.0 )); }),
		
		action( sf::Mouse::Left,     [&](){ pad1.jump( sf::Mouse::getPosition( window )); }),
		action( [&](){ my_ball.update();}),
		action( [&](){ return my_ball.intersect(pad1.getGlobalBounds());}, [&](){ my_ball.setSpeed(my_ball.collision(pad1.getGlobalBounds())); }),
		action( [&](){ return my_ball.intersect(pad2.getGlobalBounds());}, [&](){ my_ball.setSpeed(my_ball.collision(pad2.getGlobalBounds())); }),


	};
	
	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		for( auto p : walls ){
			p->draw(window);
			if( my_ball.intersect( p->getGlobalBounds() )){
				my_ball.setSpeed(my_ball.collision(p->getGlobalBounds()));
			}
		}
		my_ball.draw( window );
		pad1.draw( window );
		pad2.draw( window );
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

