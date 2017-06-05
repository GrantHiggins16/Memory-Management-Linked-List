//
//  Process.hpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//
#include "LinkedList.hpp"
#include <iostream>
using namespace::std;

#ifndef Process_hpp
#define Process_hpp

#include <stdio.h>

class Process
{
public:
    Process();//default constructor
    Process(int start, int end, int processID, bool hole);//non-default constructor
    Process(Process const &toCopy);//copy constructor
    virtual ~Process();//destructor
    int getStartingAdress();//returns starting adress
    int getEndingAdress();//returns ending adress
    int getProcessID();//returns processID
    bool holeExists();//tells if there is a hole
    void setStartingAdress(int start);//sets the starting adress
    void setEndingAdress(int end);//sets the ending adress
    void setProcessID(int ID);//sets the process ID
    void setHole(bool status);//sets the status of hole
private:
    int startingAdress;//starting adress of process
    int endingAdress;//ending adress of process
    int processID;//if hole is false it contains process identifier of the process using the partition otherwise -1
    bool hole;//false if occupied by process,true otherwise
    
};
#endif /* Process_hpp */
