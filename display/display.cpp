#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <iostream>
#include "display.h"
using namespace std;


int Temp::move()
{
  while (true)
  {
    width = vec[2];
    height = vec[3];
    cout << "Enter x & y: ";
    cin >> x >> y;
    if (cin.fail() || cin.peek() != '\n' || x < 0 || y < 0 || x > 80 || y > 50 || x + width > 80 || y + height > 50)
    {
      cerr << "Incorrect input" << endl;
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      return 0;
    }
    else
    {
      vec[0] = x;
      vec[1] = y;
      cout << "X: " << vec[0] << "   Y: " << vec[1] << endl;
      break;
    }
  }
}

int Temp::resize()
{
  while (true)
  {
    x = vec[0];
    y = vec[1];
    cout << "Enter width and height: ";
    cin >> width >> height;
    if (cin.fail() || cin.peek() != '\n' || x < 0 || y < 0 || x > 80 || y > 50 || x + width > 80 || y + height > 50)
    {
      cerr << "Incorrect input" << endl;
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      return 0;
    }
    else
    {
      vec[2] = width;
      vec[3] = height;
      cout << "Width: " << vec[2] << "  Height: " << vec[3] << endl;
      break;
    }
  }
}

void Temp::initVec()
{
  vec = { 0, 0, 0, 0 };
}

int Temp::getVec(int value)
{
  if (value == 0)
  {
    return vec[0];
  }
  if (value == 1)
  {
    return vec[1];
  }
  if (value == 2)
  {
    return vec[2];
  }
  if (value == 3)
  {
    return vec[3];
  }
}


void Display::output(Temp* temp)
{
  x = temp->getVec(0);
  y = temp->getVec(1);
  width = temp->getVec(2);
  height = temp->getVec(3);
  cout << endl;
  if (y > 0)
  {
    for (int i = 0; i < y; ++i)
    {
      for (int j = 0; j < 80; ++j)
      {
        cout << "0";
      }
      cout << endl;
    }
  }
  for (int i = 0; i < height; ++i)
  {
    if (x > 0)
    {
      for (int n = 0; n < x; ++n)
      {
        cout << "0";
      }
    }
    for (int j = 0; j < width; ++j)
    {
      cout << "1";
    }
    for (int j = 0; j < 80 - (width + x); ++j)
    {
      cout << "0";
    }
    cout << endl;
  }
  if ((height + y) < 50)
  {
    for (int i = 0; i < 50 - (height + y); ++i)
    {
      for (int j = 0; j < 80; ++j)
      {
        cout << "0";
      }
      cout << endl;
    }
  }
}

int Display::close(int q)
{
  q = -1;
  return q;
}