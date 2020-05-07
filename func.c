#include <stdio.h>

void scan_paths(char *str, char *delim) {
	FILE *file;
	file = fopen("input.txt", "r");
	fscanf(file, "%s", delim);
	fscanf(file, "%s", str);
  //fprintf(stdout,"\n delim: %s\n str: %s\n", delim, str);
	fclose(file);
}

