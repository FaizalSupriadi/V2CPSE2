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
	sf::Vector2f location;	

public:
	
	ball( sf::Vector2f position, sf::Vector2f speed = sf::Vector2f(-1.0 , 1.0 ),float size = 30.0 );

	void draw( sf::RenderWindow & window );
	

	void move(sf::Vector2f delta);
	void update();
	
	void setSpeed( sf::Vector2f delta );
	
	bool intersect( const sf::FloatRect& other)const;
	
	sf::FloatRect getBounds();
	void collision( const sf::FloatRect& other);


};

#endif
