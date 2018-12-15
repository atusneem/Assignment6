/*
Ayra Tusneem
2287899
tusneem@chapman.edu
CPSC 350-01
Asssignment 06
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include "sortingMethods.cpp"
#include <time.h>
using namespace std;

int main(int argc, char* argv[])
{
  //takes input from file and puts it into an array
  ifstream inputFile;
  string file;
  int num = 0;
  double *myArray;
  file = argv[1];
  int count = 0;

  inputFile.open(file);
  if(!inputFile.is_open())
  {
    cout << "sorry, your file does not exist!" << endl;
  }
  else
  {
    string line;
    while(getline(inputFile, line))
    {
      count++;
      if(count == 1) //prevent segmentation fault
      {
        stringstream s(line);
        s >> num;
      }
      else
      {
        myArray = new double[num];
        double temp;
        stringstream s(line);
        s >> temp;
        myArray[count - 2] = temp;
      }
    }

    //creating array copies and adding current array into the copies
    double myArray0[num];
    double myArray1[num];
    double myArray2[num];

    for(int i = 0; i < num; i++)
    {
      myArray0[i] = myArray[i];
      myArray1[i] = myArray[i];
      myArray2[i] = myArray[i];
    }

    sortingMethods s;
    //uses clock_t to get time and ctime to print exact time and date
    cout << "Bubble Sort: " << endl;

    clock_t start = clock();
    cout << ctime(&start) << endl;

    s.bubbleSort(myArray1, num);

    clock_t end = clock();
    cout << ctime(&end) << endl;

    double elapsedTime = double(end - start) / 1000;
    cout << "Runtime: " << elapsedTime << endl;



    cout << "Quick Sort: " << endl;

    start = clock();
    cout << ctime(&start) << endl;

    s.quickSort(myArray, 0, num - 1);

    end = clock();
    cout << ctime(&end) << endl;

    elapsedTime = double(end - start) / 1000;
    cout << "Runtime: " << elapsedTime << endl;




    cout << "Insertion Sort: " << endl;

    start = clock();
    cout << ctime(&start) << endl;

    s.insertionSort(myArray0);

    end = clock();
    cout << ctime(&end) << endl;

    elapsedTime = double(end - start) / 1000;
    cout << "Runtime: " << elapsedTime << endl;




    cout << "Selection Sort: " << endl;

    start = clock();
    cout << ctime(&start) << endl;

    s.selectionSort(myArray2, num);

    end = clock();
    cout << ctime(&end) << endl;

    elapsedTime = double(end - start) / 1000;
    cout << "Runtime: " << elapsedTime << endl;
  }
}



