#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter the no of rows: ";
  cin >> row;

  for(int i = 1; i<= row; i++){
    for(int j = row - i + 1; j>=1; j--){
      cout << "  ";
    }

    for(int j = 1; j<=i; j++){
      cout << char('A' + j-1) << " ";
    }
    
    for(int j = i-1; j>=1; j--){
      cout << char('A' + j-1) << " ";
    }
    
    cout << endl;
  }


  return 0;
}