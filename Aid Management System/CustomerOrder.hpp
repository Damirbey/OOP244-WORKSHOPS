#ifndef CustomerOrder_hpp
#define CustomerOrder_hpp

#include <iostream>
#include "Item.hpp"
#include "Utilities.hpp"

//The Object below is the resource that my class has to manage .....
struct ItemInfo
{
    std::string m_itemName;
    unsigned int m_serialNumber = 0 ;
    bool m_fillState = false ;
    ItemInfo(std::string src) : m_itemName(src) {};
};

//The class below manages all details related to Customer order on an assembly line

class CustomerOrder{
    std::string m_name;  //name of the customer
    std::string m_product;  //name of the product being assembled
    unsigned int m_cntItem; //keeps count of customer's items
    ItemInfo** m_lstItem; //a dynamically allocated array of ItemInfo pointers
    static size_t m_widthField;  //used for display purposes
    
public:
    CustomerOrder(); //default constructor
    CustomerOrder(std::string& );  //receives a reference to a string holding a record
    CustomerOrder& operator = (const CustomerOrder& ) = delete; //preventing copy assignment
    CustomerOrder(const CustomerOrder& ); //copy constructor that will throw exception
    CustomerOrder& operator = (CustomerOrder&& ); //move assignment operator
    CustomerOrder(CustomerOrder&& ) noexcept; //move constructor
    ~CustomerOrder(); //destructor
    bool getItemFillState(std::string ) const; //returns ItemInfo::m_fillState
    bool getOrderFillState() const; //returns true if all items in the order have been filled
    void fillItem(Item& item, std::ostream&);
    void display(std::ostream&) const;
};


#endif /* CustomerOrder_hpp */
