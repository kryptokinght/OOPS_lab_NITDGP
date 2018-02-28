//implement stack data structure using calss concept, 
//include member functions like push, pop, isEmpty, ..
/**

**/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *link;
	Node() {
		data = 0;
		link = NULL;
	}
	Node(int d) {
		data = d;
		link = NULL;
	}
	Node(Node *l) {
		data = 0;
		link = l;
	}
	Node(int d, Node *l) {
		data = d;
		link = l;
	}
	~Node() {
	  cout<<" Object Destroyed with value: "<<this->data<<endl;
	}
	 
};

void destructNode(Node* ptr) {
  delete ptr; //calls the destructor for the obj
}

class Stack {	
	Node *head;
	Node *top;
	int length;
public:
	Stack() {
		length = 0;
		head = NULL;
		top = NULL;
	}
	Stack(Node *h) {
		length = 0;
		head = h;
	}
	void push();
	int pop();
	void display();
	void specialDelete(int x);
private :
	bool isEmpty();
	int getLength();
};

int Stack::getLength() {
	return length;
}

bool Stack::isEmpty() {
	if(head == NULL)
		return true;
	return false;
}

void Stack::push() {
	length++;
	int d;
	cout<<"Enter data for node"<<endl;
	cin>>d;
	Node *temp = new Node(d, NULL);
	if(head == NULL) {
		head = temp;
		top = temp;
		return;
	}
	top->link = temp;
	temp->link = NULL;
	top = temp;
}

void Stack::display() {
	Node *temp = head;
	if(head == NULL)
		cout<<"Stack is empty"<<endl;
	else {
		cout<<"Displaying stack"<<endl;
		while(temp != NULL) {
			cout<<temp->data<<" ";
			temp = temp->link;
		}
		cout<<endl;	
	}
}

int Stack::pop() {
	if(top == NULL) {
		cout<<"Cannot POP. Empty Stack!!"<<endl;
		return -1;
	}
	Node *temp = head;
	while( temp->link != NULL && temp->link != top) {
		temp = temp->link;
	}
	cout<<temp->data<<endl;	
	int d = top->data;
	destructNode(top);
	if(length == 1) {
		top = NULL;
		head = NULL;	
	}
	else {
		top = temp;
		top->link = NULL;
	}
	length--;
	return d;
}

void Stack::specialDelete(int x) {
	Node *temp = head, *prev = NULL, *temp2 = head;
	int flag = 0, first = 0;
	if(temp == NULL)
		cout<<"Cannot Delete! Empty Stack!";
	else {
		if(temp->data == x) {  //if first element in the stack is x
			flag = 1;
			first = 1;
		}
		while(temp->link != NULL && flag != 1) { //when first element is not x
			prev = temp;
			temp = temp->link;
			if(temp->data == x) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			cout<<"Element not found!!"<<endl;
			return;
		}
		else if(first)
			head = temp->link;
		else {
			head = temp->link;
		}
		destructNode(temp);
		cout<<"Successfull"<<endl;
	}
}

int main()
{	
	Stack s1;
	int ch, c = 1, p =-1, k = -1;
	while(c) {
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. Special Delete"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		cout<<endl;
		switch(ch) {
			case 1:
			s1.push();
			break;	
			case 2:
			p = s1.pop();
			if(p != -1)
				cout<<"Popped element: "<<p<<endl;
			break;
			case 3:
			s1.display();
			break;
			case 4:
			cout<<"Enter element for special delete: "<<endl;
			cin>>k;
			s1.specialDelete(k);
			break;
			default: cout<<"Wrong Entry!!"<<endl;
		}
		cout<<"Do you want to continue(1/0)"<<endl;
		cin>>c;
	}
	cout<<"THANKS....."<<endl;
	return 0;
}