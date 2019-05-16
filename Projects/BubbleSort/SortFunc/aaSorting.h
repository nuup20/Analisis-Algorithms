#pragma once

#include "aaSTD.h"

class Sorting
{
public:
  Sorting();

  virtual ~Sorting();

  virtual void
  exec(vector<int> & _vector);

  long double m_microseconds;

protected:

  virtual void
  algorithm_exec(vector<int> &);
};