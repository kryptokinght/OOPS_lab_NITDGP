//implement stack using class

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

class Queue {

	Node *head = NULL;
	Node *top = NULL;
	int length;
public:
	Queue() {
		length = 0;
		head = NULL;
		top = NULL;
	}
	Queue(Node *h) {
		length = 0;
		head = h;
	}

	void enqueue();
	int dequeue();
	void display();
	void specialDelete(int x);
private:
	int getLength() {
		return length;
	}
	bool isEmpty() {
		if(head == NULL)
			return true;
		return false;
	}
};

void Queue::enqueue() {
	length++;
	int d;
	cout<<"Enter data for Node"<<endl;
	cin>>d;
	Node *temp = new Node(d, NULL);
	if(head == NULL) {
		head = temp;
		return;
	}
	temp->link = head;
	head = temp;
}

void Queue::display() {
	Node *temp = head;
	if(head == NULL)
		cout<<"Queue is empty"<<endl;
	else {
		cout<<"Displaying Queue"<<endl;
		while(temp != NULL) {
			cout<<temp->data<<" ";
			temp = temp->link;
		}
		cout<<endl;	
	}
}

int Queue::dequeue() {
	if(head == NULL) {
		cout<<"Cannot dequeue. Returning -1!!"<<endl;
		return -1;
	}
	Node *temp = head, *prev = NULL;
	while( temp->link != NULL) {
		prev = temp;
		temp = temp->link;
	}
	int d = temp->data;
	if(temp == head) {
		head = NULL;
	}
	else {
		prev->link = NULL;
	}
	destructNode(temp);
	length--;
	return d;
}

void Queue::specialDelete(int x) {
	Node *temp = head, *prev = NULL;
	int flag = 0, first = 0;
	if(temp == NULL)
		cout<<"Cannot Delete! Empty Queue!";
	else {
		if(temp->data == x) {
			flag = 1;
			first = 1;
		}
		while(temp->link != NULL && flag != 1) {
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
		else 
			prev->link = temp->link;
		destructNode(temp);
		cout<<"Successfull"<<endl;
	}
}

int main()
{	
	Queue s1;
	int ch, c = 1, p =-1, k = -1;
	while(c) {
		cout<<"1. ENQUEUE"<<endl;
		cout<<"2. DEQUEUE"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. Special Delete"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		cout<<endl;
		switch(ch) {
			case 1:
			s1.enqueue();
			break;	
			case 2:
			p = s1.dequeue();
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