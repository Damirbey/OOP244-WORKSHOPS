//  Created by Mamdinho on 26/11/2018.
//  Copyright © 2018 Mamdinho. All rights reserved.
//  NAME: MOHAMMED SULEIMAN MOHAMED AL-FALAHY     ID: 121083174
//  EMAIL: MSMOHAMED-AL-FALAHY@MYSENECA.CA


#ifndef Task_hpp
#define Task_hpp

#include <iostream>
#include <deque>
#include "Item.hpp"
#include "CustomerOrder.hpp"

//each Task is responsible for a particular item
class Task : public Item{ //a Task object manages a single Item on the assembly line
    std::deque<CustomerOrder> m_orders;  //a que of Customer Orders
    Task* m_pNextTask;  //pointer to the next Task in assembly line
    
public:
    Task(const std::string&);
    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&);
    Task& operator+=(CustomerOrder&&);
    Task(const Task&) = delete;
    Task& operator =(const Task&) = delete;
    Task(Task&&) = delete;
    Task& operator =(Task&&) = delete;
};

#endif /* Task_hpp */
