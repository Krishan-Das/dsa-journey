#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter rows(Odd): ";
  cin >> row;

  if(row % 2 == 0){
    cout << "Enter odd no. of rows.";
    return 0;
  }
  
  // --- upper section ---
  for(int i = 1; i<= row/2 + 1; i++){
    for(int j = 1; j<=i; j++){
      cout << "* ";
    }cout << endl;
  }

  // --- lower section ---
  for(int i = row/2; i>=1; i--){
    for(int j = 1; j<=i; j++){
      cout << "* ";
    }cout << endl;
  }

  return 0;
}