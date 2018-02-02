#include <iostream>
#include <iomanip>

using namespace std;

typedef struct Node {
	int data;
	int conn[100];
};

int main()
{
	int nodes, con, i, j;
	cout<<"Enter the number of nodes in the graph"<<endl;
	cin>>nodes;
	
	int am[nodes][nodes + 1];
	
	for(i = 0; i < nodes; i++) {
		cout<<"Enter connections for node "<<i<<endl;
		cin>>con;
		am[i][0]= con;
		for(j = 1; j <= con; j++)
			cin>>am[i][j];
	}	

	//printing the graph
	for(i = 0; i < nodes; i++) {
		cout<<"Node "<<i<<":";
		for(j = 1; j<am[i][0]; j++)
			cout<<" "<<am[i][j];
		cout<<endl;
	}
}