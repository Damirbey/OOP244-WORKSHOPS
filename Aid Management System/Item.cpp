//
//  Item.cpp
//  MS1
//
//  Created by Mamdinho on 09/11/2018.
//  Copyright © 2018 Mamdinho. All rights reserved.
//  NAME: MOHAMMED SULEIMAN MOHAMED AL-FALAHY    ID: 121083174

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

#include "Item.hpp"
#include "Utilities.hpp"

size_t Item::m_widthField = 1; //initializing static variable

Item::Item(const std::string& record){
    Utilities temp; //temp object of type Utilities
    // Set defaults for the next_pos and more
    bool flag = true;
    size_t index = 0u;
    
    m_name = temp.extractToken(record, index, flag);
    m_serialNumber = stoi(temp.extractToken(record, index, flag));
    m_quantity = stoi(temp.extractToken(record, index, flag));
    m_description = temp.extractToken(record, index, flag);
    m_widthField = temp.getFieldWidth();
    
}

const std::string& Item::getName() const{
    
    return m_name;
}

const unsigned int Item::getSerialNumber(){
    
    return m_serialNumber++;
}

const unsigned int Item::getQuantity(){
    
    return m_quantity;
}

void Item::updateQuantity(){
    if(getQuantity() > 0){
        --m_quantity;  //deducts the quantity by 1 if it's not 0
    }
}

void Item::display(std::ostream& os, bool full) const{
    os << std::setw(m_widthField) << std::left << m_name
    << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ')<< "]";
    if (full)
        os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity << " Description: " << m_description;
    os << std::endl;
    
}

