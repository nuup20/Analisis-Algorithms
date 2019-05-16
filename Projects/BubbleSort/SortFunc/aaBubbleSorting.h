#pragma once

#include "aaSorting.h"

class BubbleSorting
  : public Sorting
{
public:
  BubbleSorting();

  ~BubbleSorting();

protected:

  virtual void
  algorithm_exec(vector<int> &);

};
