#include <iostream>
using namespace std;

void bubbleSort(int * arr, int n){
  for(int i = 0; i<n-1; i++){
    bool swapped = false;

    for(int j = 1; j<n - i; j++){
      if(arr[j-1] > arr[j]){
        swap(arr[j-1], arr[j]);
        swapped = true;
      }
    }

    if(!swapped) break;
  }
}

int main() {

  int arr[] = {5,9,4,3,6,7,1};
  int n = sizeof(arr)/ sizeof(int);

  bubbleSort(arr, n);

  for(int n: arr){
    cout << n << "  ";
  }

  return 0;
}