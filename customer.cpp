//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for customer class
//

#include<iostream>
#include<string>
#include "customer.h"
using namespace std;


bool Customer::purchase(const string desc)
{
  if(num_purchases >= MAX_PURCHASES)
    return false;
  purchases[num_purchases] = desc;
  num_purchases ++;
  return true;
}

string Customer::getName() const
{
  return this->name;
}

float Customer::getMoney() const
{
  return this->spending_money;
}

void Customer::setMoney(const float spending_money)
{
  this->spending_money = spending_money;
  return;
}

void Customer::print()
{
  cout << this->getName() << " has $" << this->getMoney() << " and purchases";
  for(int i = 0 ; i < this->num_purchases ; i ++)
    cout << " '" << this->purchases[i] << "'";
  cout << endl;
  return;
}
