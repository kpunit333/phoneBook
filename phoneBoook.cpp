#include<bits/stdc++.h>
using namespace std;

map<string, set<string>> ph;
map<string, string> revph;

string cyan = "\033[96m";
string red = "\033[31m";
string yellow = "\033[33m";
string green = "\033[92m";
string white = "\033[97m";

string shift = "\t\t\t\t";

void loadingScreen(char c, int length)
{
	system("Color 0E");
	string loadComplete = "";

	cout << endl << endl;

	cout << shift << "=========================================" << endl;
	cout << shift << "|              PHONE BOOK               |" << endl;
	cout << shift << "=========================================" << endl;

	cout << shift << "|                                       |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "|               Loading..               |" << endl;
	cout << shift << "|                                       |" << endl;

	cout << shift ;
	for(int i=0; i<=length; i++)
    {
        cout << c ;
        loadComplete += c;
        _sleep(100);
    }
    cout << endl;

	cout << shift << "|                                       |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "=========================================" << endl;

	system("cls");
	cout << endl << endl ;

	cout << shift << "=========================================" << endl;
	cout << shift << "|              PHONE BOOK               |" << endl;
	cout << shift << "=========================================" << endl;

	cout << shift << "|                                       |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "|         Loading Complete...           |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << loadComplete << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "|                                       |" << endl;
	cout << shift << "=========================================" << endl;
	_sleep(1000);
	system("cls");
}

void start()
{
	cout << cyan << endl << endl;

	cout << shift <<  "=========================================" << endl;
	cout << shift <<  "|              PHONE BOOK               |" << endl;
	cout << shift <<  "=========================================" << endl;

	cout << shift <<  "|          [1] Add contact              |" << endl;
	cout << shift <<  "|          [2] Display all contacts     |" << endl;
	cout << shift <<  "|          [3] Search by number         |" << endl;
	cout << shift <<  "|          [4] Search by name           |" << endl;
	cout << shift <<  "|          [5] Update contact           |" << endl;
	cout << shift <<  "|          [6] Delete contact           |" << endl;
	cout << shift <<  "|          [7] Delete All               |" << endl;
	cout << shift <<  "|          [8] Number of contacts       |" << endl;

	cout << shift <<  "=========================================" << endl;
	cout << shift <<  "|          [0] Exit                     |" << endl;
	cout << shift <<  "=========================================" << endl;

}

void display(string name)
{
    cout << shift;

	cout << green << "Name : " << white << name << "\t";

	cout << green << "Phone numbers : " << white;

	for(auto it = ph[name].begin(); it!=ph[name].end(); it++)
	{
		cout << *it ;
		auto next = it;

		if(++next != ph[name].end())
		{
			cout << ", ";
		}
	}

	cout << cyan << endl;
}


void display(string name, string number)
{
    cout << shift ;

	cout << green << "Name : " << white << name << "\t";

	cout << green << "Phone numbers : " << white;

	for(auto it = ph[name].begin(); it!=ph[name].end(); it++)
	{
	    if(*it == number)
        {
            cout << yellow;
        }

		cout << *it << white ;
		auto next = it;

		if(++next != ph[name].end())
		{
			cout << ", ";
		}
	}

	cout << cyan << endl;
}

void displayrv()
{
    cout <<  shift ;

	for(auto it : revph)
	{
		cout << green << "Name : " << white << it.second << "\t" ;
		cout << green << "Phone numbers : " << white << it.first << endl;
	}

	cout << cyan << endl;

}

void status(int n)
{
	string msg = (n==0) ? "Contact not found.." : "Contact found..";
	string color = (n==0) ? red : green;

	system("cls");

	cout << endl << color ;
	cout << shift <<  "-----------------------------------------" << endl;
	cout << shift <<  "   " << msg << endl;
	cout << shift <<  "-----------------------------------------" << endl;
	cout << cyan << endl;
}

void status(string msg)
{
    system("cls");

	cout << endl << green ;
	cout << shift <<  "-----------------------------------------" << endl;
	cout << shift <<  "   " << msg << endl;
	cout << shift <<  "-----------------------------------------" << endl;
	cout << cyan << endl;
}

