/*
=========
  Note:
=========

[0 0 0 0 1 1 1 1   0 2 0 1 1   2 2 2 2]
        low       mid         high    

  Rules:
  1. 0 to low - 1 --> 0 (Extreme left)
  2. low to mid - 1 --> 1
  3. mid to high - 1 --> Unsorted portion
  4. high to n-1 --> 2 (Extreme right)


  [1 0 2 1 0 2 1 0]
  Approach:
  1. low = 0, mid = 0, high = n-1.
    considering the whole array is unsorted so range (mid-high).
  2. if we found 0. arr[mid] is current elem --> swap(arr[i], arr[mid]).
      after swapping... low ++, mid++;
  3. if arr[mid] == 1 then just mid++.
  4. if curr == 2 then swap with the extreme right.


  =============================
  Dutch national flag algorithm
  =============================
*/ 

#include <iostream>
using namespace std;

// answer
void sort012(int* arr, int n){
  int low = 0, mid = 0, high = n-1;
  while(mid<=high){
    if(arr[mid] == 0){
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }else if(arr[mid] == 1){
      mid++;
    }else{
      swap(arr[mid], arr[high]);
      high--;
    }
  }
}

// print array
void print(int* arr, int n){
  for(int i = 0; i<n; i++){
    cout << arr[i] << "  ";
  }
}

int main() {

  int arr[] = {0,1,2,1,0,1,2,0,2,0,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);

  sort012(arr, n); // Dutch national flag algorithm.
  print(arr,n);
  return 0;
}