#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "hwlib.hpp"
ball::ball( sf::Vector2f position, float size, float ballX, float ballY ) :
	position{ position },
	size{ size },
	ballX{ ballX },
	ballY{ ballY}
{  }

void ball::draw( sf::RenderWindow & window ){
	circle.setFillColor( sf::Color::Red );
	circle.setRadius(size);
	circle.setPosition(position);
	window.draw(circle);
}

void ball::move(){
	position += sf::Vector2f( ballX, ballY);
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

sf::FloatRect ball::getBounds(){
	return circle.getGlobalBounds();
}

void ball::collision(){
		if( (ballX > 0 && ballY > 0) || (ballX<0 && ballY<0 ) ){
			ballX = (ballX *-1.0) ;
		}else{
			ballY = (ballY *-1.0);
		}
		move();
		move();
		std::cout<<ballX << " : " << ballY << "\n";
}



