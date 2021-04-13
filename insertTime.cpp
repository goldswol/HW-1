#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void printArray(int*, int);
void insertSort(int*, int);
void runTimeN(int);

int main()
{
  int arrsize;

  runTimeN(10000);
  runTimeN(20000);
  runTimeN(30000);
  runTimeN(40000);
  runTimeN(50000);

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

void runTimeN(int n)
{
  clock_t clock;
  srand(time(NULL));
  int arr[500000];
  clock = clock();
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand()%1000;
  }
  clock = clock() - clock;
  insertSort(arr, n);
  std::cout << "Time taken for " << n << " variables: " << (float)clocks/CLOCKS_PER_SEC;
}
