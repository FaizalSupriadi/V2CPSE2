#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <string>
#include "image.hpp"
#include "drawable.hpp"

class command{
private:
	drawable* img;
	std::string pic,before;
	bool curPic;
public:
	command(drawable* img);
	
	bool execute( bool curPic);
	
	void back();
};
#endif