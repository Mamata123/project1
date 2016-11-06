#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include <unistd.h>
#include <errno.h>
#include"grep.h"

int contains(char *line, char *pattern){
	char *p, *q;
	p=line;
	q=pattern;
	while(*q && *p){
		if(*p == *q)
		q++;
		else
			q=pattern;
		p++;
	}
	if(!*q){
		return 1;
	}
       return 0;
}
void grepIt(char *pattern,char *file_name)	{
	FILE *fp= fopen(file_name,"r");
 	int i=0, buf_size=300;
	
	char *line = (char *)malloc(buf_size);
	if(!fp){
		printf("no such  file");
		return;
	}
	while(fgets(line,buf_size, fp)){
		if(contains(line,pattern))
				printf("%s",line);
		}
	}
char * read_line(FILE *fp)
{
    char *buffer, *t;
    int chars = 0, buffer_size = 256;
    char *line = malloc(buffer_size);
    buffer = line;
    while(fgets(buffer, buffer_size - chars, fp))
    {
	chars = strlen(line);
	if(line[chars - 1] == '\n')
	{
		line[chars - 1] = '\0';
		return line;
	}
	else
	{
		buffer_size = 2 * buffer_size;
		t = realloc(line, buffer_size);
		if(t)
		{
			line = t;
			buffer = line + chars;
		}
		else
		{
			free(line);
			return NULL;
		}

	}	
    }
    return NULL;
}  

