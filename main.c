#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include <unistd.h>
#include <errno.h>
#include"grep.h"
#define BUFSIZE 256
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
/*******************************************************************************
    Copyright (C) 2015  Patil Mamata
    ID: mamatapatil2210@gmail.com
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.
    *************************************************************************/
int main(int argc, char *argv[]){
	char *filename;
	FILE *fp;
	if(argc < 3) /*Check argument line passing*/
	{
		printf("grep <string> <filename> \n");
		return -1;
	}
	if(argc == 3) /* If we have only 3 arguements */
	{
		filename = argv[2];
		fp = fopen(filename,"r");

		if(fp==NULL)
		{
			printf("File not found, check the error %d\n",errno);
      			return -1;
		}
	grepIt(argv[1], argv[2]);
	}

	else{
		char *buf[BUFSIZE];
		char pattern[BUFSIZE];
		char file_name[BUFSIZE];
		char *str,*line;
		int linecount = 1;
		FILE *fp;
		int i;
		int count;
		count = 0;
		char state = argv[1][1];
		switch(state) {
			case 'c' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while( line = read_line(fp)) 
				{
					char *token = strtok(line," "); //break the line;
				        int flag = 0;
				        while(token != NULL)
				        {			    
				    		int s = strcmp(token,argv[2]); /*compare token with pattern*/
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			count++;
				    		
				    		}
				    		token = strtok(NULL," ");
				        }
				}
				printf("%d\n",count);
				break;
			case 'v' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while( line = read_line(fp)) 
				{
					if (strstr(line,argv[2]) == NULL) 
					{
						printf("%s\n",line);	
					}
				}
				break;
			
			case 'o' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while(line = read_line(fp)) 
				{
				        char *token= strtok(line," ");
				        int flag = 0;
				        while(token != NULL)
				        {			    
				    		int s = strcmp(token,argv[2]);
				    		if (s == 0)
				    		{
				    			flag = 1;
				    			printf(ANSI_COLOR_RED "%s \n",token);
				    			printf(ANSI_COLOR_RESET);
				    		}
				    		token = strtok(NULL," ");
				    	
				       }
				}
				break;
			case 'e' :
				if(argc == 4)
					fp = fopen(argv[3],"r");
				while(line = read_line(fp)) 
				{
					char *token[100];
					char *string;
				        int sign = 0;
				        int i = 0, j;
				        token[i] = strtok(line," ");
				        while(token[i] != NULL)
				        {			    
				    		if (strcmp(token[i],argv[2]) == 0)
				    		{
				    			sign = 1;
				    			string = token[i];
				    		}
				    		i++;
				    		token[i] = strtok(NULL," ");			    	
				       }
				       if(sign == 1)
				       {	
				       		for(j = 0; j < i; j++)
				       		{
				       			if(strcmp(string, token[j]) == 0)
				       			{
				       		     		printf(ANSI_COLOR_RED "%s ",token[j]);
				    		     		printf(ANSI_COLOR_RESET);
				    			}
				    			else
				    		     		printf("%s ",token[j]);
				       		}
				       		printf("\n");
				       }
	
				}
				break;

			
			
			case'i' :
				for (i = 3; i < argc; i++) 
				{
					fp = fopen(argv[i],"r");
					while(line = read_line(fp)) 
					{
						char *token[100];
						char *string;
				        	int flag = 0;
				        	int i = 0, j;
				        	token[i] = strtok(line," ");	
				        	while(token[i] != NULL)
				        	{	
				        		int s = strcasecmp(token[i],argv[2]);		    
				    			if (s == 0)
				    			{
				    				flag = 1;
				    				string =token[i];
				    			}
				    			i++;
				    			token[i] = strtok(NULL," ");
				    					    	
				       		}
				       		
				       		
				      		if(flag == 1)
				        	{
				        		for(j = 0; j < i; j++)
				       			{	
				       				
				       				if(strcmp(string, token[j]) == 0)
				       				{
				       		     			printf(ANSI_COLOR_RED "%s ",token[j]);
				    		     			printf(ANSI_COLOR_RESET);
				    				}
				    				else
				    	     			printf("%s ",token[j]);
				       			}
			
							printf("\n");
						}
					}
					fclose(fp);
				}
				break;
			
			case'q' :
				printf("Quiet\n");
				break;				
			
			default :
				printf("Match not found");
			        break;
			}	/*end switch*/       
	return 0;
	} /*end else*/ 
}/*end main*/

				
		

