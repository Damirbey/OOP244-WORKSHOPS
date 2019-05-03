#include <iostream>
#include <iomanip>
#include "Task.hpp"
using namespace std;

//The constructor below initialize the item with the record passed & initialize the pointer
Task::Task(const std::string& record) : Item(record){
    m_pNextTask = nullptr; //safe empty state
    
}

void Task::runProcess(std::ostream& os){
        if(!m_orders.empty()){ //if there are CustomerOrders in the queue
        //verifying the fillState of the last customer order
        if(m_orders.back().getItemFillState(getName()) == false){
            m_orders.back().fillItem(*this , os);  //NOT SURE !!!!!
        }
    }
}

bool Task::moveTask(){
    if(m_orders.empty()){
          return false;
    }
    else{
        if(m_orders.back().getItemFillState(this->getName()) && m_pNextTask){
            *m_pNextTask += std::move(m_orders.back()); //move last order to next task
            m_orders.pop_back(); //remove moved order
        }
    }
    return true;
}

void Task::setNextTask(Task& t_ask){
    m_pNextTask = &t_ask;
}

bool Task::getCompleted(CustomerOrder& cust_order){
    if(m_orders.empty()){
        return false;
    }
    else{
        cust_order = std::move(m_orders.back());
        m_orders.pop_back();
        return true;
    }
}

void Task::validate(std::ostream& os){
    os << getName() << " ---> ";
    if(m_pNextTask == nullptr)
        os << "END OF LINE" ;
    else
        os << m_pNextTask->getName();
    os << endl;
}

Task& Task::operator+=(CustomerOrder&& cust_order){
//adds the parameter onto the front of the m_orders queue
    m_orders.push_front(move(cust_order));
    return *this;
}
