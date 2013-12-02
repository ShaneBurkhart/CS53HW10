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


bool Customer::buySomething(const Business & b)
{
  int choice, randItem;
  float tempMoney;
  
  choice = rand % 2; //50-50 at whether to buy or not.
  if(choice)
    return false;
  if(!choice)
  {
    randItem = (rand() % b.numItems);
    tempMoney = getMoney();
    
    if(tempMoney >= b.items[randItem].price || numPurchases <= MAX_PURCHASES)
    {
      purchases[numPurchases] = b.items[randItem];
      tempMoney -= b.items[randItem].price;
      setMoney(tempMoney);
      numPurchases++;
      b.money += b.items[randItem].price;
      happiness += SUCCESS_BUY;
      return true;
    }
    if(tempMoney < b.items[randItem].price || numPurchases > MAX_PURCHASES)
    {
      happiness -= FAILED_BUY;
      return false;
    }
  }
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
