#ifndef ADDCURRENCY
#define ADDCURRENCY
#include <vector>
#include <string>
#include "struct.h"
using namespace std;

void addCurency(vector <record> &data,string defaultCurrency)
{
  for(int i=0;i<data.size();++i)
    data.at(i).currency=defaultCurrency;
  return;
}


#endif
