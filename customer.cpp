//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for customer class
//

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include "customer.h"
using namespace std;

bool Customer::buySomething(const Business & b)
{
  int choice, randItem;

  choice = rand % 2; //50-50 at whether to buy or not.
  if(choice == 0)
    return false;
  if(choice == 1)
  {
    randItem = (rand() % b.numItems);

    if(spendingMoney >= b.items[randItem].price || numPurchases <= MAX_PURCHASES)
    {
      purchases[numPurchases] = b.items[randItem];
      spendingMoney -= b.items[randItem].price;
      numPurchases++;
      b.money += b.items[randItem].price;
      happiness += SUCCESS_BUY;
      return true;
    }
    if(spendingMoney < b.items[randItem].price || numPurchases > MAX_PURCHASES)
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

void Customer::setName(string name)
{
  this->name = name;
  return;
}

void Customer::setInclination(bool inclination)
{
  this->inclination = inclination;
  return;
}

bool Customer::getInclination() const
{
 return inclination;
}

void Customer::setMoney(const float spending_money)
{
  this->spendingMoney = spending_money;
  return;
}

void Customer::throws(const Customer & c) //c = victim
{
  if(numPurchases != 0)
  {
    numPurchases--;
    happiness += INTERACTION_PERP;
    c.happiness -= INTERACTION_VICTIM;
  }
  else if(numPurchases == 0)
  {
    happiness -= FAILED_THROW_PERP;
  }
  return;
}

void Customer::rob(const Customer & c) //c = victim
{
  if(numPurchases < MAX_PURCHASES && c.numPurchases != 0)
  {
    happiness += INTERACTION_ATTEMPT;
    c.happiness -= INTERACTION_VICTIM;
    purchases[numPurchases] = c.purchases[c.numPurchases];
    numPurchases ++;
    c.numPurchases --;
  }
  if(numPurchases >= MAX_PURCHASES && c.numPurchases != 0)
  {
    happiness -= INTERACTION_PERP;
  } 
  return;
}

ostream & operator << (ostream & stream, const Customer & c)
{
  stream << c.name << " has $" << c.spendingMoney << " and purchases";
  for(int i = 0; i < c.numPurchases; i++)
    stream << " " << c.purchases[i];
  stream << endl;
  return stream;
}

static void Customer::readCustomers(Customer customers[], int num_customers)
{
  ifstream fin;
  fin.open(CUSTOMER_FILE);
  for(int i = 0 ; i < num_customer ; i ++)
  {
    string name;
    getline(fin, name, ',');
    customers[i].setName(name);
    fin.ignore(1);
    if(static_cast<char>(fin.peek()) == '-')
      customer[i].setDestination(false);
    else
      customer[i].setDestination(true);
    fin.ignore(100, '\n');
  }
  return;
}



