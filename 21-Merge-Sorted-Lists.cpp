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

   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* head=nullptr;
      ListNode* i1 = list1;
      ListNode* i2 = list2;
      while(!(i1 == nullptr && i2 == nullptr)){
        if (i1==nullptr){
          insertNodeEnd(&head, i2->val);
          i2 = i2->next;
        }else if(i2==nullptr){
          insertNodeEnd(&head, i1->val);
          i1 = i1->next;
        }
        else if(i1->val > i2->val){
          insertNodeEnd(&head,i2->val);
          i2 = i2->next;
        }else{
          insertNodeEnd(&head,i1->val);
          i1 = i1->next;
        } 
      }
      return head;
    }
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
int main(){
  Solution a;
  ListNode* l1=nullptr;
  a.insertNodeEnd(&l1,1);
  a.insertNodeEnd(&l1, 2);
  a.insertNodeEnd(&l1, 4);

  ListNode* l2 = new ListNode(1);
  a.insertNodeEnd(&l2, 3);
  a.insertNodeEnd(&l2, 4);
  
  ListNode* l3 = a.mergeTwoLists(l1, l2);
  cout<<endl;
  PrintList(l3);

  Destructor(l1);
  Destructor(l2);
  Destructor(l3);
  return 0;
}
