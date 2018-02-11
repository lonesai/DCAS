#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "../include/world.h"
#include "../include/drone.h"
using namespace std;

world::world(){
  for (int i = 0; i < gridSize; i++){
    for (int j = 0; j < gridSize; j++){
      pos temp = {i,j};
      cell temp2 = {temp,0};
      grid[i][j] = temp2;
    }
  }
}

void world::printGrid() {
  // for (int i = 0; i < gridSize; i++){
  //   for (int j = 0; j < gridSize; j++){
  //     std::cout << "("<< this->grid[i][j].cellPos.x << "," << this->grid[i][j].cellPos.y << "," << this->grid[i][j].free << ")" << ' ';
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << "" << '\n';

  for (int i = 0; i < this->gridSize; i++){
    for (int j = 0; j < this->gridSize; j++){
      if (i + j == 0){
        std::cout << "A" << ' ';
      }else{
        std::cout << grid[i][j].free << ' ';
      }
    }
    std::cout << std::endl;
  }
  std::cout << "" << '\n';

}

void world::update(pos current, int f){
  if(f == 1){
    this->grid[current.x][current.y].free = 1;
  }
  else{
    this->grid[current.x][current.y].free = 0;
  }
}
