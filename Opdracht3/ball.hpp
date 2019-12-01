#ifndef _BALL_HPP
#define _BALL_HPP


#include <SFML/Graphics.hpp>
#include "drawable.hpp"
class ball : public drawable {
private:
	sf::CircleShape circle;
	bool holding=0;
	sf::Vector2f position;
	float size;
	sf::Color color;
	sf::Vector2f speed;

public:
	
	ball( sf::Vector2f position,float size = 30.0, sf::Color color = sf::Color::Red,sf::Vector2f speed = sf::Vector2f(+4.0 , +2.0 ) );

	void draw( sf::RenderWindow & window )override;	

	void move(sf::Vector2f delta);
	void update();
	
	void setSpeed( sf::Vector2f delta );
	
	virtual void setHold(bool i)override;
	virtual bool getHold()override;
	
	virtual void jump( sf::Vector2f target ) override;
	virtual void jump( sf::Vector2i target ) override;
	
	virtual bool intersect( const sf::FloatRect& other)const override;
	virtual bool contains( const sf::Vector2f& other)const override;
	
	sf::FloatRect getBounds();
	sf::Vector2f collision( const sf::FloatRect& other);


};

#endif
