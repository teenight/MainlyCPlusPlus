#include "Sale.h"

Sale::Sale() 
{
	subtotal = 0;
	totalamount = 0;
	tax = 0;
	type = 0;
	receipt = "";					
}

void Sale::process_payment() {}

void Sale::print_sale()	{print_payment();}

void Sale::print_payment() {}

void Sale::formatReceipt()
{
	ostringstream oss(ostringstream::out);
	int N = descriptions.size();
	oss.precision(2);
	for(int i = 0; i < N ;i++)
	{
		oss << "\n" << i + 1 << ". " << descriptions.at(i) << "\t$ " << fixed << prices.at(i);
	}  
	string test = oss.str();
	oss << "\n   Sub-Total:\t$ " << fixed << getSubtotal();
	switch (getType())	
	{
		case REGULAR:
			oss << "\n   Tax:\t$ " << fixed << calculateTax();
			oss << "\n   Total amount:\t$ " << fixed << getTotal();
	  		break;
		case DISCOUNT:
			oss << "\n   Discount:\t$ " << calculateDiscount();
			oss << "\n   Sub-Total:\t$ " << getSubtotal();
			oss << "\n   Tax:\t$ " << calculateTax();		
			oss << "\n   Total amount:\t$ " << getTotal();
			break; 
	} 
	receipt = oss.str();  
}

float Sale::calculateSubtotal(vector<float> pricelist)
{
	float new_subtotal = 0;
	vector<float>::iterator i;
	for(i = pricelist.begin(); i < pricelist.end(); i++)
	{
		new_subtotal += (*i);
	}
	setSubtotal(new_subtotal);
	return subtotal;
}

void Sale::setSubtotal(float newsub)
{
	subtotal = newsub;
}

float Sale::getSubtotal()
{
	return subtotal;
}

float Sale::calculateDiscount()
{
	float discount = subtotal * DISCOUNTPRICE; 
	subtotal = subtotal - discount;
	return floorf(discount * 100 + 0.5) / 100;
}

float Sale::calculateTax()
{
	float tax = subtotal * TAX;
	totalamount = tax + subtotal; 
	return floorf(tax * 100 + 0.5) / 100;
}

void Sale::setTax(float newtax)
{
	tax = newtax;
}

float Sale::getTotal()
{
	return totalamount;
}

void Sale::setTotal(float newtotal)
{
	totalamount = newtotal;
}

void Sale::getDescriptions()
{		
	vector<string>::iterator s;
	for(s = descriptions.begin(); s < descriptions.end(); s++)
	{
		cout << (*s) << endl;
	}
	cout << endl << "END OF ITEMS" << endl;
}

void Sale::setDescriptions(vector<string> inventory)
{
	descriptions.swap(inventory);
}

void Sale::getPrices()
{
	vector<float>::iterator s;
	for(s = prices.begin(); s < prices.end(); s++)
	{
		cout << (*s) << endl;
	}
	cout << endl << "END OF ITEMS" << endl;
}

void Sale::setPrices(vector<float> newprices)
{
	prices.swap(newprices);
}

int Sale::getType()
{
	return type;
}

void Sale::setType(int salestype)
{
	type = salestype;
}
