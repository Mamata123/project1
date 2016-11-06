#ifndef __GREP_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void grepIt(char *pattern,char *file_name);
int contains(char *line, char *pattern);
char * read_line(FILE *fp);
#endif
