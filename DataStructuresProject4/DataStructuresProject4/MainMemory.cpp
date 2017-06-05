//
//  MainMemory.cpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//

#include <iostream>
#include "MainMemory.hpp"
#include "LinkedList.hpp"
#include "Process.hpp"

using namespace::std;

MainMemory::MainMemory()
{
    mainMem = LinkedList<Process>();
    availableSpace = 128;
    currentProcessID = 0;
}

void MainMemory::add(int ID, int memRequested)
{
    if (ID < currentProcessID + 1)
    {
        cout << "you are attempting to add a process that already exists" << endl;
    }
    else
    {
        currentProcessID++;
        if (mainMem.isEmpty())
        {
            int start = 0;
            int end = memRequested;
            Process p = Process(start, end, currentProcessID, false);
            mainMem.add(p);
        }
        else
        {
            int start = mainMem.info(currentProcessID - 1).getEndingAdress() + 1;
            int end = start + memRequested;
            Process p = Process(start, end, currentProcessID, false);
        }
            
    }
}

void MainMemory::addMemory(int process, int memToAdd)
{
    if (availableSpace < memToAdd)
    {
        cout << "request to add memory rejected" << endl;
    }
    else
    {
        availableSpace = availableSpace - memToAdd;
        int currentEnd = mainMem.info(process).getEndingAdress();
        mainMem.info(process).setEndingAdress(currentEnd + memToAdd);
        compact();
    }
}

void MainMemory::remove(int process)
{
    for (int i = 0; i < mainMem.size(); i++)
    {
        if (mainMem.info(i).getProcessID() == process)
        {
            mainMem.info(i).setProcessID(-1);
            mainMem.info(i).setHole(true);
        }
    }
}

void MainMemory::reduceMemory(int process, int memToRemove)
{
    int currentEnd = mainMem.info(process).getEndingAdress();
    int currentStart = mainMem.info(process).getStartingAdress();
    if (currentEnd - memToRemove < currentStart)
    {
        cout << "request to remove memory rejected" << endl;
    }
    if (currentEnd - memToRemove == currentStart)
    {
        remove(process);
    }
    else
    {
        mainMem.info(process).setEndingAdress(currentEnd - memToRemove);
        compact();
    }
}

void MainMemory::compact()
{
    int currentIndex = 0;
    for (int i = 0; i < mainMem.size(); i++)
    {
        Process currentProcess = mainMem.info(i);
        if (!currentProcess.holeExists())
        {
            int size = currentProcess.getStartingAdress() - currentProcess.getEndingAdress();
            currentProcess.setStartingAdress(currentIndex);
            currentIndex = currentIndex + size;
            currentProcess.setEndingAdress(currentIndex);
            currentIndex++;
        }
    }
}

void MainMemory::printContents()
{
    
}

void MainMemory::printSpaceAvailable()
{
    cout << "Space available: " << availableSpace << endl;
}
