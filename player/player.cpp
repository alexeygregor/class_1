#include <ctime>
#include <vector>
#include <string>
#include <iostream>
#include "player.h"
using namespace std;


  void Track::setName(string n)
  {
    name = n;
  }

  void Track::setCreate(string c)
  {
    create = c;
  }

  void Track::setLength(string l)
  {
    length = l;
  }

  string Track::getName()
  {
    return name;
  }

  string Track::getCreate()
  {
    return create;
  }

  string Track::getLength()
  {
    return length;
  }


  void Player::add(Track& track)
  {
    tracks.push_back(track);
  }

  void Player::play(Track& track, int pos)
  {
    pause_ch = false;
    stop_ch = false;
    track = tracks.at(pos);
    cout << track.getName() << " " << track.getCreate() << " " << track.getLength() << endl;
  }

  int Player::next(Track& track, int pos)
  {
    pause_ch = true;
    stop_ch = true;
    srand(time(nullptr));
    pos = rand() % tracks.size();
    return pos;
  }

  void Player::pause()
  {
    if (!pause_ch && !stop_ch)
    {
      cout << "PAUSE" << endl;
    }
    pause_ch = true;
  }

  void Player::stop()
  {
    if (!stop_ch)
    {
      cout << "STOP" << endl;
    }
    stop_ch = true;
  }

  int Player::exit(int q)
  {
    q = -1;
    return q;
  }
