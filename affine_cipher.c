#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int find_inverse(int n, int z) {
	bool foundInverse = false;
	for(int m = 2; m < z; m++) {
		if((m*n)%z == 1) {
			return m;
		}
	}
}

void change_neg(int* n) {
	int fact = -1;
	while(fact*26 >= *n) {
		fact--;
	}
	*n -= (fact*26);
}

int main(int argc, char** argv) {
	if(argc != 5) {
		printf("USAGE: ./affine a b text e/d, where a,b are the key, text is the text to cipher-/plain-text, and e or d is the flag to encrypt or decrypt the text");
	}
	
	int a = strtol(argv[1],NULL,10);
	int b = strtol(argv[2],NULL,10);
	int inv = find_inverse(a,26);
	
	for(int i = 0; i < strlen(argv[3]); i++) {
		int ch = ((int)argv[3][i]-97);
		if(argv[4][0] == 'e') {
			//encrypt
			int y = ((a*ch)+b)%26;
			printf("%c",y+97);
		}
		else {
			//decrypt
			int x = (inv*(ch-b))%26;
			if(x < 0) {
				change_neg(&x);
			}
			printf("%c",x+97);
		}
	}
	
	printf("\n");
	
	return EXIT_SUCCESS;

}
