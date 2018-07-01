#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	const char* test = "abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcbaABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char* buf;
	int j;

	buf = (char *) malloc(27);

	if (buf) {
		for (int i = 0; i < 3; ++i)
		{
			for (j=0; ((j <26) && (test[j]!=0)); j++) {
				buf[j] = test[j+(26*i)];
			}
			buf[j] = 0;
			printf("%d\n",i);
			puts(buf);
		}

	}
	else {
		printf("Error: Memory Error");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}