#include <string>
#include "user.h"
using namespace std;

user::user(string userNameIn)
{
	username = userNameIn;
}

string user::getUsername()
{
	return username;
}

void user::getWallPage(string message_buffer)
{
	cout << "===========================================================" << endl;
	cout << "|              " + getUsername() + "’s Wall Page           |" << endl;
	cout << "===========================================================" << endl;

	int numberOfMessages = 0;
	while (message_buffer.length() > 0)
	{
		unsigned int startOfUserName;
		startOfUserName = message_buffer.rfind("!^");
		string subString = message_buffer.substr(startOfUserName, message_buffer.length());
		int endOfUserName = subString.rfind("^!");
		string userName;
		userName = subString.substr(2, (unsigned int) (endOfUserName - 2));
		numberOfMessages++
		if (numberOfMessages == 3)
		{
			string choice;
			do
			{
				cout << "More messages? (yes/no): " << endl;
				getline(cin, choice);
			}
			while (choice != "yes" && choice != "no");
			if (choice == "no")
			{
				break;
			}
		}
		message_buffer = message_buffer.substr(0, startOfUserName);
		cout << endl;
	}
}

void user::messageReader(int end, string subString)
{

	string message = subString.substr((unsigned int) (end + 2), subString.length() - 2);
	unsigned int newLine = message.find("$^");
	while (message.length() > 0)
	{
		string msg = message.substr(0, newLine);
		string msg2 = message.substr(newLine + 2, message.length());
		cout << msg << endl;
		message = msg2;
		newLine = message.find("$^");
	}
}
