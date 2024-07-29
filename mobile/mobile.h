#pragma once
#include <vector>
#include <string>
using namespace std;

class PhoneBook
{
  string name;
  string phone;
  vector <string> contact_name;
  vector <string> contact_phone;

public:

  void setName(string n);

  string getName();

  void setPhone(string p);

  string getPhone();

  void setContacts();

  vector <string> getVecName(vector <string> vecName);

  vector <string> getVecPhone(vector <string> vecPhone);
};


class Contact
{
  double phone_num = 0;
  bool check = true, find = false;
  string name, phone, message, input, buf;
  vector <string> vecName;
  vector <string> vecPhone;

public:

  bool valid(string phone);

  void add(PhoneBook* pb);

  void call(PhoneBook* pb);

  void sms(PhoneBook* pb);

  void show(PhoneBook* pb);

  int exit(int q);
};
