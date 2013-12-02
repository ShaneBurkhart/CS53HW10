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
  Customer customers[20];
  Customer tempc[20];
  int num = 0;

  Customer::readCustomers(customers, 20);

  for(int i = 0 ; i < 20 ; i ++)
    cout << customers[i];

  return 0;
  Business moes("Moe's Bar", 0, 20);
  Business comics("Comic Book Store, 0, 20);
  Customer street[20];
  
  do
  {
    for(int i = 0; i < num_customers; i++)
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


