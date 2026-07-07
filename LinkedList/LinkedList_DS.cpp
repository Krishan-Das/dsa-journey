#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }

  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

Node* arrayToLL(int* arr, int n){
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for(int i = 1; i<n; i++){
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = mover->next;
  }

  return head;
}



int main() {

  int arr[] = {10,20,30,40,50};
  int n = sizeof(arr)/ sizeof(int);


  Node* res = arrayToLL(arr, n);
  cout << res->data;

  return 0;
}