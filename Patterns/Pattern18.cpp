#include <iostream>
using namespace std;

int main() {

  int row;
  cout << "Enter the no of rows: ";
  cin >> row;

  for(int i = row; i>=1; i--){
    for(int j = i; j<=row; j++){
      cout << char('A' + j - 1)<< " ";
    }    
    cout << endl;
  }


  return 0;
}