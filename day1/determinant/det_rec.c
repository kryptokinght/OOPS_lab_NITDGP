#include <stdio.h>
#include <math.h>

int N = 2;  // n*n matrix

int det(int[], int);

int main() {
  printf("ENter the order of matrix:\n");
  scanf("%d", &N);
  int a[N*N], i = 0;
  //input elements of a
  printf("Enter elements of %d*%d matrix\n",N,N);
  for(i = 0; i < N*N; i++) {
    printf("%d ",i+1);
    scanf("%d",&a[i]);
  }
  //displaying the matrix
  for(i = 0; i < N*N; i++) {
    if(i % N == 0)
      printf("\n");
    printf("%d ", a[i]);
  }
  printf("\n");  
  int ans = det(a,N*N);
  printf("The determinant is %d\n",ans);
  return 0;
}

//dtereminant function

int det(int d[], int dlen) {
  int sum = 0, i = 0, flag = 0, tcounter = 0;
  int sqd = (int)sqrt(dlen);
  int m,n; //loop variables for tarr
  int tarr[100]; //stores the subarray for the different parts of the matrix
  
  if(dlen == 1) //when the matrix of just size 1
    return d[0];
  
  //calculating the determinant recursively
  for(i = 0; i<sqd; i++) {
    //initialize tarr
    for(m = 0; m < sqd; m++) {
      for(n = 0; n < sqd; n++) {
        if(m != 0 && n != i) {
          tarr[tcounter] = d[m*sqd + n];
          tcounter++;
        }
      }
    }
    //calculate the sum by passing tarr recursively
    if(flag == 1) {
      sum = sum - d[i]*det(tarr,(sqd-1)*(sqd-1));
      flag = 0;
    }
    else {
      sum = sum + d[i]
      *det(tarr,(sqd-1)*(sqd-1));
      flag = 1;
    }
    tcounter = 0;
    //***************end of for loop*********
  }
  return sum;
}