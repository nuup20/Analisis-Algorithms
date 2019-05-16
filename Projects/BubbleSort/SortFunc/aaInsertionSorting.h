#pragma once

#include "aaSorting.h"

class InsertionSorting
  : public Sorting
{
public:
  InsertionSorting();

  ~InsertionSorting();  

private:
   
  virtual void
  algorithm_exec(vector<int> &);

};
