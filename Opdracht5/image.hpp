#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class image {
private:
	std::string picture;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f size;
	

public:

	image( std::string pic, sf::Vector2f position, sf::Vector2f size = sf::Vector2f{+0.5,+0.5});

	 bool contains( const sf::Vector2f& other)const;
	 void draw( sf::RenderWindow & window );
	 void setSprite( std::string newSprite );

	 std::string getSprite();
};


#endif