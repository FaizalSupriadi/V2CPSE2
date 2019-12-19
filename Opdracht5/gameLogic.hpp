#ifndef _GAMELOGIC_HPP
#define _GAMELOGIC_HPP
int gameState(std::vector< drawable * > & objects){
  int buf = 0;

      for (int i = 0; i < 3; ++i){
          if(objects[i]->getSpriteInt() == 2 && objects[i+3]->getSpriteInt() == 2 && objects[i+6]->getSpriteInt() == 2){
              std::cout << "winner: egg" << std::endl;
              return 2;
          }else if(objects[buf]->getSpriteInt() == 2 && objects[buf+1]->getSpriteInt() == 2 && objects[buf+2]->getSpriteInt() == 2){
              std::cout << "winner: egg" << std::endl;
              return 2;
          }else if(objects[i]->getSpriteInt() == 3 && objects[i+3]->getSpriteInt() == 3 && objects[i+6]->getSpriteInt() == 3){
              std::cout << "winner: butter" << std::endl;
              return 1;
          }else if(objects[buf]->getSpriteInt() == 3 && objects[buf+1]->getSpriteInt() == 3 && objects[buf+2]->getSpriteInt() == 3){
              std::cout << "winner: butter" << std::endl;
              return 1;
          }
          buf+=3;
      }

  if(objects[0]->getSpriteInt() == 2 && objects[4]->getSpriteInt() == 2 && objects[8]->getSpriteInt() == 2){
      std::cout << "winner: egg" << std::endl;
      return 2;
  }else if(objects[0]->getSpriteInt() == 3 && objects[4]->getSpriteInt() == 3 && objects[8]->getSpriteInt() == 3){
      std::cout << "winner: egg" << std::endl;
      return 1;
  }else if(objects[2]->getSpriteInt() == 2 && objects[4]->getSpriteInt() == 2 && objects[6]->getSpriteInt() == 2){
      std::cout << "winner: butter" << std::endl;
      return 2;
  }else if(objects[2]->getSpriteInt() == 3 && objects[4]->getSpriteInt() == 3 && objects[6]->getSpriteInt() == 3){
      std::cout << "winner: butter" << std::endl;
      return 1;
  }

  int count = 0;
  for (int i = 0; i < 9; ++i){
      if(objects[i]->getSpriteInt() != 1){
          count++;
      }
  }

  if(count == 9){
      std::cout << "draw" << std::endl;
      return 3;
  }
  return 0;
}
void makeBoard(std::vector< drawable * > &object){
	uint k = 0;
	float x = 30;
	float y = 70;
	for(uint i = 0; i < 3; i++){
	  for(uint j = 0; j < 3; j++){
		  object.push_back( new image{"black.png", sf::Vector2f{ x, y }});
		  k++;
		  x+=115;
	  }
	  x = 30;
	  y+=120;
  }
}

#endif