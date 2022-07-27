#include <iostream>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode* intersection(ListNode* head) {
      ListNode* fast = head;
      ListNode* slow = head;
      while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
          return slow;
        }
      }
      return nullptr;
    }
    ListNode* detectCycle(ListNode* head) {
      ListNode* start = head;
      ListNode* intersected = intersection(head);
      if (intersected == nullptr){return intersected;}
      while(start != intersected){
        start = start->next;
        intersected = intersected->next;
      }
      return start;
    }
};

int main(){
  Solution a;
  ListNode* l1=nullptr;
  insertNodeEnd(&l1, 3);
  insertNodeEnd(&l1, 2);
  insertNodeEnd(&l1, 0);
  insertNodeEnd(&l1, -4);
  l1->next->next->next->next = l1->next;
  ListNode* l= a.detectCycle(l1);
  cout<<l1->val<<endl;
  cout<<l1->next->next->next->val<<endl;
  cout<<l1->next->next->next->next->val<<endl;
  cout<<"respuesta: ";
  cout<<l->val<<endl;
  cout<<endl;
  //Destructor(l1);
  //Destructor(l);
  return 0;
}
