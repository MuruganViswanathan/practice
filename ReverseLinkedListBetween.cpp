
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
  ReverseBetween(head, 1,3);
  Print();
  
  return 0;
}

void ReverseBetween(Node* &head, int m, int n)
{
  if(m < 1 || n < 1 || m >= n || head == NULL)
    return; // error
  
  Node *p = NULL; //node before m
  int i = 1;
  
  //find node before m
  if(m > 1)
  {
    p = head;
        
    while(p && i < m-1)
    {
      p = p->next;
      i++;
    }
    
    if(p == NULL)
      return; //m index out of bound
  }
  
  // reverse the node from m to n
  // fix boundries later
  
  Node *c = p?p->next:head;
  Node *nx = NULL, *r = NULL;
  
  i = m;
  while(c && i <= n)
  {
    nx = c->next;
    c->next = r;
    r = c;
    c = nx;
    i++;
  }
  
  if(c == NULL && i <= n)
    cout << "Total number of nodes is "<<i-1<<". Reversing from "<<m<<" to "<<i-1<<"\n";
  
  //fix boundries
  if(p)
  {
    p->next->next = c;
    p->next = r;
  }
  else
  {
    head->next = c;
    head = r;
  }
   
  return;
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
                 
