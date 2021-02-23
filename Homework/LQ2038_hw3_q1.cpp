//Homework 3 Question 1
/*
To compute how much a customer has to pay after purchasing two
items. The price is calculated according to the following rules:
• Buy one get one half off promotion: the lower price item is half price.
• If the customer is club card member, additional 10% off.
• Tax is added.
Inputs to the program include:
• Two items’ prices
• Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
• Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax
rate is 8.25%)
Program displays:
• Base price - the price before the discounts and taxes
• Price after discounts - the price after the buy one get one half off promotion and the
member’s discount, if applicable
• Total price – the amount of money the customer has to pay (after tax).
*/
#include <iostream>
using namespace std;
const double MEMBERSHIP_DISCOUNT = 0.1;
int main()
{
	double price1, price2;
	double basePrice, discountPrice, taxRate, totalPrice;
	char clubCard;
	cout << "Enter price of first item: ";
	cin >> price1;
	cout << "Enter price of second item: ";
	cin >> price2;
	basePrice = price1 + price2;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> clubCard;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxRate;
	if (price1 > price2)
	{
		discountPrice = price1 + 0.5 * price2;
	}		
	else
	{
		discountPrice = 0.5 * price1 + price2;
	}		
	if ((clubCard == 'Y') || (clubCard == 'y'))
	{
		discountPrice *= 1 - MEMBERSHIP_DISCOUNT;
	}		
	totalPrice = discountPrice * (1 + taxRate / 100);
	//The output format is not set to 2 digits after decimal point,
	//which is to fit the example in the instruction of the question.
	cout << "Base price: " << basePrice << endl;
	cout << "Price after discounts: " << discountPrice << endl;
	cout << "Total price: " << totalPrice << endl;
	return 0;
}