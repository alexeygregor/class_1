#include <vector>
#include <string>
#include <iostream>
#include "mobile.h"
using namespace std;


void PhoneBook::setName(string n)
{
  name = n;
}

string PhoneBook::getName()
{
  return name;
}

void PhoneBook::setPhone(string p)
{
  phone = p;
}

string PhoneBook::getPhone()
{
  return phone;
}


void Contact::add(PhoneBook &pb)
{
  insert(pb);
  contacts.push_back(pb);
}

void Contact::insert(PhoneBook& pb)
{
  cout << "Insert Phone number: ";
  getline(cin, phone);

  if (valid(phone))
  {
    cout << "Insert Name: ";
    getline(cin, name);

    pb.setName(name);
    pb.setPhone(phone);
  }
}

void Contact::call(PhoneBook &pb)
{
  cout << "Input name ^ number: ";
  getline(cin, input);

  for (int i = 0; i < contacts.size(); ++i)
  {
    pb = contacts.at(i);
    if (input == pb.getName())
    {
      buf = pb.getName();
      while (buf.length() <= 13)
      {
        buf += " ";
      }
      cout << "#CALL  " << buf;
      buf = pb.getPhone();
      cout << buf << endl;
      find = true;
      break;
    }
    else if (input == pb.getPhone())
    {
      pb = contacts.at(i);
      buf = pb.getName();
      while (buf.length() <= 13)
      {
        buf += " ";
      }
      cout << "#CALL  " << buf;
      buf = pb.getPhone();
      cout << buf << endl;
      find = true;
      break;
    }
  }
  if (!find)
  {
    if (valid(input))
    {
      cout << "#CALL                " << input << endl;
    }
  }
  find = false;
}

void Contact::sms(PhoneBook &pb)
{
  cout << "@MESSAGE" << endl;
  getline(cin, message);

  int q = 0;
  while (q != -1)
  {
    cout << "Input name ^ number: ";
    getline(cin, input);

    if (input == "-1")
    {
      cout << "Abort message" << endl;
      q = -1;
      continue;
    }
    for (int i = 0; i < contacts.size(); ++i)
    {
      pb = contacts.at(i);
      if (input == pb.getName())
      {
        buf = pb.getName();
        while (buf.length() < 4)
        {
          buf += " ";
        }
        cout << "Message sent to " << buf;
        buf = pb.getPhone();
        cout << " " << buf << endl;
        find = true;
        q = -1;
        break;
      }
      else if (input == pb.getPhone())
      {
        buf = pb.getName();
        while (buf.length() < 4)
        {
          buf += " ";
        }
        cout << "Message sent to " << buf;
        buf = pb.getPhone();
        cout << " " << buf << endl;
        find = true;
        q = -1;
        break;
      }
    }    
    if (!find)
    {
      if (valid(input))
      {
        cout << "Message sent to      " << input << endl;
        q = -1;
      }
    }
    find = false;
  }
}

void Contact::show(PhoneBook &pb)
{
  for (int i = 0; i < contacts.size(); ++i)
  {
    pb = contacts.at(i);
    buf = pb.getName();
    while (buf.length() <= 20)
    {
      buf += " ";
    }
    cout << buf;
    buf = pb.getPhone();
    cout << buf << endl;
  }
}

bool Contact::valid(string phone)
{
  check = true;
  if (phone.length() != 12)
  {
    cerr << "Input error" << endl; check = false;
  }
  else if (phone.substr(0, 2) != "+7")
  {
    cerr << "Input error" << endl; check = false;
  }
  else
  {
    try
    {
      phone_num = stod(phone.substr(1, 11));
    }
    catch (const exception&)
    {
      cerr << "Input error" << endl; check = false;
    }
  }
  return check;
}

int Contact::exit(int q)
{
  q = -1;
  return q;
}