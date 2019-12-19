#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <unordered_set>


int main(){
	std::vector<char> tekst;
	std::ifstream myFile("garbage.txt");
	char c;
	while(myFile.get(c)){
		tekst.push_back(c);
	}
	myFile.close();
	std::cout<<"opdr1:\n";
	for(auto x : tekst){
		std::cout<<x;
	}
	std::cout<<"\n\nopdr2:\nSize: "<<tekst.size()<<"\n";

	std::ifstream line("garbage.txt");
	line.unsetf(std::ios_base::skipws);
	std::cout << "\nopdr3:\nLines: " << std::count(std::istream_iterator<char>(line),std::istream_iterator<char>(),'\n') << "\n";
	
	std::cout <<"\nopdr4:\nLetters: "<< std::count_if(tekst.begin(),tekst.end(), [](char c){ return std::isalpha(c);})<< "\n";

	std::cout <<"\nopdr5:\nlowercase: ";
	for(auto & x : tekst){
		x = std::tolower(x);
		std::cout<<x;
	}
	
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::vector< std::pair<int,char> > alpha;
	std::cout << "\nopdr6&7:\n";
	for(auto c : alphabet){
		int amount = std::count(tekst.begin(), tekst.end(), c);
		alpha.push_back(std::make_pair(amount,c));
		std::cout << c << " : " << amount <<"\n";
	}
	std::cout<<"\n";
	std::sort(alpha.begin(), alpha.end());
	for(auto c : alpha){
		std::cout << c.second << " : " << c.first <<"\n";
	}
	
	std::vector<std::string> words;                                     //holds all the words that are in the tekst after changing uppercase to lower and digit to alpha
  	std::vector<std::pair<int, std::string>> bufferVec;                 //a vector that is meant to sort what will be put in the map
  	std::unordered_set<std::string> uniqueSet;                          //a list that can only hold unique values (saves the word)
  	std::map<int, std::pair<std::string, int>, std::greater<int> > occurance;                  //the map where we will save the sorted occurance in
  	std::string buf = "";                                               //a buffer string that holds multiple char objects, that create a word (std::greater<int> is to put the highest value above)

    for_each(tekst.begin(), tekst.end(), [&buf, &words](char c){ if(c==' '||c=='\0'){ words.push_back(buf); buf = ""; }else{ buf+=c; } });      //makes from a vector of char's a new vector with words
    for_each(words.begin(), words.end(), [&uniqueSet](std::string s){ uniqueSet.insert(s); });                                                  //puts every word in a uniqueSet (automatically removes duplicates)

    std::cout << std::endl;

    for_each(uniqueSet.begin(), uniqueSet.end(), [&words, &bufferVec](std::string s){ int count = std::count(words.begin(), words.end(), s); bufferVec.push_back(std::make_pair(count, s)); });   //puts the unordered occurance in a buffer vector

    std::sort(bufferVec.begin(), bufferVec.end());      //sorts the buffer vector

    int tmp = 0;    //a temporarly int value to count through the vector
    for_each(bufferVec.begin(), bufferVec.end(), [&occurance, &tmp](std::pair<int, std::string> vec){occurance.insert(std::make_pair(tmp, std::make_pair(vec.second, vec.first))); tmp++; });     //puts the now ordered vector values in to the map

    for(int i = occurance.size()-1; i >= ((int)occurance.size() - 10); i--){                //couts the 10 biggest values in the map
	  auto theMap = occurance[i];
	  std::cout << theMap.first << ", " << theMap.second << '\n';
    } 

	
}