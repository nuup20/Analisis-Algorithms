// SortFunc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "aaSTD.h"

int
getRandomInt(const int & _min, const int & _max)
{
  return _min + (rand() % static_cast<int>(_max - _min + 1));
}

void
getAscVector(std::vector<int> & _vector, const int & _size)
{
  for (int index = 1; index <= _size; index++)
  {
    _vector.push_back(index);
  }
  return;
}

void
getDescVector(std::vector<int> & _vector, const int & _size)
{
  for (int index = 0; index < _size; index++)
  {
    _vector.push_back(_size - index);
  }
  return;
}

void
getRandomVector(std::vector<int> & _vector, const int & _size)
{
  std::vector<int> ascvector;
  getAscVector(ascvector, _size);

  while (ascvector.size() > 1)
  {

    int randPos = getRandomInt(0, ascvector.size() - 1);    
    _vector.push_back(ascvector[randPos]);

    ascvector.erase(ascvector.begin() + randPos);
  }

  _vector.push_back(ascvector[0]);
}

void
printVector(std::string & _name, std::vector<int> & _vector)
{
  std::cout << "\n----------------- (" << _name.c_str() << ") Size: " << _vector.size() << " --------------------" << std::endl;
  for (int value : _vector)
  {
    std::cout << value << " ";
  }

  std::cout << "\n";
  return;
}

void 
bubbleAscSorting(std::vector<int> & _vector)
{
  int vecSize = _vector.size();
  int vecSizeR = vecSize - 1;

  for (int indexPass = 0; indexPass < vecSize; ++indexPass)
  {
    for (int idxPos = 0; idxPos < vecSizeR; ++idxPos)
    {
      if (_vector[idxPos] > _vector[idxPos + 1])
      {
        std::swap(_vector.at(idxPos), _vector.at(idxPos + 1));
      }
    }
  }
}

void
insertionAscSorting(std::vector<int> & _vector)
{ 
  
}

int
partition(std::vector<int> & _vector, const int & _min, const int & _max)
{
  int pivot = _vector[_max];

  int i = (_min - 1);
  for (int j = _min; j < _max; j++)
  {
    if (_vector[j] < pivot)
    {
      i++;
      std::swap(_vector.at(i), _vector.at(j));
    }
  }

  std::swap(_vector.at(i + 1), _vector.at(_max));
  return i + 1;
}

void
mergeSortA(std::vector<int> & _vector, int & _lIndex, int & _rIndex)
{

}

void
mergeSort(std::vector<int> & _vector)
{
  mergeSortA(_vector, 0, static_cast<int>(_vector.size()));
  return;
}

void
quickAscSorting(std::vector<int> & _vector, const int & _min, const int & _max)
{
  if (_min < _max)
  {
    int pi = partition(_vector, _min, _max);

    quickAscSorting(_vector, _min, pi - 1);
    quickAscSorting(_vector, pi + 1, _max);
  }
}

void
runAscSort
(
  std::string &       _name, 
  std::vector<int> &  _vector, 
  std::string &       _fileContent
)
{
  ////////////////////////////////////
  // Vars

  long double microsecs;
  std::vector<int> vectorCopy(_vector);

  ////////////////////////////////////
  // Bubble Sorting

  startTime = steady_clock::now();
  
  bubbleAscSorting(vectorCopy);
  
  endTime = steady_clock::now();
 
  // Calculate time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();

  _fileContent += ( std::to_string(_vector.size())+ "," + std::to_string(microsecs) + ",");

  ////////////////////////////////////
  // Quick Sorting

  vectorCopy = _vector;

  startTime = steady_clock::now();

  quickAscSorting(vectorCopy, 0, vectorCopy.size() - 1);

  endTime = steady_clock::now();

  // Calculate time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();

  _fileContent += (std::to_string(microsecs) + "," );

  ////////////////////////////////////
 // Insert Sorting

  vectorCopy = _vector;

  startTime = steady_clock::now();

  insertionAscSorting(vectorCopy);

  endTime = steady_clock::now();

  // Calculate time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();

  _fileContent += (std::to_string(microsecs));  

  return;
}

void
execTest(const int & _size, std::string & _fileContent)
{
  std::vector<int> ascVec;
  std::vector<int> descVec;
  std::vector<int> randVec;

  getAscVector(ascVec, _size);

  std::string name1 = "Best";
  //printVector(name1, ascVec);

  getDescVector(descVec, _size);
  std::string name2 = "Worst";
  //printVector(name2, descVec);

  getRandomVector(randVec, _size);

  std::string name3 = "Medium";
  //printVector(name3, randVec);

  ////////////////////////////////////
  // Sort

  runAscSort(name1, ascVec, _fileContent);
  _fileContent += ",";

  runAscSort(name2, descVec, _fileContent);
  _fileContent += ",";

  runAscSort(name3, randVec, _fileContent);
  _fileContent += "\n";

  return;
}

void
writeInFile(std::string & _fileContent)
{
  std::ofstream out("data.csv");
  out << _fileContent;
  out.close();

  return;
}

int main()
{
    std::string       fileContent;
    std::vector<int>  aElements;
    bool              addElement = true;

    fileContent = "Elements(Best),Bubble Sorting (Microseconds), QuickSorting (Microseconds), InsertSorting (Microseconds),"
                  "Elements(Worst),Bubble Sorting (Microseconds), QuickSorting (Microseconds), InsertSorting (Microseconds),"
                  "Elements(average),Bubble Sorting (Microseconds), QuickSorting (Microseconds), InsertSorting (Microseconds)\n";

    std::cout << "Ingresa un tamaño: \n"; 
    
    int size;
    std::cin >> size;
    aElements.push_back(size);

    while (addElement)
    {
      std::cout << "\n Elements: \n";
      for (int element : aElements)
      {
        std::cout << std::to_string(element) << std::endl;
      }
      cout << std::endl;

      std::cout << " Do you want to add more Elements? (y/n) \n" << std::endl;

      char input;
      std::cin >> input;

      if (input == 'y')
      {
        std::cout << "\n Ingresa un tamaño: \n";

        int size;
        std::cin >> size;
        aElements.push_back(size);
      }
      else
      {
        addElement = false;
      }
    }
    
    for (int element : aElements)
    {
      execTest(element, fileContent);
    }

    writeInFile(fileContent);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
