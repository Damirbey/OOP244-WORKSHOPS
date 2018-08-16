#include<iostream>
#include<cstring>
#include "CRA_Account.h"
using namespace std;
using namespace sict;

void CRA_Account::set(const char *familyName, const char*givenName, int sin)
{
	if (sin>min_sin&&sin<max_sin)
	{
		strncpy(family_name, familyName, max_name_length);
		strncpy(given_name, givenName, max_name_length);
		SIN = sin;
	}
	else
	{
		SIN = NULL;
		given_name[max_name_length]='/0';
		family_name[max_name_length] = '/0';
	
	}

}


bool CRA_Account::isEmpty()const
{
	if (SIN > min_sin&& SIN < max_sin)
	{
		return false;
	}
	else
		return true;

}

void CRA_Account::display()const
{
	if (!isEmpty())
	{
		cout << "Family Name: " << family_name << endl;
		cout << "Given Name: " << given_name << endl;
		cout << "CRA Account: " << SIN << endl;

	}
	else
	{
		cout << "Account object is empty!" << endl;
	}
}