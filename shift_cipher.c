#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * shift cipher decrypter
 * author:	Gianna Mule
 * date:	1/30/18
 * to use, provide the ciphertext to be decrypted
 * program will print all possible shifts of the text to console
 */

int main(int* argc, char** argv) {

	if(argc != 2) {
		printf("USAGE: ./shift text, where text is the ciphertext to be decrypted\n");
		return EXIT_FAILURE;
	}

	char* cipher = argv[1];
	int shift = 1;

	printf("Cipher: %s\n\n", cipher);

	// try all shifts of the alphabet
	while(shift < 26) {
		printf("\nshift: %d\n", shift);
		for(int i = 0; i < strlen(cipher); i++) {
			int sc = (int)cipher[i] + shift;
			if(sc > 122) {
				// convert to correct ascii before printing
				sc = sc % 122;
				sc += 96;
			}
			printf("%c",sc);
		}
		printf("\n");
		shift++;
	}

	return EXIT_SUCCESS;	

}
