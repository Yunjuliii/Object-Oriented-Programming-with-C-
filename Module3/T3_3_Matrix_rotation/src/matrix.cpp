#include "matrix.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  Matrix matrix(n);
  for (int i = 0; i < n; i++){
    matrix[i].resize(n);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      std::cin >> matrix[i][j];
    }
  }
  return matrix;
  }

Matrix Rotate90Deg(const Matrix &m) {
  Matrix rota(m);
  for (std::vector<std::vector<int> >::size_type i = 0; i < m.size(); i++){
    for (std::vector<int>::size_type j = 0; j < m[0].size(); j++){
      rota[j][i] = m[i][j];
    }
  }
  for (std::vector<std::vector<int> >::size_type i = 0; i < rota.size(); i++){
    std::reverse(rota[i].begin(),rota[i].end());
  }
  return rota;
  }

void Print(const Matrix &m) {
  std::cout << "Printing out a " << m.size() << " x " << m[0].size() << " matrix:" << std::endl;
  for (std::vector<std::vector<int> >::size_type i = 0; i < m.size(); i++){
    for (std::vector<int>::size_type j = 0; j < m[0].size(); j++){
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }
  }
  
