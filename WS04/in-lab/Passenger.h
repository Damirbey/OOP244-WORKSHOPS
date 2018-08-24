#ifndef _SICT_PASSENGER_H
#define _SICT_PASSENGER_H

namespace sict //declaration of the namespace sict
{
	class Passenger //Passenger class declaration
	{

	 
	  private:
		  bool flag;
		  char passenger_name[32];
		  char destination[32];
	 
	  public:

		  Passenger();
		  Passenger(char *name, char *dest);
		  bool isEmpty() const;
		  void display() const;


	};




}








#endif