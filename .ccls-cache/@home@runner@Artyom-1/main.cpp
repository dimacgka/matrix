#include <iostream>
#include "header.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");
  int n;
  cout << "Enter N" << endl;
  cin >> n;

  DerivedArrayProcessor arrayProcessor(n);
  arrayProcessor.Run();
  
  return 0;
}