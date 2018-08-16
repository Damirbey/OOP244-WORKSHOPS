#include<iostream>
#include<cstring>
#include"CRA_Account.h"
using namespace std;
using namespace sict;



//definition for bool isEmpty function
bool CRA_Account::isEmpty() const
{

	if (SIN>min_sin && SIN<max_sin)
	{
		return false;
	}
	else
		return true;


}

//defining the set function

void CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
	if (sin > min_sin && sin < max_sin)
	{
		strncpy(this->familyName, familyName, 40);
		strncpy(this->givenName, givenName, 40);
		this->SIN = sin;

	}

	else
	{
		*this->familyName = NULL;
		*this->givenName = NULL;
	}




}

//definition for the display function

void CRA_Account::display()const
{

	if (this->SIN != NULL)
	{
		cout << "Family Name : " << familyName << endl;
		cout << "Given Name : " << givenName << endl;
		cout << "CRA Account : " << SIN << endl;


	}

	else
	{
		cout << "Account object is empty!" << endl;
	}

}


//overloaded function set definition

void CRA_Account::set(int year, double balance)
{

	if (SIN > min_sin && SIN < max_sin)
	{
		
			*this->tax_return_years = year;
			*this->balance_owed = balance;
			
		
		


	}

}