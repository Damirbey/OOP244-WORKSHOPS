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
