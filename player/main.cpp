#include <ctime>
#include <string>
#include <iostream>
#include "player.h"
using namespace std;


int main()
{
  string command;
  int q = 0, pos = 0;
  Track* track = new Track();
  Player* player = new Player();
  
  track->setName("I left my Heart in Harvard Medical School");
  track->setCreate("01.07.24");
  track->setLength("02:10");
  player->add(*track);

  track->setName("NewYork, NewYork - City, full of Wonders");
  track->setCreate("02.07.24");
  track->setLength("01:20");
  player->add(*track);

  track->setName("Dance with Yahoo from Here up to Maternity Hospital");
  track->setCreate("03.07.24");
  track->setLength("04:30");
  player->add(*track);

  track->setName("Girl from Island IwoJima");
  track->setCreate("04.07.24");
  track->setLength("03:40");
  player->add(*track);

  while (q != -1)
  {
    cout << "Enter command: ";
    cin >> command;

    if (command == "exit")
    {
      q = player->exit(q);
    }

    else if (command == "play")
    {
      player->play(*track, pos);
    }

    else if (command == "next")
    {
      pos = player->next(*track, pos);
    }

    else if (command == "pause")
    {
      player->pause();
    }

    else if (command == "stop")
    {
      player->stop();
    }
  }

  delete track;
  delete player;
}
