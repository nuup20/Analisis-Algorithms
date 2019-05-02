#pragma once

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

  int 
  fibonnacciRecursive(const int &);

  int
  fibonacciOneFunc(const int &);
};
