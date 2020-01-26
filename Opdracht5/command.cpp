#include <string>
#include "command.hpp"
#include "image.hpp"

command::command(image* pic, std::string picture):
	pic{ pic },
	picture{ picture }
{}

void command::execute(){
	pictureBefore = pic->getSprite();

	pic->setSprite( picture );
}

void command::undo(){
	pic->setSprite( pictureBefore );
}