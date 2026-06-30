#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter the no of rows: ";
  cin >> row;

  for(int i = 1; i <= row; i++){

    for(int j = 1; j <= i; j++){
      cout << j << " ";
    }

    for(int j = 2*row-2*i; j>= 1; j--){
      cout << "  ";
    }

    for(int j = i; j>=1; j--){
      cout << j << " ";
    }

    cout << endl; // cout after printing last elem of each row.
  }

  return 0;
}