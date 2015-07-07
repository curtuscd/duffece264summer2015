#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{
size_t src_len = strlen(src);
size_t len_dest = *dest==NULL ? 0 : strlen(*dest); 
  if(*dest == NULL || len_src + len_dest + 1 >= *n)
    {
      *n=1 + (2 * (len_dest + len_src));
      char *buffer = malloc(*n * sizeof(char));
      *buffer='\0';
      if(*dest!=NULL)
	{
	  strcpy(buffer,*dest);
	}
      free(*dest);
      *dest = buffer;
    }
  strcat(*dest,src);
  return *dest;
}


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


