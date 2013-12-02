#include<iostream>
using namespace std;

ostream & operator << (ostream & stream, const Product & p)
{
  cout << p.name;
  cout << p.price;
  return stream;
}
