#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class image : public drawable {
private:
	bool holding=0;
	std::string picture;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	int identity;

public:

	image( std::string pic, sf::Vector2f position, int identity = -1);
	
	virtual void jump( sf::Vector2f target ) override;
	virtual void jump( sf::Vector2i target ) override;
	virtual void setHold(bool i)override;
	virtual bool getHold()override;
	
	virtual bool intersect( const sf::FloatRect& other)const override;
	virtual bool contains( const sf::Vector2f& other)const override;
	virtual void draw( sf::RenderWindow & window ) override;
	
	virtual void setId( int id)override;
	virtual int getId()override;
	virtual std::string getPosition()override;
};

#endif