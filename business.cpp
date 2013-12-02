//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Header file for business class
//

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
  string buffer;
  //while(getline(file, buffer) && num_items < MAX_ITEMS)
    //items[this->num_items++] = buffer;
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
  int index = rand() % this->numItems;
  cout << "Something" << endl;
  for(int i = 0 ; i < this->numCustomers ; i ++)
  {
    if(customers[i].getMoney() >= ITEM_PRICE &&
      customers[i].buySomething(items[index]))
    {
      this->money += ITEM_PRICE;
      customers[i].setMoney(customers[i].getMoney() - ITEM_PRICE);
    }
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
    this->customers[i].print();
  return;
}

void Business::customersLeave(Customer c[], int & num)
{
  for(int i = 0; i < numCusomers; i++)
  {
    c[num++] = customers[i];
  }
  num_customers = 0;
  return;
}
