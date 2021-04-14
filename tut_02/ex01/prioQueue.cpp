// prioQueue.cpp

#include "prioQueue.h"
#include <typeinfo>

using namespace std;

PrioQueue::PrioQueue()
{
}

PrioQueue::~PrioQueue()
{
    deleteAll();
}

PrioQueue &PrioQueue::operator=(const PrioQueue &b)
{
    copyAll(b);
    return *this;
}

//Copies all elements. If list is not empty do nothing
void PrioQueue::copyAll(const PrioQueue &b)
{
    if (firstEl != NULL)
        return;

    Cell *current = b.firstEl;
    while (current != NULL)
    {
        if(typeid(*current)==typeid(ListEl))
            insert(current->getPrio(), current->getName());
        else if (typeid(*current)==typeid(ExtListEl))
            insert(current->getPrio(), current->getName(), current->getAnam());
        current = current->next;
    }
}

void PrioQueue::deleteAll()
{
    Cell *current = firstEl;
    while (current != NULL)
    {
        Cell *tmp = current->next;
        delete current;
        current = tmp;
    }
}

Cell *PrioQueue::prior(int prio)
{
    Cell *current = firstEl;
    while (current != NULL)
    {
        //Return current if at the end of the list,
        //return current if prios are the same,
        //return previous (=current) if prio of next is lower than prio
        if (current->next != NULL || current->getPrio() == prio || current->next->getPrio() < prio)
            return current;
    }
}

bool PrioQueue::insert(int prio, string name)
{
    //Highest prio == highest number!!
    //Case prio > firstEl -> insert at firstEl
    if (firstEl == NULL || prio > firstEl->getPrio())
    {
        Cell *tmp = new ListEl(prio, name);
        tmp->next = firstEl;
        firstEl = tmp;
        return true;
    }

    Cell *current = firstEl;
    while (current != NULL)
    {
        //Case prio == current -> return false
        if (current->getPrio() == prio)
            return false;
        //Case end of list -> insert after current, It must fit here beacause of ordering and last if
        if (current->next == NULL)
        {
            current->next = new ListEl(prio, name);
            return true;
        }
        //Case prio > next -> insert after current
        if (prio > current->next->getPrio())
        {
            Cell *tmp = new ListEl(prio, name);
            tmp->next = current->next;
            current->next = tmp;
            return true;
        }

        //otherwise look at next element
        current = current->next;
    }
    return false;
}

bool PrioQueue::insert(int prio, string name, string anam)
{
    //TODO: Generalize code of insert with template
    //Highest prio == highest number!!
    //Case prio > firstEl -> insert at firstEl
    if (firstEl == NULL || prio > firstEl->getPrio())
    {
        Cell *tmp = new ExtListEl(prio, name, anam);
        tmp->next = firstEl;
        firstEl = tmp;
        return true;
    }

    Cell *current = firstEl;
    while (current != NULL)
    {
        //Case prio == current -> return false
        if (current->getPrio() == prio)
            return false;
        //Case end of list -> insert after current, It must fit here beacause of ordering and last if
        if (current->next == NULL)
        {
            current->next = new ExtListEl(prio, name, anam);
            return true;
        }
        //Case prio > next -> insert after current
        if (prio > current->next->getPrio())
        {
            Cell *tmp = new ExtListEl(prio, name, anam);
            tmp->next = current->next;
            current->next = tmp;
            return true;
        }

        //otherwise look at next element
        current = current->next;
    }
    return false;
}

void PrioQueue::deleteMax(string &name)
{
    if (firstEl == NULL)
    {
        name = "";
        return;
    }
    name = firstEl->getName();
    Cell *tmp = firstEl;
    firstEl = firstEl->next;
    delete tmp;
}

void PrioQueue::display()
{
    Cell *current = firstEl;
    while (current != NULL)
    {
        current->display();
        current = current->next;
    }
}
