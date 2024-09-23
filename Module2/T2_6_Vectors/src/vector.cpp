#include "vector.hpp"

#include <vector>

int GetMin(std::vector<int> v) {
  int min_num = v[0];
  for (unsigned int i=1;i<v.size();i++){
    if (v[i] < min_num){
      min_num = v[i];
    }
  }

  return min_num; 
}

int GetMax(std::vector<int> v) {
  int max_num = v[0];
  for (unsigned int i=1;i<v.size();i++){
    if (v[i] > max_num){
      max_num = v[i];
    }
  }
  return max_num; 
}

double GetAvg(std::vector<int> v) {
  double ave_num = 0;
  for (unsigned int i = 0; i < v.size();i++){
    ave_num += v[i];
  }
  
  return ave_num/v.size(); 
}
