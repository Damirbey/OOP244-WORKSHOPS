#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#define SIZE 4
class Item{
    std::string m_name;
    std::string m_description;
    unsigned int m_serialNumber;
    unsigned int m_quantity;
    static size_t m_widthField;  //all item object share same m_widthField
    
public:
    Item(const std::string&);
    const std::string& getName() const;
    const unsigned int getSerialNumber();
    const unsigned int getQuantity();
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
    
};

#endif /* Item_hpp */
