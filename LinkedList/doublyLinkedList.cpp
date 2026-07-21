#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* back;

  Node(int data, Node* next, Node* back){
    this->data = data;
    this->next = next;
    this->back = back;
  }

  Node(int data){
    this->data = data;
    next = nullptr;
    back = nullptr;
  }
};

// --- create LinkedList ---
Node* createLL(int* arr, int n){
  Node* head = new Node(arr[0]);
  Node* prev = head;

  for(int i = 1; i<n; i++){
    Node* newNode = new Node(arr[i], nullptr, prev);
    prev->next = newNode;
    prev = newNode;
  }

  return head;
}

// === Print LL ===
void printLF(Node* head){
  while(head != nullptr){
    cout << head->data << "  ";
    head = head->next;
  }
}


int main() {

  int arr[] = {1,2,3,4,5};
  int n = sizeof(arr)/sizeof(arr[0]);

  Node* head = createLL(arr, n);
  printLF(head);
  

  return 0;
}