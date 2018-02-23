//Matrix

#include <bits/stdc++.h>
using namespace std;

class Matrix {
	int row;
	int col;
	int **m;

public:
	Matrix(int r = 0, int c = 0) {
		row = r;
		col = c;
		
	}
	void insert() {
		int i = 0, j = 0;
		int **m = (int **)malloc(sizeof(int)*n*n);
		for(i = 0; i < n; i++ ){ 
			m[i] = (int *)malloc(sizeof(int)*n);
		}
		cout<<"Enter value for "<<r<<"x"<<c<<" matrix"<<endl;
		for(i = 0; i < r; i++) {
			for(j = 0; j < c; j++) {
				cin>>m[i][j];
			}
		}
	}
	void display();
};


int main()
{	
	Matrix m1(2,3), m2(3,2);

	
	return 0;
}