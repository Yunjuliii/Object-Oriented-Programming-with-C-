#include "vector_strings.hpp"

#include <iostream>
#include <vector>

void Adder(std::vector<std::string>& names) {
  std::cout << "Enter a name:" << std::endl;
  std::string name_add;
  std::cin >> name_add;
  names.push_back(name_add);
  std::cout << "Number of names in the vector:" << std::endl << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
  std::cout << "Removing the last element:" << std::endl << names.back() << std::endl;
  names.pop_back();
}

void Printer(std::vector<std::string>& names) {
  for (unsigned int i=0;i<names.size();i++){
    std::cout << names[i] << std::endl;
  }
}

void CMDReader() {
  std::string cmd;
  std::vector<std::string> names_;
  std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl << "Enter a command:" << std::endl;

  while (std::cin >> cmd){
    if (cmd == "ADD") {
        Adder(names_);
        std::cout << "Enter a command:" << std::endl;
    }

    else if (cmd == "REMOVE") {
        Remover(names_);
        std::cout << "Enter a command:" << std::endl;
    }
    else if (cmd == "PRINT") {
        Printer(names_);
        std::cout << "Enter a command:" << std::endl;
    }
    else if (cmd == "QUIT") break;
  }
  
}
