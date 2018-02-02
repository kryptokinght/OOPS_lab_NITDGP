#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	int **arr = (int **)malloc(sizeof(int)*n*n);
	for(int i = 0; i < n; i++ ){ 
		arr[i] = (int *)malloc(sizeof(int)*n);
	}
	arr[0][0] = 12;
	arr[1][1] = 24;
	cout<<arr[0][0];
	cout<<arr[1][1];
	return 0;
}