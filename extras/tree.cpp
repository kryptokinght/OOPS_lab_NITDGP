/*
Implement BFS and DFS over a class by taking graph as a input from a file. 
class Graph {
	constructor("filename")
	DFS method() {stack}
	BFS method() {queue}
}
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
	vector <int> *adj;
	int size;
public:
	Graph(int s) {
		size = s;
		adj = new vector <int>[s];
	}
	int breadhFirstSearch();
	int depthFirstSearch();
	void display();
	void addEdge(int u, int v)
	{
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
};

void Graph::display() {
	vector <int> :: iterator i;
	for(int j = 0; j < size; j++) {
		cout<<"For vertex "<<j<<endl;
		for (i = g[j].begin(); i != g[j].end(); ++i)
        	cout << *i << ' ';
    	cout<<endl;
	}
}

int main() {
	Graph g(5);
	g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.display();
	return 0;	
}

//***************single-linked Node****************************
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

//***********************stack class********************************************
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

//***************************queue class*************************************************

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
