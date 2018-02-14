#include <iostream>
using namespace std;

struct Stack {
  int data;
  Stack* next;
};

Stack* head = NULL;

void display() {
  Stack* temp = new Stack();
  temp = head;
  while(temp != NULL) {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

void push(int data) {
  Stack* new_el = new Stack();
  new_el -> data = data;
  new_el -> next = NULL;
  if(head == NULL)
    head = new_el;
  else {
    new_el -> next = head;
    head = new_el;
  }
  display();
}

int pop() {
  Stack* temp = new Stack();
  
}

int main() {
  push(10);
  push(9);
  push(8);
  push(7);
  push(6);
  cout<<"thank you"<<endl;
  return 0;
}