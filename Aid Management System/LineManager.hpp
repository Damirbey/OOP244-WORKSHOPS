//  Created by Mamdinho on 26/11/2018.
//  Copyright © 2018 Mamdinho. All rights reserved.
//  NAME: MOHAMMED SULEIMAN MOHAMED AL-FALAHY     ID: 121083174
//  EMAIL: MSMOHAMED-AL-FALAHY@MYSENECA.CA


#ifndef LineManager_hpp
#define LineManager_hpp

#include <iostream>
#include <vector>
#include <functional>
#include "Task.hpp"

//lineManager manages the entire assembly line
class LineManager{
    std::vector<Task*> AssemblyLine; //will contain all REFERENCES of tasks on assembly line
    std::deque<CustomerOrder> ToBeFilled; //a que of customerorders to be filled
    std::deque<CustomerOrder> Completed; //a que of completed customer orders
    unsigned int m_cntCustomerOrder; //num of customerorders the assembly line started with

public:
    LineManager(const std::string& , std::vector<Task*>& ,std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;
};

#endif /* LineManager_hpp */
