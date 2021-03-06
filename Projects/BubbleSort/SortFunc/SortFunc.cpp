// SortFunc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include "aaSTD.h"
#include <algorithm>

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

int
get_key_primer_number(const int & _value, const int & _prime_number)
{
  return static_cast<int>(_value % _prime_number);
}

void
get_hash_table(std::vector<int> & _int_vector)
{
  for (int index = 0; index < _int_vector.size(); ++index)
  {
    int key = get_key_primer_number(_int_vector[index], _int_vector.size());

  }
  return;
}

void
get_random_int_vector(std::vector<int> & _random, const int & _size)
{
  for (int index = 0; index < _size; ++index)
  {
    _random.push_back(getRandomInt(0, 999));
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
mergeSortA(std::vector<int> & _vector, int & _low, int & _midle, int & _high)
{
  
  int left_size = _midle - _low + 1;
  
  int i, j, k;

  int right_size = _high - _midle;

  std::vector<int> v_left;
  std::vector<int> v_right;

  for (int index = 0; index < left_size; ++index)
  {
    v_left.push_back(_vector[_low + index]);
  }

  for (int index = 0; index < right_size; ++index)
  {
    v_right.push_back(_vector[_midle + index + 1]);
  } 
  
  i = 0;
  j = 0;

  for (k = _low; i < left_size && j < right_size; ++k)
  {
    if (v_left[i] < v_right[j])
    {
      _vector[k] = v_left[i++];
    }
    else
    {
      _vector[k] = v_right[j++];
    }
  }

  while (i < left_size)
  {
    _vector[k++] = v_left[i++];
  }

  while (j < right_size)
  {
    _vector[k++] = v_right[j++];
  }

  return;
}

void
mergeSort(std::vector<int> & _vector, int & _low, int & _high)
{
  int middle;

  if (_low < _high)
  {
    middle = (_low + _high) / 2;

    mergeSort(_vector, _low, middle);

    int middle_plus = middle + 1;
    mergeSort(_vector, middle_plus, _high);

    mergeSortA(_vector, _low, middle, _high);
  }

  return;
}

void
mergeSortA_Float(std::vector<float> & _vector, int & _low, int & _midle, int & _high)
{

  int left_size = _midle - _low + 1;

  int i, j, k;

  int right_size = _high - _midle;

  std::vector<float> v_left;
  std::vector<float> v_right;

  for (int index = 0; index < left_size; ++index)
  {
    v_left.push_back(_vector[_low + index]);
  }

  for (int index = 0; index < right_size; ++index)
  {
    v_right.push_back(_vector[_midle + index + 1]);
  }

  i = 0;
  j = 0;

  for (k = _low; i < left_size && j < right_size; ++k)
  {
    if (v_left[i] < v_right[j])
    {
      _vector[k] = v_left[i++];
    }
    else
    {
      _vector[k] = v_right[j++];
    }
  }

  while (i < left_size)
  {
    _vector[k++] = v_left[i++];
  }

  while (j < right_size)
  {
    _vector[k++] = v_right[j++];
  }

  return;
}

void
mergeSort_Float(std::vector<float> & _vector, int & _low, int & _high)
{
  int middle;

  if (_low < _high)
  {
    middle = (_low + _high) / 2;

    mergeSort_Float(_vector, _low, middle);

    int middle_plus = middle + 1;
    mergeSort_Float(_vector, middle_plus, _high);

    mergeSortA_Float(_vector, _low, middle, _high);
  }

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

class HashTable
{
public:
  HashTable(const int & _prime_key)
  {
    this->m_prime_key = _prime_key;
    m_table.resize(_prime_key);

    return;
  }

  ~HashTable()
  { }

  void
  addElement(const int & _element)
  {
    int index = get_key_primer_number(_element, m_prime_key);
    this->m_table[index].push_back(_element);
  }

  int
  searchElement(const int & _element)
  {
    int index = get_key_primer_number(_element, m_prime_key);
    return index;
  }

  void
  logInfo()
  {
    std::cout << "--- Hash Table --- \n\n";
    
    for (int index = 0; index < this->m_table.size(); ++index)
    {
      std::cout << " Position [" << std::to_string(index) << "] : [";
      
      for (int indexB = 0; indexB < this->m_table[index].size(); ++indexB)
      {
        std::cout << std::to_string(this->m_table[index][indexB]) << " ";
      }

      std::cout << "] \n\n ----------------";
    }

    return;
  }

private:

  int m_prime_key;

  std::vector<std::vector<int>> m_table;
};

void
countingSort(std::vector<int> & _vector)
{
  int size = _vector.size();

  std::vector<int> indexed_list;
  indexed_list.resize(size, 0);

  for (int index = 0; index < size; ++index)
  {
    indexed_list[index]++;
  }

  std::vector<int>::iterator it;
  int indexed_size = indexed_list.size();
  for (int index = 1; index < indexed_size; ++index)
  {
    indexed_list[index] += indexed_list[index - 1];
  }

  std::vector<int> original_vector(_vector);
  for (int index = 0; index < size; ++index)
  {
    int i = original_vector[index] - 1;
    int position = indexed_list[i];
    indexed_list[i]--;

    _vector[position - 1] = original_vector[index];
  }

  return;
}

int 
getMax(std::vector<int> & _vector)
{
  int size = _vector.size();

  int max_num = _vector[0];
  for (int index = 1; index < size; index++)
  {
    if (_vector[index] > max_num)
    {
      max_num = _vector[index];
    }
  }

  return max_num;
}

void
countingSortByDigit(std::vector<int> & _vector, int & _exp)
{
  std::vector<int> origin(_vector);
  
  int size = _vector.size();
  int count[10] = { 0 };

  for (int index = 0; index < size; ++index)
  {
    count[(origin[index] / _exp) % 10]++;
  }

  for (int index = 1; index < 10; ++index)
  {
    count[index] += count[index - 1];
  }

  for (int index = size - 1; index >= 0; --index)
  {
    int j = (origin[index] / _exp) % 10;

    _vector[count[j] - 1] = origin[index];
    count[j]--;
  }

  return;
}

void
radixSort(std::vector<int> & _vector)
{

  int max_num = getMax(_vector);

  for (int exp = 1; (max_num / exp) > 0; exp *= 10)
  {
    countingSortByDigit(_vector, exp);
  }

  return;
}

void
sortFloat(std::vector<float> & _vector)
{

}

void
bucketSort(std::vector<float> & _vector)
{
  int size = _vector.size();

  std::vector<std::vector<float>> buckets;
  buckets.resize(size);   

  for (int index = 0; index < size; ++index)
  {
    int bucket_idx = size * _vector[index];
    buckets[bucket_idx].push_back(_vector[index]);
  }

  for (int index = 0; index < size; ++index)
  {
    std::sort(buckets[index].begin(), buckets[index].end(), std::less<float>());
  }

  int arr_index = 0;
  for (int bucket_idx = 0; bucket_idx < size; ++bucket_idx)
  {
    for (int j = 0; j < buckets[bucket_idx].size(); ++j)
    {
      _vector[arr_index++] = buckets[bucket_idx][j];
    }
  }

  return;
}

/**
 * Genera un arreglo de número aleatorios con decimales.
 */
void
arrglo_random(vector<float> & _vector, const int & _size)
{
  for (int index = 0; index < _size; ++index)
  {
    float decimal = static_cast<float>(rand()) / RAND_MAX;
    float number = (rand() % 1000 + 1) + decimal;

    _vector.push_back(number);
  }

  return;
}

/**
 * representación de la unión de ambas partes del merge
 */
void
merge_sort_merge
(
  vector<float> &   _vector,
  int &             _low,
  int &             _middle,
  int &             _high
)
{
  int left_size = _middle - _low + 1;

  int i, j, k;

  int right_size = _high - _middle;

  std::vector<float> v_left;
  std::vector<float> v_right;

  /**
   * Guarda los valores de lado izquierdo.
   */
  for (int index = 0; index < left_size; ++index)
  {
    v_left.push_back(_vector[_low + index]);
  }

  /**
   * Guarda los valores del lado derecho.
   */
  for (int index = 0; index < right_size; ++index)
  {
    v_right.push_back(_vector[_middle + index + 1]);
  }

  i = 0;
  j = 0;

  /**
   * Recorrido en ambas secciones / swaping / Merge
   */
  for (k = _low; i < left_size && j < right_size; ++k)
  {
    if (v_left[i] < v_right[j])
    {
      _vector[k] = v_left[i++];
    }
    else
    {
      _vector[k] = v_right[j++];
    }
  }

  while (i < left_size)
  {
    _vector[k++] = v_left[i++];
  }

  while (j < right_size)
  {
    _vector[k++] = v_right[j++];
  }

  return;
}

/**
 * Función general del merge sort.
 */
void
merge_sort(vector<float> & _vector, int & _low, int & _high)
{
  int middle;

  if (_low < _high)
  {
    middle = (_low + _high) / 2;

    /**
     * Difurcación por la izquierda.
     */
    merge_sort(_vector, _low, middle);

    /**
     * Difurcación por la derecha.
     */
    int middle_plus = middle + 1;
    merge_sort(_vector, middle_plus, _high);

    /**
     * Unión.
     */
    merge_sort_merge(_vector, _low, middle, _high);
  }

  return;
}

/*
int main()
{
  ////////////////////////////////////
  // Array 

  vector<float>   numbers_list;
  int             list_size = 100;
  int             minimum = 0;

  ////////////////////////////////////
  // Obtener un arreglo random de N elementos

  arrglo_random(numbers_list, list_size);

  cout << "\n Arreglo Desordeando: \n";
  for (int index = 0; index < list_size; index++)
  {
    cout << numbers_list[index] << " ";
  }

  ////////////////////////////////////
  // Ordenar Arreglo

  list_size--;
  merge_sort(numbers_list, minimum, list_size);

  ////////////////////////////////////
  // Imprimir Arreglo ordenado

  cout << "\n Arreglo Ordenado: \n";
  for (int index = 0; index < list_size; index++)
  {
    cout << numbers_list[index] << " ";
  }

  return 0;
}
*/

void
runAscSort
(
  std::string &       _name, 
  std::vector<float> &  _vector, 
  std::string &       _fileContent
)
{
  time_point<steady_clock>  startTime;
  time_point<steady_clock>  endTime;

  ////////////////////////////////////
  // Vars

  long double microsecs;
  std::vector<float> vectorCopy(_vector);

  ////////////////////////////////////
  // Bubble Sorting

  startTime = steady_clock::now();
  
  int minimum = 0;
  int list_size = _vector.size() - 1;
  merge_sort(_vector, minimum, list_size);
  
  endTime = steady_clock::now();
 
  // Calculate time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();

  _fileContent += ( std::to_string(_vector.size())+ "," + std::to_string(microsecs));

  ////////////////////////////////////
  // Quick Sorting
  /*
  vectorCopy = _vector;

  startTime = steady_clock::now();

  radixSort(vectorCopy);

  endTime = steady_clock::now();

  // Calculate time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();

  _fileContent += (std::to_string(microsecs) + ",");

  
  ////////////////////////////////////
 // Insert Sorting

  std::vector<float> v_float;
  for (int value : _vector)
  {
    v_float.push_back(value * 0.001);
  }

  startTime = steady_clock::now();

  bucketSort(v_float);

  endTime = steady_clock::now();

  // Calculate time
  microsecs = duration_cast<microseconds>(endTime - startTime).count();
  
  _fileContent += (std::to_string(microsecs));  
  */
  return;
}

void
execTest(const int & _size, std::string & _fileContent)
{
  std::vector<int> ascVec;
  std::vector<int> descVec;
  std::vector<int> randVec;
  /*
  getAscVector(ascVec, _size);

  std::string name1 = "Best";
  //printVector(name1, ascVec);

  getDescVector(descVec, _size);
  std::string name2 = "Worst";
 // printVector(name2, descVec);

  getRandomVector(randVec, _size);

  std::string name3 = "Medium";
  //printVector(name3, randVec);
  */

  ////////////////////////////////////
  // Array 

  vector<float>   numbers_list;
  int             list_size = 100;
  int             minimum = 0;

  ////////////////////////////////////
  // Obtener un arreglo random de N elementos

  arrglo_random(numbers_list, list_size);

  ////////////////////////////////////
  // Sort
  /*
  runAscSort(name1, ascVec, _fileContent);
  _fileContent += ",";

  runAscSort(name2, descVec, _fileContent);
  _fileContent += ",";
  */

  std::string vec = "vector";
  runAscSort(vec, numbers_list, _fileContent);

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

    fileContent = "Elements(Best), Merge Sorting (Microseconds), QuickSorting (Microseconds), InsertSorting (Microseconds),"
                  "Elements(Worst), Merge Sorting (Microseconds), QuickSorting (Microseconds), InsertSorting (Microseconds),"
                  "Elements(Random), Merge Sorting (Microseconds), QuickSorting (Microseconds), InsertSorting (Microseconds)\n";

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
    
    /*
  std::vector<int> rnd_numbers;
  get_random_int_vector(rnd_numbers, 100);

  HashTable h_table(rnd_numbers.size());

  for (int index = 0; index < rnd_numbers.size(); ++index)
  {
    h_table.addElement(rnd_numbers[index]);
  }

  h_table.logInfo();
  */
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
