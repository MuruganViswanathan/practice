// reverse linked list between node m to n

#include <iostream>

using namespace std;

struct Node 
{
  int val;
  Node* next;
  Node(int v): val(v), next(NULL) {}
};

Node *head = NULL, *tail = NULL;
void Insert(int val);
void Print();

void ReverseBetween(Node* &head, int m, int n);

int main()
{
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(5);
  Insert(6);
  Insert(7);
  
  Print();
  ReverseBetween(head, 2,7);
  Print();
  
  return 0;
}

void ReverseBetween(Node* &head, int m, int n)
{
  if(m < 1 || n < 1 || m >= n || head == NULL)
    return; // error
  
  Node *p, *q, *x, *y;
  int i = 0;
  
  if(m == 1)
  {
    p = NULL;
    x = head;
  }
  else
  {
    p = head;
    i = m - 2;
    while(p && i--)
      p = p->next;
    
    if(p == NULL)
      return; // m index incorrect
    
    x = p->next;
    if(x == NULL)
      return; //m incorrect
  }
  
  y = x;
  i = n - m;
  while (y && i--)
    y = y->next;

  if(y == NULL)
    return; //incorrect n

  q = y->next;
    
  // now we got the boundries, lets reverse from x to y
  
  Node *c = x, *nx = NULL, *r = q;
  while(c && c != q)
  {
    nx = c->next;
    c->next = r;
    r = c;
    c = nx;
  }
 
  if(p)
    p->next = r;
  else
    head = r;
  
}

void Insert(int val)
{
  Node* p = new Node(val);
  if(!p)
    return; // error
  
  if (head == NULL)
    head = tail = p;
  else
  {
    tail->next = p;
    tail = p;
  }  
}

void Print()
{
  Node* p = head;
  cout << "[ ";
  while (p)
  {
    cout << p->val << " ";
    p = p->next;    
  }
  cout << "]\n";
}
    
