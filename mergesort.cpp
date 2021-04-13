#include <iostream>
#include <fstream>
#include <cstdlib>

void printArray(int*, int);
void mergeSort(int* ,int, int);

int main() {
  int arrsize;
  int* arr;
  std::ifstream infile;
  infile.open("data.txt");
  //Handling file not opening as expected
  if (infile.fail()) {
      std::cerr << "failed to open file" << std::endl;
      exit(0);
  }

  infile >> arrsize;
  arr = new int[arrsize];

  //SHOULD feed the txt file into an array of integers
  for (int i = 0; i < arrsize; i++) {
    infile >> arr[i];
  }

  std::cout << "Given array is: \n";
  printArray(arr, arrsize);

  mergeSort(arr, 0, arrsize-1);

  std::cout << "\n\nSorted array is:\n";
  printArray(arr, arrsize);

  //Here comes the part where the sort actually happens


  delete[] arr;
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
