#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  // constructor
  ListNode(int val)
  {
    this->val = val;
    next = nullptr;
  }
};

// create LL
ListNode *createLL(int *arr, int n)
{
  if (n < 1)
    return nullptr;
  ListNode *head = new ListNode(arr[0]);
  ListNode *temp = head;

  for (int i = 1; i < n; i++)
  {
    temp->next = new ListNode(arr[i]);
    temp = temp->next;
  }
  return head;
}

// print LL
void print(ListNode *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
}

// insert at the head pos
ListNode *insertHead(ListNode *head, int val)
{
  if (head == nullptr)
  {
    return new ListNode(val);
  }
  ListNode *temp = new ListNode(val);
  temp->next = head;
  return temp;
}

// insert at the tail pos
ListNode *insertTail(ListNode *head, int val)
{
  if (head == nullptr)
  {
    return new ListNode(val);
  }

  ListNode *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = new ListNode(val);
  return head;
}

// Insert k'th poss
ListNode* insertKth(ListNode* head, int k, int val) {

    if (k < 1)
        return head;

    // Insert at head
    if (k == 1) {
        return insertHead(head, val);
    }

    ListNode* temp = head;
    int count = 1;

    // Move to (k-1)th node
    while (temp && count < k - 1) {
        temp = temp->next;
        count++;
    }

    // Invalid position
    if (temp == nullptr)
        return head;

    ListNode* node = new ListNode(val);
    node->next = temp->next;
    temp->next = node;

    return head;
}

int main()
{

  int arr[] = {2, 3, 9, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  ListNode *head = createLL(arr, n);
  head = insertKth(head, 1, 10);
  print(head);

  return 0;
}