#pragma once
#include <vector>
#include <string>
#include "player.h"
using namespace std;

class Track
{
  string name;
  string create;
  string length;
  vector <string> vecName;
  vector <string> vecCreate;
  vector <string> vecLength;

public:

  void setName(string n);

  string getName();

  void setCreate(string c);

  string getCreate();

  void setLength(string l);

  string getLength();

  void setVector();

  vector <string> getVecName(vector <string> vec);

  vector <string> getVecCreate(vector <string> vec);

  vector <string> getVecLength(vector <string> vec);
};

class Player
{
  bool stop_ch = true;
  bool pause_ch = true;
  vector <string> vectorName;
  vector <string> vectorCreate;
  vector <string> vectorLength;

public:

  void tracks(Track* track);

  void add(Track* track);

  void play(Track* track, int pos);

  int next(Track* track, int pos);

  void pause();

  void stop();

  int exit(int q);
};