#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

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
	
	
}