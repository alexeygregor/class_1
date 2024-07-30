#pragma once
#include <vector>
#include <string>
using namespace std;

class PhoneBook
{
  string name;
  string phone;

public:

  void setName(string n);

  string getName();

  void setPhone(string p);

  string getPhone();
};


class Contact
{
  double phone_num = 0;
  vector <PhoneBook> contacts;
  bool check = true, find = false;
  string name, phone, message, input, buf;

public:

  bool valid(string phone);

  void add(PhoneBook &pb);

  void call(PhoneBook &pb);

  void sms(PhoneBook &pb);

  void show(PhoneBook &pb);

  int exit(int q);
};
