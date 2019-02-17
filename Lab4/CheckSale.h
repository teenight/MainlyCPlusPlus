#ifndef CHECKSALE_H
#define CHECKSALE_H
#include "Sale.h"
class CheckSale : public Sale
{
public:
	CheckSale(vector<string> inventory, vector<float> pricelist);

	string name;
	string driverslicense;

	void process_payment();
	void print_sale();
	void print_payment();
	void setCashReceived(float cashin);
	float getCashReceived();
	void setChangeGiven(float change);
	float getChangeGiven();

	void setName(string newname);
	string getName();
	void setNumber(string newnumber);
	string getNumber();
};
#endif
