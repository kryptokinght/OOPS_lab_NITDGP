#include <iostream>
#include <cmath>

using namespace std;

void insert(int data, int *h, int count);
void del(int n, int *h);

int main() {
	int n, data, i;
	int *h;
	
	cout<<"Enter number of nodes"<<endl;
	cin>>n;
	h = new int[n]; //allocating new array
	
	cout<<"enter nodes"<<endl;
	
	for(i = 0; i < n; i++) {
		cin>>data;
		insert(data, h, i);
	}
	cout<<"Displaying heap"<<endl;
	for(i = 0; i < n; i++) {
		cout<<h[i]<<endl;
	}
	
	del(n, h);

	cout<<"Displaying heap"<<endl;
	for(i = 0; i < n; i++) {
		cout<<h[i]<<endl;
	}
	del(n, h);
	cout<<"Displaying heap"<<endl;
	for(i = 0; i < n; i++) {
		cout<<h[i]<<endl;
	}
	return 0;
}

void insert(int data, int *h, int count) {
	if(count == 0) {
		h[count] = data;
		return;
	}
	else {
		h[count] = data;
		int parent = floor((count-1)/2); //initializing parent
		while(h[parent] < h[count] && parent >= 0) {
			int t = h[parent];
			h[parent] = h[count];
			h[count] = t;
			count = parent;
			parent = floor((parent - 1)/2);
		}
	}
}

void del(int n, int *h) {
	int count = 0, lc, rc, data;
	while(count < n) {
		data = h[count];
		lc = (2*count + 1);
		rc = (2*count + 2);
		if(h[lc] > h[rc]) {
			h[count] = h[lc];
			count = lc;
		}
		else {
			h[count] = h[rc];
			count = rc;
		}
	}
}