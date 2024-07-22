#include <map>
#include <string>
#include <iostream>
using namespace std;

class PhoneBook
{
  string phone, name;
  map<string, string> phonebook;
  map<string, string> phonebooks;
  map<string, string>::iterator it;
  map<string, string>::iterator itf;

public:

  bool valid (string phone)
  {
    bool check = true;
    double phone_num = 0;
    if (phone.length() != 10)
    { cerr << "Input error: " << "incorrect phone" << endl; check = false; }
    else
    {
      try
      { phone_num = stod(phone); }
      catch (const exception& e)
      { cerr << "Input error: incorrect phone" << endl; check = false; }
    }
    return check;
  }

  void add()
  {
    cout << "Insert phone number: +7 ";
    getline(cin, phone);

    if (valid(phone))
    {
      it = phonebook.find(phone);
      if (it->first == phone)
      { cerr << "Phone is already reserved" << endl; }

      cout << "Insert Name: ";
      getline(cin, name);
      itf = phonebooks.find(name);
      if (itf->first == name)
      { cerr << "Name is already reserved" << endl; }

      phonebook.insert(pair<string, string> (phone, name));
      phonebooks.insert(pair<string, string> (name, phone));
    }
  }

  void show()
  {
    for (it = phonebook.begin(); it != phonebook.end(); ++it)
      cout << "#" << it->first << " " << it->second << endl;
  }

  void call(string input)
  {
    int cnt = 0;
    if (input == "+7")
    {
      getline(cin, phone);
      if (valid (phone))
      {
        it = phonebook.find(phone);
        if (it->first == phone)
          cout << "CALL +7 " << it->first << " " << it->second << endl;
        else cout << "CALL +7 " << phone << endl;
      }
    }
    else
    {
      name = input;
      itf = phonebooks.find(name);
      if (itf->first == name)
        cout << "CALL +7 " << itf->second << " " << itf->first << endl;
      else
        cerr << "Not found" << endl;
    }
  }
};

class Phone
{
  string input, message;

public:

  void add(PhoneBook* phonebook)
  {
    phonebook->add();
  }

  void show(PhoneBook* phonebook)
  {
    phonebook->show();
  }

  void call(PhoneBook* phonebook)
  {
    getline (cin, input);
    phonebook->call(input);
  }

  void sms(PhoneBook* phonebook)
  {
    cout << "Input number: +7 ";
    getline(cin, input);

    if (phonebook->valid(input))
    {
      cout << "@" << endl;
      getline(cin, message);
      cout << "@" << endl;
      cout << "Message sent" << endl;
    }
  }

  int exit(int q)
  {
    q = -1;
    return q;
  }
};

int main()
{
  int q = 0;
  string command;

  Phone* phone = new Phone;
  PhoneBook* phonebook = new PhoneBook;

  while(q != -1)
  {
    cout << "\nEnter command: ";
    getline(cin, command);

    if (command == "exit")
      q = phone->exit(q);

    if (command == "add")
      phone->add(phonebook);

    if (command == "call")
      phone->call(phonebook);

    if (command == "show")
      phone->show(phonebook);

    if (command == "sms")
      phone->sms(phonebook);
  }
  delete phone;
  delete phonebook;
}
