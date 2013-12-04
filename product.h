//////////////////////////////////////////////////////////////////////////////
// Programer: Shane Burkhart         Student ID: 99999
//            Alec Bayliff
// Assignment: 10 "Street Brawl"          Filename: main.cpp
// Due Date: 11/12/13                Class: CS53, Section E
// Desc: Header file for the Product class

#ifndef PRODUCT_H
#define PRODUCT_H

#include<string>
using namespace std;

struct Product
{
  string name;
  float price;

  friend ostream & operator << (ostream & stream, const Product & p);
};

#endif
