#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class user
{
	public:
	void getHomepage(string message_buffer);
       	void getWallPage(string message_buffer);
	user(std::string userNameIn);
	std::string getUsername();
	private:
	std::string username;
	string hashTag;
	void messageReader(int end, string subString;
};

#endif
