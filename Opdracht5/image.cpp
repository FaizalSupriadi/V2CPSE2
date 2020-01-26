#include <SFML/Graphics.hpp>
#include <string>
#include "image.hpp"

image::image( std::string picture, sf::Vector2f position,sf::Vector2f size ):
	picture{ picture },
	position{ position },
	size{size}
{sprite.setScale(size);}

void image::draw( sf::RenderWindow & window ) {
	texture.loadFromFile(picture);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(size);
	window.draw(sprite);
}

bool image::contains( const sf::Vector2f& object ) const {
	return sprite.getGlobalBounds().contains( object );
}

void image::setSprite( std::string newSprite ){
 	picture = newSprite;
}

std::string image::getSprite(){
	return picture;
}