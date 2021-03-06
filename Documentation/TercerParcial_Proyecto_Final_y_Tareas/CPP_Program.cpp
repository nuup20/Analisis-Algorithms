// CPP_Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <chrono>
#include <algorithm>

using std::vector;
using std::string;
using std::pow;

using std::chrono::system_clock;
using std::chrono::time_point;
using std::chrono::duration;

// Coins
/*
void
getCoin
(
  int & _monto, 
  int * _a_coins,
  int & _size,
  int & _index,
  std::vector<int> & _vector
)
{  
  if (_monto <= 0)
  {
    return;
  }

  if (_monto >= _a_coins[_index])
  {
    _monto -= _a_coins[_index];
    _vector.push_back(_a_coins[_index]);    
  }
  else
  {
    _index++;
  }

  return getCoin(_monto, _a_coins, _size, _index, _vector);
}

int
main()
{
  int m_coins[]     = {10, 5, 2, 1};
  int m_coins_size  = 4;
  int m_monto       = 35;
  int m_start_index = 0;

  std::vector<int> m_coins_vector;
  getCoin(m_monto, &m_coins[0], m_coins_size, m_start_index, m_coins_vector);

  std::cout << "hola";
}
*/

// ADN Brute Force

vector<string>
getSubsecuences
(
  const string & _subsecuence, 
  const unsigned int _number
)
{
    
  unsigned int string_lenght = _subsecuence.length();
  int subsecuence_length = pow(2, string_lenght);

  vector<string> subsecuence_list;
  for (unsigned int counter = 1; counter < subsecuence_length; ++counter)
  {
    string subsecuence = "";
    for (unsigned int j = 0; j < string_lenght; ++j)
    {
      if (counter & (1 << j))
      {
        subsecuence.push_back(_subsecuence[j]);
      }
    }

    subsecuence_list.push_back(subsecuence);
  }

  return subsecuence_list;
}

string
subsecuenceComparison
(
  const vector<string> & _sub_1,
  const vector<string> & _sub_2
)
{
  string lcs = "";

  unsigned int sub_1_len = _sub_1.size();
  unsigned int sub_2_len = _sub_2.size();

  for (unsigned int i = 0; i < sub_1_len; ++i)
  {
    for (unsigned int j = 0; j < sub_2_len; ++j)
    {
      if (_sub_1[i] == _sub_2[j])
      {
        if (lcs.size() < _sub_1[i].size())
        {
          lcs = _sub_1[i];
        }
      }
    }
  }

  return lcs;
}

string
LCS
(
  const string & _secuence_1, 
  const string & _secuence_2
)
{
  const size_t m = 15;
  const size_t n = 16;

  int matrix[m+1][n+1] {};

  for (unsigned int i = 0; i < m + 1; ++i)
  {
    for (unsigned int j = 0; j < n + 1; ++j)
    {
      if (i == 0 || j == 0)
      {
        matrix[i][j] = 0;
      }
      else if (_secuence_1[i - 1] == _secuence_2[j - 1])
      {
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      }
      else
      {
        matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
      }
    }
  }

  int index = matrix[m][n];

  string lcs;
  lcs.resize(index + 1, '#');
  lcs[index];

  int i = m;
  int j = n;

  while (i > 0 && j > 0)
  {
    if (_secuence_1[i - 1] == _secuence_2[j - 1])
    {
      lcs[index - 1] = _secuence_1[i - 1];

      --i;
      --j;
      --index;
    }
    else if (matrix[i - 1][j] > matrix[i][j - 1])
    {
      --i;
    }
    else
    {
      --j;
    }
  }

  return lcs;
}

int
main()
{
  string secuence_1 = "TTCGCATCGGGTTG";
  string secuence_2 = "TGACCGTGTGTCACG";
  string lcs = ""; 

  std::chrono::time_point<std::chrono::system_clock> start;
  std::chrono::time_point<std::chrono::system_clock> end;

  start = std::chrono::system_clock::now();  
  lcs = LCS(secuence_1, secuence_2);
  end = std::chrono::system_clock::now();

  std::chrono::duration<double> elpased_time = end - start;

  //std::cout << "Fuerza Bruta \n";
  std::cout << "Dynamic Programming \n";
  std::cout << "Elapsed seconds : " << elpased_time.count() << "\n";
  //std::cout << "Subsecuencia más larga : ";
  //std::cout << lcs;
  
  start = std::chrono::system_clock::now();
  
  vector<string> sub_secuencce_1 = getSubsecuences(secuence_1, 1);
  vector<string> sub_secuencce_2 = getSubsecuences(secuence_2, 2);

  lcs = subsecuenceComparison(sub_secuencce_1, sub_secuencce_2);
  end = std::chrono::system_clock::now();

  elpased_time = end - start;

  std::cout << "Brute Force Programming \n";
  std::cout << "Elapsed seconds : " << elpased_time.count() << "\n";  

  return 0;
}