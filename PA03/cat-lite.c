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

int concatenate(const char * name, FILE *foutput)
{
	FILE *finput;
	int standard_in;
	standard_in = strcmp(name,"-") == 0;
 
	if(standard_in)
  	{
    	finput = stdin;
  	}
 	else
  	{
    	finput = fopen(name, "r");
  	}

  	if (finput == NULL)
  	{
    	return 0;
  	}

  	int ch;
  	while ((ch = fgetc(finput)) != EOF)
	{
    	fputc(ch, foutput);
  	}

  	if(!standard_in)
	{
    	fclose(finput);
	}
  	return 1;
}





int main(int argc, char **argv)
{	
	int i;
  	for(i = 1;i < argc;i++)
 	{
    	if(strcmp(argv[i],"--help") == 0)
    	{
      	helpstatement();
      	return EXIT_SUCCESS;
    	}
  	}

	for(i=1;i < argc;i++)
	{
	if(concatenate(argv[i],stdout) == 0)
    	{
      	fprintf(stderr,"cat cannot open %s\n",argv[i]);
      	return EXIT_FAILURE;
    	}
  	}
  return 0;
	

}

