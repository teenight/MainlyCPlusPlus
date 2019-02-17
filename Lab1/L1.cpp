// Lab 1:       L1
// Name:        Zejian Zhong
// Class:       COMP 2710 Section 2
// Date:        10/12/2017
// E-Mail:      zzz0065@auburn.edu
//
// Description: This program names TigerBook Social Network, which is similar to Facebook
//		that is widely used for social networking and sharing of information among friends.


#include <iostream>
#include "user.h"
#include <string>
#include <vector>
using namespace std;

void createNewUser();
string optionSelected();
void quit();
vector<user> users;
int currentUser = 0;
int switchUser();
void broadCast();
void multiCast();
void unicast();
string message_buffer;

void switchCase(string option);

int main()
{
	cout << "===========================================================" << endl;
	cout << "|         Welcome to the TigerBook Social Network!        |" << endl;
	cout << "===========================================================" << endl;
	string option;
	do
	{
		option = optionSelected();
		switchCase(option);
	}
	while (option != "q");
	return 0;
}

string optionSelected()
{
	cout << "Create new user (n), Broadcast (b), Multicast (m), Unicast (u), " + 
		"Wall page (w), Home page (h), Create new group (g), " + 
		"Join a group (j), Switch user (s), Quit (q)" << endl;
	cout << "Please choose an option: ";
	string option;
	getline(cin, option);
	cout << endl;
	return option;
}

void createNewUser()
{
	cout << "Please enter user name: ";
	std::string username;
	getline(cin, username);
	if (users.size() > 0) 
	{
		currentUser++;
		users.push_back(user(username));
		cout << "\t===========================================================" << endl;
		cout << "\t|        Welcome to TigerBook Social Network, " + 
			 users[currentUser].getUsername() + "!      |" << endl;
		cout << "\t===========================================================" << endl;
	}
}

void quit()
{
	cout << "\t===========================================================" << endl;
	cout << "\t|         Thank you for using TigerBook Social Network    |" << endl;
	cout << "\t===========================================================" << endl;
}

void switchCase(string o)
{
	const char *option = o.c_str();
    	switch (*option) 
	{
	case 'n':
		createNewUser();
		break;
	/*case 'b':
		if (users.size() < 1)
		{
            		cout << "No user defined." << endl;
		}
       		else
		{
           		broadCast();
		}
		break;
	case 'm':
		if (users.size() < 1)
		{
			cout << "No user defined." << endl;
		}
		else
		{
			multiCast();
		}
	case 'u':
                if (users.size() < 1)
                {
                        cout << "No user defined." << endl;
                }
                else
                {
                        unicast();
                }*/
	case 'w':
        	if (users.size() < 1)
		{
			cout << "No user defined." << endl;
		}
        	else
		{
			users[currentUser].getWallPage(message_buffer);
		}
		break;
	case 'h':
        	if (users.size() < 1)
		{
            		cout << "No user defined." << endl;
		}
        	else
		{
			users[currentUser].getHomepage(message_buffer);
		}
		break;
	/*case 'g':
		if (users.size() < 1)
		{
			cout << "No user defined." << endl;
		}
		else
		{
			users[currentUser].createNewGroup();
		}
	case 'j':
        	if (users.size() < 1)
		{
            		cout << "No user defined." << endl;
		}
        	else
		{
			users[currentUser].joinGroup();
		}
		break;*/
	case 's':
        	if (users.size() < 2)
		{
            		cout << "Not enough users defined." << endl;
		}
        	else
		{
			switchUser();
		}
		break;
	case 'q':
		quit();
		break;
	default:
		cout << "Invalid input." << endl;
		break;
	}
}

int switchUser()
{
	cout << "Enter user's name: " << endl;
	string username;
	getline(cin, username);
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername() == username)
		{
			currentUser = i;
			break;
		}
		if (users[i].getUsername() != username)
		{
			cout << "User does not exist" << endl;
		}
		else
		{
			cout << "\t===========================================================" << endl;
                	cout << "\t|        Welcome to TigerBook Social Network, " +
                         users[currentUser].getUsername() + "!      |" << endl;
                	cout << "\t===========================================================" << endl;
	       	}
	}
}

/*void broadCast()
{
	cout << "Enter message: " << endl;
	message_buffer += "^!" + users[currentUser].getUsername();
	string message;
	while (message != "\n^!")
	{
		message_buffer += message;
		message_buffer += "$^";
		cin.clear();
		getline(cin, message);
	}
	cout << endl;
}
*/
