#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
class drawable{
public:
	virtual void draw( sf::RenderWindow & window );
};

class wall : public drawable {
private:
	sf::RectangleShape rectangle;
	sf::Vector2f position;
	sf::Vector2f size;
public:

	wall( sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 30.0, 50.0 } );

	void draw( sf::RenderWindow & window )override;
	
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
	sf::Vector2f position;
	sf::Vector2f size;
	
public:
	pad(  sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 20.0, 100.0 } );
	void draw( sf::RenderWindow & window ) override;
	void move( sf::Vector2f delta );
	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );
	sf::FloatRect getGlobalBounds()const;

};

#endif

