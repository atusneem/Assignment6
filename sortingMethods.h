/*
Ayra Tusneem
2287899
tusneem@chapman.edu
CPSC 350-01
Asssignment 06
*/

#include <fstream>
#include <iostream>

using namespace std;

class sortingMethods
{
public:
  void bubbleSort(double* myArray, int n);
  void quickSort(double* myArray, int left, int right);
  void insertionSort(double* myArray);
  void selectionSort(double* myArray, int n);
};
