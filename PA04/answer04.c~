#include "answer04.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>
#include <math.h>

  


Image * SetFree(FILE *fpointer, Image * picture)
{
	if(fpointer != NULL)
	{
	fclose(fpointer);
	}
	
	if(picture != NULL)
	{
		if(picture->data != NULL)
		{
		free(picture->data);
		}
		if(picture->comment != NULL)
		{
		free(picture->comment);
		}

		free(picture);
	}
	return NULL;
}

/*
int checkheader(ImageHeader * header)
{
	if((header -> magic_number) != ECE264_IMAGE_MAGIC_NUMBER)
	{
		return 0;
	}
	if((header -> height) == 0)
	{
		return 0;
	}
	if((header -> width) == 0)
	{
		return 0;
	}
	if(((header -> comment_len) - 1) == 0)
	{
		return 0;
	}
	return 1;

}


*/

Image * Image_load(const char * filename)
{
	FILE *fpointer = NULL;
	Image *picture = NULL;
	ImageHeader heading;
	int checker; 
	checker = 0;

	
	fpointer = fopen(filename, "rb");
	if(fpointer == NULL)
	{
	return SetFree(fpointer,picture);
	}
	
	
	if(fread(&(heading),sizeof(ImageHeader),1,fpointer) != 1)
	{
	return SetFree(fpointer,picture);
	}
/*	
	if(checkheader(&heading) == 0)
	{
		return SetFree(fpointr,picture);
	}
*/
	if((heading->magic_number) != ECE264_IMAGE_MAGIC_NUMBER)
	{
	checker = 1;
	}

/*	if((heading -> width) == 0)
	{
	checker = 1;
	}
*/	
	if(((heading->comment_len) - 1) == 0)
	{
	checker = 1;
	}
	if((heading->height) == 0 || (heading -> width) == 0)
	{
	checker = 1;
	}
	
	if(checker == 1)
	{
	return SetFree(fpointer,picture);
	}

 
	picture = malloc(sizeof(Image));
	
	if(picture == NULL)
	{
	return SetFree(fpointer,picture);
	}
	
	picture->height = heading.height;
	picture->width = heading.width;
	
	picture->comment = NULL;
	picture->data = NULL;
	picture->comment = malloc(sizeof(char) * heading.comment_len);
	
	
	if(picture->comment == NULL)
	{
	return SetFree(fpointer,picture);
	}
	if(fread((picture->comment), sizeof(char),heading.comment_len,fpointer) != (heading.comment_len))
	{
	return SetFree(fpointer,picture);
	}
	if(picture->comment[heading.comment_len - 1] != '\0')
	{
	return SetFree(fpointer,picture);
	}
	
	picture->data = malloc(sizeof(uint8_t) * heading.width * heading.height);
	
	if(picture->data == NULL)
	{
	return SetFree(fpointer,picture);
	}
	
	
	int howmanybytes;
	howmanybytes = sizeof(uint8_t) * heading.width * heading.height;
	if(fread(picture -> data, sizeof(uint8_t), howmanybytes, fpointer) != (howmanybytes))
	{
	return SetFree(fpointer,picture);
	}

	
	uint8_t unit;
	if(fread((&unit),sizeof(uint8_t),1,fpointer) != 0)
	{
	return SetFree(fpointer,picture);
	}

	fclose(fpointer);
	return picture;

	
}


int Image_save(const char * filename, Image * image)
{
  	FILE * fpointer;
	fpointer = fopen(filename, "w");
  	ImageHeader heading;

  	heading.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  	heading.width = image->width;
  	heading.height = image->height;
  	heading.comment_len = strlen(image->comment) + 1;

  	fwrite(&heading, sizeof(ImageHeader), 1, fpointer);
  	fprintf(fpointer,"%s%c", image->comment, '\0');
  	
	if(fpointer == NULL)
	{
	return 0;
	}

  	int i;
  	i=0;
	while(i<image->height*image->width)
	{	
	fprintf(fpointer, "%c", image->data[i]);
	i++;
	}
	
/*
	for(i = 0; i < image->width * image->height; i++)
    	{
      	fprintf(fptr, "%c", image->data[i]);
    	}
*/
  	fclose(fpointer);
  return 1;
}

void Image_free(Image * image)
{
  free(image->comment);
  free(image->data);
  free(image);
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
  	int i;
  	uint8_t maximum;
  	uint8_t minimum;
  	maximum = intensity[0];
  	minimum = intensity[0];
/*	
  	for(i=1; i < height * width; i++)
    	{
      		if(intensity[i] > max)
		{
	  	max = intensity[i];
		}
      		if(intensity[i] < min)
		{
	  	min = intensity[i];
		}
    	}
 
  	for(i = 0; i < height * width; i++)
    	{
      		intensity[i] = (intensity[i] - min) * 255 / (max - min);
    	}
*/
	i=1;
  	while(i<width*height)
    	{
      		if(intensity[i]<minimum)
		{
	  	minimum = intensity[i];
		}
      		if(intensity[i]>maximum)
		{
	  	maximum = intensity[i];
		}
	i++;
    	}

	i=0;
	while(i<width*height)
	{
	intensity[i] = (intensity[i] - minimum) * 255 / (maximum - minimum);
	i++;
	}
}

