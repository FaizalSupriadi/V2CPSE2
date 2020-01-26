#ifndef _GAMESETUP_HPP
#define _GAMESETUP_HPP
//a very lazy win or draw checker
uint winOrDraw(std::array< gridObjects *, 9 > & objects){
  uint buf = 0;
  char cross = 'X';
  char circle = 'O';

      for (uint i = 0; i < 3; ++i){
          if(objects[i]->getObject() == circle && objects[i+3]->getObject() == circle && objects[i+6]->getObject() == circle){
              std::cout << "winner: circle" << std::endl;
              return 2;
          }else if(objects[buf]->getObject() == circle && objects[buf+1]->getObject() == circle && objects[buf+2]->getObject() == circle){
              std::cout << "winner: circle" << std::endl;
              return 2;
          }else if(objects[i]->getObject() == cross && objects[i+3]->getObject() == cross && objects[i+6]->getObject() == cross){
              std::cout << "winner: cross" << std::endl;
              return 1;
          }else if(objects[buf]->getObject() == cross && objects[buf+1]->getObject() == cross && objects[buf+2]->getObject() == cross){
              std::cout << "winner: cross" << std::endl;
              return 1;
          }
          buf+=3;
      }

  if(objects[0]->getObject() == circle && objects[4]->getObject() == circle && objects[8]->getObject() == circle){
      std::cout << "winner: circle" << std::endl;
      return 2;
  }else if(objects[0]->getObject() == cross && objects[4]->getObject() == cross && objects[8]->getObject() == cross){
      std::cout << "winner: cross" << std::endl;
      return 1;
  }else if(objects[2]->getObject() == circle && objects[4]->getObject() == circle && objects[6]->getObject() == circle){
      std::cout << "winner: circle" << std::endl;
      return 2;
  }else if(objects[2]->getObject() == cross && objects[4]->getObject() == cross && objects[6]->getObject() == cross){
      std::cout << "winner: cross" << std::endl;
      return 1;
  }

  uint count = 0;
  for (int i = 0; i < 9; ++i){
      if(objects[i]->getObject() != ' '){
          count++;
      }
  }

  if(count == 9){
      std::cout << "draw" << std::endl;
      return 3;
  }
  return 0;
}

void draw(std::array< gridObjects *, 9 > & objects){
  std::cout << objects[0]->getObject() << '|' << objects[1]->getObject() << '|' << objects[2]->getObject() << '\n';  
  std::cout << "-----\n";
  std::cout << objects[3]->getObject() << '|' << objects[4]->getObject() << '|' << objects[5]->getObject() << '\n';
  std::cout << "-----\n";  
  std::cout << objects[6]->getObject() << '|' << objects[7]->getObject() << '|' << objects[8]->getObject() << '\n';  
}

//a loop with values declared here
void makeBoard(std::array< gridObjects *, 9 > & objects){
  uint k = 0;

  for(uint i = 0; i < 3; i++){
      for(uint j = 0; j < 3; j++){
          objects[k] = new gridObjects(' ');
          k++;
      }
  }
}

#endif