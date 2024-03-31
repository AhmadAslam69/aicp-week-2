#include<iostream>
#include<string>

using namespace std;

bool parkingno(string code)
{
	if (code.length() != 5)
	{
		return false;
	}

	string numPart = code.substr(0, 4);
	int sum = 0;
	int multiplier = 1;


	for (int i = numPart.length() - 1; i >= 0; --i)
	{

		sum += (numPart[i] - '0') * multiplier;
		multiplier++;

	}

	int checkDigit = sum % 11;
	if (checkDigit == 10)

	{
		return (code[4] == '0');

	}

	else
	{
		return (code[4] - '0' == checkDigit);
	}
}


void price_topark(string day, int time, int hours, string code)
{

	double price = 0;
	do {
		cout << "Enter day: ";
		cin >> day;

		cout << "Enter hour of arrival (excluding minutes)(8-23) :";
		cin >> time;


		cout << "Enter total hours to leave your car :";
		cin >> hours;

		cout << "Enter any dicount code (enter 0 if no discoutn code):";
		cin >> code;

		if (time > 23 || time < 8)
		{
			cout << "invalid entry  enter again" << endl;
		}

	} while (time > 23 || time < 8);


	double discount = 0.0;
	if (time >= 16 && time <= 23)
	{

		if (parkingno(code))

		{
			discount = 0.50;
		}
		else

		{
			cout << "Discount code invalid. No discount applied." << endl;

		}

	}
	else
	{
		if (parkingno(code))
		{

			discount = 0.10;

		}

	}


	if (day == "sunday" && time >= 8 && time <= 15)
	{
		cout << "max stay in hours are allowed = 8" << endl;
		cout << "rate per hour: 2.00" << endl;


		price = hours * 2 * (1.0 - discount);
		cout << "price to park: " << price << " $";

		cout << "Discount applied: " << (discount * 100) << "%" << endl;

	}

	else if (day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" && time >= 8 && time <= 15)
	{
		cout << "max stay in hours are allowed = 2" << endl;
		cout << "rate per hour: 10.00" << endl;


		price = hours * 10 * (1.0 - discount);
		cout << "price to park: " << price << " $";

		cout << "Discount applied: " << (discount * 100) << "%" << endl;


	}

	else if (day == "saturday" && time >= 8 && time <= 15)
	{
		cout << "max stay in hours are allowed = 4" << endl;
		cout << "rate per hour: 3.00" << endl;

		price = hours * 3 * (1.0 - discount);
		cout << "price to park: " << price << " $";

		cout << "Discount applied: " << (discount * 100) << "%" << endl;



	}


	else if (day == "sunday" || day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" ||
		day == "friday" || day == "saturday" && time >= 16 && time <= 23)

	{
		cout << "max stay in hours are allowed upto midnight" << endl;
		cout << "rate per hour: 2.00" << endl;
		price = hours * 2 * (1.0 - discount);
		cout << "price to park: " << price << " $";
		cout << "Discount applied: " << (discount * 100) << "%" << endl;


	}


    




	// task 2 
	double am;
	double ttl = 0;
	cout << "enter amount to pay (amount should be greater or equal to amount showed) :";
	cin >> am;

	do {
		if (am < price)
		{
			cout << "amount is less deposit again" << endl;


		}
		else
		{
			ttl += am;


		}
	} while (am < price);

	cout << "daily total amount = " << ttl << " $" << endl;






	// task 3
	cout << endl << endl;
	cout << "New pricings including payments fairer " << endl;
	double price_before_16 = 0.0;
	double price_after_16 = 0.0;


	if (time >= 8 && time <= 15)
	{
		if (day == "sunday")
		{
			int max_hours = 8;
			double rate = 2.00;
			price_before_16 = min(hours, max_hours) * rate * (1.0 - discount);

		}
		else if (day == "saturday")
		{
			int max_hours = 4;
			double rate = 3.00;
			price_before_16 = min(hours, max_hours) * rate * (1.0 - discount);

		}
		else
		{
			int max_hours = 2;
			double rate = 10.00;
			price_before_16 = min(hours, max_hours) * rate * (1.0 - discount);

		}

	}


	if (time >= 16 && time <= 23)

	{
		double rate = 2.00;

		price_after_16 = (hours - 8) * rate * (1.0 - discount);

	}

	double total_price = price_before_16 + price_after_16;

	cout << "Price to park: " << total_price << " $" << endl;
	cout << "Discount applied: " << (discount * 100) << "%" << endl;


}



int main()

{
	string day = "0";
	int time = 0;
	int hours = 0;
	string code = "0";





	price_topark(day, time, hours, code);

	return 0;
}



