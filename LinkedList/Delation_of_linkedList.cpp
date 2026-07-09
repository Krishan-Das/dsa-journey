#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  // Constructor
  Node(int data){
    this->data = data;
    this->next = nullptr;
  }

  // Constructor
  Node(int data, Node* next){
    this->data = data;
    this->next = next;
  }
};

// Create Linked list
Node* createLL(int* arr, int n){
  if(n == 0) return nullptr;
  Node* head = new Node(arr[0]);
  Node* mover = head;
  for(int i = 1; i<n; i++){
    Node* newNode = new Node(arr[i]);
    mover->next = newNode;
    mover = newNode;
  }

  return head;
}

// Print LL
void print(Node* head){
  while(head){
    cout << head->data <<" ";
    head = head->next;
  }
}


// --- Deletion ---
// 1. Head
// 2. Kth elem
// 3. Value
// 4. Tail


// 1. Delete head of the LL
Node* deleteHead(Node* head){
  if(head == nullptr) return head;
  if(head->next == nullptr){
    delete head;
    return nullptr;
  }

  Node* currHead = head;
  head = head->next;
  delete currHead;
  return head;
}


// 2. Delete k'th element from the Linked List
Node* deleteK(Node* head, int k){
  if(head == nullptr) return head;
  if(k == 1){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  Node* temp = head;
  Node* prev = nullptr;
  int count = 0;

  while (temp)
  {
    count++;
    if(count == k){
      prev->next = prev->next->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}


// 3. Delete node (node.value == value) from the linked list
Node* deleteVal(Node* head, int val){
  if(head == nullptr) return head;
  if(head->data == val){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }

  Node* prev = nullptr;
  Node* temp = head;
  while (temp)
  {
    if(temp->data == val){
      prev->next = temp->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;  
}


// 4. Delete Tail of the linked list
Node* deleteTail(Node* head){
  if(head == nullptr) return head;
  if(head->next == nullptr){
    delete head;
    return nullptr;
  }
  Node* temp = head;
  while (temp->next)
  {
    if(temp->next->next == nullptr){
      delete temp->next;
      temp->next = nullptr;
      return head;
    }
    temp = temp->next;
  }
  
}


// Main class
int main() {

  int arr[] = {2,4,6,8,10};
  int n = sizeof(arr)/sizeof(arr[0]);

  Node* head = createLL(arr, n);
  head = deleteTail(head);
  print(head);
  

  return 0;
}