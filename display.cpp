#include <limits>
#include <numeric>
#include <iostream>
using namespace std;

class Temp
{
public:

  int move(int arr[6])
  {
    while (true)
    {
      int x = 0, y = 0, width = 0, height = 0;
      width = arr[2] * 10 + arr[3];
      height = arr[4] * 10 + arr[5];
      cout << "Enter x & y: ";
      cin >> x >> y;
      if (width < 0 || height < 0 || width > 80 || height > 50)
        { width = 0; height = 0; }
      if (x < 0 || y < 0 || x > 80 || y > 50)
      {
        x = 0; y = 0;
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        return 0;
      }
      else
      {
        if (width + x > 80) x = 80 - width;
        if (height + y > 50) y = 50 - height;
        arr[0] = x;
        arr[1] = y;
        arr[2] = width / 10; arr[3] = width % 10;
        arr[4] = height / 10; arr[5] = height % 10;
        cout << "X: " << arr[0] << "   Y: " << arr[1] << endl;
        return arr[6];
      }
    }
  }

  int resize(int arr[6])
  {
    while (true)
    {
      int x = 0, y = 0, width = 0, height = 0;
      x = arr[0];
      y = arr[1];
      cout << "Enter width and height: ";
      cin >> width >> height;
      if (x < 0 || y < 0 || x > 80 || y > 50)
        { x = 0; y = 0; }
      if (cin.fail() || cin.peek() != '\n' || width < 0 || height < 0 || width > 80 || height > 50)
      {
        width = 0; height = 0;
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        return 0;
      }
      else
      {
        if (width + x > 80) width = 80 - width;
        if (height + y > 50) height = 50 - height;
        arr[0] = x;
        arr[1] = y;
        arr[2] = width / 10; arr[3] = width % 10;
        arr[4] = height / 10; arr[5] = height % 10;
        cout << "Width: " << arr[2] << arr[3] << "  Height: " << arr[4] << arr[5] << endl;
        return arr[6];
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

  void output(int arr[6])
  {
    cout << endl;
    int x = 0, y = 0, width = 0, height = 0;
    x = arr[0];
    y = arr[1];
    width = arr[2] * 10 + arr[3];
    height = arr[4] * 10 + arr[5];
    if (width < 0 || height < 0 || width > 80 || height > 50)
      { width = 0; height = 0; }
    if (x < 0 || y < 0 || x > 80 || y > 50)
      { x = 0; y = 0; }

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
    if((height + y) < 50)
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
  int arr[6];
  string command;
  Temp* temp = new Temp;
  Display* display = new Display;

  while (true)
  {
    cout << endl;
    cout << "Enter command: ";
    cin >> command;
    if (command == "move")
      temp->move(&arr[6]);
    if (command == "resize")
      temp->resize(&arr[6]);
    if (command == "display")
      display->output(&arr[6]);
    if (command == "close")
      q = temp->close(q);
    if (q == -1)
      return 0;
  }
  delete temp;
  delete display;
}
