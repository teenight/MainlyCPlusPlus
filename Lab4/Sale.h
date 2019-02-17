#ifndef SALE_H
#define SALE_H
#define TAX 0.08;
#define DISCOUNTPRICE 0.15;
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;
enum sale_type{REGULAR, DISCOUNT, MAILORDER};
class Sale
{
public:
	Sale();

	vector<string> descriptions;
	vector<float> prices;
	int type;
	float tax;
	float subtotal;
	float totalamount;
	string receipt;

	virtual void process_payment();
	void print_sale();
	virtual void print_payment();
	void formatReceipt();

	float calculateSubtotal(vector<float> prices);
	void setSubtotal(float newsub);
	float getSubtotal();
	float calculateDiscount();
	float calculateShipping(int num_items);
	float calculateTax();
	void setTax(float newtax);
	float getTotal();
	void setTotal(float newtotal);
	void getDescriptions();
	void setDescriptions(vector<string> inventory);
	void getPrices();
	void setPrices(vector<float> prices);
	int getType();
	void setType(int salestype);
};
#endif
