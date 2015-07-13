#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void helpstatement()
{
  printf("Usage: grep-lite [OPTION]... PATTERN\n"
	 "Search for PATTERN in standard input. PATTERN is a\n"
	 "string. grep-lite will search standard input line by\n"
	 "line, and (by default) print out those lines which\n"
 	 "contain pattern as a substring.\n\n"

	 "  -v, --invert-match     print non-matching lines\n"
	 "  -n, --line-number      print line number with output\n"
	 "  -q, --quiet            suppress all output\n\n"

 	 "Exit status is 0 if any line is selected, 1 otherwise;\n"
	 "if any error occurs, then the exit status is 2.\n");
}



int main(int argc, char ** argv)
{
	int i;
	int invert_match;
	int line_number;
	int quiet;
   	i = 0;
	invert_match = 0;
	line_number = 0;
	quiet = 0;

  	for(i = 1;i < argc;i++)
    	{
      		if(argv[i],"--help") == 0)
		{
		helpstatement();
		return EXIT_SUCCESS;
		}
	}	
	
	for(i=1;i < argc-1;i++)
	{
		
      		if(!strcmp(argv[i],"-v") || !strcmp(argv[i], "--invert-match"))
		{
	  	invert_match = 1;
		}
                else if(!strcmp(argv[i],"-q") || !strcmp(argv[i], "--quiet"))
		{
	  	quiet = 1;
		}
      		else if(!strcmp(argv[i],"-n") || !strcmp(argv[i], "--line-number"))
		{
	  	line_number = 1;
		}
		else if(invert_match != 1 && quiet != 1 && line_number != 1)
		{
		fprintf(stderr,"Bogus command-line arguement %s\n", argv[i]);
		}
    	}
		if(argv[i][0] == '-')
		{
	  	fprintf(stderr,"Pattern can't start with '-'%s\n", argv[i]);
	  	return 2;
		}























