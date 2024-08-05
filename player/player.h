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

public:

  void setName(string n);

  void setCreate(string c);

  void setLength(string l);

  string getName();

  string getCreate();

  string getLength();
};

class Player
{
  bool stop_ch = true;
  bool pause_ch = true;
  vector <Track> tracks;

public:

  void add(Track &track);

  void play(Track &track, int pos);

  int next(Track &track, int pos);

  void pause();

  void stop();

  int exit(int q);
};
