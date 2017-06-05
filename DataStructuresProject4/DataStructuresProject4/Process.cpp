//
//  Process.cpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//

#include "Process.hpp"

Process::Process()
{
    startingAdress = NULL;
    endingAdress = NULL;
    processID = NULL;
    hole = NULL;
}

Process::Process(int start, int end, int ID, bool hole)
{
    startingAdress = start;
    endingAdress = end;
    processID = ID;
    this->hole = hole;
}

Process::Process(Process const &toCopy)
{
    startingAdress = toCopy.startingAdress;
    endingAdress = toCopy.endingAdress;
    processID = toCopy.processID;
    hole = toCopy.hole;
}

Process::~Process()
{
    //nothing needed
}

int Process::getStartingAdress()
{
    return startingAdress;
}

int Process::getProcessID()
{
    return processID;
}

int Process::getEndingAdress()
{
    return endingAdress;
}

bool Process::holeExists()
{
    return hole;
}

void Process::setHole(bool status)
{
    hole = status;
}

void Process::setStartingAdress(int start)
{
    startingAdress = start;
}

void Process::setEndingAdress(int end)
{
    endingAdress = end;
}

void Process::setProcessID(int ID)
{
    processID = ID;
}
