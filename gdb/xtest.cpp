#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

int main() {
	unsigned int size = 1 << 31;
	char *str;
	str = (char *)malloc(size);
	strcpy(str, "hello");
	printf("%s", str);
	free(str);
	return 0;
}