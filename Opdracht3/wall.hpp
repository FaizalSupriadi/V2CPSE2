#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"


class wall : public drawable {
private:
	sf::RectangleShape rectangle;
	bool holding=0;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	
public:

	wall( sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 30.0, 50.0 }, sf::Color color = sf::Color::Green );

	virtual void draw( sf::RenderWindow & window )override;
	
	virtual void setHold(bool i)override;
	virtual bool getHold()override;
	
	virtual void jump( sf::Vector2f target ) override;
	virtual void jump( sf::Vector2i target ) override;
	
	virtual bool intersect( const sf::FloatRect& other)const override;
	virtual bool contains( const sf::Vector2f& other)const override;
	sf::FloatRect getGlobalBounds()const;
};

template< typename T, int N >
class storage {
private:
	T * store[N];
	int count =0;
public:
	void add( T * p ){
		if( count < N ){
			store[ count ] = p;
			++count;    
		}
	}
	
	T ** begin(){ return store; }
	T ** end(){ return store + count; }
};

class pad : public drawable {
	sf::RectangleShape rectangle;
	bool holding=0;
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	
	
public:
	pad(  sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 20.0, 100.0 }, sf::Color color = sf::Color::Blue  );
	virtual void draw( sf::RenderWindow & window ) override;
	void move( sf::Vector2f delta );
	
	virtual void setHold(bool i)override;
	virtual bool getHold()override;
	
	virtual void jump( sf::Vector2f target ) override;
	virtual void jump( sf::Vector2i target ) override;
	
	virtual bool intersect( const sf::FloatRect& other)const override;
	virtual bool contains( const sf::Vector2f& other)const override;
	sf::FloatRect getGlobalBounds()const;

};

#endif

