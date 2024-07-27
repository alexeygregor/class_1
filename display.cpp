#include <string>
#include <vector>
#include <limits>
#include <numeric>
#include <iostream>
using namespace std;

class Temp
{
  vector <int> vec = {0, 0, 0, 0};

public:

  int getVec(int value)
  {
    if (value == 0)
      return vec[0];
    if (value == 1)
      return vec[1];
    if (value == 2)
      return vec[2];
    if (value == 3)
      return vec[3];
  }

  int move()
  {
    while (true)
    {
      int x = 0, y = 0, width = 0, height = 0;
      width = vec[2];
      height = vec[3];
      cout << "Enter x & y: ";
      cin >> x >> y;
      if (cin.fail() || cin.peek() != '\n' || x < 0 || y < 0 || x > 80 || y > 50)
      {
        cerr << "Incorrect input" << endl;
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        return 0;
      }
      else
      {
        if (width + x > 80) x = 80 - width;
        if (height + y > 50) y = 50 - height;
        vec[0] = x;
        vec[1] = y;
        vec[2] = width;
        vec[3] = height;
        cout << "X: " << vec[0] << "   Y: " << vec[1] << endl;
        break;
      }
    }
  }

  int resize()
  {
    while (true)
    {
      int x = 0, y = 0, width = 0, height = 0;
      x = vec[0];
      y = vec[1];
      cout << "Enter width and height: ";
      cin >> width >> height;
      if (cin.fail() || cin.peek() != '\n' || width < 0 || height < 0 || width > 80 || height > 50)
      {
        cerr << "Incorrect input" << endl;
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        return 0;
      }
      else
      {
        if (width + x > 80) width = 80 - width;
        if (height + y > 50) height = 50 - height;
        vec[0] = x;
        vec[1] = y;
        vec[2] = width;
        vec[3] = height;
        cout << "Width: " << vec[2] << "  Height: " << vec[3] << endl;
        break;
      }
    }
  }

  int close(int q)
  {
    q = -1;
    return q;
  }
};

class Display
{
public:

  void output(Temp* temp)
  {
    int x = 0, y = 0, width = 0, height = 0;
    x = temp->getVec(0);
    y = temp->getVec(1);
    width = temp->getVec(2);
    height = temp->getVec(3);

    if (width < 0 || height < 0 || width > 80 || height > 50)
    {
      width = 0; height = 0;
    }
    if (x < 0 || y < 0 || x > 80 || y > 50)
    {
      x = 0; y = 0;
    }

    cout << endl;
    if (y > 0)
    {
      for (int i = 0; i < y; ++i)
      {
        for (int j = 0; j < 80; ++j)
          cout << "0";
        cout << endl;
      }
    }
    for (int i = 0; i < height; ++i)
    {
      if (x > 0)
      {
        for (int n = 0; n < x; ++n)
          cout << "0";
      }
      for (int j = 0; j < width; ++j)
        cout << "1";
      for (int j = 0; j < 80 - (width + x); ++j)
        cout << "0";
      cout << endl;
    }
    if ((height + y) < 50)
    {
      for (int i = 0; i < 50 - (height + y); ++i)
      {
        for (int j = 0; j < 80; ++j)
          cout << "0";
        cout << endl;
      }
    }
  }
};

int main()
{
  int q = 0;
  string command;
  Temp* temp = new Temp;
  Display* display = new Display;

  while (q != -1)
  {
    cout << endl;
    cout << "Enter command: ";
    cin >> command;

    if (command == "move")
    {
      temp->move();
    }
    if (command == "resize")
    {
      temp->resize();
    }
    if (command == "display")
    {
      display->output(temp);
    }
    if (command == "close")
    {
      q = temp->close(q);
    }
  }

  delete temp;
  delete display;
}
