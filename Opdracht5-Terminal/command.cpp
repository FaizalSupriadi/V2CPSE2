#include "command.hpp"

command::command(gridObjects * object, char charObject):
	object( object ),
	charObject( charObject )
{}

void command::execute(){
	charObjectBefore = object->getObject();

	object->setObject( charObject );
}

void command::undo(){
	object->setObject( charObjectBefore );
}