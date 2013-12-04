//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
//            Alec Bayliff
// Assignment: 10 "Street Brawl"     Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for customer class

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include "business.h"
#include "customer.h"
using namespace std;

bool Customer::buySomething(const Product & p)
{
  int choice = rand() % 2; //50-50 at whether to buy or not.
  if(choice)
  {
    if(spendingMoney >= p.price && numPurchases < MAX_PURCHASES)
    {
      purchases[numPurchases++] = p;
      spendingMoney -= p.price;
      happiness += SUCCESS_BUY;
      cout << name << " bought " << p.name << " for $" << p.price << endl;
      return true;
    }
    else
    {
      happiness -= FAILED_BUY;
      return false;
    }
  }
  return false;
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

int Customer::getHappiness() const
{
  return happiness;
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

void Customer::throwStuff(Customer & c) //c = victim
{
  if(numPurchases != 0)
  {
    happiness += INTERACTION_PERP;
    c.happiness -= INTERACTION_VICTIM;
    cout << name << " throws a " << purchases[numPurchases - 1].name << " at ";
    cout << c.name << endl;
    numPurchases--;
  }
  else if(numPurchases == 0)
  {
    this->happiness -= FAILED_THROW_PERP;
  }
  return;
}

void Customer::rob(Customer & c) //c = victim
{
  if(numPurchases < MAX_PURCHASES && c.numPurchases != 0)
  {
    happiness += INTERACTION_ATTEMPT;
    c.happiness -= INTERACTION_VICTIM;
    purchases[numPurchases] = c.purchases[c.numPurchases - 1];
    cout << name << " steals a " << c.purchases[c.numPurchases - 1].name;
    cout << " from " << c.name << endl;
    numPurchases ++;
    c.numPurchases --;
  }
  else if(numPurchases >= MAX_PURCHASES || c.numPurchases == 0)
  {
    happiness -= INTERACTION_PERP;
  }
  return;
}

ostream & operator << (ostream & stream, const Customer & c)
{
  stream << c.name << " has $" << c.spendingMoney << " with " << c.happiness;
  stream << " happiness and purchased";
  for(int i = 0; i < c.numPurchases; i++)
    stream << " " << c.purchases[i].name << ", ";
  stream << endl;
  return stream;
}

void Customer::readCustomers(Customer customers[], int num_customers)
{
  ifstream fin;
  fin.open("people.txt");
  for(int i = 0 ; i < num_customers ; i ++)
  {
    string name;
    getline(fin, name, ',');
    customers[i].setName(name);
    fin.ignore(1);
    if(static_cast<char>(fin.peek()) == '-')
      customers[i].setInclination(false);
    else
      customers[i].setInclination(true);
    fin.ignore(100, '\n');
  }
  fin.close();
  return;
}


Customer & Customer::operator = (Customer & dude)
{
  for(int i = 0; i < dude.numPurchases; i++)
  {
    purchases[i] = dude.purchases[i];
  }
  spendingMoney = dude.spendingMoney;
  name = dude.name;
  happiness = dude.happiness;
  inclination = dude.inclination;
  numPurchases = dude.numPurchases;
  return (*this);
}




