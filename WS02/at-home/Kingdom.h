/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
// TODO: sict namespace
namespace  sict {

	  struct Kingdom
	   {
		  char m_name[32];
		  int m_population;
	   };
	  void display(Kingdom&);
	  void display(Kingdom*,int);

}





#endif