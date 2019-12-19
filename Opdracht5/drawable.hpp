#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class drawable{
public:
	virtual void draw( sf::RenderWindow & window )=0;
	virtual bool contains( const sf::Vector2f& other)const=0;
	virtual bool setSprite( bool x)=0;
	virtual void setSprite(std::string newSprite)=0;
	virtual std::string getSprite()=0;
	virtual int getSpriteInt()=0;
};

#endif