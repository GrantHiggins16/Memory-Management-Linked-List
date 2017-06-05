//
//  MainMemory.hpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//
#include "Process.hpp"
#include "LinkedList.hpp"

#ifndef MainMemory_hpp
#define MainMemory_hpp

#include <stdio.h>

class MainMemory
{
public:
    MainMemory();
    void add(int ID, int memRequested);//adds a process to main memory
    void remove(int process);//removes a certain process
    void reduceMemory(int process, int memToRemove);//removes a certain amount of memory allocated to a specific process
    void addMemory(int process, int memToAdd);//adds a certain amount of memory allocated to a specific process
    void printContents();//prints contents of main memory
    void printSpaceAvailable();//prints space available in main memory
private:
    void compact();//method that compacts main memory
    LinkedList<Process> mainMem;//representation of main memory
    int availableSpace;//space available in mainMem
    int currentProcessID;//last process id currently occupied
};
#endif /* MainMemory_hpp */
