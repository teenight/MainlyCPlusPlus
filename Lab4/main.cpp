// Lab 4:	L4
// Name:	Zejian Zhong
// Class:	COMP 2710 Section 2
// Date: 	12/8/2017
// E-mail: 	zzz0065@auburn.edu
//
// Description:	This program is a simple cash register application that calculate price and print receipt.
#include <iostream>
#include <vector>
#include "Register.h"

using namespace std;

int main(int argc, char *argv[])
{
	Register r = Register();
	while(true)
	{
		r.beginItemize();
	}
	return 0;	
}
