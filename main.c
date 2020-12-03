#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char** parse_args (char* line) {
	char** args = malloc(sizeof(char *) * 6);
	char *token, *p;
	p = line;
	
	int i = 0;
	while (p != NULL) {
		token = strsep (&p, " ");
		args[i] = token;
		i++;
	}
	args[i] = NULL;
	
	return args;
}

int main () {

	char line[] = "ls -a -l";
	char** args = parse_args (line);
	execvp (args[0], args);
	
	return 0;
}
