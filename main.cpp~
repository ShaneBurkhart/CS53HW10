//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
// Assignment: 9 "business"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Program that tests the business and customer classes
//

#include<fstream>
#include<iostream>
#include "customer.h"
#include "business.h"
using namespace std;

int main()
{
  const int MAX_HAP = 90;
  const int MIN_HAP = 10;
  Customer customers[NUM_CUSTOMERS];
  Customer tempc[NUM_CUSTOMERS];
  int num = NUM_CUSTOMERS;

  Customer::readCustomers(customers, NUM_CUSTOMERS);

  for(int i = 0 ; i < NUM_CUSTOMERS ; i ++)
    cout << customers[i];

  Business moes("Moe's Bar", 0, NUM_CUSTOMERS);
  Business comics("Comic Book Store, 0, NUM_CUSTOMERS);
  Customer street[20];
  
  do
  {
    for(int i = 0; i < num; i++)
    {
      if(street[i].happiness < MIN_HAP || street[i].happiness > MAX_HAP)
      {
        street[num] = tempc[i];
        tempc[i] = street[i];
        num--;
      }
    for(int i = 0; i < num; i++)
    {
      if(inclination = false)
      {
        moes.addCustomer(street[i]);
      }

      else
      {
        comics.addCustomer(street[i]);
      }
    }

    moes.sellStuff();
    comics.sellStuff();
    
    num = 0;
    
    moes.customersLeave(street, num);
    comics.customersLeave(street, num);
  
    for(int i = 0; i < num; i++)
    {
      rnum = rand()%num;
    
      tempc[i] = street[i]
      street[i] = street[rnum]
      street[rnum] = tempc[i]
    }
  
    for(int i = 0; i < num; i++)
    {
      rnum = rand()%num;
    
      if(street[i] = street[rnum])
      {
        street[i].rob(street[rnum])
      }
    
      else 
      {
        street[i].throw(street[rnum]);
      }
    }
  while(num > 1);
  
  return 0;
}


