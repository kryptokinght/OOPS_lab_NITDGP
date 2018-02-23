//polynomial class, addition, subtraction, multiplication 
//matrix class, addition
//tree class

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	int factor;
	node *next;
};

class Poly {
	node *head = NULL;
	int length;
	public :
		Stack() {
			length = 0;
		}
		void push();
		int pop();
		void display();
		int getLength() {
			return length;
		}
		bool isEmpty() {
			if(head == NULL)
				return true;
			return false;
		}
		void specialDelete(int x);

};

void Stack::push() {
	length++;
	int d;
	node *temp = new node();
	cout<<"Enter data for node"<<endl;
	cin>>d;
	temp->data = d;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
		top = temp;
		return;
	}
	top->next = temp;
	temp->next = NULL;
	top = temp;
}

void Stack::display() {
	node *temp = head;
	if(head == NULL)
		cout<<"Stack is empty"<<endl;
	else {
		cout<<"Displaying stack"<<endl;
		while(temp != NULL) {
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;	
	}
}

int Stack::pop() {
	if(top == NULL) {
		cout<<"Cannot POP. Returning -1!!"<<endl;
		return -1;
	}
	node *temp = head;
	while( temp->next != NULL && temp->next != top) {
		temp = temp->next;
	}
	int d = top->data;
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
}

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
			/*node *temp3;
			while(temp2->next != temp->next) {
				temp3 = temp2;
				delete temp3;

			}*/
			head = temp->next;
		}
		delete temp;
		cout<<"Successfull"<<endl;
	}
}

int main()
{	
	Stack s1;
	int ch, c = 1;
	while(c) {
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. isEmpty"<<endl;
		cout<<"5. LENGTH"<<endl;
		cout<<"6. Special Delete"<<endl;
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
			cout<<"isEmpty: "<<s1.isEmpty()<<endl;
			break;
			case 5:
			cout<<"Length of stack: "<<s1.getLength()<<endl;
			break;
			case 6:
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