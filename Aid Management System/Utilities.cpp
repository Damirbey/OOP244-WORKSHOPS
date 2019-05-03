//  Created by Mamdinho on 09/11/2018.
//  Copyright © 2018 Mamdinho. All rights reserved.
//  NAME: MOHAMMED SULEIMAN MOHAMED AL-FALAHY     ID: 121083174
//  EMAIL: MSMOHAMED-AL-FALAHY@MYSENECA.CA


#include <iostream>
#include <vector>
#include "Utilities.hpp"
using namespace std;

void Utilities::setFieldWidth(size_t m_w){
    m_widthField = m_w; //sets the field width of the Utilities object
}

size_t Utilities::getFieldWidth() const{
    return m_widthField;
}


//This function uses the delimiter to extract the  next  token  from strstarting at next_pos
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool &more){
    string error = "Error no tokens separated by delimiter found";
    string result; //for holding the final string returned
    char delimiter = getDelimiter();
    
    
    if(more){
        size_t delim_Pos = str.find(delimiter , next_pos + 1u);
        
        if(delim_Pos != std::string::npos){
            result = str.substr(next_pos, delim_Pos - next_pos); //extracts the token
            more = true; //success
            
            if(delim_Pos == next_pos) //checks if no tokens are between 2 delimiters
                throw error;
            next_pos = delim_Pos + 1u; //resetting the new position
            
            if(m_widthField < result.size())
                setFieldWidth(result.size());
        }
        else{
            result = str.substr(next_pos, str.length());
            more = false;
        }
    }
    
    return result;
    
}

char Utilities::m_delimiter = ' ' ; //initializing static member variable REQUIREMENT for using static variables

void Utilities::setDelimiter(const char del){
    
    Utilities::m_delimiter = del;
    
}

const char Utilities::getDelimiter() const{
    return Utilities::m_delimiter;
}
