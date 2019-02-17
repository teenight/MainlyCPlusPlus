#include "CreditCardSale.h"

CreditCardSale::CreditCardSale(vector<string> inventory, vector<float> pricelist) 
{
	descriptions.swap(inventory);
	prices.swap(pricelist);
	totalamount = 0;
	tax = 0;
	setType(prices.back());
	prices.pop_back();
	calculateSubtotal(prices);
}

void CreditCardSale::process_payment()
{
	cout << "Enter name on the credit card: ";
	while( getchar() != '\n' )
	{
		continue;
	}
	getline(cin, name, '\n');
	cout << "Enter credit card number: ";
	cin >> cardnumber;
	cout << "Enter expiration date: ";
	cin >> expiration;     
	formatReceipt();   
}

void CreditCardSale::print_sale()
{	
	print_payment();
}

void CreditCardSale::print_payment()
{
	string tempReceipt = receipt;
	ostringstream oss(ostringstream::out);
	oss << "\nCREDIT CARD\t" << name << " " << cardnumber << " " << expiration;
    oss << "\n";
	tempReceipt += oss.str(); 
	cout << tempReceipt;
}

void CreditCardSale::setName(string newname)
{
	name = newname;
}

string CreditCardSale::getName()
{
	return name;
}

void CreditCardSale::setExpiration(string newdate)
{
	expiration = newdate;
}

string CreditCardSale::getExpiration()
{
	return expiration;
}

void CreditCardSale::setCardNumber(string newnumber)
{
	cardnumber = newnumber;
}

string CreditCardSale::getCardNumber()
{
	return cardnumber;
}
