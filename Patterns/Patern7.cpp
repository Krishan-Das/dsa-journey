#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter no of rows: ";
  cin >> row;

  for(int i = 1; i<=row; i++){
    // --- Print space ---
    for(int j = row - i; j>0; j--){
      cout << "  ";
    }
    
    // --- Print star ---
    for(int k = 1; k<= 2*i-1; k++){
      cout << "* ";
    }
    cout << endl;
  }

  return 0;
}