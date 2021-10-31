#include <stdio.h>
#include <string.h>
int func(FILE *input) {
	char buffer[17];
	fread(buffer, sizeof(char), 41, input);
	//printf("buffer 		%s\n",buffer);
	//printf("input		%s\n",input);
	return 1;
}
int main(int argc, char *argv[]) {
	FILE *input = fopen("./badfile", "r");
	//printf("input main	%s\n",input);
	//char *shell = getenv("MYSHELL");
	//if (shell)
	//	printf("%x\n", shell);
	func(input);
	printf("Success\n");
	return 1;
}
