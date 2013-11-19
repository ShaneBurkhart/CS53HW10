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
#include "customer.h"
#include "business.h"
using namespace std;

Business::Business(string name, float money, string f_name)
{
  this->name = name;
  this->money = money;
  this->num_items = 0;
  this->num_customers = 0;
  ifstream file;
  file.open(f_name.c_str());
  if(!file)
    return;
  string buffer;
  while(getline(file, buffer) && num_items < MAX_ITEMS)
    items[this->num_items++] = buffer;
  file.close();
}

void Business::enterCustomer(Customer customer)
{
  if(this->num_customers < MAX_CUSTOMERS)
    customers[this->num_customers++] = customer;
  return;
}

void Business::makeASell()
{
  if(!this->num_items)
    return;
  int index = rand() % this->num_items;
  cout << "Something" << endl;
  for(int i = 0 ; i < this->num_customers ; i ++)
  {
    if(customers[i].getMoney() >= ITEM_PRICE &&
      customers[i].purchase(items[index]))
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
  for(int i = 0 ; i < this->num_items ; i ++)
    cout << this->items[i] << endl;
  cout << "Customers: " << endl;
  for(int i = 0 ; i < this->num_customers ; i ++)
    this->customers[i].print();
  return;
}
