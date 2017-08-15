#include <iostream>

using namespace std;


struct Node
{
  int val;
  Node* next;
};

Node *head = NULL, *tail = NULL;

void Insert(int val);
void Delete();
void Print(Node *head);

bool IsPalindromeLinkedList(Node *head);
void Reverse(Node* &head);

int main()
{
  Insert(1);
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(3);
  Insert(2);
  Insert(1);

  Print(head);
  cout << "is a palindrame ? "<< (IsPalindromeLinkedList(head)?"true\n":"false\n");
  Print(head);

   
  return 0;
}


Node* FindMid(Node *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  
  Node *slow = head, *fast = head;
  
  while(fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  
  return slow;
}


void Reverse(Node* &h)
{
  Node *p = h, *q = NULL, *r = NULL;
  
  while(p)
  {
    q = p->next;
    p->next = r;
    r = p;
    p = q;
  }
  
  h = r;
}


bool IsPalindromeLinkedList(Node *head)
{
  bool ret = true;
  
  Node *mid = FindMid(head);

  Reverse(mid->next);

  Node *p = head, *q = mid->next;
  while(q)
  {
    if(p->val != q->val)
    {
      ret = false;
      break;
    }
    
    p = p->next;
    q = q->next;
  }
  
  Reverse(mid->next);
  return ret;
}


void Print(Node *h)
{
  cout << "[ ";
  Node *p = h;
  while (p != NULL)
  {
    cout << p->val << " ";
    p = p->next;
  }
  cout << "]\n";
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

void Delete()
{
  if(head == NULL)
  {
    cout << "Empty List\n"; 
  }
  else
  {
    Node *p = head;
    head = head->next;
    delete(p);    
  }
}


