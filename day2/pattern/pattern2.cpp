#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int rows, n, spaces = 0;
	cout<<"Enter number of rows"<<endl;
	cin>>rows;
	for(int i = 0; i < rows; i++) {
		if(i == rows - 1){
			for(int m = 0; m < 2*rows - 1; m++) 
			cout<<"1";
			cout<<endl;
		}
		else {
			cout<<setw(rows - i);
			cout<<"1";
			if(i == 0)
				spaces = 0;
			else
				spaces = 2*i-1;
			cout<<setw(spaces+1);
			if(i != 0)
				cout<<"1";
			cout<<endl;	
		}
		
	}
}