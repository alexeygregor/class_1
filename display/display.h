#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "display.h"
using namespace std;

class Temp
{
  vector <int> vec;
  int x = 0, y = 0, width = 0, height = 0;

public:

  int move();

  int resize();

  void initVec();

  int getVec(int value);
};


class Display
{
  int x = 0, y = 0, width = 0, height = 0;

public:

  void output(Temp* temp);

  int close(int q);
};
