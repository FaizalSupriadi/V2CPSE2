#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall( sf::Vector2f position, sf::Vector2f size ) :
	position{ position },
	size{ size }
{}

void wall::draw( sf::RenderWindow & window ) {
	rectangle.setFillColor( sf::Color::Green);
	rectangle.setSize(size);
	rectangle.setPosition(position);
	window.draw(rectangle);
}

sf::FloatRect wall::getGlobalBounds()const{
	return rectangle.getGlobalBounds();
}

pad::pad( sf::Vector2f position, sf::Vector2f size ) :
	position{ position },
	size{ size }
{}

void pad::move( sf::Vector2f delta ){
	position += delta;
}

void pad::draw( sf::RenderWindow & window ){
	rectangle.setFillColor( sf::Color::Blue );
	rectangle.setSize(size);
	rectangle.setPosition(position);
	window.draw(rectangle);
}

void pad::jump( sf::Vector2f target ){
	position = target;
}

void pad::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

sf::FloatRect pad::getGlobalBounds()const{
	return rectangle.getGlobalBounds();
}
