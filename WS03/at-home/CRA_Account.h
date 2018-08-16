#ifndef SICT_CRA_Account_H
#define SICT_CRA_Account_H


namespace sict
{

	//defining all constant integers

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;


	//defining class CRA_Account

	class CRA_Account

	{
	private:

		char familyName[41];
		char givenName[41];
		int SIN;
		int tax_return_years[max_yrs];
		double balance_owed[max_yrs];
		int num_of_yrs;

	public:
		//declaring the public member functions
		void set(const char* familyName, const char* givenName, int sin);

		bool isEmpty() const;

		void display() const;

		void set(int year, double balance);



	};




}







#endif