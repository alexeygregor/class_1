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
