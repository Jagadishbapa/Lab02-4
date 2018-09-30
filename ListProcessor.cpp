// ListProcessor.cpp
// Modified by Ben Howe
// COSC 2030
// September 29, 2018

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
// and destructor.

#include "LinkedList.h"

int main()
{
  List cows;
  cout << "cows list  :  " << cows << endl << endl;

  cows.insertAsFirst(1.23);
  cows.insertAsFirst(2.34);
  cout << "cows list  :  " << cows << endl << endl;

  cows.removeFirst();
  cout << "cows list  :  " << cows << endl << endl;

  List horses(cows);
  cout << "cows list  :  " << cows << endl;
  cout << "horses list:  " << horses << endl << endl;

  horses.removeFirst();
  horses.insertAsFirst(5.67);
  cows.insertAsFirst(6.78);
  cout << "cows list  :  " << cows << endl;
  cout << "horses list:  " << horses << endl << endl;

  List pigs;
  cout << "cows list  :  " << cows << endl;
  cout << "horses list:  " << horses << endl;
  cout << "pigs list  :  " << pigs << endl << endl;

  pigs = cows;
  cout << "cows list  :  " << cows << endl;
  cout << "horses list:  " << horses << endl;
  cout << "pigs list  :  " << pigs << endl << endl;

  pigs = horses;
  cout << "cows list  :  " << cows << endl;
  cout << "horses list:  " << horses << endl;
  cout << "pigs list  :  " << pigs << endl << endl;

  cout << "End of original code" << endl;
  cout << "===================================" << endl;
  cout << "Start of extra test code" << endl;
  cout << "Creating new array..." << endl;
  List test_list;
  test_list.insertAsFirst(0.9);
  test_list.insertAsFirst(3.0);
  test_list.insertAsFirst(7.5);
  test_list.insertAsFirst(8.6);
  cout << "test_list list : " << test_list << endl;
  cout << "Adding 1.2 to the end of the list..." << endl;
  test_list.insertAsLast(1.2);
  cout << "test_list list : " << test_list << endl;
  cout << "Adding 3.4 to the end of the list..." << endl;
  test_list.insertAsLast(3.4);
  cout << "test_list list : " << test_list << endl;
  cout << "Adding 5.6 to the end of the list..." << endl;
  test_list.insertAsLast(5.6);
    cout << "test_list list : " << test_list << endl;

  cout << "End of extra test code" << endl;
  return 0;
}