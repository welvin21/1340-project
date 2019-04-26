#ifndef ADD_FILE
#define ADD_FILE
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "struct.h"
#include "budget_limit_alert.h"

using namespace std;

string incomeCategories[]={"Salary","Bank loan","Prize","Gift"};
string expenseCategories[]={"Food","Clothes","Entertainment","Transportation"};

void addDate(record &dataAdded, string dateAdded)
{
  dataAdded.date=stoi(dateAdded.substr(0,2));
  dataAdded.month=stoi(dateAdded.substr(3,2));
  dataAdded.year=stoi(dateAdded.substr(6,4));
  return;
}

void addIncomeOrExpense(record &dataAdded, string incomeOrExpenseAdded)
{
  if(incomeOrExpenseAdded=="1")
    dataAdded.incomeOrExpense="Income";
  else
    dataAdded.incomeOrExpense="Expense";
  return;
}

int addCategory(record &dataAdded, string incomeOrExpense, string category, string if_other)
{
  if(incomeOrExpense=="1")
  {
    if(stoi(category)>0 && stoi(category)<5)
    {
      dataAdded.category=incomeCategories[stoi(category)-1];
      return 3;
    }
    else
    {
      dataAdded.category=if_other;
      return 4;
    }
  }
  else
  {
    if(stoi(category)>0 && stoi(category)<5)
    {
      dataAdded.category=expenseCategories[stoi(category)-1];
      return 3;
    }
    else
    {
      dataAdded.category=if_other;
      return 4;
    }
  }

}

void addAmount(record &dataAdded, string amount)
{
  dataAdded.amount=stod(amount);
  return;
}
void addNote(record &dataAdded, string arr[], int index, int num_of_element_in_line)
{
  for(int i=index;i<num_of_element_in_line;++i)
    dataAdded.note+=(arr[i]+" ");
  return;
}
int count_element_in_line(string line)
{
  int output=1;
  for(int i=0;i<line.length();++i)
  {
    if(line[i]==' ')
      output++;
  }
  return output;
}

void add_line_from_file(vector <record> &data, string line)
{
  record dataAdded;
  int num_of_element_in_line=0;
  num_of_element_in_line=count_element_in_line(line);
  string *arr=new string[num_of_element_in_line];
  for(int i=0;i<num_of_element_in_line-1;++i)
  {
    arr[i]=line.substr(0,line.find(" "));
    line.erase(0,line.find(" ")+1);
  }
  arr[num_of_element_in_line-1]=line;
  addDate(dataAdded,arr[0]);
  addIncomeOrExpense(dataAdded,arr[1]);
  int n = addCategory(dataAdded,arr[1],arr[2],arr[3]);
  addAmount(dataAdded,arr[n]);
  addNote(dataAdded,arr,n+1,num_of_element_in_line);
  data.push_back(dataAdded);
  delete []arr;
  arr=nullptr;
  return;
}
void add_file(vector <record> &data , string filename, double defaultBudgetLimit)
{
  int *num_of_line_in_file=new int(0);
  string input;
  ifstream fin(filename.c_str());
  if(fin.fail())
  {
    cout<<"The filename you entered is not valid!"<<endl;
    cout<<"Please move the file to the same directory as your program"<<endl<<endl;
    return ;
  }
  while(getline(fin,input))
  {
    add_line_from_file(data,input);
    (*num_of_line_in_file)++;
  }
  cout<<"Total "<<(*num_of_line_in_file)<<" new records have been added"<<endl<<endl;
  fin.close();
  delete num_of_line_in_file;
  num_of_line_in_file=nullptr;
  cout<<"Total current records : "<<data.size()<<endl<<endl;
  return;
}


#endif
