#include <SFML/Graphics.hpp>
#include "line.hpp"
#include "drawable.hpp"

line::line( sf::Vector2f position, int rotation,sf::Color color, int identity ) :
	position{ position },
	rotation{ rotation },
	color{ color },
	identity{ identity }
{ }

void line::setId( int id){
	identity = id;
}

int line::getId(){
	return identity;
}

std::string line::getPosition(){
	int x = position.x;
	int y = position.y;
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}

void line::draw( sf::RenderWindow & window ) {
	rectangle.setFillColor( color );
	rectangle.setSize(sf::Vector2f{1,100});
	rectangle.setPosition(position);
	rectangle.setRotation(rotation);
	window.draw(rectangle);
}

sf::FloatRect line::getGlobalBounds()const{
	return rectangle.getGlobalBounds();
}

bool line::intersect(const sf::FloatRect& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return rectangle.getGlobalBounds().intersects( other);
	
}

bool line::contains(const sf::Vector2f& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return rectangle.getGlobalBounds().contains( other);
	
}

void line::setHold(bool i){
	holding=i;
}

bool line::getHold(){
	return holding;
}

void line::jump( sf::Vector2f target ){
	position.x = target.x;
	position.y = target.y;
}

void line::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}