void status(int n, string msg)
{
    system("cls");

	cout << endl << green ;
	cout << shift <<  "-----------------------------------------" << endl;
	cout << shift <<  "   " << n << " " << msg << endl;
	cout << shift <<  "-----------------------------------------" << endl;
	cout << cyan << endl;
}

int choice()
{
	int a;
	cout << shift << "=========================================" << endl;
	cout << shift << "| Enter choice : ";

	cin >> a;
	return a;
}

void replaceContact(string name, string newNumber)
{
    for(auto it : ph[name])
    {
        revph.erase(it);
    }

    ph.erase(name);
    ph[name].insert(newNumber);

    revph[newNumber] = name;
}

void replaceNumber(string newName, string number)
{
    ph[revph[number]].erase(number);
    revph.erase(number);

    ph[newName].insert(number);
    revph[number] = newName;
}

void newContact(string name, string number)
{
	set<string> s;
	s.insert(number);
	ph[name] = s;

	revph[number] = name;
}

void mergeContact(string name, string number)
{
	ph[name].insert(number);

	revph[number] = name;
}

void addContact()
{
    cout << endl << shift << "Adding new contact" << endl;
    cout <<  shift << "-----------------------------------------" << endl << endl;

	int a = 0;

	string name;
	cout << shift << "Enter name : ";
	cin >> name;

	string number;
	cout << shift << "Enter phone number : ";
	cin >> number;

	while(ph.find(name) != ph.end())
	{
		status("Contact already exist..");

		cout <<  shift << "=========================================" << endl;
		cout <<  shift << "|          [1] Rename contact           |" << endl;
		cout <<  shift << "|          [2] Merge contact            |" << endl;
		cout <<  shift << "|          [3] Replace contact          |" << endl;
		cout <<  shift << "|          [0] Exit                     |" << endl;

		a = choice();

		if(a == 0)
		{
			return;
		}
		else if(a == 1)
		{
			cout << endl << shift << "Enter new name : ";
			cin >> name;
		}
		else if(a == 2)
		{
			mergeContact(name, number);
			status("Contact merged..");
			return;
		}
		else if(a == 3)
        {
            replaceContact(name, number);
            status("Contact replaced..");
            return;
        }
		else
		{
			cout << endl << shift << "Invalid choice..";
			return;
		}
	}

    while(revph.find(number) != revph.end())
	{
		status("Number already exist..");
		cout << shift <<  "=========================================" << endl;
		cout << shift <<  "|        [1] Edit number                |" << endl;
		cout << shift <<  "|        [2] Add to new contact         |" << endl;
		cout << shift <<  "|        [0] Exit                       |" << endl;

		a = choice();

		if(a == 0)
		{
			return;
		}
		else if(a == 1)
		{
			cout << endl << "Enter new number : ";
			cin >> number;
		}
		else if(a == 2)
		{
			replaceNumber(name, number);
			status("Contact replaced..");
			return;
		}
		else
		{
			cout << endl << shift << "Invalid choice..";
			return;
		}
	}

	newContact(name, number);
	status("New contact added..");
}

void displayContact()
{
    cout << endl;

	if(ph.size()==0)
	{
		status(0, "Contacts found..");
		return;
	}

	for(auto it : ph)
	{
		display(it.first);
	}
}

void searchByNumber()
{
    cout << endl << shift << "Searching by number" << endl;
    cout <<  shift << "-----------------------------------------" << endl << endl;

	string number;
	cout << shift << "Enter phn number : ";
	cin >> number;

//	if(revph.find(number) != revph.end())
//    {
//        status(1);
//        display(revph[number], number);
//        return;
//    }
//
//	status(0);

    int found = 0;
	for(auto it : revph)
    {
        if(it.first.find(number) != string::npos)
        {
            found++;
        }
    }

    if(found > 0)
    {
        status(found, "Contacts found..");
        for(auto it : revph)
        {
            if(it.first.find(number) != string::npos)
            {
                cout << shift << green << "Phone numbers : " << white << it.first << "\t";
                cout << green << "Name : " << white << it.second << endl ;
            }
        }
        return;
    }
    else
    {
        status(0);
    }
}

