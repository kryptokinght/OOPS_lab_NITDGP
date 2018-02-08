#include<stdio.h>
#include<string.h>

void reverse(char[], int);
int calcSum(char a[], char b[], char c[], int la, int lb);

int main() {
	char a[100000] , b[100000], c[100001];
	int la, lb, lenc, i;
	printf("Enter first number: \n");
	scanf("%s",a);
	la = strlen(a);
	printf("Enter second number: \n");
	scanf("%s",b);
	lb = strlen(b);
	reverse(a,la);
	reverse(b,lb);
	if(la > lb) 
		lenc = calcSum(a,b,c,la,lb);
	else
		lenc = calcSum(b,a,c,lb,la);
	//printing the sum
	printf("The sum is: \n");
	for( i = 0; i < lenc; i++) {
		printf("%c",c[i]);
	}
	printf("\n");
	return 0;
}

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

int calcSum(char a[], char b[], char c[], int la, int lb) {
	int i = 0, j = 0, d1, d2, s = 0, ca = 0, d = 0, len;
	while(i < lb) {
		d1 = a[i] - '0';
		d2 = b[i] - '0';
		s = d1 + d2 + ca;
		if(s > 9) {
			d = s-10;
			ca = 1;
		}
		else {
			d = s;
			ca = 0;
		}
		//printf("d = %d ca = %d\n",d,ca);
		c[i] = d + '0';
		//printf("c[%d] = %c\n",i,c[i]);
		i++;
	} 
	if(ca > 0 && i == la) {
		c[i] = ca - '0';
		//printf("c[%d] = %c\n",i,c[i]);
		len = i++;
	}
	else {
		while(i < la) {
			//printf("a[%d] = %c\n",i,a[i]);
			c[i] = a[i] + ca;
			//printf("c[%d] = %c\n",i,c[i]);
			ca = 0;
			i++;
		}
		len = i;	
	}
	reverse(c, len);
	printf("Minanshu_Swag");
	return len;
}
