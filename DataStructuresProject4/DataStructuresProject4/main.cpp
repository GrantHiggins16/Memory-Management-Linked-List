//
//  main.cpp
//  DataStructuresProject4
//
//  Created by Grant Higgins on 3/21/17.
//  Copyright © 2017 Grant Higgins. All rights reserved.
//

#include <iostream>

using namespace::std;

template<class DT>
class LinkedList
{
public:
    LinkedList(); // creates empty linked list
    LinkedList(DT value, LinkedList next); // creates linked list with one value
    LinkedList(LinkedList const &LL); // copy constructor

    LinkedList create(); //creates and returns empty linked list
    bool isEmpty(); //returns bool indicating if LL is empty
    int size();//returns number of nodes in list
    void add(const DT& object);//adds an object to beginning of linked list
    void insertAt(const DT& object, int position);//inserts obj at position
    DT& info();//returns data from current node or null if list is empty
    DT& info(int node);//returns data from specific node or null if list is empty
    LinkedList next();//returns next
    void setNext(LinkedList next);//sets next
    DT remove();//removes first node of the linked list
    DT remove(int node);//removes specific node of the linked list
    DT& find(const DT& object);// returns node of object or -1 if not found
    void readLinkedList(LinkedList const &LL);//copies from a linked list into current linked list
    virtual ~LinkedList();//destructor for linked list
private:
    DT* value;
    LinkedList* nextLL;
};

template<class DT>
LinkedList<DT>::LinkedList()
{
    value = NULL;
    nextLL = NULL;
}

template<class DT>
LinkedList<DT>::LinkedList(DT value, LinkedList<DT> next)
{
    value = value;
    nextLL = next;
}

template<class DT>
LinkedList<DT>::LinkedList(LinkedList const &LL)
{
    readLinkedList(LL);
}

template<class DT>
LinkedList<DT> LinkedList<DT>::create()
{
    return LinkedList<DT>();
}

template<class DT>
bool LinkedList<DT>::isEmpty()
{
    if (value == NULL && nextLL == NULL)
        return true;
    else
        return false;
}

template<class DT>
int LinkedList<DT>::size()
{
    int size = 0;
    LinkedList<DT> temp = nextLL;
    if (isEmpty())
    {
        return size;
    }
    else
    {
        size++;
        while (temp != NULL)
        {
            temp = temp->next();
            size++;
        }
    }
    return size;
}

template<class DT>
void LinkedList<DT>::add(const DT& object)
{
    if (value == NULL)
    {
        value = new DT(object);
    }
    else
    {
        LinkedList<DT>* newList = new LinkedList<DT>(*value, next);
        *value = new DT(object);
        nextLL = newList;
    }
}

template<class DT>
void LinkedList<DT>::insertAt(const DT& object, int position)
{
    if (position == 0)
    {
        add(object);
    }
    else
    {
        if (nextLL == NULL)
        {
            nextLL = new LinkedList(object);
        }
        else
        {
            nextLL->insertAt(object, position - 1);
        }
    }
}

template<class DT>
DT& LinkedList<DT>::info()
{
    return *value;
}

template<class DT>
DT& LinkedList<DT>::info(int node)
{
    if (node == 0)
    {
        return info();
    }
    else
    {
        if (nextLL == NULL)
        {
            cout << "node does not exist" << endl;
        }
        else
        {
            nextLL->info(node - 1);
        }
    }
}

template<class DT>
LinkedList<DT> LinkedList<DT>::next()
{
    return nextLL;
}

template<class DT>
void LinkedList<DT>::setNext(LinkedList<DT> next)
{
    nextLL = next;
}

template<class DT>
DT LinkedList<DT>::remove()
{
    DT temp = *value;
    delete value;
    if (nextLL == NULL)
    {
        value = NULL;
    }
    else
    {
        LinkedList<DT>* oldnext = nextLL;
        value = nextLL->value;
        nextLL = nextLL->nextLL;
        oldnext->value = NULL;
        oldnext->nextLL = NULL;
        delete oldnext;
    }
    return temp;
}

template<class DT>
DT LinkedList<DT>::remove(int node)
{
    if (isEmpty())
    {
        cout << "linked list bounds error" << endl;
    }
    if (node == 0)
    {
        return remove();
    }
    return nextLL->removeAt(node - 1);
}

template<class DT>
DT& LinkedList<DT>::find(const DT& object)
{
    if (object == value)
    {
        return value;
    }
    if (nextLL == NULL)
    {
        return NULL;
    }
    else
    {
        return nextLL->find(object);
    }
}

template<class DT>
LinkedList<DT>::~LinkedList<DT>()
{
    delete value;
}

template<class DT>
void LinkedList<DT>::readLinkedList(LinkedList<DT> const &LL)
{
    value = LL->info();
    nextLL = LL->next();
    if (LL->next() == NULL)
    {
        return;
    }
    else
    {
        nextLL->readLinkedList(LL->next());
    }
}

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

Process::Process()
{
    startingAdress = 0;
    endingAdress = 0;
    processID = 0;
    hole = 0;
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


int main()
{
    int process;
    int memRequest;
    MainMemory MM = MainMemory();
    int* processes = new int[50];
    for (int i = 0; i < 50; i++)
    {
        processes[i] = 0;
    }
    while (!cin.eof())
    {
        cin >> process >> memRequest;
        if (process == 0)
        {
            MM.printContents();
        }
        if (process == -1)
        {
            MM.printSpaceAvailable();
        }
        else
        {
            if (processes[process] == 1)
            {
                if (memRequest > 0)
                {
                    MM.addMemory(process, memRequest);
                }
                if (memRequest == 0)
                {
                    MM.remove(process);
                }
                else
                {
                    MM.reduceMemory(process, memRequest);
                }
            }
            else
            {
                MM.add(process, memRequest);
            }

        }
    }
}
