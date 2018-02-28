#include <iostream>

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
	  cout<<this->data<<" Object Destroyed!!"<<endl;
	}
	 
};

void destructNode(Node* ptr) {
  cout <<ptr->data<<" Dyn obj destroyed\n";
  delete ptr; //calls the destructor for the obj
}

int main() {
  Node *head = NULL;
  Node n1(10, NULL);
  head = new Node(100, NULL);
  cout<<head->data<<endl;
  cout<<n1.data<<endl;
  destructNode(head);//destruct dynamically created objects
  return 0;
}