#include "stdio.h"
#include "string.h"
#include "largemaths.h"

void convert_to_str(int n, char str[]);
void reverse(char[], int);

int main() {
	int n, i = 1, j;
	char *m, temp[100];
	m = large_multiply("1","1");
	m[1] = '\0';
	printf("Enter number to find its factorial: \n");
	scanf("%d",&n);
	
	if(n == 0) {
		printf("Factorial: %d\n",n);
		return 0;
	}

	while(i <= n) {
		convert_to_str(i,temp);
		m = large_multiply(temp, m);
		i++;
	}
	
	printf("Factorial: \n");
	for(i = 0; i < strlen(m); i++) 
		printf("%c",m[i]);
	printf("\n");
	return 0;
}

void convert_to_str(int n, char str[]) {
	int i = 0, d;
	while(n > 0) {
		d = n%10;
		str[i] = d + '0';
		n = n/10;
		i++;
	}
	str[i] = '\0';
	reverse(str, strlen(str));
}
