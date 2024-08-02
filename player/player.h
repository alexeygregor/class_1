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

  string getName();

  void setCreate(string c);

  string getCreate();

  void setLength(string l);

  string getLength();
};

class Player
{
  bool stop_ch = true;
  bool pause_ch = true;
  vector <Track> tracks;

public:

  void add(Track &track);

  void playlist(Track& track);

  void play(Track &track, int pos);

  int next(Track &track, int pos);

  void pause();

  void stop();

  int exit(int q);
};