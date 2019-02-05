#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int* argc, char** argv) {

	(void)argc;
	
	char* cipher = argv[1];
	int shift = 1;

	printf("Cipher: %s\n\n", cipher);

	while(shift < 26) {
		printf("\nshift: %d\n", shift);
		for(int i = 0; i < strlen(cipher); i++) {
			int sc = (int)cipher[i] + shift;
			if(sc > 122) {
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
