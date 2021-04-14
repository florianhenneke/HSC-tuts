// listEl.h
// Definitions of the classes Cell, ListEl and ExtListEl

#ifndef LISTEL_H
#define LISTEL_H

#include <string>
#include <iostream>
using namespace std;

class Cell
{
public:
  virtual ~Cell() {}; 
  virtual inline int getPrio() const = 0;
  virtual inline const string &getName() const = 0;
  virtual inline const string &getAnam() const = 0;
  virtual inline void display() = 0;
  Cell *next = NULL;
};

class ListEl : public Cell
{
public:
  ListEl(int prio, string name) : name_(name), prio_(prio){};
  inline int getPrio() const { return prio_; };
  inline const string &getName() const { return name_; };
  inline const string &getAnam() const { return ""; };
  inline void display() { cout << prio_ << ":" << name_ << endl; };

private:
  string name_;
  int prio_;
};

class ExtListEl : public ListEl
{
public:
  ExtListEl(int prio, string name, string anam) : ListEl(prio, name), anam_(anam){};
  inline const string &getAnam() const { return anam_; };

private:
  string anam_;
};

#endif
