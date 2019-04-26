#ifndef SETTINGS
#define SETTINGS
#include <iostream>
#include <vector>
#include "currency_converter.h"
#include "change_username.h"
#include "struct.h"
#include "change_budget_limit.h"

//Function : void display_settings
//Input : None
//Output : None
//         Display all options to be chosen by user
void display_settings()
{
  cout<<"Please choose one of the options below (1-) : "<<endl;
  cout<<"1. Change Currency"<<endl;
  cout<<"2. Change username"<<endl;
  cout<<"3. Change budget limit"<<endl;
  cout<<"0. Exit"<<endl;
  cout<<"Your input : ";
  return;
}

//Function : void setting
//Input : -a vector of records named data
//        -string defaultCurrency (pass-by-reference)
//        -string username (pass-by-reference)
//        -double defaultBudgetLimit (pass-by-reference)
//Output : None
//         Do basic setting options based on user preference
void setting(vector <record> &data,string &defaultCurrency,string &username,double &defaultBudgetLimit)
{
  int input=1;
  while(input)
  {
    display_settings();
    cin>>input;
    cout<<endl;
    switch(input)
    {
      case 0:
        break;
      case 1:
        convert(data,defaultCurrency);
        break;
      case 2:
        changeUsername(username);
        break;
      case 3:
        changeBudget(defaultBudgetLimit,defaultCurrency);
        break;
    }
  }
}

#endif
