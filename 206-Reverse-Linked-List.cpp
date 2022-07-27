#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode* node){
  ListNode* temp = node;
  while(temp != nullptr){
    cout<<temp->val<<endl;
    temp = temp->next;
  }
}

void Destructor(ListNode* node){
  ListNode* current = node;
  while(current != nullptr){
    ListNode* next = current->next;
    delete current;
    current = next;
  }
}

class Solution {
public:
   void insertNodeEnd(ListNode** head, int value){
    ListNode* newNode = new ListNode(value);
    if(*head == nullptr){
      *head = newNode;
      return;
    }

    ListNode* idx = *head;
    while(idx->next != nullptr){
      idx=idx->next;
    }
    idx->next = newNode;
    return;
  }

    ListNode* reverseList(ListNode* head) {
      ListNode* next = nullptr;
      ListNode* prev = nullptr;
      ListNode* current = head;

      while(current != nullptr){
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;
      }
      return prev;
    }
};
int main(){
  Solution a;
  ListNode* l1 =nullptr;
  a.insertNodeEnd(&l1, 1);
  a.insertNodeEnd(&l1, 2);
  a.insertNodeEnd(&l1, 3);
  a.insertNodeEnd(&l1, 4);
  a.insertNodeEnd(&l1, 5);

  PrintList(l1);
  ListNode* res = a.reverseList(l1);
  PrintList(res);
  Destructor(res);
  return 0;
}
