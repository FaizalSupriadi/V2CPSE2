#include <SFML/Graphics.hpp>
#include "ball.hpp"
ball::ball( sf::Vector2f position, float size , sf::Color color, int identity, sf::Vector2f speed) :
	position{ position },	
	size{ size },
	color{ color },
	identity{ identity },
	speed{ speed }
	
{  }

void ball::setId( int id){
	identity = id;
}

int ball::getId(){
	return identity;
}
std::string ball::getPosition(){
	int x = position.x;
	int y = position.y;
	
	return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}
 
void ball::draw( sf::RenderWindow & window ){
	circle.setFillColor( color );
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}

void ball::update(){
	position += speed;
}

void ball::move( sf::Vector2f delta ){
	position += delta;
}

void ball::setSpeed( sf::Vector2f delta ){
	speed = delta;
}

bool ball::intersect(const sf::FloatRect& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return circle.getGlobalBounds().intersects( other);
	
}

bool ball::contains(const sf::Vector2f& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return circle.getGlobalBounds().contains( other);
	
}

void ball::setHold(bool i){
	holding=i;
}

bool ball::getHold(){
	return holding;
}

void ball::jump( sf::Vector2f target ){
	position = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}

sf::Vector2f ball::collision(const sf::FloatRect& object){
	//std::cout << object.left << " : " << object.top << " : " << object.width  << " : " << object.height << " : "<<(object.top - position.y)<<" --- " << position.x << " : " << position.y ;
	
	if( (object.left - position.x) <= 60 && (object.left - position.x) >= 50){
   		std::cout << "left" << std::endl;
   		position.x -= 10;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( (object.left - position.x) >= -20 && (object.left - position.x) <= 0){
   		std::cout << "right" << std::endl;
   		position.x += 10;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( (object.top - position.y) <=60 && (object.top - position.y) >= 50 ){
   		std::cout << "up" << std::endl;
   		position.y -= 10;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}
   	if( (object.top - position.y) <= 0 ){
   		std::cout << "bottom" << std::endl;
   		position.y += 10;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}

   	return sf::Vector2f{ speed.x, speed.y };
   }



