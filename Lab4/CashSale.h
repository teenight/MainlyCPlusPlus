#ifndef CASHSALE_H
#define CASHSALE_H
#include "Sale.h"
class CashSale : public Sale
{
public:
	CashSale(vector<string> & inventory, vector<float> & pricelist);

	float cashreceived;
	float changegiven;

	void process_payment();
	void print_sale();
	void print_payment();
	void setCashReceived(float cashin);
	float getCashReceived();
	void setChangeGiven(float change);
	float getChangeGiven();
};
#endif