void searchByName()
{
    cout << endl << shift << "Searching by Name" << endl;
    cout <<  shift << "-----------------------------------------" << endl << endl;

	string name;
	cout << shift << "Enter name : ";
	cin >> name;

	int found = 0;
	for(auto it : ph)
    {
        if(it.first.find(name) != string::npos)
        {
            found++;
        }
    }

    if(found > 0)
    {
        status(found, "Contacts found..");
        for(auto it : ph)
        {
            if(it.first.find(name) != string::npos)
            {
                display(it.first);
            }
        }
        return;
    }
    else
    {
        status(0);
    }

}

void updateNumber(string oldNumber, string newNumber)
{
    string name = revph[oldNumber];

    revph.erase(oldNumber);
    revph[newNumber] = name;

    ph[name].erase(oldNumber);
    ph[name].insert(newNumber);
}

void updateName(string oldName, string newName)
{
    ph[newName] = ph[oldName];

    for(auto it : ph[newName])
    {
        revph[it] = newName;
    }

    ph.erase(oldName);
}

void updateContact()
{
    cout << endl;
    cout << endl << shift << "Updating contact" << endl;
    cout <<  shift << "-----------------------------------------" << endl << endl;

    cout << shift <<  "=========================================" << endl;
    cout << shift <<  "|     [1] Update contact number         |" << endl;
    cout << shift <<  "|     [2] Update contact name           |" << endl;
    cout << shift <<  "|     [0] Exit                          |" << endl;

    int a = choice();

    if(a == 0)
    {
        return;
    }
    else if(a == 1)
    {
        string oldNumber, newNumber;
        cout << shift << "Enter old number : ";
        cin >> oldNumber;

        cout << shift << "Enter new number : ";
        cin >> newNumber;

        updateNumber(oldNumber, newNumber);
        return;
    }
    else if(a == 2)
    {
        string oldName, newName;
        cout << shift << "Enter old name : ";
        cin >> oldName;

        cout << shift << "Enter new name : ";
        cin >> newName;

        updateName(oldName, newName);
        return;
    }
    else
    {
        cout << endl << "Invalid choice.." << endl;
        return;
    }
}

void deleteContact()
{
    cout << endl << shift << "Deleting contact" << endl;
    cout <<  shift << "-----------------------------------------" << endl << endl;

	string name;
	cout << shift << "Enter name : ";
	cin >> name;

	cout << endl << endl;
	cout << shift <<  "Are you sure you want to delete this contact ? " << endl;
    cout << shift <<  "=========================================" << endl;
    cout << shift <<  "|              [1] Yes                  |" << endl;
    cout << shift <<  "|              [2] No                   |" << endl;

    int a = choice();

    if(a == 1)
    {
        for(auto it : ph[name])
        {
            revph.erase(it);
        }

        ph.erase(name);
        status("Contact deleted..");
        return;
    }

    if(a != 2)
    {
        cout << shift << "Invalid Choice..." << endl;
        return;
    }

    status("Cancelled..");
    return;
}


void deleteAll()
{
    cout << endl << endl;

    cout << shift <<  "Are you sure you want to clear all ? " << endl;
    cout << shift <<  "=========================================" << endl;
    cout << shift <<  "|              [1] Yes                  |" << endl;
    cout << shift <<  "|              [2] No                   |" << endl;

    int a = choice();

    if(a == 1)
    {
        ph.clear();
        revph.clear();
        status("PhoneBook cleared..");
        return;
    }

    if(a != 2)
    {
        cout << shift << "Invalid Choice..." << endl;
        return;
    }

    status("Cancelled..");
    return;

}

void countContact()
{
	status(ph.size(), "Contacts found..");
}


void operation(int choice)
{
	system("cls");
	switch(choice)
	{
		case 1:
			addContact();
			break;

		case 2:
			displayContact();
			break;

		case 3:
			searchByNumber();
			break;

		case 4:
			searchByName();
			break;

		case 5:
			updateContact();
			break;

		case 6:
			deleteContact();
			break;

		case 7:

			deleteAll();
			break;

		case 8:
			countContact();
			break;

		case 0:
			exit(0);

		default:
			cout << "Invalid choice.." << endl;
	}
}


int main()
{
	loadingScreen(219, 40);
	int option = 9;
	do
	{
		start();
		int option = choice();
		operation(option);

	}while(option != 0);


 	return 0;
}

