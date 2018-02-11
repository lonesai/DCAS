
#ifndef WORLD_H
#define WORLD_H

#include "drone.h"

class world{

  struct cell{
    pos cellPos;
    int free; //to keep track if that cell is free
  };
  //places on the world
  const static int gridSize = 8;

  public:
    cell grid[gridSize][gridSize];

    world();
    //constructor that fills the grid with cells
    void printGrid();
    //print out current grid
    void update(pos,int);
    //update the free variable in each cell as the drones get populated
};




#endif
