#include <ctime>
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
public:

  static void track1(Track* track)
  {
    track->setName("I left my heart in Harvard Medical School");
    track->setCreate("01.07.24");
    track->setLength("00:10");
  }

  static void track2(Track* track)
  {
    track->setName("NewYork, NewYork - city, full of Wonders");
    track->setCreate("02.07.24");
    track->setLength("00:20");
  }

  static void track3(Track* track)
  {
    track->setName("Dance with yahoo from Here up to Maternity Hospital");
    track->setCreate("03.07.24");
    track->setLength("00:30");
  }

  static void track4(Track* track)
  {
    track->setName("Girl from island IwoJima");
    track->setCreate("04.07.24");
    track->setLength("00:40");
  }

  static void play(Track* track)
  {
    cout << track->getName() << " " << track->getCreate() << " " << track->getLength() << endl;
  }

  bool pause (bool pause_ch)
  {
    if (!pause_ch) cout << "Pause" << endl;
    pause_ch = true;
    return pause_ch;
  }

  bool stop (bool stop_ch)
  {
    if (!stop_ch) cout << "Stop" << endl;
    stop_ch = true;
    return stop_ch;
  }

  int next (int rnd)
  {
    srand(time(nullptr));
    rnd = rand() % 4 + 1;
    return rnd;
  }

  int exit(int q)
  {
    q = -1;
    return q;
  }
};

int main()
{
  string command;
  bool play_ch = false;
  bool next_ch = false;
  bool stop_ch = false;
  bool pause_ch = false;
  int q = 0, buf1 = 0, buf2 = 0, rnd = 0;

  while(q != -1)
  {
    Track* track = new Track();
    Player* player = new Player();

    cout << "Enter command: ";
    cin >> command;

    if (command == "exit")
      q = player->exit(q);

    if (command == "next")
    {
      buf1 = player->next(rnd);
      cout << "Track: " << buf1 << endl;
      next_ch = true;
    }

    else if (command == "play")
    {
      if (!play_ch)
      {
        buf1 = 1;
        play_ch = true;
      }
      else if (!next_ch) buf1 = buf2;

      if (buf1 == 1) player->track1(track);
      if (buf1 == 2) player->track2(track);
      if (buf1 == 3) player->track3(track);
      if (buf1 == 4) player->track4(track);

      player->play(track);
      next_ch = false;
      buf2 = buf1;
    }

    if (command == "pause")
      pause_ch = player->pause(pause_ch);

    else
      pause_ch = false;

    if (command == "stop")
      stop_ch = player->stop(stop_ch);

    else
      stop_ch = false;

    delete track;
    delete player;
  }
}
