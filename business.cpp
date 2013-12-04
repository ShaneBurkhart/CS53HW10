//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
//            Alec Bayliff
// Assignment: 10 "Street Brawl"     Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Function implementations for the Business class.

#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include "business.h"
#include "customer.h"
using namespace std;

Business::Business(string name, float money, string f_name)
{
  this->name = name;
  this->money = money;
  this->numItems = 0;
  this->numCustomers = 0;
  ifstream file;
  file.open(f_name.c_str());
  if(!file)
    return;
  float price;
  while(file >> price && numItems < MAX_ITEMS)
  {
    Product p;
    p.price = price;
    file.ignore(1);
    getline(file, p.name, '\n');
    items[this->numItems++] = p;
  }
  file.close();
}

void Business::addCustomer(Customer & customer)
{
  if(this->numCustomers < MAX_CUSTOMERS)
    customers[this->numCustomers++] = customer;
  return;
}

void Business::sellStuff()
{
  if(!this->numItems)
    return;
  for(int i = 0 ; i < this->numCustomers ; i ++)
  {
    int index = rand() % this->numItems;
    Product p = items[index];

    if(customers[i].buySomething(p))
      this->money += p.price;
  }
  return;
}

void Business::print()
{
  cout << "Business Name: " << this->name << endl;
  cout << "Money: " << this->money << endl;
  cout << "Items: " << endl;
  for(int i = 0 ; i < this->numItems ; i ++)
    cout << this->items[i] << endl;
  cout << "Customers: " << endl;
  for(int i = 0 ; i < this->numCustomers ; i ++)
    cout << this->customers[i];
  return;
}

void Business::customersLeave(Customer c[], int & num)
{
  for(int i = 0; i < numCustomers; i++)
  {
    c[num++] = customers[i];
  }
  numCustomers = 0;
  return;
}
