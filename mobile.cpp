#include <vector>
#include <string>
#include <iostream>
using namespace std;

class PhoneBook
{
  string name;
  string phone;

public:

  vector <string> contact;

  string setName(string n)
  {
    name = n;
    return name;
  }

  string getName()
  {
    return name;
  }

  string setPhone(string p)
  {
    phone = p;
    return phone;
  }

  string getPhone()
  {
    return phone;
  }

  void contacts()
  {
    contact.push_back(getName());
    contact.push_back(getPhone());
  }
};


class Contact
{
  bool find = false;
  string name, phone, message, input, buf;

public:

  bool valid(string phone)
  {
    bool check = true;
    double phone_num = 0;

    if (phone.length() != 12)
    {
      cerr << "Input error " << endl; check = false;
    }
    else if (phone.substr(0, 2) != "+7")
    {
      cerr << "Input error " << endl; check = false;
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

  void add(PhoneBook* pb)
  {
    cout << "Insert Phone number: ";
    getline (cin, phone);

    if (valid(phone))
    {
      cout << "Insert Name: ";
      getline(cin, name);

      pb->setName(name);
      pb->setPhone(phone);
      pb->contacts();
    }
  }

  void call(PhoneBook* pb)
  {
    cout << "Input name or number: ";
    getline(cin, input);

    for (int i = 0; i < pb->contact.size(); ++i)
    {
      if (input == pb->contact[i])
      {
        if (i % 2 == 0)
        {
          name = input;
          cout << "#CALL  " << name << endl;
          find = true;
          break;
        }
        else if (i % 2 != 0)
        {
          phone = input;
          cout << "#CALL  " << phone << endl;
          find = true;
          break;
        }
      }
    }
    if (!find)
    {
      phone = input;
      if (valid(phone))
      {
        cout << "#CALL  " << phone << endl;
      }
    }
    find = false;
  }

  void sms(PhoneBook* pb)
  {
    cout << "@MESSAGE" << endl;
    getline(cin, message);

    int q = 0;
    while (q != -1)
    {
      cout << "Input name or number: ";
      getline(cin, input);

      if (input == "-1")
      {
        cout << "@Abort message" << endl;
        q = -1;
        continue;
      }
      for (int i = 0; i < pb->contact.size(); ++i)
      {
        if (input == pb->contact[i])
        {
          if (i % 2 == 0)
          {
            name = input;
            cout << "@Message sent to " << name << endl;
            find = true;
            q = -1;
            break;
          }
          else if (i % 2 != 0)
          {
            phone = input;
            cout << "@Message sent to " << phone << endl;
            find = true;
            q = -1;
            break;
          }
        }
      }
      if (!find)
      {
        phone = input;
        if (valid(phone))
        {
          cout << "@Message sent to " << phone << endl;
          q = -1;
        }
      }
      find = false;
    }
  }

  void show(PhoneBook* pb)
  {
    for (int i = 0; i < pb->contact.size(); ++i)
    {
      buf = pb->contact[i];
      if (i % 2 == 0)
      {
        while (buf.length() <= 20)
        {
          buf += " ";
        }
      }
      cout << buf;
      if (i % 2 != 0)
      {
        cout << endl;
      }
    }
  }

  int exit (int q)
  {
    q = -1;
    return q;
  }
};


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
      contact->exit(q);
    }
    if (command == "add")
    {
      contact->add(pb);
    }
    if (command == "call")
    {
      contact->call(pb);
    }
    if (command == "show")
    {
      contact->show(pb);
    }
    if (command == "sms")
    {
      contact->sms(pb);
    }
  }

  delete contact;
  delete pb;
}
