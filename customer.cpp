//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for customer class
//

#include<iostream>
#include<string>
#include "customer.h"
using namespace std;


bool Customer::buySomething(const string desc)
{
  int choice;
  choice = rand % 2;
  if(choice)
    return false;
  if(!choice)
  {
    
  }
/*  if(num_purchases >= MAX_PURCHASES)
    return false;
  purchases[num_purchases] = desc;
  num_purchases ++;
  return true; */
}

string Customer::getName() const
{
  return this->name;
}

float Customer::getMoney() const
{
  return this->spendingMoney;
}

void Customer::setMoney(const float spendingMoney)
{
  this->spendingMoney = spendingMoney;
  return;
}

void Customer::setHappiness(const int happiness)
{
  this->happiness = happiness;
  return;
}

void Customer::throws(const Customer & c)
{
  
}

void Customer::rob(const Customer & c)
{
  
}

ostream & operator << (ostream & stream, const Customer & c)
{
  cout << c.name << " has $" << c.spendingMoney << " and purchases";
  for(int i = 0; i < c.numPurchases; i++)
    cout << " " << c.purchases[i];
  cout << endl;
  return stream;
}
