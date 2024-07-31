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

  string Track::getName()
  {
    return name;
  }

  void Track::setCreate(string c)
  {
    create = c;
  }

  string Track::getCreate()
  {
    return create;
  }

  void Track::setLength(string l)
  {
    length = l;
  }

  string Track::getLength()
  {
    return length;
  }


  void Player::add(Track &track)
  {
    track.setName("I left my Heart in Harvard Medical School");
    track.setCreate("01.07.24");
    track.setLength("02:10");
    tracks.push_back(track);

    track.setName("NewYork, NewYork - City, full of Wonders");
    track.setCreate("02.07.24");
    track.setLength("01:20");
    tracks.push_back(track);

    track.setName("Dance with Yahoo from Here up to Maternity Hospital");
    track.setCreate("03.07.24");
    track.setLength("04:30");
    tracks.push_back(track);

    track.setName("Girl from Island IwoJima");
    track.setCreate("04.07.24");
    track.setLength("03:40");
    tracks.push_back(track);
  }

  void Player::play(Track& track, int pos)
  {
    pause_ch = false;
    stop_ch = false;
   track = tracks.at( pos );
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
