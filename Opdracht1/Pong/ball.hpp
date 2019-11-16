#ifndef _BALL_HPP
#define _BALL_HPP


#include <SFML/Graphics.hpp>
#include "wall.hpp"

class ball {
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	
	float size;
	float ballX;
	float ballY;
public:
	
	ball( sf::Vector2f position, float size = 30.0, float ballX = 2.0, float ballY = 1.0 );

	void draw( sf::RenderWindow & window );

	void move();
	
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
	
	sf::FloatRect getBounds();
	void collision();


};

#endif
