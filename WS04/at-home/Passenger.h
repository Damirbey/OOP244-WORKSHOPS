#ifndef _SICT_PASSENGER_H
#define _SICT_PASSENGER_H

namespace sict //namespace declaration
{
	class Passenger //Passenger class declaration
	{


	private:
		bool flag;
		char passenger_name[32];
		char destination[32];
		int year_of_departure;
		int month_of_departure;
		int day_of_departure;

	public:

		Passenger();
		Passenger(char *name, char *dest);
		Passenger(char *name, char*dest, int year, int month, int day);
		const char*name()const;
		bool canTravelWith(const Passenger&)const;
		bool isEmpty() const;
		void display() const;


	};




}








#endif