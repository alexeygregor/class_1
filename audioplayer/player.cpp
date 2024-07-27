#include "header.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
  string command;
  int q = 0, pos = 1;
  Track* track = new Track();
  Player* player = new Player();

  while (q != -1)
  {
    player->add(track);

    cout << "Enter command: ";
    cin >> command;

    if (command == "exit")
    {
      q = player->exit(q);
    }
    else if (command == "play")
    {
      player->play(track, pos);
    }
    else if (command == "next")
    {
      pos = player->next(pos);
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
