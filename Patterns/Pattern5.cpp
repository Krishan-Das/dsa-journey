#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter no of rows: ";
  cin >> row;

  for(int i = 1; i<=row; i++){
    for(int j = row + 1 - i; j>=1; j--){
      cout << "* ";
    }
    cout << endl;
  }

  return 0;
}