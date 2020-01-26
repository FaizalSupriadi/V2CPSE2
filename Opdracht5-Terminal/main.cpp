#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "gridObjects.hpp"
#include "action.hpp"
#include "command.hpp"
#include "gameSetup.hpp"

long string_to_long(const std::string & s){
  float f = std::stof(s);
  return long(f);
}

bool is_integer(const std::string & s){
  float f;
  float r;
  f = std::stof(s);
  r = f - long(f);

  return r == 0;
}



int main( int argc, char *argv[] ){
  std::cout << "Starting application 01-05 array of actions\n";

  std::array< gridObjects *, 9 > objects = {};      //holds all the 9 places on the board
  std::vector< command * > undoList;               //holds a list with al the undo's

  std::string tmp_x_as,tmp_y_as;
  int x_as, y_as ;
  bool placeChar = 0;

  makeBoard(objects);

  while( true ){
  	std::cout << "\nEnter location: ";

  	std::cin >> tmp_x_as >> tmp_y_as;
    long x;
    try{
      if(is_integer(tmp_x_as)){
        x = string_to_long(tmp_x_as);
         x_as = stoi(tmp_x_as);
      }
      if(is_integer(tmp_y_as)){
        x = string_to_long(tmp_y_as);
        y_as = stoi(tmp_y_as);
      }

     
     }catch(...){ std::cout << "invalid input\n"; continue;}
     
    // if the location is inside of the grid and the location is empty, draw the char into it
  	if(x_as <= 3 && y_as <= 3 && x_as > 0 && y_as > 0){
  		uint location = (x_as - 1) + ((y_as - 1) * 3);
  		if(objects[location]->getObject() == ' '){
  			if(placeChar){
  				undoList.push_back(new command(objects[location], 'O'));  // Push the location and char to the undolist
  				placeChar = 0;
  			}else{
  				undoList.push_back(new command(objects[location], 'X'));
  				placeChar = 1;
  			}
  		}else{
  			std::cout << "location already in use!\n";
  		}
  	}
    // If the numbers are higher than 3, undo a move
  	else if(x_as > 3 || y_as > 3){
  		if(undoList.size() > 0){
  			undoList.back()->undo();
  			undoList.pop_back();
  			placeChar ? placeChar = 0 : placeChar = 1; // Revert to the previous char to place(x or o)
  		}
  	}
    // Stop when the numbers are 0
  	else if(x_as == 0 || y_as == 0){
  		break;
  	}

  	if(undoList.size() > 0){
  		undoList.back()->execute();
  	}

  	draw(objects);


  	if(winOrDraw(objects) != 0){                 //checks if there is a winner or if there is a draw
        makeBoard(objects);                 //makes the board blank again
        placeChar = 0;
        undoList.clear();                         //makes sure there is nothing in the list anymore
      }
  }

}