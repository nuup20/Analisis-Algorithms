#pragma once

#include "aaSorting.h"

class MergeSorting
  : public Sorting
{
public:
  MergeSorting();

  ~MergeSorting();

protected:

  virtual void
  algorithm_exec(vector<int> &);

};
