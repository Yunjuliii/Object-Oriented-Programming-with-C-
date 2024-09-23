#include "list.hpp"

#include <iostream>
#include <sstream>
// Implement the functions here
std::istream& GetLines(std::istream& is, std::list<std::string>& list) {
  std::string str;
  list.clear();
  while (std::getline(is,str)){
    list.push_back(str);
  }
  return is;
  }


void Print(const std::list<std::string>& list) {
  for (auto i : list){
    std::cout << i << std::endl;
  }
}

void SortAndUnique(std::list<std::string>& list) {
  list.sort();
  list.unique();
}