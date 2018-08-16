#ifndef _SICT_CRA_ACCOUNT_H
#define _SICT_CRA_ACCOUNT_H


namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account
	{
	    private:
			
			char family_name[max_name_length + 1];
			char given_name[max_name_length + 1];
			int SIN;

	    public:
			void set(const char*familyName, const char*givenName, int sin);
			bool isEmpty()const;
			void display()const;

	};







}






#endif