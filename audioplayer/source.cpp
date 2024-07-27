#include <ctime>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Track
{
  string name;
  string create;
  string length;

public:

  string setName(string n)
  {
    name = n;
    return name;
  }

  string setCreate(string c)
  {
    create = c;
    return create;
  }

  string setLength(string l)
  {
    length = l;
    return length;
  }

  string getName()
  {
    return name;
  }

  string getCreate()
  {
    return create;
  }

  string getLength()
  {
    return length;
  }
};

class Player
{
  int buf = 0, rnd = 0;
  bool pause_ch = true;
  bool stop_ch = true;
  vector <string> melody = { "go" };

public:

  void tracks(Track* track)
  {
    melody.push_back(track->getName());
    melody.push_back(track->getCreate());
    melody.push_back(track->getLength());
  }

  void add(Track* track)
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

  void play(Track* track, int pos)
  {
    pause_ch = false;
    stop_ch = false;
    for (int i = pos; i < pos + 3; ++i)
      cout << melody[i] << " ";
    cout << endl;
  }

  int next(int pos)
  {
    pause_ch = true;
    stop_ch = true;
    buf = (melody.size() - 1) / 3;
    srand(time(nullptr));
    rnd = rand() % buf + 1;
    if (rnd != 1) pos = rnd * 3 - 2;
    return pos;
  }

  void pause()
  {
    if (!pause_ch && !stop_ch)
      cout << "PAUSE" << endl;
    pause_ch = true;
  }

  void stop()
  {
    if (!stop_ch)
      cout << "STOP" << endl;
    stop_ch = true;
  }

  int exit(int q)
  {
    q = -1;
    return q;
  }
};
