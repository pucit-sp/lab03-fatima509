/*
**	This program is a template for SP lab 3 task 3 you are 
**	required to implement its one function.
*/


#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
*/
void mygrep(FILE*, char*);

/*	
**	This function take file pointer as paramter to read content from and 
**	char pointer as an second argument which points to string to search in file
** 	and char pointer as an third argument to replace the string finded with it.
*/
void myreplace(FILE *fp,char *find, char * replace);


int  main(int argc,char *argv[])
{
	int behaviour;
	FILE *fp;
	char *filename=argv[1];
	char *find=argv[2];
	char * replace;

	if( strcmp(argv[0],"./mygrep") == 0 )
	{
		if(argc != 3)
		{
			printf("usage\t./mygrep filename <string-to-search>\n");
			exit(1);
		}

		behaviour = 0;
	}
	else if( strcmp(argv[0],"./myreplace") == 0 )
	{
		if(argc != 4)
		{
			printf("\t./myreplace filename  <string-to-search> <string-to-replace>\n");
			exit(1);
		}
		behaviour = 1;
		replace = argv[3];
	}
	else
	{
		behaviour = -1;
	}


	fp=fopen(filename,"rt");

	if(behaviour == 0)
	{
		mygrep(fp,find);		
	}
	else if ( behaviour == 1 )
	{
		myreplace(fp,find,replace);
	}
	
	//fclose(fp);
	return 0;
}


void mygrep(FILE *fp,char *find)
{
	char c1[500];

	if (fp == NULL)
	{
        	printf("Could not open file");
    	}
    	
	else
	{
		while (fgets(c1, 500, fp) != NULL)
		{	
			if(strstr(c1,find) != NULL)
				printf("%s\n",c1);
		}
	}
}



void myreplace(FILE *fp,char *find, char * replace)
{
	char c1[500],*temp, *pos;
	int flen = strlen(find),i,j,k;
	int status=0;

	while( fgets(c1, 500, fp) != NULL )
	{
		if(status == 0)
		{
			pos = strstr(c1,find);
			if( pos != NULL)
			{
				for(int j=0;j<strlen(c1);j++)
				{
					if(pos == &c1[j])
						k=j;
				}
				printf("Original: %s",c1);
				pos=pos-flen;
				for(i=k,j=0; i<k+flen; i++,j++)
				{
					c1[i]=replace[j];
				}
				printf("Replaced: %s\n",c1);
				status=1;
			}
		}
	}
}


