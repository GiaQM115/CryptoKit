#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if(argc != 4) {
		printf("USAGE: ./log b n m, such that 7^x = n mod b\n");
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
