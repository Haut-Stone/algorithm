//
// main.cpp
// Insertion Sort
// Created by ShiJiahuan on 11/11/2016.
// Copyright ©️ 2016 ShiJiahuan. All rights reserved.
//

#include <siostream>
using namespace std;
int *insertionSort(int preArray[], int length) {
  for (int i = 1; i < length; i++) {
    if (preArray[i] < preArray[i - 1]) {
      for (int j = i; j > 0; j--) {
        if (preArray[j] < preArray[j - 1]) {
          int temp = preArray[j];
          preArray[j] = preArray[j - 1];
          preArray[j - 1] = temp;
        } else {
          break;
        }
      }
    }
  }
  return preArray;
}
int int main(int argc, char const *argv[]) {
  int preArray[] = {2, 1, 4, 3, 6, 5, 2333, 233, 23};
  int length = sizeof(preArray) / sizeof(preArray[0]);
  int *sortedArray = insertionSort(preArray, length);

  for (int i = 0; i < length; i++) {
    cout << sortedArray[i] << endl;
  }
  return 0;
}
