//  Created by Mamdinho on 09/11/2018.
//  Copyright © 2018 Mamdinho. All rights reserved.
//  NAME: MOHAMMED SULEIMAN MOHAMED AL-FALAHY     ID: 121083174
//  EMAIL: MSMOHAMED-AL-FALAHY@MYSENECA.CA

#ifndef Utilities_hpp
#define Utilities_hpp

#include <iostream>

class Utilities{
    size_t m_widthField = 1;
    static char m_delimiter;
    
public:
    void setFieldWidth(size_t);
    size_t getFieldWidth() const;
    const std::string extractToken(const std::string& str, size_t& next_pos, bool &more);
    static void setDelimiter(const char);
    const char getDelimiter() const;
};

#endif /* Utilities_hpp */
