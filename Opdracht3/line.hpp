#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"


class line : public drawable {
private:
	sf::RectangleShape rectangle;
	bool holding=0;
	sf::Vector2f position;
	int rotation;
	sf::Color color;
	int identity;
	
public:

	line( sf::Vector2f position, int rotation, sf::Color color = sf::Color::Green, int identity = -1 );

	virtual void draw( sf::RenderWindow & window )override;
	
	virtual void setHold(bool i)override;
	virtual bool getHold()override;
	
	virtual void jump( sf::Vector2f target ) override;
	virtual void jump( sf::Vector2i target ) override;
	
	virtual bool intersect( const sf::FloatRect& other)const override;
	virtual bool contains( const sf::Vector2f& other)const override;
	sf::FloatRect getGlobalBounds()const;
	
	virtual void setId( int id)override;
	virtual int getId()override;
	virtual std::string getPosition()override;

};

#endif


