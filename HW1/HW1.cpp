// Program 1:   HW1
// Name:        Zejian Zhong
// Class:       COMP 2710 Section 2
// Date:        09/18/2017
// E-Mail:      zzz0065@auburn.edu
//
// Description: This program provides a chat room
// 	        for users to share messages.


#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "===========================================================" <<endl;
	cout << "|         Welcome to the TigerBook Social Network!        |" <<endl;
	cout << "===========================================================";

	string message_buffer;
	string moreUsers = "yes";

	while (moreUsers == "yes")
	{
		cout << "\nEnter user name > ";
		string username;
		getline(cin, username);
		message_buffer += "<!" + username;
		cin.clear();
		cout << "Enter group name > ";
		string groupname;
		getline(cin, groupname);
		message_buffer += ":" + groupname + "!>";
		cin.clear();
		cout << "Enter the message > ";
		string message;
		getline(cin, message);

		while (message != "^!")
		{
			message_buffer += message + "^n";
			cin.clear();
			getline(cin, message);
		}
		cout << "\nAny more users? > ";
		getline(cin, moreUsers);
		cin.clear();
	}
	cout << "\nThe current messages are >>" << endl;

	while (message_buffer.length() > 0)
	{
		int startOfUserName = message_buffer.rfind("<!");
		int endOfUserName = message_buffer.rfind(":");
		int endOfGroupName = message_buffer.rfind("!>");
		string userName = message_buffer.substr(startOfUserName + 2, endOfUserName - startOfUserName - 2);
		string groupName = message_buffer.substr(endOfUserName + 1, endOfGroupName - endOfUserName - 1);
		cout << "\n" +  userName + " (" + groupName + ") >\n";
		string messageOnly = message_buffer.substr(endOfGroupName + 2);
		int newLine = messageOnly.find("^n");

		while (messageOnly.length() > 0)
		{
			string msg = messageOnly.substr(0, newLine);
			string msg2 = messageOnly.substr(newLine + 2, messageOnly.length());
			cout << msg + "\n";
			messageOnly = msg2;
			newLine = messageOnly.find("^n");
		}
		message_buffer = message_buffer.substr(0, startOfUserName);
	}
	return 0;
}
