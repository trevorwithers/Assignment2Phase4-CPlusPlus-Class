#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
//Trevor Withers
//Program to track customer purchaces and calculate costs


int main()
{
	//Housekeeping
	string custName;
	string meatChoice;
	char meatType = ' ';
	double weight, cost, beef = 7.95, chicken = 5.49, pork = 6.8, totalSales = 0, averageSales = 0;
	int noPurchases = 0;

	ofstream fout("receipts.data");
	if (!(fout.is_open()))
	{
		cout << "The file could not load. Program will now terminate..." << endl;
		system("pause");
		exit(-1);
	}
	fout << fixed << setprecision(2);

	//Input
	//The next fout statement needs to be here so that it is not repeated in the loop.
	cout << "Welcome! Please enter the customer name, meat type, and total weight (in kg)." << endl << "Press ctr + z at any time to exit." << endl;
	cout << "Please enter the customer's name (or ctrl z to exit): ";
	getline(cin, custName);
	while (!cin.eof())
	{
		noPurchases++;
		while (custName == "") //Validate name is not blank
		{
			cin.clear();
			cout << "No name entered. Please enter name: ";
			getline(cin, custName);
		}
		cout << "Please enter the first letter of the meat type (B, C, or P): ";
		cin >> meatType; //Enter meat type
		meatType = toupper(meatType);
		while (meatType != 'B' && meatType != 'C' && meatType != 'P') //Validate meat type is appropriate entry
		{
			cout << endl << "Invalid meat type entered. Please re-enter meat type: ";
			cin >> meatType;
			meatType = toupper(meatType);
		}
		cout << "Please enter total weight (in kgs): ";
		cin >> weight; //Enter the total weight
		while (cin.fail() || weight < 0.0) //Validate weight is a number and greater than 0
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Weight must be greater than 0 and a number. Please reenter weight: ";
			cin >> weight;
		}

		//Proccessing
		if (meatType == 'B')
		{
			cost = weight * beef;
			meatChoice = "Beef";
		}
		else if (meatType == 'C')
		{
			cost = weight * chicken;
			meatChoice = "Chicken";
		}
		else if (meatType == 'P')
		{
			cost = weight * pork;
			meatChoice = "Pork";
		}
		totalSales += cost;
		averageSales = totalSales / noPurchases;

		//Output
		fout << setw(35) << "ABC Butcher Shop" << endl;
		fout << "Customer: " << custName << endl << endl;
		fout << "Meat Purchased:" << endl;
		fout << meatChoice << "@ " << cost / weight << "kg" << setw(15) << cost << endl << endl;
		cout << "Please enter the customer's name (or ctrl z to exit): ";
		cin.ignore(80, '\n');
		getline(cin, custName);
	}
	cout << "Cash Closed" << endl;
	fout << "Total Sales: " << setw(15) << totalSales << endl;
	fout << "Average Sales: " << setw(15) << averageSales << endl;

	system("type receipts.data");
	system("pause");

	/*
		Welcome! Please enter the customer name, meat type, and total weight (in kg).
		Press ctr + z at any time to exit.
		Please enter the customer's name (or ctrl z to exit): Trevor
		Please enter the first letter of the meat type (B, C, or P): C
		Please enter total weight (in kgs): 44
		Please enter the customer's name (or ctrl z to exit): Dan
		Please enter the first letter of the meat type (B, C, or P): B
		Please enter total weight (in kgs): 55
		Please enter the customer's name (or ctrl z to exit): Pete
		Please enter the first letter of the meat type (B, C, or P): P
		Please enter total weight (in kgs): 12
		Please enter the customer's name (or ctrl z to exit): ^Z
		Cash Closed
						   ABC Butcher Shop
		Customer: Trevor

		Meat Purchased:
		Chicken@ 5.49kg         241.56

						   ABC Butcher Shop
		Customer: Dan

		Meat Purchased:
		Beef@ 8.80kg         484.00

						   ABC Butcher Shop
		Customer: Pete

		Meat Purchased:
		Pork@ 6.80kg          81.60

		Total Sales:          807.16
		Average Sales:          269.05
		Press any key to continue . . .
	*/

}