#ifndef CHANGE_BUDGET
#define CHANGE_BUDGET

#include <iostream>
using namespace std;

//Function : void changeBudget
//Input : -double defaultBudgetLimit(pass-by-reference)
//        -string defaultCurrency
//Output : None
//         Change the value of defaultBudgetLimit based on user input
void changeBudget(double &defaultBudgetLimit,string defaultCurrency)
{
  cout<<"Old budget limit = "<<defaultCurrency<<' '<<defaultBudgetLimit<<endl;
  cout<<"Please enter new budget limit : ";
  cin>>defaultBudgetLimit;
  cout<<endl;
  cout<<"Budget limit has been changed!"<<endl;
  cout<<"New budget limit = "<<defaultCurrency<<' '<<defaultBudgetLimit<<endl<<endl;
  return;
}
#endif
