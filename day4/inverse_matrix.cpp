#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int **allocate(int n) {
	int **temp = (int **)malloc(sizeof(int)*n*n);
	for(int i = 0; i < n; i++ ){ 
		temp[i] = (int *)malloc(sizeof(int)*n);
	}
	return temp;
}

void insert(int **m, int n) {
	cout<<"Enter elements of "<<n<<"*"<<n<<" matrix:"<<endl;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cin>>*(*(m+i)+j);
	}
}

void display(int **m, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout<<*(*(m+i)+j)<<" ";
		cout<<endl;
	}
}

int convert(int **m, int *n, int l) {
	int count = 0;
	for(int i = 0; i < l; i++) {
		for(int j = 0; j < l; j++) {
			*(n+count) = *(*(m+i)+j);
			count++;	
		}	
	}
}

int determinant(int *d, int dlen) {
  int sum = 0, i = 0, flag = 0, tcounter = 0;
  int sqd = (int)sqrt(dlen);
  int m,n; //loop variables for tarr
  int tarr[100]; //stores the subarray for the different parts of the matrix
  
  if(dlen == 1) //when the matrix of just size 1
    return *(d+0);
  
  //calculating the determinant recursively
  for(i = 0; i<sqd; i++) {
    //initialize tarr
    for(m = 0; m < sqd; m++) {
      for(n = 0; n < sqd; n++) {
        if(m != 0 && n != i) {
          tarr[tcounter] = *(d + m*sqd + n);
          tcounter++;
        }
      }
    }
    //calculate the sum by passing tarr recursively
    if(flag == 1) {
      sum = sum - *(d+i)*determinant(tarr,(sqd-1)*(sqd-1));
      flag = 0;
    }
    else {
      sum = sum + *(d+i)*determinant(tarr,(sqd-1)*(sqd-1));
      flag = 1;
    }
    tcounter = 0;
    //***************end of for loop*********
  }
  return sum;
}


int cofactor(int ti, int tj, int **m, int n) {
	int *temp = new int[(n-1)*(n-1)];
	int count = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == ti || j == tj) 
				continue;
			else {
				*(temp + count) = *(*(m+i)+j);
				count++;
			}
		}
	}
	return determinant(temp, (n-1)*(n-1));
}

int **transpose(int **m, int n) {
	int **tp = allocate(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			*(*(tp+j)+i) = *(*(m+i)+j);
		}
	}
	return tp;
}

int **adjoint(int **m, int n) {
	int **temp = allocate(n);
	//finding cofactors for each position
	int cf = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cf = cofactor(i, j, m, n); //cofactor for each postion of matrix
			if((i+j)%2 == 0) //if even
				*(*(temp+i)+j) = cf;
			else
				*(*(temp+i)+j) = -cf;
		}
	}
	/*cout<<"Displaying adjoint without transpose"<<endl;
	display(temp, n);*/
	return transpose(temp, n);
}

float **inverse(int **adj_m, int d, int n) {
	float **temp = (float **)malloc(sizeof(float)*n*n);
	for(int k = 0; k < n; k++ ){ 
		temp[k] = (float *)malloc(sizeof(float)*n);
	}
	float dx= float(d);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			*(*(temp+i)+j) = *(*(adj_m + i)+j)/dx;
	}
	return temp;

}

int main() {
	int n;
	cout<<"Enter size of square matrix: "<<endl;
	cin>>n;
	int **m = allocate(n);
	insert(m, n);
	display(m, n);
	int *m1 = new int[n*n];
	convert(m, m1, n);
	int d = determinant(m1, n*n);
	cout<<"The determinant is: "<<d<<endl;
	if(d == 0) 
		cout<<"Cannot find Inverse!!"<<endl;
	else {
		//find adjoint matrix/
		int **adj_m = allocate(n);
		adj_m = adjoint(m, n);
		cout<<"Displaying adjoint:"<<endl;
		display(adj_m, n);
		cout<<"THe INVERSE of the matrix is: "<<endl;
		float **inv = (float **)malloc(sizeof(float)*n*n);
		for(int i = 0; i < n; i++ ){ 
			inv[i] = (float *)malloc(sizeof(float)*n);
		}
		inv = inverse(adj_m, d, n);
		//dsiplaying the inverse
		for(int f = 0; f < n; f++) {
			for(int r = 0; r < n; r++)
				cout<<*(*(inv+f)+r)<<" ";
			cout<<endl;
		}
	}
	return 0;
}


