#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "hwlib.hpp"
ball::ball( sf::Vector2f position, sf::Vector2f speed, float size) :
	position{ position },
	speed{ speed },
	size{ size }
{ 
	location = sf::Vector2f{ position.x - size, position.y - size };
}
 
void ball::draw( sf::RenderWindow & window ){
	circle.setFillColor( sf::Color::Red );
	circle.setRadius(size);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(position);
	window.draw(circle);
}

void ball::update(){
	position += speed;
	location+=speed;
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

void ball::collision(const sf::FloatRect& object){
	std::cout << object.left << " : " << object.top << " : " << object.width  << " : " << object.height << " : "<< location.x << " : " << location.y <<"\n"; ;
	
	if(object.left + object.width == location.x + 2 ){
         position += sf::Vector2f{2, 0};
         std::cout << "left" << std::endl;
        speed = sf::Vector2f{ speed.x * -1, speed.y };
      }else if(object.left == (position.x + size) - 2){
         position += sf::Vector2f{-2, 0};
         std::cout << "right" << std::endl;
         speed = sf::Vector2f{ speed.x * -1, speed.y };
      }else if(object.top == (position.y + size) - 2){
         position += sf::Vector2f{0, -2};
         std::cout << "up" << std::endl;
         speed = sf::Vector2f{ speed.x, speed.y * -1 };
      }else if(object.top + object.height == location.y){
         position += sf::Vector2f{0, 2};
         std::cout << "down" << std::endl;
         speed = sf::Vector2f{ speed.x, speed.y * -1 };
      } else{
         std::cout << "error" << std::endl;
         speed =  sf::Vector2f{ speed.x , speed.y };
	}
}



