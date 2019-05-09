#pragma once

#include <vector>

class FibonnacciSeries
{
public:

  FibonnacciSeries();

  ~FibonnacciSeries();

  void 
  run();

private:

  void
  exec(const int &);

  void
  exec(const std::vector<int> &);

  int 
  fibonnacciRecursive(const int &);

  int
  fibonacciOneFunc(const int &);
};
