#ifndef _FACTORY_HPP
#define _FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string>
#include <exception>

class unknown_color : public std::exception {
private:
   std::string s;
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown color [" } + name + "]" }
   {}
   virtual const char * what() const throw(){
      return s.c_str();
   }
};

class end_of_file : public std::exception {
public:
	end_of_file( ){}

	virtual const char * what() const throw(){
      return "end of file";
   }
};

class invalid_position : public std::exception {
private:
	char s;
public:
	invalid_position(char name):
		s( name )
	{}

	virtual const char * what() const throw(){
      return "unknown pos";
   }
};

class unknown_shape : public std::exception {
private:
	std::string s;
public:
	unknown_shape( const std::string & s ):
		s{ std::string{ "unknown shape [" } + s + "]" }
	{}

	const char * what() const noexcept {
      return s.c_str();
   }

};

std::istream & operator>>( std::istream & input, sf::Color & rhs ){
	std::string s;
	input >> s;
	const struct { const char * name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "blue",	sf::Color::Blue },
		{ "green",	sf::Color::Green },

	};
	for( auto const & color : colors ){
		if( color.name == s ){ 
			rhs = color.color;
			return input;
		}
	}
		if( s == "" ){
			throw end_of_file();
		}
		throw unknown_color( s );
}


std::istream & operator>>( std::istream & input, sf::Vector2f & rhs ){
	char c;
	if( ! ( input >> c )){ throw end_of_file(); }
	if( c != '(' ){ throw invalid_position( c ); }

	if( ! ( input >> rhs.x )){ }

	if( ! ( input >> c )){ }
	if( ! ( input >> rhs.y )){ }

	if( ! ( input >> c )){ }
	if( c != ')' ){ throw invalid_position( c ); }

	return input;
}	


#endif