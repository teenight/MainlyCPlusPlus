#include "Register.h"

	Register::Register()
	{
		numberOfSales = 0;
		numberOfItems = 0;
		tempSubtotal = 0;
	}
 
	void Register::beginItemize()
	{
		cout << "\n\n\t==========================================================================" << endl;		
		cout << "\t|			   Welcome to Tiger Store!		  	 |" << endl;
		cout << "\t==========================================================================" << endl;
		numberOfSales++;
		cout << "Select an option: (1) Regular Cash, (2) Regular Check, (3) Regular Credit Card, (4) Contract Cash, (5) Contract Check, (6) Contract Credit Card, (7) Print all sales or (8) Quit: ";
		switch (choseOption())
		{
			case 1:	addItems();
					handleSales(1);
					break;
			case 2:	addItems();
					handleSales(2);
					break;
			case 3:	addItems();
					handleSales(3);
					break;
			case 4:	addItems();
					handleSales(4);
					break;
			case 5:	addItems();
					handleSales(5);
					break;
			case 6:	addItems();
					handleSales(6);
					break;
			case 7:	printReceipts();
					break;
			case 8:	exit(0);
					break;
		}
	}

	void Register::printReceipts()
	{
		vector<Sale*>::iterator s;
		int i = 0;
		for(s = saleslist.begin(); s < saleslist.end(); s++,i++)
		{
			cout << endl << "Sales #" << (i + 1) << ":" << endl;
			(*s)->print_sale();
		}
		cout << endl << "END" << endl;
	}

	void Register::handleSales(int selection)
	{
		switch (selection)
		{	
			case 1:	cout << "Regular Sale" << endl;
					cout << "Tax: $" << calculateTempTax() << endl << endl;
					cout << "Total amount: $" << tempSubtotal << endl << endl;
					itemPrices.push_back(REGULAR);
					newCashSale();
					break;
			case 2:	cout << "Regular Sale" << endl;
					cout << "Tax: $" << calculateTempTax() << endl << endl;
					cout << "Total amount: $" << tempSubtotal << endl << endl;
					itemPrices.push_back(REGULAR);
					newCheckSale();
					break;
			case 3:	cout << "Regular Sale" << endl;
					cout << "Tax: $" << calculateTempTax() << endl << endl;
					cout << "Total amount: $" << tempSubtotal << endl << endl;
					itemPrices.push_back(REGULAR);
					newCreditCardSale();
					break;
			case 4:	cout << "Contractor Sale" << endl;
					cout << "Discount: $" << calculateTempDiscount() << endl << endl;
					cout << "Subtotal: $" << tempSubtotal << endl << endl;
					cout << "Tax: $" << calculateTempTax() << endl << endl;
					cout << "Total amount: $" << tempSubtotal << endl << endl;
					itemPrices.push_back(DISCOUNT);
					newCashSale();
					break;
			case 5:	cout << "Contractor Sale" << endl;
					cout << "Discount: $" << calculateTempDiscount() << endl << endl;
					cout << "Subtotal: $" << tempSubtotal << endl << endl;
					cout << "Tax: $" << calculateTempTax() << endl << endl;
					cout << "Total amount: $" << tempSubtotal << endl << endl;
					itemPrices.push_back(DISCOUNT);
					newCheckSale();
					break;
			case 6:	cout << "Contractor Sale" << endl;
					cout << "Discount: $" << calculateTempDiscount() << endl << endl;
					cout << "Subtotal: $" << tempSubtotal << endl << endl;
					cout << "Tax: $" << calculateTempTax() << endl << endl;
					cout << "Total amount: $" << tempSubtotal << endl << endl;
					itemPrices.push_back(DISCOUNT);
					newCreditCardSale();
					break;
		}
	}

	void Register::newCashSale()
	{
		CashSale *temp = new CashSale(itemNames, itemPrices);
		temp->process_payment();
		saleslist.push_back(temp);
	}

	void Register::newCheckSale()
	{
		CheckSale *temp = new CheckSale(itemNames, itemPrices);
		temp->process_payment();
		saleslist.push_back(temp);
	}

	void Register::newCreditCardSale()
	{
		CreditCardSale *temp = new CreditCardSale(itemNames, itemPrices);
		temp->process_payment();	
		saleslist.push_back(temp);
	}

	void Register::addItems()
	{
		numberOfItems = 0;
		itemNames.clear();
		itemPrices.clear();
		string itemName = "";
		float itemPrice = 0;
		while(true)
		{
			cout << "Enter item: ";
			while( getchar() != '\n')
			{
				continue;
			}
			getline(cin, itemName, '\n');
			if(itemName == "*")
			{
				break;
			}
			numberOfItems++;
			cout << "Enter amount: $";
			itemPrice = 0;
			cin >> itemPrice;
			itemNames.push_back(itemName);
			itemPrices.push_back(itemPrice);	
		}
		tempSubtotal = calculateTempSubtotal(itemPrices);
		cout.precision(2);
		cout << "Sub-total: $" << fixed << tempSubtotal << endl;
	}

	float Register::calculateTempSubtotal(vector<float> prices)
	{
		float sub = 0;
		for(int i = 0; i < numberOfItems; i++)
		{
			sub+= prices.at(i);
		}
		return sub;
	}

	char Register::choseOption()
	{
		int option;
		while(true)
		{
			cin >> option;
			if(option >= 9)
			{
				cout << "Invalid response. Please type only a number from 1 to 8." << endl;
				cout << "Enter reponse: ";
			}
			else if(option >= 1 && option <= 8)
			{
				return option;
			}
		}
	}

	float Register::calculateTempDiscount()
	{
		float discount = tempSubtotal * DISCOUNTPRICE; 
		tempSubtotal = tempSubtotal - (floorf(discount * 100 + 0.5) / (100));
		return floorf(discount * 100 + 0.5) / 100;
	}

	float Register::calculateTempTax()
	{
		float tax = tempSubtotal * TAX; 
		tempSubtotal = tempSubtotal + (floorf(tax * 100 + 0.5) / (100));
		return floorf(tax * 100 + 0.5) / 100;
	}
