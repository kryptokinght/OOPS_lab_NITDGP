#include <iostream>
#include <stdlib.h>

using namespace std;

int **allocate(int n) {
	int **temp = (int **)malloc(sizeof(int)*n*n);
	for(int i = 0; i < n; i++ ){ 
		temp[i] = (int *)malloc(sizeof(int)*n);
	}
	return temp;
}

void insert(int **m, int n, char sh) {
	cout<<"Enter elements of "<<n<<"*"<<n<<" "<<sh<<" matrix :"<<endl;
	int i, j;
	if(sh == 'u') {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(j >= i)
					cin>>*(*(m+i)+j);
				else
					*(*(m+i)+j) = 0;	
			}
		}		
	}
	else {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if(j <= i)
					cin>>*(*(m+i)+j);
				else
					*(*(m+i)+j) = 0;	
			}		
		}	
	}
}

void display(int **m, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout<<*(*(m+i)+j)<<" ";
		cout<<endl;
	}
}

int **sum(int n, int **m1, int **m2) {
	int **s = allocate(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			s[i][j] = m1[i][j] + m2[i][j];
	}
	return s;
}

int main() {
	int n;
	cout<<"Enter size of the square matrix:"<<endl;
	cin>>n;
	//first matrix
	int **m1 = allocate(n);
	//second matrix
	int **m2 = allocate(n);
	insert(m1, n, 'u');
	insert(m2, n, 'l');
	cout<<"Displaying matrix 1"<<endl;
	display(m1, n);
	cout<<"Displaying matrix 2"<<endl;
	display(m2, n);
	int **s = allocate(n);
	s = sum(n, m1, m2);
	cout<<"Displaying sum of triangular matrices: "<<endl;
	display(s, n);
	return 0;
}

