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

  void Track::setVector()
  {
    vecName.push_back(name);
    vecCreate.push_back(create);
    vecLength.push_back(length);
  }

  vector <string> Track::getVecName(vector <string> vectorName)
  {
    return vecName;
  }

  vector <string> Track::getVecCreate(vector <string> vectorCreate)
  {
    return vecCreate;
  }

  vector <string> Track::getVecLength(vector <string> vectorLength)
  {
    return vecLength;
  }


  void Player::tracks(Track* track)
  {
    track->getName();
    track->getCreate();
    track->getLength();
    track->setVector();
  }

  void Player::add(Track* track)
  {
    track->setName("I left my Heart in Harvard Medical School");
    track->setCreate("01.07.24");
    track->setLength("02:10");
    tracks(track);

    track->setName("NewYork, NewYork - City, full of Wonders");
    track->setCreate("02.07.24");
    track->setLength("01:20");
    tracks(track);

    track->setName("Dance with Yahoo from Here up to Maternity Hospital");
    track->setCreate("03.07.24");
    track->setLength("04:30");
    tracks(track);

    track->setName("Girl from Island IwoJima");
    track->setCreate("04.07.24");
    track->setLength("03:40");
    tracks(track);
  }

  void Player::play(Track* track, int pos)
  {
    pause_ch = false;
    stop_ch = false;
    cout << track->getVecName(vectorName)[pos] << " "
         << track->getVecCreate(vectorCreate)[pos] << " "
         << track->getVecLength(vectorLength)[pos] << endl;
  }

  int Player::next(Track* track, int pos)
  {
    pause_ch = true;
    stop_ch = true;
    srand(time(nullptr));
    pos = rand() % track->getVecName(vectorName).size();
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