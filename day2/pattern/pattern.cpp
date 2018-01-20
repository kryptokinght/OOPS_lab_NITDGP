#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int rows, n;
	cout<<"Enter number of rows"<<endl;
	cin>>rows;
	cout<<setw(2*rows + 1)<<"1"<<endl;
	for(int i = 0; i < rows; i++) {
		cout<<setw(2*rows-(2*i+1));
		for(n = 1; n <= i+1; n++)
			cout<<n<<" ";
		for(int k = n; k >= 1; k--)
			cout<<k<<" ";
		cout<<endl;
	}
}