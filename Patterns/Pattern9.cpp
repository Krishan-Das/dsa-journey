#include <iostream>
using namespace std;

int main() {

  int n;
  cout << "Enter no of rows(EVEN): ";
  cin >> n;

  if(n%2 != 0){
    cout << "Enter even no.";
    return 0;
  }
  
  int rows = n / 2;



  for(int i = 1; i<=rows; i++){
    for(int j = rows - i; j>=0; j--){
      cout << "  ";
    }
    for(int j = 1; j<= 2*i - 1; j++){
      cout << "* ";
    }
    cout << endl;
  }

  for(int i = rows; i>=1; i--){
    for(int j = 0; j<= rows - i; j++){
      cout << "  ";
    }

    for(int j = 2*i-1; j>=1; j--){
      cout << "* ";
    }
    cout << endl;
  }


  return 0;
}