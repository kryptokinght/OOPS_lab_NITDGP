//implement stack data structure using calss concept, 
//include member functions like push, pop, isEmpty, ..
/**

**/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	node *link;
	node() {
		data = 0;
		link = NULL;
	}
	node(int d) {
		data = d;
		link = NULL;
	}
	node(node *l) {
		d = 0;
		link = l;
	}
	node(int d, node *l) {
		data = d;
		link = l;
	}
	~node() {
		cout<<"Object Destroyed!!"<<endl;
	}
}
struct node {
	int data;
	node *next;
};

class Stack {
	//node *head = NULL;
	//node *top = NULL;
	node head;
	node top;
	
	int length;
public :
	Stack() {
		length = 0;
		head(NULL);
		top(NULL);
	}
	Stack(node h) {
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
	//node *temp = new node();
	cout<<"Enter data for node"<<endl;
	cin>>d;
	node n(d, NULL);
	//temp->data = d;
	//temp->next = NULL;
	if(head == NULL) {
		head = n;
		top = n;
		return;
	}
	top.next = n;
	n.next = NULL;
	top = n;
}

void Stack::display() {
	node *temp = head;
	if(head == NULL)
		cout<<"Stack is empty"<<endl;
	else {
		cout<<"Displaying stack"<<endl;
		while(temp != NULL) {
			//cout<<temp->data<<" ";
			cout<<temp.data<<endl;
			//temp = temp->next;
			temp = temp.link;
		}
		cout<<endl;	
	}
}
/*
int Stack::pop() {
	if(top == NULL) {
		cout<<"Cannot POP. Returning -1!!"<<endl;
		return -1;
	}
	node *temp = head;
	while( temp->next != NULL && temp->next != top) {
		temp = temp->next;
	}
	cout<<temp->data<<endl;	
	int d = top->data;
	delete top;
	if(length == 1) {
		top = NULL;
		head = NULL;	
	}
	else {
		top = temp;
		top->next = NULL;
	}
	length--;
	return d;
}*/
/*
void Stack::specialDelete(int x) {
	node *temp = head, *prev = NULL, *temp2 = head;
	int flag = 0, first = 0;
	if(temp == NULL)
		cout<<"Cannot Delete! Empty Stack!";
	else {
		if(temp->data == x) {
			flag = 1;
			first = 1;
		}
		while(temp->next != NULL && flag != 1) {
			prev = temp;
			temp = temp->next;
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
			head = temp->next;
		else {
			head = temp->next;
		}
		delete temp;
		cout<<"Successfull"<<endl;
	}
}*/

int main()
{	
	Stack s1;
	int ch, c = 1;
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
			cout<<"Popped element: "<<s1.pop()<<endl;
			break;
			case 3:
			s1.display();
			break;
			case 4:
			cout<<"Enter element for special delete: "<<endl;
			int k;
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