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
#include<ctime>
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
  int num = NUM_CUSTOMERS;
  int count = 0;

  // seed rand
  srand(time(NULL));

  Customer::readCustomers(street, NUM_CUSTOMERS);

  for(int i = 0 ; i < NUM_CUSTOMERS ; i ++)
    cout << street[i];

  Business moes("Moe's Bar", 0, MOES_ITEMS);
  Business comics("Comic Book Store", 0, CGB_ITEMS);

  do
  {
    cout << "=========Start of Level " << count + 1 << "=========" << endl;

    for(int i = 0 ; i < num ; i ++)
    { // Leave if too happy or not happy enough
      if(street[i].getHappiness() < MIN_HAP || street[i].getHappiness() > MAX_HAP)
      {
        cout << street[i].getName() << " falls desperately hopeless at level ";
        cout << count + 1 << " and is shipped to Shelbyville House of ";
        cout << "Desperation" << endl;
        street[i] = street[num - 1];
        num--;
      }
    }

    for(int i = 0 ; i < num ; i ++)
    { // Customers enter stores
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

    for(int i = 0 ; i < num ; i ++)
    { // Swapping function
      int rnum = rand() % num;
      Customer t;
      t = street[i];
      street[i] = street[rnum];
      street[rnum] = t;
    }

    for(int i = 0 ; i < num ; i ++)
    { // Interactions
      int rnum = rand() % num;

      if(street[i].getInclination() == street[rnum].getInclination())
        street[i].rob(street[rnum]);
      else
        street[i].throwStuff(street[rnum]);
    }

    cout << "=========End of Level " << count + 1 << "=========" << endl;

    cout << "=========Remaining Customers=========" << endl;

    for(int i = 0 ; i < num; i ++)
      cout << street[i];

    count ++;
  }while(num > 1 && count < 20);

  cout << endl;

  cout << "All customers have fought honorably but only " << num;
  cout << " survive:"<< endl;

  for(int i = 0 ; i < num; i ++)
    cout << street[i];

  int moe = 0;
  int cgb = 0;
  for(int i = 0 ; i < num ; i ++)
  {
    if(street[i].getInclination() == false)
      moe += street[i].getHappiness();
    else
      cgb += street[i].getHappiness();
  }

  cout << "***The winner is ";
  if(moe > cgb)
    cout << "Moe";
  else
    cout << "Comic Book Guy";
  cout << "***" << endl;

  cout << "The economy is in shambles, as there are too few customers" << endl;

  return 0;
}


