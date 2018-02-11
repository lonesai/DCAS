#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <pthread.h>
#include "../include/world.h"
#include "../include/drone.h"

using namespace std;

world space;

void* move(void* arg_d){

  drone* ptrD = (drone*) arg_d;
  drone d = *ptrD;

  for(int i = 0; i < d.path.size(); i++){
    if (i != 0){
      space.update(d.path[i-1], 0);
    }
    d.currentPos = d.path[i];
    space.update(d.currentPos, 1);
    space.printGrid();
    std::cout << "" << '\n';
  }
  // move drone from home to destanation
  std::cout << "drone reached its destanation and is now flying back" << '\n' << '\n';

  for(int i = d.path.size()-1; i >= 0; i--){
    if (i != d.path.size()-1 ){
      space.update(d.path[i+1], 0);
    }
    d.currentPos = d.path[i];
    space.update(d.currentPos, 1);
    space.printGrid();
  }
  pthread_exit(NULL);

}


int main(){

  pos desPos1 = {5,6};
  pos startPos1 = {0,0};
  drone d1(desPos1, startPos1);

  pos desPos2 = {3,5};
  pos startPos2 = {0,0};
  drone d2(desPos1, startPos1);

  pos desPos3 = {4,2};
  pos startPos3 = {0,0};
  drone d3(desPos3, startPos3);

  pthread_t t1,t2,t3;
  std::cout << "drone1 starts:" << '\n';
  int rc = pthread_create(&t1,NULL,move,&d1);
  pthread_join(t1,NULL);
  std::cout << "drone2 starts:" << '\n';
  int rc1 = pthread_create(&t2,NULL,move,&d2);
  pthread_join(t2,NULL);
  std::cout << "drone3 starts:" << '\n';
  int rc2 = pthread_create(&t3,NULL,move,&d3);
  pthread_join(t3,NULL);

  return 0;
};
