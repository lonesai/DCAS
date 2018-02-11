#ifndef DRONE_H
#define DRONE_H

class world;

struct pos{
  int x;
  int y;
  void printPos(){
    std::cout << "("<< x << "," << y << ")" << '\n';
  }
};

class drone{
  pos desPos;
  pos startPos;
public:
  pos currentPos;
  std::vector<pos> path;
  int posIndex;

  drone(pos);
  //default constructor
  drone(pos, pos);
  //overloade constructor if start pos is given
  std::vector<pos> findPath();
  //return a vector of pos with the correct path
  int pathSize();
  //return size of path
};
#endif
