#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter no of rows: ";
  cin >> row;

  for(int i = row; i>=1; i--){
    // --- print space ---
    for(int j = row - i; j>=1; j--){
      cout << "  ";
    }

    // --- print * ---
    for(int k = 2*i - 1; k>=1; k--){
      cout << "* ";
    }
    cout << endl;
  }

  return 0;
}