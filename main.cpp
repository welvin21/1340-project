#include <iostream>
#include <vector>
#include "struct.h"
#include "add\add.h"
#include "settings\settings.h"
#include "statistics\statistic.h"
#include "print.h"
#include "sort.h"
#include "display_options.h"
#include "edit.h"
using namespace std;


int main()
{
  vector <record> data;
  string username="",prefix="",defaultCurrency;
  int defaultCurrencyIndex;
  double defaultBudgetLimit=0;

  //Starting point for user
  cout<<"WELCOME TO WEALTH MANAGEMENT SYSTEM 101 !"<<endl;

  cout<<"Before we start, let us know more a little bit about you"<<endl;
  cout<<"1.Mr"<<endl<<"2.Mrs"<<endl<<"Please choose (1/2) : ";
  cin>>prefix;
  if(prefix=="1")
    prefix="Mr.";
  else
    prefix="Mrs.";
  cout<<"Please enter 6-12 characters as your username : ";
  cin.ignore();
  getline(cin,username);
  cout<<endl<<"Welcome "<<prefix<<username<<"!"<<endl<<endl;

  showCurrencies();
  cin>>defaultCurrencyIndex;
  cout<<endl;
  defaultCurrency=country[defaultCurrencyIndex-1];
  cout<<"Please enter your monthly budget limit (in "<<defaultCurrency<<") : ";
  cin>>defaultBudgetLimit;
  cout<<endl;
  int input=1;
  //Functionality
  while(input)
  {
    display_option();
    cin>>input;
    cout<<endl;
    switch (input)
    {
      case 0 :
        break;
      case 1:
        add(data,defaultCurrency,defaultBudgetLimit);
        break;
      case 2:
        print(data,username);
        break;
      case 3:
        sort(data);
        break;
      //case 4:
        //edit(data);
        //break;
      //case 5:
        //remove(data);
        //break;
      case 6:
        statistic(data,username);
        break;
      case 7:
        setting(data,defaultCurrency,username,defaultBudgetLimit);
        break;
    }
  }






}
