#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <string>
#include "image.hpp"

class command{
private:
	image* pic;
	std::string picture;
	std::string pictureBefore = "";

public:
	command( image* pic, std::string picture );

	void execute();

	void undo();

};

#endif