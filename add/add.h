#ifndef ADD
#define ADD

#include <vector>
#include "add_manual.h"
#include "add_file.h"
#include "struct.h"
#include "add_currency.h"
#include "change_budget_limit.h"
#include "budget_limit_alert.h"

using namespace std;

void add(vector <record> &data,string defaultCurrency,double defaultBudgetLimit)
{
  int input;
  cout<<"Please choose one of the number below (1/2): "<<endl;
  cout<<"1.Input record manually"<<endl;
  cout<<"2.Input records by file"<<endl;
  cout<<"0.Back"<<endl;
  cout<<"Your choice : ";
  cin>>input;
  cout<<endl;
  if(input==1)
  {
    add_manual(data,defaultBudgetLimit);
    addCurency(data,defaultCurrency);
  }
  else if(input==2)
  {
    string filename;
    cout<<"Please specify the filename of your input file : ";
    cin>>filename;
    cout<<endl;
    add_file(data,filename,defaultBudgetLimit);
    addCurency(data,defaultCurrency);
  }
  else if(input==0)
    return;
  return;
}

#endif
