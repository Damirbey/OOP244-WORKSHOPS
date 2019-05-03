#include <iostream>
#include <fstream>
#include "LineManager.hpp"

using namespace std;

//FIGURE WHAT THE FUCK DOES THIS CONSTRUCTOR WANT -------
LineManager::LineManager(const std::string& fileName, std::vector<Task*>& tasks ,std::vector<CustomerOrder>& orders){
    string record;
    string token;
    Utilities temp;
    size_t nextpos = 0u;
    bool more = true;
    
    m_cntCustomerOrder = static_cast<unsigned int>(orders.size()); //setting the size
    AssemblyLine = tasks; //copying all tasks into assembly line
    ifstream fs (fileName); //connecting fs to fileName for reading
    
    if(!fs){ //if fs.open() == false
        cout << "Error cannot open file" << endl;
    }
    else{
        while(fs.peek() != EOF){
            getline(fs,record); //reading the whole record from file
            Utilities::setDelimiter('|'); //setting delimeter for extracting record
            //extracting first item from the record
            token = temp.extractToken(record, nextpos, more);
            for(auto& t_ask : AssemblyLine){ //looping through the Tasks to see if item exists
                if(token == t_ask->getName()){ //e.g. Line1/Token1 - Power Supply
                    if(more){
                        //extract second item from the record
                        token = temp.extractToken(record, nextpos, more);
                        
                        for(auto& nt_ask : AssemblyLine){ //looping through the Tasks again
                            if(token == nt_ask->getName()){  //e.g. Line1/Token2 - CPU
                                // setup m_pNextTask in the Task objects
                                t_ask->setNextTask(*nt_ask);
                            }
                        }
                    }
                }
            }
            
            //resetting the values for extracting again
            nextpos = 0u;
            more = true;
        }
        fs.close();
        //move all customer orders to the TobeFilled
        for(size_t i=0u; i<orders.size(); i++){
            ToBeFilled.push_front(move(orders.at(i)));
        }
    }
}

bool LineManager::run(std::ostream& os){
    for(int j=0; j<7; j++){
        
    if(!ToBeFilled.empty()){
        *AssemblyLine[4] += std::move(ToBeFilled.back()); //4 is the starting point
        ToBeFilled.pop_back();
    }
    
    for(size_t i=0u; i<AssemblyLine.size(); i++){
        AssemblyLine[i]->runProcess(os);
    }
        
    for(size_t i=0u; i<AssemblyLine.size(); i++){
            AssemblyLine[i]->moveTask();
        }
        
    }
    
    for(size_t i=0u; i<AssemblyLine.size(); i++){
        if(AssemblyLine[i]->moveTask()){
            CustomerOrder temp;
            bool check = AssemblyLine[i]->getCompleted(temp);
            if(check)
                Completed.push_back(std::move(temp));
        }
    }
    
    if(Completed.size() == m_cntCustomerOrder)
        return true;
    else
        return false;
}

void LineManager::displayCompleted(std::ostream& os) const{
    for(size_t i=0u; i<Completed.size(); i++){
        Completed[i].display(os);
    }
}

void LineManager::validateTasks() const{
    for(size_t i=0u; i<AssemblyLine.size(); i++){
        AssemblyLine[i]->validate(cout);
    }
}


