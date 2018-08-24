#define _CRT_SECURE_NO_WARNINGS
#include"Passenger.h"
#include<iostream>
#include<cstring>
using namespace std;
using namespace sict;

Passenger::Passenger() //default constructor
{
	flag = false;
	strncpy(passenger_name, "No data", 7);
	passenger_name[7] = char(0);
	strncpy(destination, "No data", 7);
	destination[7] = char(0);
}


//constructor with 2 parameters 

Passenger::Passenger( char *name,  char *destination1) 
{
	if (name != nullptr&&name[0] != char(0)&&destination1!=nullptr&&destination1[0]!=char(0))
	{
		flag = true;
		strncpy(passenger_name, name, strlen(name));
		passenger_name[strlen(name)] = char(0);
		strncpy(destination, destination1, strlen(destination1));
		destination[strlen(destination1)] = char(0);
		
	}
			
	else
	{
		flag = false;
		strncpy(passenger_name, "no data", 7);
		passenger_name[7] = char(0);
		strncpy(destination, "No data", 7);
		destination[7] = char(0);
	}
		
	
}

//isEmpty function implementation

bool Passenger::isEmpty()const 
{
	return !flag;

}

//display function implementation 

void Passenger::display()const
{
   
	if (!isEmpty())
	{
		cout << passenger_name << " - " << destination << endl;
	}
	else
		cout << "No passenger!" << endl;


}