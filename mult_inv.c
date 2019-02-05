#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_inverse(int n, int z) {
	bool foundInverse = false;
	for(int m = 2; m < z; m++) {
		if((m*n)%z == 1) {
			return m;
		}
	}
}

int main(int argc, char** argv) {

	if(argc != 2) {
		printf("USAGE: ./multinv n, where n is the integer ring size\n");
		return EXIT_SUCCESS;
	}
	
	if(strtol(argv[1],NULL,10) <= 0) {
		printf("Invalid ring size; enter a number > 0\n");
		return EXIT_SUCCESS;
	}

	int z = strtol(argv[1],NULL,10);
	bool hasInverse = false;
	int n;

	printf("Multiplicative Inverses for Integer Ring %d:\n", z);
	printf("1 has inverse 1\n");

	for(int i = 2; i < z; i++) {
		for(int j = 2; j < z; j++) {
			if(i%j == 0 && z%j == 0) {
				hasInverse = false;
				break;
			}
			hasInverse = true;
		}
		if(hasInverse) {
			printf("%d has inverse %d\n",i,find_inverse(i,z));
		}
	}
	
	// find gcd; if gcd is 1, send to method that does what these loops do

}
