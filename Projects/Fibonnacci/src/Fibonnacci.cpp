// Fibonnacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "aaFibonacciSeries.h"

int main()
{
    std::cout << "Hello World!\n"; 

    FibonnacciSeries * fibo = new FibonnacciSeries();
    fibo->run();
}
