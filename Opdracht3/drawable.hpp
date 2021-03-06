#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP
#include <iostream>

class drawable{
public:
	virtual void draw( sf::RenderWindow & window );
	
	virtual bool intersect( const sf::FloatRect& other)const;
	virtual bool contains( const sf::Vector2f& other)const;
	
	virtual void setHold(bool i);
	virtual bool getHold();
	
	virtual void jump( sf::Vector2f target );
	virtual void jump( sf::Vector2i target );
	
	virtual void setId( int id);
	virtual int getId();
	virtual std::string getPosition();

};

#endif