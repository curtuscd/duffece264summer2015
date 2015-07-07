#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{

size_t lensrc;
lensrc = 0;
size_t lendest;
lendest = 0;

if(src != NULL)
{
lensrc = strlen(src);
}

if(*dest != NULL)
{
lendest = *dest==NULL ? 0 : strlen(*dest); 
}

if(*dest == NULL || lensrc + lendest + 1 >= *n)
{
      	*n=1 + (2 * (lendest + lensrc));
      	char *nothing = malloc(*n * sizeof(char));
      	*nothing='\0';
      
	if(*dest! = NULL)
	{
	strcpy(nothing,*dest);
	}
      	
	free(*dest);
      	*dest = nothing;
}

strcat(*dest,src);
 
return *dest;
}


char * * explode(const char * str, const char * delims, int * arrLen)
{



}


char * implode(char * * strArr, int len, const char * glue)
{



}


void sortStringArray(char * * arrString, int len)
{



}

void sortStringCharacters(char * str)
{



}

void destroyStringArray(char * * strArr, int len)
{



}


