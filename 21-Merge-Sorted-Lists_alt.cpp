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
      ListNode* dummy = new ListNode(-1);
      ListNode* head = dummy;
      while(!(list1 == nullptr && list2 == nullptr)){
        if (list1==nullptr){
          dummy->next = list2;
          break;
        }else if(list2==nullptr){
          dummy->next = list1;
          break;
        }
        else if(list1->val > list2->val){
          dummy->next = list2;
          list2 = list2->next;
        }else{
          dummy->next = list1;
          list1 = list1->next;
        } 
        dummy=dummy->next;
      }
      dummy = head->next;
      delete head;
      return dummy;
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
  PrintList(l1);
  cout<<endl;
  
  ListNode* l2 = new ListNode(1);
  a.insertNodeEnd(&l2, 3);
  a.insertNodeEnd(&l2, 4);
  PrintList(l2);
  cout<<endl;
 
  ListNode* l3 = a.mergeTwoLists(l1, l2);
  cout<<endl;
  PrintList(l3);

//  Destructor(l1);
//  Destructor(l2);
  Destructor(l3);
  return 0;
}
