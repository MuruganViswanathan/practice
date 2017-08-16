//Print a singly-linked list backwards, in constant space and  linear time

#include <iostream>

using namespace std;

struct Node
{
  int val;
  Node* next;
};

Node *head = NULL, *tail = NULL;

void Insert(int val);

void PrintReverse(Node *head);

int main()
{
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(5);
  
  PrintReverse(head);
  
  return 0;
}


void Insert(int val)
{
  Node *p = new Node();
  p->val = val;
  p->next = NULL;
  
  if (head == NULL)
    head = tail = p;
  else
  {
    tail->next = p;
    tail = p;
  }  
}

void Reverse(Node* &head)
{
  if(head == NULL || head->next == NULL)
    return;
  
  Node *p = head, *q = NULL, *r = NULL;
  
  while(p)
  {
    q = p->next;
    p->next = r;
    r = p;
    p = q;
  }
  
  head = r;  
}

void PrintReverse(Node *head)
{
  Reverse(head);
  
  Node *p = head;
  cout << "[ ";
  while(p)
  {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "]\n";
  
  Reverse(head);
}

