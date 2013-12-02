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
  return this->spending_money;
}

void setName(string name)
{
  this->name = name;
  return;
}

void setInclination(bool inclination)
{
  this->inclination = inclination;
  return;
}

void Customer::setMoney(const float spending_money)
{
  this->spending_money = spending_money;
  return;
}

void Customer::throws(const Customer & c1, const Customer & c2)
{

}

void Customer::rob(const Customer & c1, const Customer & c2)
{

}

ostream & operator << (ostream & stream, const Customer & c)
{
  cout << c.name << " has $" << c.spending_money << " and purchases";
  for(int i = 0; i < c.num_purchases; i++)
    cout << " " << c.purchases[i];
  cout << endl;
  return stream;
}

static void read_customers(customer customers[], int num_customers)
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

    else

    fin.ignore(100, '\n');
  }
  return;
}



