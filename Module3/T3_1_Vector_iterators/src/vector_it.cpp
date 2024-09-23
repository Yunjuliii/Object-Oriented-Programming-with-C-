#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  int num;
  while (std::cin >> num){
    v.push_back(num);
  }
  return v;
}

void PrintSum1(const std::vector<int>& v) {
  for (std::vector<int>::const_iterator v_ite = v.begin(); v_ite !=v.end()-1; v_ite++){
    std::cout << *v_ite + *(v_ite + 1) << ' ';
  }
  std::cout << std::endl;
}

void PrintSum2(const std::vector<int>& v) {
  int n = v.size();
    for (int i = 0; i < n / 2; ++i) {
        std::cout << v[i] + v[n - 1 - i] << " ";
    }


    std::cout << std::endl;
}
