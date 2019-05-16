#pragma once

#include "aaSorting.h"

class HeapSorting
  : public Sorting
{
public:
  HeapSorting();

  ~HeapSorting();

protected:

  virtual void
  algorithm_exec(vector<int> &);

};
