#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

void printArray(int*, int);
void mergeSort(int* ,int, int);
void runTimeN(int);

int main() {
  runTimeN(200000);
  runTimeN(400000);
  runTimeN(600000);
  runTimeN(800000);
  runTimeN(1000000);
  runTimeN(1200000);
  runTimeN(1400000);
  runTimeN(1600000);
  return 0;
}

// Merge two subarrays L and M into arr
void mergeArray(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    mergeArray(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void runTimeN(int n)
{
  clock_t start, stop;
  double time_elapsed;
  int arr[1600000];
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand()%1000;
  }
  start = clock();
  mergeSort(arr, 0, n);
  stop = clock();
  time_elapsed = ((float)stop-start)/CLOCKS_PER_SEC;
  std::cout << "Time taken for " << n << " variables: " << time_elapsed <<std::endl;
}
