#ifndef _GRID_OBJECTS_HPP
#define _GRID_OBJECTS_HPP

#include <iostream>

class gridObjects{
private:
	char object;

public:
	gridObjects( char object ):
		object( object )
	{}

	void setObject( char newObject ){
		object = newObject;
	}

	char getObject(){
		return object;
	}

};

#endif