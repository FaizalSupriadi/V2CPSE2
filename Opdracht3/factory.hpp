#ifndef _FACTORY_HPP
#define _FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <array>
#include <fstream>
#include <string>
#include <exception>
#include <memory>
#include <vector>
#include <sstream>

class invalid_axis : public std::exception {
private:
	std::string s;
public:
  invalid_axis( const char & c):
    s{ std::string{ "missing " } + c + "-axis " } 
  {}

  const char * what() const noexcept {
      return s.c_str();
   }
};

class unknown_color : public std::exception {
private:
   std::string s;
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown color [" } + name + "]" }
   {}
   const char * what() const noexcept {
      return s.c_str();
   }
};

class end_of_file : public std::exception {
public:
	end_of_file( ){}

	 const char * what() const noexcept {
      return "end of file";
   }
};

class invalid_position : public std::exception {
public:
	invalid_position( const char & c, const char & a):
		s{ std::string{ "missing a [\'" } + c + "\'] instead got a [\'" + a + "\'] "}
	{}

	const char * what() const noexcept {
      return s.c_str();
   }

private:
	std::string s;
};

class unknown_shape : public std::exception {
private:
	std::string s;
public:
	unknown_shape( const std::string & s ):
		s{ std::string{ "unknown shape [" } + s + "]" }
	{}

	const char * what() const noexcept  {
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
	
	if( c != '(' ){ throw invalid_position('(', c ); }

	if( ! ( input >> rhs.x )){ throw invalid_axis( 'x' ); }

	if( ! ( input >> c )){ throw invalid_position(c, c );}
	
	if(c != ',' ){ throw invalid_position( ',', c ); }

	if( ! ( input >> rhs.y )){ throw invalid_axis( 'y' ); }

	if( ! ( input >> c )){ throw invalid_position(c, c );}

	if( c != ')' ){ throw invalid_position( ')',c ); }

	return input;
}	

drawable* read( std::istream & input){
	sf::Vector2f position,size;
	sf::Color color;
	int rotation;
	int id;
	std::string name,sizef, pic;

	
	input >> id >> position >> name;
	std::cout<< id<<" : " << name <<"\n";
	if( name == "CIRCLE" ){
		input >> color >> sizef;
	return new ball( position, std::stof(sizef), color, id);
	} else if( name == "RECTANGLE" ){
		input >> color >> size;
	return new wall( position, size, color, id );
   	} else if( name == "PICTURE" ){
   		input >> pic;
    return new image( pic, position, id );
	}else if( name == "LINE" ){
		input >> color >> rotation;
	return new line( position, rotation, color, id);
	}else if( name == "" ){
      	throw end_of_file();
	}

   	throw unknown_shape( name );
}
/*
	Standard
	0 (50,60) CIRCLE blue 10
	1 (10,10) RECTANGLE red (10, 10)
	2 (110, 50) PICTURE Slimeball.png*/
void write(int id, std::string position ){
	std::string identity,pos,name,c,d;
	std::ifstream input("objects.txt");
	std::ofstream tmp("tmp.txt");
	while(true){
		
		input >> identity; 
		if(input.eof()){break;}	
		input >> pos >> name >> c;
		
		if(c.find(".png") == std::string::npos){ input >> d; }else{d = "";}
		
		//std::cout <<identity << " : "<< id<<"\n";
		
		if( identity == std::to_string(id) ){
			std::cout<<"verified\n";
			tmp << identity << " " << position << " "<< name<< " " << c<< " " << d<< std::endl;
		}else{	
			tmp << identity << " " << pos << " "<< name<< " " << c<< " " << d<< std::endl;
		}		
	}
	
	std::rename("tmp.txt", "objects.txt");
}



#endif