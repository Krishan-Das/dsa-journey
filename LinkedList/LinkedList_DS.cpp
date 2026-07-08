#include <iostream>
using namespace std;

// --- Linked List ---
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

// --- create linked list ---
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

// --- traverse in Linked List ---
void print(Node* head){
  Node* mover = head;
  while(mover){
    cout << mover->data <<" ";
    mover = mover->next;
  }
}

// --- Deletion ---
// delete head elem of the linked list
Node* deleteHead(Node* head){
  if(head == NULL) return head;

  Node* temp = head;
  head = head->next;

  delete temp;
  return head;
}

// Delete tail of the linked list
Node* deleteTail(Node* head){
  if(head == nullptr) return nullptr;

  if(head->next == nullptr){
    delete head;
    return nullptr;
  }

  Node* temp = head;
  while(temp->next->next){
    temp = temp->next;
  }

  delete temp->next;
  temp->next = nullptr;

  return head;
}



int main() {

  int arr[] = {10,20,30,40,50};
  int n = sizeof(arr)/ sizeof(int);

  Node* head = arrayToLL(arr, n);
  Node* nHead = deleteTail(head);
  print(nHead);
  

  return 0;
}