#ifndef PRINT
#define PRINT

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "struct.h"
using namespace std;

//Function : bool file_is_empty
//Input : string filename and string username
//Output : return true if filename.txt doesn't exist
//         or if it does but contains no data
//         return false if filename.txt does exist and contain
//         the string "username"+"\'s\'" as its first data
bool file_is_empty(string filename,string username)
{
  ifstream fin(filename.c_str());
  if(fin.fail())
  {
    fin.close();
    return true;
  }
  string input;
  fin>>input;
  if(input!="")
  {
    fin.close();
    return false;
  }
  else
  {
    fin.close();
    return true;
  }
}

//Function : void print
//Input : vector of records named data and string username
//Output : None
//         print out all the records in data to user-desired filename
void print(vector <record> data,string username)
{
  string filename;
  cout<<"Please specify the name of the output file : ";
  cin>>filename;
  cout<<endl;
  ofstream fout;
  if(file_is_empty(filename,username))
  {
    fout.open(filename.c_str());
    fout<<setprecision(2)<<fixed;
    fout<<username<<"'s records data"<<endl<<endl;
    for(int i=0;i<data.size();++i)
    {
      record output=data.at(i);
      fout<<"Date : "<<output.date<<'/'<<output.month<<'/'<<output.year<<endl;
      fout<<"Category : "<<output.category<<" ("<<output.incomeOrExpense<<")"<<endl;
      fout<<"Amount : "<<output.currency<<' '<<output.amount<<endl;
      fout<<"Note : "<<output.note<<endl<<endl;
    }
    cout<<"All records have been succesfully added to "<<filename<<endl<<endl;

    fout.close();
  }
  else
  {
    int answer;
    cout<<filename<<" is already exist!"<<endl<<endl;
    cout<<"Do you want to overwrite "<<filename<<"? (1/2)"<<endl;
    cout<<"1. Yes, delete all existing data in "<<filename<<" and replace with my current data"<<endl;
    cout<<"2. No, append my current data to "<<filename<<endl;
    cout<<"Your answer : ";
    cin>>answer;
    cout<<endl<<endl;
    if(answer==1)
    {
      fout.open(filename.c_str());
      fout<<setprecision(2)<<fixed;
      fout<<username<<"'s records data"<<endl<<endl;
      for(int i=0;i<data.size();++i)
      {
        record output=data.at(i);
        fout<<"Date : "<<output.date<<'/'<<output.month<<'/'<<output.year<<endl;
        fout<<"Category : "<<output.category<<" ("<<output.incomeOrExpense<<")"<<endl;
        fout<<"Amount : "<<output.currency<<' '<<output.amount<<endl;
        fout<<"Note : "<<output.note<<endl<<endl;
      }
      cout<<"All records have been succesfully added to "<<filename<<endl<<endl;

      fout.close();
    }
    else
    {
      fout.open(filename.c_str(),ios::app);
      fout<<setprecision(2)<<fixed;
      for(int i=0;i<data.size();++i)
      {
        record output=data.at(i);
        fout<<"Date : "<<output.date<<'/'<<output.month<<'/'<<output.year<<endl;
        fout<<"Category : "<<output.category<<" ("<<output.incomeOrExpense<<")"<<endl;
        fout<<"Amount : "<<output.currency<<' '<<output.amount<<endl;
        fout<<"Note : "<<output.note<<endl<<endl;
      }
      cout<<"All records have been succesfully appended to "<<filename<<endl<<endl;

      fout.close();
    }
  }


  return;
}

#endif
