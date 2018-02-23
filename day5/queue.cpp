//implement stack using class

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *next;
};

class Queue {
	node *head = NULL;
	node *top = NULL;
	int length;
	public :
		Queue() {
			length = 0;
		}
		void enqueue();
		int dequeue();
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

void Queue::enqueue() {
	length++;
	int d;
	node *temp = new node();
	cout<<"Enter data for node"<<endl;
	cin>>d;
	temp->data = d;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
}

void Queue::display() {
	node *temp = head;
	if(head == NULL)
		cout<<"Queue is empty"<<endl;
	else {
		cout<<"Displaying Queue"<<endl;
		while(temp != NULL) {
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;	
	}
}

int Queue::dequeue() {
	if(head == NULL) {
		cout<<"Cannot dequeue. Returning -1!!"<<endl;
		return -1;
	}
	node *temp = head, *prev = NULL;
	while( temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	int d = temp->data;
	if(temp == head) {
		head = NULL;
	}
	else {
		prev->next = NULL;
	}
	delete temp;
	length--;
	return d;
}

void Queue::specialDelete(int x) {
	node *temp = head, *prev = NULL;
	int flag = 0, first = 0;
	if(temp == NULL)
		cout<<"Cannot Delete! Empty Queue!";
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
		else 
			prev->next = temp->next;
		delete temp;
		cout<<"Successfull"<<endl;
	}
}

int main()
{	
	Queue s1;
	int ch, c = 1;
	while(c) {
		cout<<"1. ENQUEUE"<<endl;
		cout<<"2. DEQUEUE"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. isEmpty"<<endl;
		cout<<"5. LENGTH"<<endl;
		cout<<"6. Special Delete"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		cout<<endl;
		switch(ch) {
			case 1:
			s1.enqueue();
			break;	
			case 2:
			cout<<"Popped element: "<<s1.dequeue()<<endl;
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