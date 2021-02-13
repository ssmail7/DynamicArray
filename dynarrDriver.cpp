#include <iostream>
#include <exception>#include "dynarr.h"
using namespace std;int main(){
  cout << "\nThis is the DynarrDrive program.\n";

  // Define dynarr object  dynarr<int> first(0);

  int index, renum;

  cout << "Please enter a capacity for the first array: ";
  cin >> renum;

  first.reserve(renum);

  cout << "The capacity of the first array is " << first.getCapacity() << endl;
  cout << "Please fill the array with numbers.\n";
  for (int num = 0; num < first.getCapacity(); num++)
  {
     cout << "Enter an item: ";
     cin >> first[num];
  }

  cout << "Contents of A:\n";
  for (int num = 0; num < first.getCapacity(); num++)
  {
    cout << first[num] << " ";
  }
  cout << endl;

  cout << "To retrieve an item, please enter a number: ";
  cin >> index;
  try
  {
    cout << first[index] << " is the item at that location" << endl;
  }
  catch(InvalidIndex &e)
  {
    cout << e.getMessage() << endl;
  }

  cout << "Creating a copy of A\n";
  dynarr<int> second(first);

  cout << "The capacity of the second array is " << second.getCapacity() << endl;

  cout << "Changing the copy's entries to even numbers\n";
  for (int num = 0; num < second.getCapacity(); num++)
  {
    if (second[num] % 2 != 0)
      second[num] -= 1;
  }

  cout << "Contents of the modified copy:\n";
  for (int num = 0; num < second.getCapacity(); num++)
  {
    cout << second[num] << " ";
  }
  cout << endl;

  cout << "Contents of A:\n";
  for (int num = 0; num < first.getCapacity(); num++)
  {
    cout << first[num] << " ";
  }
  cout << endl;

  cout << "Creating a new dynamic array C\n";
  dynarr<int> third(0);

  cout << "Assigning A to C\n";
  third = first;

  cout << "Squaring all entries in C\n";
  for (int num = 0; num < third.getCapacity(); num++)
    third[num] = (third[num] * third[num]);

  cout << "Contents of C:\n";
  for (int num = 0; num < third.getCapacity(); num++)
  {
    cout << third[num] << " ";
  }
  cout << endl;

  cout << "Contents of A:\n";
  for (int num = 0; num < first.getCapacity(); num++)
  {
    cout << first[num] << " ";
  }
  cout << endl;

  cout << "Please enter a new capacity for the first array: ";
  cin >> renum;

  first.reserve(renum);

  cout << "The capacity of the first array is " << first.getCapacity() << endl;

  cout << "Contents of A:\n";
  for (int num = 0; num < first.getCapacity(); num++)
  {
    cout << first[num] << " ";
  }
  cout << endl;

  cout << "End of program" << endl;

  return 0;}