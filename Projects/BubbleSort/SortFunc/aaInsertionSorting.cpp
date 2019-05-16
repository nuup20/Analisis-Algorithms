#include "pch.h"
#include "aaInsertionSorting.h"

InsertionSorting::InsertionSorting()
{ }

InsertionSorting::~InsertionSorting()
{ }

void 
InsertionSorting::algorithm_exec(vector<int> & _vector)
{
  if (_vector.size() < 2)
  {
    return;
  }

  int anchorPosition = 1;
  int itPosition = 0;
  int vecSize = _vector.size();

  while (anchorPosition < vecSize)
  {
    // Check values before anchor position
    while (itPosition >= 0)
    {
      if (_vector[itPosition] < _vector[anchorPosition])
      {

        // Move element
        _vector.insert(_vector.begin() + itPosition + 1, _vector[anchorPosition]);
        _vector.erase(_vector.begin() + anchorPosition + 1);

        break;
      }

      if (itPosition == 0)
      {
        // Move element
        _vector.insert(_vector.begin(), _vector[anchorPosition]);
        _vector.erase(_vector.begin() + anchorPosition + 1);
      }

      itPosition--;
    }

    itPosition = anchorPosition;
    anchorPosition++;
  }

  return;
}