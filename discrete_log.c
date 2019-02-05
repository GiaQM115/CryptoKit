#include <stdio.h>
#include <stdlib.h>

/*
 * discrete log solver
 * author:	Gianna Mule
 * date:	2/1/18
 * to use, provide the b, n, and m such that b^x = n mod m
 */

int main(int argc, char** argv) {
	if(argc != 4) {
		printf("USAGE: ./log a b n m, such that b^x = n mod n\n");
		return EXIT_SUCCESS;
	}
	int b = strtol(argv[1],NULL,10);
	int n = strtol(argv[2],NULL,10);
	int m = strtol(argv[3],NULL,10);

	printf("Solving %d^x = %d mod %d...\n",b,n,m);

	int t = n;
	while(t%b != 0) {
		t += n;
	}

	printf("x = %d\n",t);
	
	return EXIT_SUCCESS;
}
