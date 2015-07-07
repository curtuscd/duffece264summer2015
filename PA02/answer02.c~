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

int i;
i = 0;
int position;
position = 0;

while(str[position] != '\0')
{
	if(strchr(delims,str[position]) != NULL)
	{
	i++;
	}
	position++
}
char **strArr = malloc((i+1) * sizeof(char *));

int next;
next = 0;
const char *start = str;
position = 0;

while(str[position] != '\0')
{
	if (strchr(delims, str[position]))
	{
	  int length;
	  length = position - start;
	  strArr[next] = malloc((length+1) * sizeof(char));
	  memcpy(strArr[next], start, length * sizeof(char));
	  strArr[next][length] = '\0';
	  next++;
	  start = position+1;
	}
      	position++;
}

int length = position-start;
strArr[ind] = malloc((length+1) *sizeof(char));
memcpy(strArr[next], start, length * sizeof(char));
strArr[next][length] = '\0';

*arrLen = i+1;

return strArr; 


}


char * implode(char * * strArr, int len, const char * glue)
{

int i;
char * outcome = NULL;
int length;
length = 0;

for(i=0; i < len; i++)
{
strcat_ex(&outcome, &length, strArr[i]);
	if(i != len-1)
	{
	strcar_ex(&outcome, &length, glue);
	}
]

return outcome;

}

int compareSTR(const void * first, const void * second)
{
  const char **ind1 = (const char **) first;
  const char **ind2 = (const char **) second;
  return strncmp(*ind1, *ind2);
}

void sortStringArray(char * * arrString, int len)
{



}

int compareCHAR(const void * first, const void * second)
{
  const char *charfirst = (const char **) first;
  const char *charsecond = (const char **) second;
  return strncmp(*charfirst - *charsecond);
}

void sortStringCharacters(char * str)
{



}

void destroyStringArray(char * * strArr, int len)
{



}


