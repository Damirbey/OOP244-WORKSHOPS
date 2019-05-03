#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "CustomerOrder.hpp"

using namespace std;

size_t CustomerOrder::m_widthField = 1; //static definition

//initializing all properties of CustomerOrder to empty state
CustomerOrder::CustomerOrder(){
    m_name = "";
    m_product = "";
    m_cntItem = 0;
    m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& record){
    Utilities temp; //temporary Utilities object
    vector<ItemInfo*> items; //for populating **
    // Set defaults for the next_pos and more
    bool flag = true;
    size_t index = 0u;
    
    m_name = temp.extractToken(record, index, flag);
    if(flag == true)
        m_product = temp.extractToken(record, index, flag);
    
    while(flag == true) //populates all the items in the items container
        items.push_back(new ItemInfo(temp.extractToken(record, index, flag)));
    
    m_widthField = temp.getFieldWidth(); //for the field width
    m_cntItem = static_cast<unsigned int>(items.size()); //for allocating dynamic memory purposes
    m_lstItem = new ItemInfo*[m_cntItem];
    
    for(size_t i=0u; i<m_cntItem; i++)
        m_lstItem[i] = std::move(items[i]); //moving all items to the original pointer
    
}

CustomerOrder::CustomerOrder(const CustomerOrder& src ){
    throw std::string("Copy not permitted");
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept{
    *this = std::move(src);
}

CustomerOrder& CustomerOrder::operator = (CustomerOrder&& src){
    if(this != &src){ //code below frees exisiting resource
        //    if (m_lstItem != nullptr) {  CODE BRINGS SEGMENTATION FAULT !! WHY ? FIGURE OUT
        //           for (size_t i = 0u; i < m_cntItem; i++)
        //                 delete m_lstItem[i];
        //          delete[] m_lstItem;
        
        //}
        
        m_name = src.m_name;
        m_product = src.m_product;
        m_widthField = src.m_widthField;
        m_cntItem = src.m_cntItem;
        m_lstItem = src.m_lstItem;
        
        src.m_name = "";
        src.m_product = "";
        src.m_widthField = 0;
        src.m_cntItem = 0;
        src.m_lstItem = nullptr;
    }
    
    return *this;
}

CustomerOrder::~CustomerOrder(){
    for (size_t i = 0u; i < m_cntItem; i++)
        delete m_lstItem[i];
    delete[] m_lstItem;
}

//NOT SURE ABOUT MY SOLN BELOW
void CustomerOrder::fillItem(Item& item, std::ostream& os){
    
    for(size_t i=0u; i<m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == item.getName()){ //cehcks if item is matched
            item.updateQuantity(); //updates the quantity
            m_lstItem[i]->m_fillState = true; //sets filled state
            m_lstItem[i]->m_serialNumber = item.getSerialNumber(); //sets serial number
            
            if(item.getQuantity() > 0){ //if item found & inventory has atleast one element
                os << "Filled " << this->m_name << ", "  << this->m_product << "[" <<
                m_lstItem[i]->m_itemName << "]" << std::endl;
            }
            else{ //if item found but inventory is empty
                os << "Unable to fill " << this->m_name << ", "  << this->m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }
    
}

bool CustomerOrder::getItemFillState(std::string item) const{
    for(size_t i=0u; i< m_cntItem; i++){
        if(item == m_lstItem[i]->m_itemName) //checks if item exists
            return m_lstItem[i]->m_fillState;
    }
    
    return true; //if item doesn't exist return true anyways
}

bool CustomerOrder::getOrderFillState() const{
    bool check = true;
    
    for(size_t i=0u; i< m_cntItem && check == true; i++){
        if(m_lstItem[i]->m_fillState){
            //if it's true do nothing & simply continue looping
        }else{ //if even ONE of the item's filledstate is false
            check = false; //set check to false & terminates loop
        }
    }
    return check;
}

void CustomerOrder::display(std::ostream& os) const {
    os << std::left << m_name << " - " << m_product << std::endl;
    
    for (size_t i = 0; i < m_cntItem; i++)
    {
        os << "[" << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber  << "]" << " "
        << setw(m_widthField) << setw(16) << setfill(' ') << std::left << m_lstItem[i]->m_itemName << std::right <<(m_lstItem[i]->m_fillState ? " - FILLED" : " - MISSING") << std::endl;
    }
    
}

/* {
 ---------------------------------
 
 os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber  << "]" << " "
 << setw(m_widthField) << setw(16) << setfill(' ') << std::left << m_lstItem[i]->m_itemName << std::right <<(m_lstItem[i]->m_fillState ? " - FILLED" : " - MISSING") << std::endl;

 ---------------------------------
 
 if(m_lstItem[i]->m_serialNumber < 99)
 os << "[000000]";
 else if(m_lstItem[i]->m_serialNumber < 99999)
 os << "[0" << m_lstItem[i]->m_serialNumber << "]";
 else
 os << "[" << setw(6) << m_lstItem[i]->m_serialNumber << "]";
 
 os << " " << setw(m_widthField) << setw(16) << setfill(' ') << std::left << m_lstItem[i]->m_itemName << std::right <<(m_lstItem[i]->m_fillState ? " - FILLED" : " - MISSING") << std::endl;

 
 
 
 
 os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::setfill(' ') << "] "
 << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName
 << " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
 }*/

