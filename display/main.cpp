#include <string>
#include <iostream>
#include "display.h"
using namespace std;

int main()
{
  int q = 0;
  string command;
  Temp* temp = new Temp;
  Display* display = new Display;

  temp->initVec();
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
      q = display->close(q);
    }
  }

  delete temp;
  delete display;
}
