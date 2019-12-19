#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class image : public drawable {
private:
	std::string picture;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f size;
	int objNum;

public:

	image( std::string pic, sf::Vector2f position, sf::Vector2f size = sf::Vector2f{+0.5,+0.5}, int objNum =1);

	virtual bool contains( const sf::Vector2f& other)const;
	virtual void draw( sf::RenderWindow & window );
	virtual bool setSprite(bool x);
	virtual void setSprite(std::string newSprite);
	virtual std::string getSprite();
	virtual int getSpriteInt();
};


#endif