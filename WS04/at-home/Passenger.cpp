#define _CRT_SECURE_NO_WARNINGS
#include"Passenger.h"
#include<iostream>
#include<cstring>
using namespace std;
using namespace sict;

/*Default constructor*/

Passenger::Passenger()
{
	flag = false;
	strncpy(passenger_name, "No data", 7);
	passenger_name[7] = char(0);
	strncpy(destination, "No data", 7);
	destination[7] = char(0);
	year_of_departure = 0;
	month_of_departure = 0;
	day_of_departure = 0;
}

/*Constructor with 2 parameters*/

Passenger::Passenger(char *name, char *destination1)
{
	if (name != nullptr&&name[0] != char(0) && destination1 != nullptr&&destination1[0] != char(0))
	{
		flag = true;
		strncpy(passenger_name, name, strlen(name));
		passenger_name[strlen(name)] = char(0);
		strncpy(destination, destination1, strlen(destination1));
		destination[strlen(destination1)] = char(0);
		year_of_departure = 2017;
		month_of_departure = 7;
		day_of_departure = 1;


	}

	else
	{
		flag = false;
		strncpy(passenger_name, "no data", 7);
		passenger_name[7] = char(0);
		strncpy(destination, "No data", 7);
		destination[7] = char(0);
		year_of_departure = 0;
		month_of_departure = 0;
		day_of_departure = 0;

	}


}

/*Constructor with 5 parameters*/

Passenger::Passenger(char*name,char*destination2,int year,int month,int day)
{
	if (name != nullptr&&name[0] != char(0) && destination2 != nullptr&&destination2[0] != char(0) && year <= 2020 && year >= 2017 && month <= 12 && month >= 1 && day <= 31 && day >= 1)
	{
		flag = true;
		strncpy(passenger_name, name, strlen(name));
		passenger_name[strlen(name)] = char(0);
		strncpy(destination, destination2, strlen(destination2));
		destination[strlen(destination2)] = char(0);
		year_of_departure = year;
		month_of_departure = month;
		day_of_departure = day;

	}

	else

	{
		flag = false;
		strncpy(passenger_name, "No data", 7);
		passenger_name[7] = char(0);
		strncpy(destination, "No data", 7);
		destination[7] = char(0);
		year_of_departure = 0;
		month_of_departure = 0;
		day_of_departure = 0;

	}

}

/*Name function*/

const char* Passenger::name()const
{

	if (!isEmpty())
	{
		return passenger_name;
	}
	else
		return nullptr;
}


/* canTravelWith function implementation  */


bool Passenger:: canTravelWith(const Passenger&src)const
{
	bool result = false;
	if (!strcmp(src.destination, destination) && year_of_departure == src.year_of_departure&&month_of_departure == src.month_of_departure&&day_of_departure == src.day_of_departure)
	{
		result = true;
	}
	

	return result;
}


/*isEmpty function implementation*/

bool Passenger::isEmpty()const
{
	return !flag;

}


/*Display function implementation*/

void Passenger::display()const
{

	if (!isEmpty())
	{
		cout << passenger_name << " - " << destination <<" on "<<year_of_departure<<"/";
		cout.width(2);
		cout.fill('0');
		cout << month_of_departure << "/";
		cout.width(2);
		cout.fill('0');
		cout << day_of_departure << endl;
	}


}