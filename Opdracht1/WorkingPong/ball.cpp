#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "hwlib.hpp"
ball::ball( sf::Vector2f position, sf::Vector2f speed, float size) :
	position{ position },
	speed{ speed },
	size{ size }
{  }
 
void ball::draw( sf::RenderWindow & window ){
	circle.setFillColor( sf::Color::Red );
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

sf::Vector2f ball::collision(const sf::FloatRect& object){
	std::cout << object.left << " : " << object.top << " : " << object.width  << " : " << object.height << " : "<<(object.top - position.y)<<" --- " << position.x << " : " << position.y ;
	
	if(object.left + object.width == location.x + 2){
         position += sf::Vector2f{2, 0};
         std::cout << "left" << std::endl;
        return sf::Vector2f{ speed.x * -1, speed.y };
      }else if(object.left == (position.x + size) - 2){
         position += sf::Vector2f{-2, 0};
         std::cout << "right" << std::endl;
         return sf::Vector2f{ speed.x * -1, speed.y };
      }else if(object.top == (position.y + size) - 2){
         position += sf::Vector2f{0, -2};
         std::cout << "down" << std::endl;
         speed = sf::Vector2f{ speed.x, speed.y * -1 };
      }else if(object.top + object.height == location.y){
         position += sf::Vector2f{0, 2};
         std::cout << "down" << std::endl;
         return sf::Vector2f{ speed.x, speed.y * -1 };
      }else{
         std::cout << "something went wrong" << std::endl;
         return sf::Vector2f{ speed.x = 0, speed.y = 0 };
      }
	/*
	if( (object.left - position.x) <= 60 && (object.left - position.x) >= 50){
   		std::cout << "left" << std::endl;
   		position.x -= 10;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	else if( (object.left - position.x) >= -20 && (object.left - position.x) <= 0){
   		std::cout << "right" << std::endl;
   		position.x += 10;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	else if( (object.top - position.y) <=60 && (object.top - position.y) >= 50 ){
   		std::cout << "up" << std::endl;
   		position.y -= 10;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}
   	else if( (object.top - position.y) <= 0 ){
   		std::cout << "bottom" << std::endl;
   		position.y += 10;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}

   	return sf::Vector2f{ speed.x, speed.y };*/
   }



