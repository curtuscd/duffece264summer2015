
#include "answer01.h"

// NOTE: You are NOT to use the strings library on this assignment,
// as stated in the README.

// DO NOT BEGIN WORKING ON THIS FILE UNTIL YOU HAVE COMPLETELY AND
// THOROUGHLY READ THE README FILE!!!

int arraySum(int * array, int len)
{
	int sum;
	int i;
	sum = 0;
	for(i=0; i < len; i++) 
	{
		sum = sum + array[i];
	}
return(sum);
}

int arrayCountNegative(int * array, int len)
{
	int countnegs;
	int i;
	countnegs = 0;
	for(i=0; i < len; i++)
	{
		if(array[i] < 0)
		{
		countnegs = countnegs + 1;
		}
	}
    return(countnegs);
}


int arrayIsIncreasing(int * array, int len)
{    
	int boolean;
	int i;
	boolean = 1;
	
	for(i=0; i < len; i++)
	{
		if(array[i+1] < array[i])
		{
		boolean = 0;
		}
		//else if(array[i] == NULL)
		//{
		//boolean = 1;
		//}
	}
	
    return(boolean);
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
	int notfind;
	int index;
	int i; 
	notfind = 0;
	for(i=0; i < len; i++)
	{
		if(haystack[i] == needle)
		{
		index = i;
		notfind++;
		}
	}
	if(notfind == 0)
		{
		index = -1;
		}
    return(index);
}

int arrayFindSmallest(int * array, int len)
{
	int small_index;
	int i;
	if(len == 0)
	{
	small_index = 0;
	}
	else if(len > 0)
	{
	for(i=len-2; i>=0; i--)
	{	
		small_index = len-1;	
		if(array[i+1] < array[i]) && array[i+1] < array[small_index])
		{
		small_index = i+1;
		}
 	}
	
    return(small_index);
}

size_t my_strlen(const char * str)
{
	int length;	
	int i;
	length = 0;
	for(i=0; str[i] != '\0'; i++)
	{
	length = length + 1;
	}
    return(length);
}

char * my_strchr(const char * str, int ch)
{
	int length; 
	length = my_strlen(str);
	int i;
	if(length == 0)
	{
		if(ch=='\0'){
		return char * str;
		}
	}
	for(i=0; i<length; i++)
	{
		if(ch=='\0'){ 
		return char * (str+length);
		}
		else if(*(str+i)==ch){
		return char * (str+i);
		}
	{

    return NULL;
}

char * my_strstr(const char * haystack, const char * needle)
{
	int a,b,c;
	a=0;
	b=0;
	c=0;
	int hay_length;
	int needle_length;
	hay_length = my_strlen(haystack);
	needle-length = my_strlen(needle);

	if(needle-length == 0)
	{
      	return char * (haystack+i);
    	}

  	for(a=0;a<hay_length;a++)
    		{
      		if(*(haystack+a)==*(needle+b))
		{
	  		for(c=i;c<hay_length;c++)
	   		{
	      			if(*(haystack+c) == (*(needle+b)))
				{
		  			if(b==needle_length-1)
		    				{
		      					return char * (haystack+(c-b));
		    				}
		  					b = b+1;
				}
	      			else
				{
		 			break;
				}
	    		}	
		}
    	}
	
    return NULL;
}

char * my_strcpy(char * dest, const char * src)
{
	int i = 0;
  	int length = my_strlen(src);
  	if(length==0)
    	{
      		dest[i]='\0';
      		return (char *) dest;
    	}
  	for(i=0;i<length;i++)
    	{
      		dest[i] = src[i];
    	}
  	dest[i]='\0';
  return (char *) dest;

}

char * my_strcat(char * dest, const char * src)
{
  	int i = 0;
  	int src_lenth = my_strlen(src);
  	int dest_length = my_strlen(dest);
  	for(i=0;i<src_length;i++)
    	{
      		dest[(dest_length+i)]=src[i];
    	}
  	dest[src_length+dest_length]='\0';
  return (char *) dest;
}
   

int my_isspace(int ch)
{
   	if(ch==' ' || ch=='\f' || ch=='\n' || ch=='\r' || ch=='\t' || ch=='\v')
    	{
      		return 1;
    	}
  return 0;
}

int my_atoi(const char * str)
{
  	int i=0;
  	int negative=0;
  	int ret=0;
 	while(my_isspace(str[i])==1)
    	{
      		i++;
    	}
  		if(str[i]=='-')
    		{
      			negative=1;
      			i++;
    		}
	
	while('0'<=str[i] && str[i]<='9')
    	{
      		ret *= 10;
      		ret+=(str[i]-'0');
      		i++;
    	}
  		if(negative==1)
    		{
      			return(-ret);
    		}
  	
	return(ret);
}

