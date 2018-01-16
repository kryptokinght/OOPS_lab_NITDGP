#include "largemaths.h"
#include  "stdio.h"
#include  "string.h"

void reverse(char[], int);
void multiply(char[], char, int, char[], int);
int add(char m[], char sum[], int l);

char m[1000];
int m_len;

char* large_multiply(char x[], char y[]) {
	char a[100], b[100], sum[100][1000], temp;
	int la, lb, i, j, len_m = 0;
	strcpy(a,x);
	strcpy(b,y);
	la = strlen(a);
	lb = strlen(b);
	for(i = 0; i<1000; i++)
		m[i] = '0';

	if(la > lb) {
		temp = lb;
		reverse(b,lb);
		reverse(a,la);
		//stores the multiplication of each step in sum
		for(i = 0; i < lb; i++) 
			multiply(a,b[i],la,sum[i],i);
	}
	else {
		temp = la;
		reverse(a,la);
		reverse(b,lb);
		//stores the multiplication of each step in sum
		for(i = 0; i < la; i++)
			multiply(b,a[i],lb,sum[i],i);
	}

	//adding up all the sums for the different steps
	for(i = 0; i < temp; i++)
		len_m = add(m,sum[i],strlen(sum[i]));
	reverse(m, len_m);
	m[len_m] = '\0';
	m_len = len_m;
	return m;
}

//helper functions

void reverse(char a[], int l) {
	if (l == 1)
		return;
	int i = 0, j = l-1;
	char t;
	while(i < j) {
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i++;
		j--;
	}
}

void multiply(char a[], char x, int la, char sum[], int i) {
	
	int d1, d2 = x - '0', d, ca = 0, s, j = 0, len;
	while(j < la) {
		d1 = a[j] - '0';
		s = d1*d2 + ca;
		d = s%10;
		ca = s/10;
		sum[j] = d + '0';
		j++;
	}
	len = j;
	if(ca > 0) {
		sum[j] = ca+'0';
		len = j + 1;
	}
	reverse(sum, len); //now the sum is in proper order not reversed
	//add the extra zeroes
	j = 0;
	while(j < i) {
		sum[len] = '0';
		len++;
		j++;
	}
	reverse(sum,len);

}

int add(char m[], char sum[], int l) {
	int i = 0, j = 0, d1, d2, s = 0, ca = 0, d = 0, len;
	while(i < l) {
		d1 = sum[i] - '0';
		d2 = m[i] - '0';
		s = d1 + d2 + ca;
		if(s > 9) {
			d = s-10;
			ca = 1;
		}
		else {
			d = s;
			ca = 0;
		}
		m[i] = d + '0';
		i++;
	}
	if(ca > 0) {
		m[i] = ca + '0';
		i++;
	}
	return i;
}

//@Copyright @#%%^&*%@