#ifndef REGISTER_H
#define REGISTER_H
#define TAX 0.08;
#define DISCOUNTPRICE 0.15;
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "CashSale.h"
#include "CheckSale.h"
#include "CreditCardSale.h"
using namespace std;

class Register
{
public:
	Register();

	void beginItemize();
	void addItems();
	void enterItemName();
	void enterPrice();
	float calculateTempSubtotal(vector<float> prices);
	char choseOption();
	
	char choseSale();
	float calculateTempDiscount();
	void handleSales(int selection);

	float calculateTempTax();

	void newCashSale();
	void newCheckSale();
	void newCreditCardSale();

	void printReceipts();

	vector<Sale *> saleslist;
	int numberOfSales;

	vector<string> itemNames;
	int numberOfItems;
	vector<float> itemPrices;
	float tempSubtotal;
};
#endif
