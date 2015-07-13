#include <stdlib.h>
#include <string.h>

void helpstatement()
{
  printf("Usage: cat-lite [--help] [FILE]...\n"
	"With no FILE, or when FILE is -, read standard input.\n\n"
	"Examples:\n"
  	"  cat-lite README   Print the file README to standard output.\n"
  	"  cat-lite f - g    Print f's contents, then standard input,\n"
  	"                    then g's contents.\n"
  	"  cat-lite          Copy standard input to standard output.\n");
}

int main(int argc, char **argv)
{	
	int i;
  	for(i = 1; i < argc; i++)
 	{
    	if(strcmp(argv[i],"--help") == 0)
    	{
      	helpstatement();
      	return EXIT_SUCCESS;
    	}
  	}







}

