#include "pch.h"
#include "aaSorting.h"

Sorting::Sorting()
{ }

Sorting::~Sorting()
{ }

void 
Sorting::exec( vector<int> & _vector)
{
  time_point<steady_clock>  startTime;
  time_point<steady_clock>  endTime;

  startTime = steady_clock::now();

  algorithm_exec(_vector);

  endTime = steady_clock::now();

  // Calculate time
  this->m_microseconds
    = duration_cast<microseconds>(endTime - startTime).count();

  return;
}

void 
Sorting::algorithm_exec(vector<int>&)
{ }
