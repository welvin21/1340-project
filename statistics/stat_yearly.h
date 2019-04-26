#ifndef YEARLY
#define YEARLY
#include <fstream>
#include <vector>
#include <iostream>
#include "struct.h"

using namespace std;

//Function : void countDataYearly
//Input : -a vector of records named data
//        -int year
//        -int dataCount (pass-by-reference)
//Output : None
//         Change the value of dataCount based on the ocurrences of record
//         that have .year==year
void countDataYearly(vector <record> data,int year,int &dataCount)
{
  for(int i=0;i<data.size();++i)
  {
    if(data[i].year==year)
      dataCount++;
  }
  return;
}

//Function : void getYearlyStat
//Input : -a vector of records named data
//        -int year
//        -int dataCount
//        -string username
//Output : None
//         Present yearly statistical report to a file
void getYearlyStat(vector <record> data, int year,int dataCount, string username)
{
  if(dataCount==0)
  {
    cout<<"You don't have any data in "<<year<<endl<<endl;
    return;
  }
  double incomeTotal=0,expenseTotal=0;
  int incomeCount=0,expenseCount=0;
  double totalFood=0,totalClothes=0,totalEntertainment=0,totalTransport=0,totalOthersIn=0;
  double totalSalary=0,totalBankLoan=0,totalPrize=0,totalGift=0,totalOthersEx=0;
  for(int i=0;i<data.size();++i)
  {
    if(data[i].year==year)
    {
      if(data[i].incomeOrExpense=="Expense")
      {
        expenseTotal+=data[i].amount;
        expenseCount++;
        if(data[i].category=="Food")
          totalFood+=data[i].amount;
        else if(data[i].category=="Clothes")
          totalClothes+=data[i].amount;
        else if(data[i].category=="Entertainment")
          totalEntertainment+=data[i].amount;
        else if(data[i].category=="Transportation")
          totalTransport+=data[i].amount;
        else
          totalOthersEx+=data[i].amount;
      }
      else if(data[i].incomeOrExpense=="Income")
      {
        incomeTotal+=data[i].amount;
        incomeCount++;
        if(data[i].category=="Salary")
          totalSalary+=data[i].amount;
        else if(data[i].category=="Bank Loan")
          totalBankLoan+=data[i].amount;
        else if(data[i].category=="Prize")
          totalPrize+=data[i].amount;
        else if(data[i].category=="Gift")
          totalGift+=data[i].amount;
        else
          totalOthersIn+=data[i].amount;
      }
    }
    else
      continue;
  }
  string outputFilename=(to_string(year)+".txt");
  ofstream fout(outputFilename.c_str());
  fout<<setprecision(2)<<fixed;
  fout<<username<<"\'s "<<year<<" records statistics"<<endl<<endl;
  fout<<"Total income : "<<data[0].currency<<' '<<(incomeTotal)<<endl;
  fout<<"Total expense : "<<data[0].currency<<' '<<(expenseTotal)<<endl;
  fout<<"Average monthly income per day: "<<data[0].currency<<' '<<(incomeTotal/365)<<endl;
  fout<<"Average monthly expense per day: "<<data[0].currency<<' '<<(expenseTotal/365)<<endl;
  fout<<"Total records in "<<year<<" = "<<dataCount<<endl<<endl;

  fout<<"INCOME STATISTICS"<<endl;
  fout<<"-Total income records : "<<incomeCount<<endl;
  fout<<"-Percentages breakdown : "<<endl;
  fout<<"1. Salary : "<<(totalSalary/incomeTotal*100)<<" %"<<endl;
  fout<<"2. Bank Loan : "<<(totalBankLoan/incomeTotal*100)<<" %"<<endl;
  fout<<"3. Prize : "<<(totalPrize/incomeTotal*100)<<" %"<<endl;
  fout<<"4. Gift : "<<(totalGift/incomeTotal*100)<<" %"<<endl;
  fout<<"5. Others : "<<(totalOthersIn/incomeTotal*100)<<" %"<<endl<<endl;

  fout<<"EXPENSE STATISTICS"<<endl;
  fout<<"-Total expense records : "<<expenseCount<<endl;
  fout<<"-Percentages breakdown : "<<endl;
  fout<<"1. Food : "<<(totalFood/expenseTotal*100)<<" %"<<endl;
  fout<<"2. Clothes : "<<(totalClothes/expenseTotal*100)<<" %"<<endl;
  fout<<"3. Entertainment : "<<(totalEntertainment/expenseTotal*100)<<" %"<<endl;
  fout<<"4. Transportation : "<<(totalTransport/expenseTotal*100)<<" %"<<endl;
  fout<<"5. Others : "<<(totalOthersEx/expenseTotal*100)<<" %"<<endl<<endl;

  cout<<"Statistics for all records in "<<year;
  cout<<" can be seen in file : "<<outputFilename<<endl<<endl;
  fout.close();
  return;
}
#endif
