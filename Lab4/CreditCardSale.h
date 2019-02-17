#ifndef CREDITCARDSALE_H
#define CREDITCARDSALE_H
#include "Sale.h"
class CreditCardSale : public Sale
{
public:
	CreditCardSale(vector<string> inventory, vector<float> pricelist);

	string name;
	string expiration;
	string cardnumber;

	void process_payment();
	void print_sale();
	void print_payment();

	void setName(string);
	string getName();
	void setExpiration(string);
	string getExpiration();
	void setCardNumber(string);
	string getCardNumber();	
};
#endif
