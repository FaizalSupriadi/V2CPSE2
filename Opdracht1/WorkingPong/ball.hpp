#ifndef _BALL_HPP
#define _BALL_HPP


#include <SFML/Graphics.hpp>
#include "wall.hpp"

class ball {
private:
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f speed;
	float size;

public:
	
	ball( sf::Vector2f position, sf::Vector2f speed = sf::Vector2f(+4.0 , +2.0 ),float size = 30.0 );

	void draw( sf::RenderWindow & window );
	

	void move(sf::Vector2f delta);
	void update();
	
	void setSpeed( sf::Vector2f delta );
	
	bool intersect( const sf::FloatRect& other)const;
	
	sf::FloatRect getBounds();
	sf::Vector2f collision( const sf::FloatRect& other);


};

#endif
