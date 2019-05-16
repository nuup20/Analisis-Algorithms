#pragma once

#include "aaSorting.h"

class QuickSorting
  : public Sorting
{
public:
  QuickSorting();

  ~QuickSorting();

protected:

  virtual void
  algorithm_exec(vector<int> &);

};