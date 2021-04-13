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

void printArray(int arr[], int arrsize) {
    for (int i = 0; i < arrsize; i++)
        std::cout << arr[i] << " ";
}

//handles arrays from [pos1...pos2] and [pos2+1...pos3]
void mergeArrays(int arr[], int pos1, int pos2, int pos3) {
  //define arrays by halving initial array
  int n1 = pos2 - pos1 + 1;
  int n2 = pos3 - pos2;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (int i = 0; i < n1; i++)
      L[i] = arr[pos1 + i];

  for (int j = 0; j < n2; j++)
      R[j] = arr[pos2 + 1 + j];

      std::cout << "L[n1] where n1=" << n1 << ":\n";
      printArray(L, n1);
      std::cout << "R[n2] where n2=" << n2 << ":\n";
      printArray(R, n2);
  // Merge the temp arrays back into arr[l..r]

  // Initial index of first, second, and merged subarrays
  int i = 0;
  int j = 0;
  int k = pos2;
  std::cout<< "\n\nmerging array from " << pos1<< " to " << pos3 << "\n";
  printArray(arr, pos3);
  while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
          arr[k] = L[i];
          i++;
      }
      else {
          arr[k] = R[j];
          j++;
      }
      k++;
    }
  std::cout << "\n\narrays merged, output is:\n";
  printArray(arr, pos3);
}

void mergeSort(int arr[],int pos1,int pos3){
    if(pos1>=pos3){
        return;//returns recursively
    }
    int pos2 = pos1 + ((pos3 - pos1) / 2);
    mergeSort(arr, pos1, pos2);
    mergeSort(arr, pos2 + 1, pos3);
    mergeArrays(arr, pos1, pos2, pos3);
}
