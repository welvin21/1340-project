#ifndef ADD_MANUAL
#define ADD_MANUAL
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "struct.h"
using namespace std;
void add_manual(vector<record> &data, double defaultBudgetLimit)
{
  record dataAdded;
  string dateAdded,noteAdded,pivot;
  int incomeOrExpenseAdded,categoryAdded;
  double amountAdded;
  cout<<"Please insert today's date (DD/MM/YYYY) : ";
  cin>>dateAdded;
  dataAdded.date=stoi(dateAdded.substr(0,2));
  dataAdded.month=stoi(dateAdded.substr(3,2));
  dataAdded.year=stoi(dateAdded.substr(6,4));
  cout<<endl;

  cout<<"Please select the number of one of the options below : (1/2)"<<endl;
  cout<<"1.Income"<<endl<<"2.Expense"<<endl<<"Your choice : ";
  cin>>incomeOrExpenseAdded;
  if(incomeOrExpenseAdded==1)
    dataAdded.incomeOrExpense="Income";
  else
    dataAdded.incomeOrExpense="Expense";
  cout<<endl;

  if(incomeOrExpenseAdded==1)
  {
    cout<<"Please select the number of one of the options below as income source : "<<endl;
    cout<<"1.Salary"<<endl<<"2.Bank loan"<<endl<<"3.Prize"<<endl<<"4.Gift"
    <<endl<<"5.Other"<<endl;
    cout<<"Your choice : ";
    cin>>categoryAdded;
    if(categoryAdded==1)
      dataAdded.category="Salary";
    else if(categoryAdded==2)
      dataAdded.category="Bank loan";
    else if(categoryAdded==3)
      dataAdded.category="Prize";
    else if(categoryAdded==4)
      dataAdded.category="Gift";
    else
    {
      cout<<endl;
      cout<<"Please specify the category : ";
      cin>>pivot;
      dataAdded.category=pivot;
      cout<<endl;
    }
    cout<<endl;

  }

  else if(incomeOrExpenseAdded==2)
  {
    cout<<"Please select the number of one of the options below as expense source : "<<endl;
    cout<<"1.Food"<<endl<<"2.Clothes"<<endl<<"3.Entertainment"<<endl<<"4.Transportation"<<endl
    <<"5.Other"<<endl;
    cout<<"Your choice : ";
    cin>>categoryAdded;
    if(categoryAdded==1)
      dataAdded.category="Food";
    else if(categoryAdded==2)
      dataAdded.category="Clothes";
    else if(categoryAdded==3)
      dataAdded.category="Entertainment";
    else if(categoryAdded==4)
      dataAdded.category="Transportation";
    else
    {
      cout<<endl;
      cout<<"Please specify the category : ";
      cin>>pivot;
      dataAdded.category=pivot;
      cout<<endl;
    }
    cout<<endl;

  }
  cout<<"Please enter the amount : ";
  cin>>amountAdded;
  dataAdded.amount=amountAdded;
  cout<<endl;

  cout<<"Is there any additional note you want to add? (Y/N) ";
  cin>>pivot;
  cout<<endl;
  if(pivot=="Y")
  {
    cout<<"Please enter the note here : ";
    cin.ignore();
    getline(cin,noteAdded);
    dataAdded.note=noteAdded;
  }
  else
    dataAdded.note="-";


  data.push_back(dataAdded);
  cout<<endl<<"Summary of added record :"<<endl<<endl;
  cout<<"Date : "<<dataAdded.date<<'/'<<dataAdded.month<<'/'<<dataAdded.year<<endl;
  cout<<"Category : "<<dataAdded.category<<" ("<<dataAdded.incomeOrExpense<<")"<<endl;
  cout<<"Amount : "<<dataAdded.amount<<endl;
  cout<<"Note : "<<dataAdded.note<<endl<<endl;
  cout<<"Total current records : "<<data.size()<<endl<<endl;
  return;
}
#endif
