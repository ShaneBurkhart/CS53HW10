//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Brendan Nulsen
//            Alec Bayliff
// Assignment: 10 "Street Brawl"     Filename: product.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Implementation file for the product struct

#include<iostream>
#include "product.h"
using namespace std;

ostream & operator << (ostream & stream, const Product & p)
{
  cout << p.name;
  cout << p.price;
  return stream;
}
