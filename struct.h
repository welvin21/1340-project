//Using simple conditional expression (header guard)
//which prevent redefinition of struct.h file
#ifndef STRUCT
#define STRUCT

//Create a new object called record
//It consists of multiple basic data types

using namespace std;
struct record
{
  int date,month,year;
  double amount;
  string category,currency,incomeOrExpense,note;
};

#endif
