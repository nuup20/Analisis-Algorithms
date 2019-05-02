#include "aaFibonacciSeries.h"


#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;

using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::time_point;

FibonnacciSeries::FibonnacciSeries()
{
}

FibonnacciSeries::~FibonnacciSeries()
{
}

void 
FibonnacciSeries::run()
{
  // Header

  cout << "*********************************************************" << endl;
  cout << "* Fibonacci Algorithms " << endl;
  cout << "*********************************************************" << endl << endl;

  bool execute = true;

  do 
  {
    cout << "Ingresa el número por el cúal deseas saber su valor Fibonacci" << endl << endl;
    
    int value;
    cin >> value;

    cout << endl;

    exec(value);

    cout << endl << "Deseas ingresar otro valor? (y/n)" << endl;

    char userInput;
    cin >> userInput;
    execute = (userInput == 'y');

    cout << endl;

  } while (execute);
}

void 
FibonnacciSeries::exec(const int & _value)
{
  // varibles

  time_point<steady_clock> startTime;
  time_point<steady_clock> endTime;

  float secs;
  float millisecs;
  float microsecs;

  int result;  

  ////////////////////////////////////
  // One Func Fibonacci

  // Start Time
  startTime = steady_clock::now();

  // Execute
  result = fibonacciOneFunc(_value);

  // End Time
  endTime = steady_clock::now();

  // Calculate Time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();
  millisecs = microsecs / 1000;
  secs = millisecs / 1000;

  // Display Informaction
  cout << "/*******************************************" << endl;
  cout << "/** Por Ciclo While" << endl << endl;

  cout << "Resultado : " << result << endl << endl;
  cout << "Serie Fibonacci por una sola función ha finalizado en: " << endl;
  cout << "time: " << secs << " seconds " << endl;
  cout << "time: " << millisecs << " milliseconds " << endl;
  cout << "time: " << microsecs << " microseconds " << endl << endl;


  ////////////////////////////////////
  // Recursive Fibonacci

  // Start Time
  startTime = steady_clock::now();

  // Execute

  result = fibonnacciRecursive(_value);

  // End Time
  endTime = steady_clock::now();

  // Calculate Time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();
  millisecs = microsecs / 1000;
  secs = millisecs / 1000;

  // Display Informaction
  cout << "/*******************************************" << endl;
  cout << "/** Por Recursividad" << endl << endl;

  cout << "Resultado : " << result << endl << endl;
  cout << "Serie Fibonacci por funciones recursivas ha finalizado en: " << endl;
  cout << "time: " << secs << " seconds " << endl;
  cout << "time: " << millisecs << " milliseconds " << endl;
  cout << "time: " << microsecs << " microseconds " << endl << endl;
}

int
FibonnacciSeries::fibonnacciRecursive(const int & _value)
{
  if (_value <= 1)
  {
    return 1;
  }
  else
  {
    return fibonnacciRecursive(_value - 1) + fibonnacciRecursive(_value - 2);
  }
}

int 
FibonnacciSeries::fibonacciOneFunc(const int & _value)
{
  int a = 1;
  int b = 1;
  int temp = 0;
  int nvalue = _value;
  
  while (nvalue > 1)
  {
    temp = a;
    a += b;
    b = temp;
  
    --nvalue;
  }

   return a;
}
