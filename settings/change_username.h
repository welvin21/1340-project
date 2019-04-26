#ifndef CHANGE_USERNAME
#define CHANGE_USERNAME
#include <iostream>
using namespace std;

//Function : void changeUsername
//Input : string username (pass-by-reference)
//Output : None
//         Change the value of username based on user input
void changeUsername(string &username)
{
  cout<<"Old username : "<<username<<endl;
  cout<<"Please enter new username : ";
  cin.ignore();
  getline(cin,username);
  cout<<endl<<"Username has been updated!"<<endl;
  cout<<"New username : "<<username<<endl<<endl;
  return;
}

#endif
