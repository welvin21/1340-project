#ifndef SORT
#define SORT

#include <vector>
#include "struct.h"
using namespace std;

//Function : bool isSmallerOrEqual
//Input : record A and record B
//        record is user-defined datatype
//Output : return true if A is chronogically less than or equal to B
//         return false if otherwise
bool isSmallerOrEqual(record A, record B)
{
  if(A.year>B.year)
    return false;
  else if(A.year<B.year)
    return true;
  else
  {
    if(A.month>B.month)
      return false;
    else if(A.month<B.month)
      return true;
    else
    {
      if(A.date>B.date)
        return false;
      else
        return true;
    }
  }
}

//Function : void sort
//Input : vector of records named data
//Output : None
//         Use Selection Sort algorithm to sort all the records in data chronogically
void sort(vector <record> &data)
{
  record pivot;
  for(int i=0;i<data.size();++i)
  {
    record key = data.at(i);
    int pos=i;
    for(int j=i;j<data.size();++j)
    {
      if(isSmallerOrEqual(data.at(j),key))
      {
        key=data.at(j);
        pos=j;
      }
    }
    pivot=data.at(i);
    data.at(i)=data.at(pos);
    data.at(pos)=pivot;
  }
  cout<<"All records have been sorted chronogically"<<endl<<endl;
  return;
}
#endif
