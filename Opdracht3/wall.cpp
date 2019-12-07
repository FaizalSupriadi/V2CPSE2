#include <SFML/Graphics.hpp>
#include "wall.hpp"
#include "drawable.hpp"

wall::wall( sf::Vector2f position, sf::Vector2f size, sf::Color color, int identity ) :
	position{ position },
	size{ size },
	color{ color },
	identity{ identity }
{}

void wall::setId( int id){
	identity = id;
}

int wall::getId(){
	return identity;
}

std::string wall::getPosition(){
	int x = position.x;
	int y = position.y;
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

void wall::draw( sf::RenderWindow & window ) {
	rectangle.setFillColor( color );
	rectangle.setSize(size);
	rectangle.setPosition(position);
	window.draw(rectangle);
}

sf::FloatRect wall::getGlobalBounds()const{
	return rectangle.getGlobalBounds();
}

bool wall::intersect(const sf::FloatRect& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return rectangle.getGlobalBounds().intersects( other);
	
}

bool wall::contains(const sf::Vector2f& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return rectangle.getGlobalBounds().contains( other);
	
}

void wall::setHold(bool i){
	holding=i;
}

bool wall::getHold(){
	return holding;
}

void wall::jump( sf::Vector2f target ){
	position.x = target.x;
	position.y = target.y;
}

void wall::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

pad::pad( sf::Vector2f position, sf::Vector2f size, sf::Color color, int identity ) :
	position{ position },
	size{ size },
	color{ color },
	identity{ identity }
{}

void pad::setId( int id){
	identity = id;
}

int pad::getId(){
	return identity;
}

std::string pad::getPosition(){
	int x = position.x;
	int y = position.y;
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

void pad::move( sf::Vector2f delta ){
	position += delta;
}

void pad::draw( sf::RenderWindow & window ){
	rectangle.setFillColor(color );
	rectangle.setSize(size);
	rectangle.setPosition(position);
	window.draw(rectangle);
}

bool pad::intersect(const sf::FloatRect& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return rectangle.getGlobalBounds().intersects( other);
	
}
bool pad::contains(const sf::Vector2f& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return rectangle.getGlobalBounds().contains( other);
	
}

void pad::setHold(bool i){
	holding=i;
}

bool pad::getHold(){
	return holding;
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
