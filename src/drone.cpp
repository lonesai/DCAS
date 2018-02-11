#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <pthread.h>
#include "../include/drone.h"
#include "../include/world.h"

using namespace std;


drone::drone(pos des){
  startPos.x= 0;
  startPos.y= 0;
  currentPos = startPos;
  posIndex = 0;
  desPos = des;
  path = this->findPath();
}
drone::drone(pos des, pos start){
  startPos = start;
  currentPos = startPos;
  posIndex = 0;
  desPos = des;
  path = this->findPath();
}

int drone::pathSize(){
  return this->path.size();
}

vector<pos> drone::findPath(){

  vector<int> xArray;
  xArray.push_back(startPos.x);

  while( xArray.back() != desPos.x ){
    if(startPos.x < desPos.x){
      xArray.push_back(xArray.back() +1);
    }else if(startPos.x > desPos.x){
      xArray.push_back(xArray.back() - 1);
    }else {
      xArray.push_back(xArray.back());
    }
  }

  vector<int> yArray;
  yArray.push_back(startPos.y);
  while( yArray.back() != desPos.y ){
    if(startPos.y < desPos.y){
      yArray.push_back(yArray.back() +1);
    }else if(startPos.y > desPos.y){
      yArray.push_back(yArray.back() -1);
    }else{
      yArray.push_back(yArray.back() );
    }
  }

  vector<pos> p;
  switch ( (desPos.x*desPos.y) % 2){
    case 1:
      for (int i = 0; i < xArray.size(); i++){
        pos temp = {xArray[i], startPos.y};
        p.push_back(temp);
      }
      for (int i = 1; i < yArray.size(); i++){
        pos temp = {desPos.x , yArray[i] };
        p.push_back(temp);
      }
      break;
    case 0:
      for (int i = 0; i < yArray.size(); i++){
        pos temp = {startPos.x , yArray[i] };
        p.push_back(temp);
      }
      for (int i = 1; i < xArray.size(); i++){
        pos temp = {xArray[i], desPos.y};
        p.push_back(temp);
      }
      break;
  }

  return p;
}

// void *drone::move(world &space){
// void* drone::move(void* arg_d){
//
//   drone* ptrD = (drone*) arg_d;
//   drone d = *ptrD;
//
//   // if (this->posIndex == 0){
//   //   space.update(this->currentPos, 1);
//   //   space.printGrid();
//   // }else{
//   //   this->currentPos = this->path[this->posIndex];
//   //   space.update(this->path[this->posIndex-1], 0);
//   //   space.update(this->currentPos, 1);
//   //   space.printGrid();
//   // }
//   // this->posIndex = this->posIndex +1;
//
//   // if(this->posIndex == this->path.size()){
//   //
//   // }
//
//   for(int i = 0; i < d.path.size(); i++){
//     if (i != 0){
//       space.update(d.path[i-1], 0);
//     }
//     d.currentPos = d.path[i];
//     space.update(d.currentPos, 1);
//     space.printGrid();
//     std::cout << "" << '\n';
//   }
//   // move drone from home to destanation
//   // std::cout << "drone reached its destanation and is now flying back" << '\n' << '\n';
//   //
//   // for(int i = this->path.size()-1; i >= 0; i--){
//   //   if (i != this->path.size()-1 ){
//   //     space.update(this->path[i+1], 0);
//   //   }
//   //   this->currentPos = this->path[i];
//   //   space.update(this->currentPos, 1);
//   //   space.printGrid();
//   // }
//   pthread_exit(NULL);
//
//
//
// }
