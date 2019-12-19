
#include <string>
#include "command.hpp"
#include "image.hpp"

command::command(drawable*img):
	img{ img }
{
	pic= img->getSprite();
}

bool command::execute( bool curPic ){
	before = img->getSprite();

	return img->setSprite( curPic );
}

void command::back(){
	img->setSprite( before );
}