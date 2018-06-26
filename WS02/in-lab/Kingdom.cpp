/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include"Kingdom.h"
#include<iostream>
using namespace std;
// TODO: the sict namespace
namespace sict {
	  
	//display function with one parameter
	void display(Kingdom & obj)
	{

		cout << obj.m_name << ", population " << obj.m_population << endl;
		
	}


	/*********************************/

	//overloaded display function
	void display(Kingdom * obj, int n)
	{
		int sum = 0;// stores total population of all Kingdoms
		

		cout << "------------------------------" << endl;

		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". " << obj[i].m_name << ", population " << obj[i].m_population << endl;
			sum += obj[i].m_population;

		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << sum << endl;
		cout << "------------------------------" << endl;

	}
	/***********************************/





}
   
