//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Program that tests the business and customer classes
//

#include<fstream>
#include<iostream>
#include<string>
#include "business.h"
#include "customer.h"
#include "product.h"
using namespace std;

int main()
{
  const int MAX_HAP = 90;
  const int MIN_HAP = 10;
  const string MOES_ITEMS = "Moe's.txt";
  const string CGB_ITEMS = "Comic Book Guy's.txt";
  const int NUM_CUSTOMERS = 20;

  Customer street[NUM_CUSTOMERS];
  Customer tempc[NUM_CUSTOMERS];
  int num = NUM_CUSTOMERS;

  Customer::readCustomers(street, NUM_CUSTOMERS);

  for(int i = 0 ; i < NUM_CUSTOMERS ; i ++)
    cout << street[i];

  Business moes("Moe's Bar", 0, MOES_ITEMS);
  Business comics("Comic Book Store", 0, CGB_ITEMS);

  do
  {
    for(int i = 0; i < num; i++)
    {
      if(street[i].getHappiness() < MIN_HAP || street[i].getHappiness() > MAX_HAP)
      {
        street[num] = tempc[i];
        tempc[i] = street[i];
        num--;
      }
    }

    for(int i = 0; i < num; i++)
    {
      if(street[i].getInclination() == false)
        moes.addCustomer(street[i]);
      else
        comics.addCustomer(street[i]);
    }

    moes.sellStuff();
    comics.sellStuff();

    num = 0;

    moes.customersLeave(street, num);
    comics.customersLeave(street, num);

    for(int i = 0; i < num; i++)
    {
      int rnum = rand()%num;

      tempc[i] = street[i];
      street[i] = street[rnum];
      street[rnum] = tempc[i];
    }

    for(int i = 0; i < num; i++)
    {
      int rnum = rand()%num;

      if(street[i].getInclination() == street[rnum].getInclination())
        street[i].rob(street[rnum]);
      else
        street[i].throwStuff(street[rnum]);
    }

  }while(num > 1);

  return 0;
}


