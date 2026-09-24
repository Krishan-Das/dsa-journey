#include <iostream>
#include <vector>
using namespace std;

void merge(int* arr, int st, int mid, int end){
  vector<int> temp;
  int left = st;
  int right = mid+1;

  // Combine array in a sorted manner.
  while(left <= mid && right <= end){
    if(arr[left] < arr[right]){
      temp.push_back(arr[left]);
      left++;
    }else{
      temp.push_back(arr[right]);
      right++;
    }
  }

  // For remaining elements of left array
  while(left <= mid){
    temp.push_back(arr[left]);
    left++;
  }
  
  // For remaining elements of right array
  while(right <= end){
    temp.push_back(arr[right]);
    right++;
  }

  // make changes on original is_array
  for(int i = st; i <= end; i++){
    arr[i] = temp[i - st];
  }
}

void mergeSort(int* arr, int st, int end){
  if(st >= end) return;
  int mid = st + (end-st)/2;

  // devide left portion
  mergeSort(arr, st, mid);

  // devide right portion
  mergeSort(arr, mid+1, end);

  merge(arr, st, mid, end);
}

int main() {

  int arr[] = {2,6,1,3,7,4,9,8};
  int n = sizeof(arr)/sizeof(int);

  mergeSort(arr, 0, n-1);

  for(int n: arr){
    cout << n << "  ";
  }

  return 0;
}