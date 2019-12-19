#include <SFML/Graphics.hpp>
#include <iostream>
#include "image.hpp"
#include "drawable.hpp"

image::image( std::string picture, sf::Vector2f position, sf::Vector2f size, int objNum ):
	picture{ picture },
	position{ position },
	size{size},
	objNum{objNum}
{}
void image::draw( sf::RenderWindow & window ) {
	texture.loadFromFile(picture);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setScale(size);
	window.draw(sprite);
}

bool image::contains(const sf::Vector2f& other)const{
	//std::cout << circle.getGlobalBounds().intersects( other) <<"\n";
	return sprite.getGlobalBounds().contains( other);
	
}

bool image::setSprite( bool x ){
	if(x && picture != "egg.png" && picture != "butter.png"){
		picture = "egg.png" ;
		objNum = 2;
		return false;
	}else if(!x && picture != "egg.png"  && picture != "butter.png"){
		picture = "butter.png";
		objNum = 3;
		return true;
	}else{
		return x;
	}
}

void image::setSprite( std::string newSprite ){
	picture = newSprite;
	if(picture == "egg.png"){
		objNum = 2;
	}else if(picture == "butter.png"){
		objNum = 3;
	}else{
		objNum = 1;
	}
}

std::string image::getSprite(){
	return picture;
}

int image::getSpriteInt(){
	return objNum;
}


