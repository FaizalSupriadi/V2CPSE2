
#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <string>
#include "gridObjects.hpp"

class command{
private:
	gridObjects* object;
	char charObject;
	char charObjectBefore = ' ';

public:
	command( gridObjects* object, char charObject );

	void execute();

	void undo();

};

#endif