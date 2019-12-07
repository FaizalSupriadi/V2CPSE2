#include <SFML/Graphics.hpp>
#include <iostream>
#include "image.hpp"
#include "drawable.hpp"

image::image( std::string picture, sf::Vector2f position, int identity ):
	picture{ picture },
	position{ position },
	identity{ identity }
{}

void image::setId( int id){
	identity = id;
}

int image::getId(){
	return identity;
}
std::string image::getPosition(){
	int x = position.x;
	int y = position.y;
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

void image::draw( sf::RenderWindow & window ) {
	texture.loadFromFile(picture);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

bool image::intersect(const sf::FloatRect& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return sprite.getGlobalBounds().intersects( other);
	
}

bool image::contains(const sf::Vector2f& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return sprite.getGlobalBounds().contains( other);
	
}

void image::setHold(bool i){
	holding=i;
}

bool image::getHold(){
	return holding;
}

void image::jump( sf::Vector2f target ){
	position = target;
}

void image::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}