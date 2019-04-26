#ifndef MONTHLY
#define MONTHLY
#include <fstream>
#include <vector>
#include <iostream>
#include "struct.h"

using namespace std;

string month[12]={"January","February","March","April","May","June","July",
"August","September","October","November","December"};
int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};

void countData(vector<record> data,int monthIndex,int year,int &dataCount);
void getMonth(int &monthIndex),getMonthlyStat(vector<record>,int,int,int,string),getYear(int &year);

//Function : void getYear
//Input : int year (pass-by-reference)
//Output : None
//         Change the value of year based on user input
void getYear(int &year)
{
  cout<<"Enter the year that you want the statistic to be presented : ";
  cin>>year;
  return;
}

//Function : void getMonth
//Input : int monthIndex (pass-by-reference)
//Output : None
//         Change the value of monthIndex based on user input
void getMonth(int &monthIndex)
{
  cout<<"Which month do you want the statistic to be presented?"<<endl;
  for(int i=0;i<12;++i)
    cout<<(i+1)<<". "<<month[i]<<endl;
  cout<<"Your input : ";
  cin>>monthIndex;
}

//Function : void countData
//Input : -vector of records named data
//        -int monthIndex
//        -int year
//        -int dataCount (pass-by-reference)
//Output : None
//       : Change the value of dataCount based on the occurences of record in data
//         that have .month==monthIndex and .year=year
void countData(vector<record> data, int monthIndex,int year,int &dataCount)
{
  for(int i=0;i<data.size();++i)
  {
    if(data[i].month==monthIndex && data[i].year==year)
      dataCount++;
  }
  return;
}

//Function : void getMonthlyStat
//Input : -vector of records named data
//        -int monthIndex
//        -int year
//        -int dataCount (pass-by-reference)
//        -string username
//Output : None
//         Present statistical report of partiular month to a file
void getMonthlyStat(vector<record> data,int monthIndex, int year,int dataCount,string username)
{
  if(dataCount==0)
  {
    cout<<"You don't have any data in "<<month[monthIndex-1]<<' '<<year<<endl<<endl;
    return;
  }
  double incomeTotal=0,expenseTotal=0;
  int earliestDate=32,latestDate=0,incomeCount=0,expenseCount=0;
  double totalFood=0,totalClothes=0,totalEntertainment=0,totalTransport=0,totalOthersIn=0;
  double totalSalary=0,totalBankLoan=0,totalPrize=0,totalGift=0,totalOthersEx=0;
  for(int i=0;i<data.size();++i)
  {
    if(data[i].month==monthIndex && data[i].year==year)
    {
      if(data[i].date<=earliestDate)
        earliestDate=data[i].date;
      if(data[i].date>=latestDate)
        latestDate=data[i].date;
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
  string myMonth=month[monthIndex-1],outputFilename=(myMonth+"_"+to_string(year)+".txt");
  ofstream fout(outputFilename.c_str());
  fout<<setprecision(2)<<fixed;
  fout<<username<<"\'s "<<myMonth<<' '<<year<<" records statistics"<<endl<<endl;
  fout<<"Total income : "<<data[0].currency<<' '<<(incomeTotal)<<endl;
  fout<<"Total expense : "<<data[0].currency<<' '<<(expenseTotal)<<endl;
  fout<<"Average monthly income per day: "<<data[0].currency<<' '<<(incomeTotal/daysInMonth[monthIndex-1])<<endl;
  fout<<"Average monthly expense per day: "<<data[0].currency<<' '<<(expenseTotal/daysInMonth[monthIndex-1])<<endl;
  fout<<"Total records in "<<myMonth<<' '<<year<<" = "<<dataCount<<endl<<endl;

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

  fout<<"Earliest record occurred on "<<earliestDate<<' '<<myMonth<<' '<<year<<endl;
  fout<<"Latest record occurred on "<<latestDate<<' '<<myMonth<<' '<<year<<endl;
  cout<<"Statistics for all records in "<<month[monthIndex-1]<<' '<<year;
  cout<<" can be seen in file : "<<outputFilename<<endl<<endl;
  fout.close();
  return;
}
#endif
