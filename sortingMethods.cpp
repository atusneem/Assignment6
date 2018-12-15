/*
Ayra Tusneem
2287899
tusneem@chapman.edu
CPSC 350-01
Asssignment 06
*/

#include <fstream>
#include <iostream>
#include "sortingMethods.h"

using namespace std;

void sortingMethods::bubbleSort(double* myArray, int n)
{
  for(int i = 0; i < n; i++)
  {
    double temp = 0;
    for (int j = i; j < n - 1; j++)
    {
      if(myArray[j] > myArray[j+1])
      {
        temp = myArray[j+1];
        myArray[j+1] = myArray[j];
        myArray[j] = temp;
      }
    }
  }
}

void sortingMethods::quickSort(double* myArray, int left, int right)
{
  int i = left;
  int j = right;
  double tmp;
  double pivot = myArray[(left + right)/2];
  /* partition */
  while (i <= j)
  {
    while (myArray[i] < pivot)
    {
      i++;
    }
    while (myArray[j] > pivot)
    {
      j--;
    }

    if (i <= j)
    {
      tmp = myArray[i];
      myArray[i] = myArray[j];
      myArray[j] = tmp;
      i++;
      j--;
    }
  }
  /* recursion */
  if (left < j)
  {
    quickSort(myArray, left, j);
  }
  if (i < right)
  {
    quickSort(myArray, i, right);
  }
}

void sortingMethods::insertionSort(double* myArray)
{
  double temp;
  for(int i = 1; i < 10; i++)
  {
    temp = myArray[i];
    int j = i;
    while(j > 0 && myArray[j-1] >= temp)
    {
      myArray[i] = myArray[j-1];
      j--;
    }
    myArray[j] = temp;
  }
}

void sortingMethods::selectionSort(double* myArray, int n)
{
  int minIndex;
  double temp;

  for(int i = 0; i < n-1; i++)
  {
    minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (myArray[j] < myArray[minIndex])
      {
        minIndex = j;
      }
      if(minIndex != i)
      {
        temp = myArray[i];
        myArray[i] = myArray[minIndex];
        myArray[minIndex] = temp;
      }
    }
  }
}
