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
    ListNode* middleNode(ListNode* head) {
      int cont = 0;
      ListNode* temp = head;
      while(temp != nullptr){
        temp=temp->next;
        cont++;
      }
      for(int i=0; i<cont/2; i++){
        head = head->next;
      }
      return head;
    }
};

int main(){
  Solution a;
  ListNode* l1=nullptr;
  insertNodeEnd(&l1, 1);
  insertNodeEnd(&l1, 2);
  insertNodeEnd(&l1, 3);
  insertNodeEnd(&l1, 4);
  insertNodeEnd(&l1, 5);
  insertNodeEnd(&l1, 6);
  ListNode* l= a.middleNode(l1);
  PrintList(l);
  cout<<endl;
  PrintList(l1);
  Destructor(l1);
  //Destructor(l);
  return 0;
}
