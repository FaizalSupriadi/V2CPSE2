#ifndef _GAMESETUP_HPP
#define _GAMESETUP_HPP

uint gameCheck(std::array< image *, 9 > & objects){
  uint buf = 0;
  std::string cross = "butter.png";
  std::string circle = "egg.png";

      for (uint i = 0; i < 3; ++i){
          if(objects[i]->getSprite() == circle && objects[i+3]->getSprite() == circle && objects[i+6]->getSprite() == circle){
              std::cout << "winner: egg" << std::endl;
              return 2;
          }else if(objects[buf]->getSprite() == circle && objects[buf+1]->getSprite() == circle && objects[buf+2]->getSprite() == circle){
              std::cout << "winner: egg" << std::endl;
              return 2;
          }else if(objects[i]->getSprite() == cross && objects[i+3]->getSprite() == cross && objects[i+6]->getSprite() == cross){
              std::cout << "winner: butter" << std::endl;
              return 1;
          }else if(objects[buf]->getSprite() == cross && objects[buf+1]->getSprite() == cross && objects[buf+2]->getSprite() == cross){
              std::cout << "winner: butter" << std::endl;
              return 1;
          }
          buf+=3;
      }

  if(objects[0]->getSprite() == circle && objects[4]->getSprite() == circle && objects[8]->getSprite() == circle){
      std::cout << "winner: egg" << std::endl;
      return 2;
  }else if(objects[0]->getSprite() == cross && objects[4]->getSprite() == cross && objects[8]->getSprite() == cross){
      std::cout << "winner: butter" << std::endl;
      return 1;
  }else if(objects[2]->getSprite() == circle && objects[4]->getSprite() == circle && objects[6]->getSprite() == circle){
      std::cout << "winner: egg" << std::endl;
      return 2;
  }else if(objects[2]->getSprite() == cross && objects[4]->getSprite() == cross && objects[6]->getSprite() == cross){
      std::cout << "winner: butter" << std::endl;
      return 1;
  }

  uint count = 0;
  for (int i = 0; i < 9; ++i){
      if(objects[i]->getSprite() != "black.png"){
          count++;
      }
  }

  if(count == 9){
      std::cout << "draw" << std::endl;
      return 3;
  }
  return 0;
}

//a loop with values declared here, because I am to lazy to make 9 invisible objects to press on
void makeBoard(std::array< image *, 9 > & objects){
  uint k = 0;
  float x = 10;
  float y = 30;

  for(uint i = 0; i < 3; i++){
      for(uint j = 0; j < 3; j++){
          objects[k] = new image{"black.png", sf::Vector2f{ x, y }, sf::Vector2f{ 0.5, 0.5}};
          k++;
          x+=151;
      }
      x = 10;
      y+=154;
  }
}

#endif