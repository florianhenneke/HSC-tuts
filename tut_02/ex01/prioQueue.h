// prioQueue.h
#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "listEl.h"

class PrioQueue
{
public:
  PrioQueue();
  ~PrioQueue();
  PrioQueue& operator=(const PrioQueue& b);
  void copyAll(const PrioQueue& b); //Copies all elements. If list is not empty do nothing
  void deleteAll();
  Cell* prior(int prio);
  bool insert(int prio, string name);
  bool insert(int prio, string name, string anam);
  void deleteMax(string& name);
  void display();
private:
  Cell *firstEl = NULL;
};

#endif 
