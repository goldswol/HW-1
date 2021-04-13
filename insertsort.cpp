#include <iostream>
#include <fstream>
#include <cstdlib>

void printArray(int*, int);
void insertSort(int*, int);

int main()
{
  int arrsize;
  int* arr;
  std::ifstream infile;
  infile.open("data.txt");
  std::cout << "File opened";
  if (infile.fail()) //Handling file not opening as expected
  {
      std::cerr << "failed to open file" << std::endl;
      exit(0);
  }

  infile >> arrsize;
  arr = new int[arrsize];

  for (int i = 0; i < arrsize; i++) //SHOULD feed the txt file into an array of integers
  {
    infile >> arr[i];
  }

  insertSort(arr, arrsize);
  printArray(arr, arrsize);

  delete[] arr;
  return 0;
}

void printArray(int arr[], int arrsize)
{
    for (int i = 0; i < arrsize; i++)
        std::cout << arr[i] << " ";
}

void insertSort(int arr[], int arrsize)
{
  int i, current, j;
    for (i = 1; i < arrsize; i++)
    {
        current = arr[i];
        j = i - 1;
        /* Move elements of arr, that are
        greater than current, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}
