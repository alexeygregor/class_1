#include <string>
#include <iostream>
#include "mobile.h"
using namespace std;

int main()
{
  int q = 0;
  string command;
  Contact* contact = new Contact;
  PhoneBook* pb = new PhoneBook;

  while (q != -1)
  {
    cout << "\nEnter command: ";
    getline(cin, command);

    if (command == "exit")
    {
      q = contact->exit(q);
    }

    if (command == "add")
    {
      contact->add(*pb);
    }

    if (command == "call")
    {
      contact->call(*pb);
    }

    if (command == "sms")
    {
      contact->sms(*pb);
    }

    if (command == "show")
    {
      contact->show(*pb);
    }
  }

  delete contact;
  delete pb;
}