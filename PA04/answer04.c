#include "answer04.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>




Image * Image_load(const char * filename);
{
  FILE * fpointer = NULL;
  ImageHeader heading;
  Image * image = NULL;
  Image * image_temp = NULL;
  size_t howmanybytes = 0;
  int readit;
  
  fpointer = fopen(filename, "r");
  if(fpointer == NULL)
    {
      return image;
    }
  
  readit = fread(&heading, sizeof(ImageHeader),1,fpointer);
  if(readit == 0){
    fclose(fpointer);
    return image;
  }

  if(heading.height == 0 || heading.width == 0)
    {
      fclose(fpointer);
      return image;
    }

  if(ECE264_IMAGE_MAGIC_NUMBER != heading.magic_number)
    {
      fclose(fpointer);
      return image;
    }

  if(heading.comment_len == 0)
    {
      fclose(fpointer);
      return image;
    }
  
  char * arr_Com = malloc(heading.comment_len * sizeof(char));
  if(arr_Com == NULL)
    {
      fclose(fpointer);
      free(arr_Com);
      return image_temp;
    }
  
  readit = fread(arr_Com, heading.comment_len, 1, fpointer);
  if(heading.comment_len != readit)
    {
      fclose(fpointer);
      free(arr_Com);
      return image_temp;
    }
  
  if(arr_Com[heading.comment_len - 1] != '\0')
    {
      fclose(fpointer);
      free(arr_Com);
      return image;
    }
  
  howmanybytes = sizeof(uint8_t) * heading.height * heading.width;
  image = malloc(sizeof(Image));
  image->comment = malloc(sizeof(char)*(strlen(arr_Com) + 1));
  image->height = heading.height;
  image->width = heading.width;
  strcpy(image->comment, arr_Com);
  image->data = malloc(howmanybytes);
  if(image->data == NULL)
    {
      Image_free(image);
      fclose(fpointer);
      return image_temp;
    } 
  
  readit = fread(image->data, sizeof(uint8_t), howmanybytes, fpointer);

  if(readit != howmanybytes)
    {
      Image_free(image);
      free(arr_Com);
      fclose(fpointer);
      return image_temp;
    }

  uint8_t bytes;
  
  readit = fread(&bytes, sizeof(uint8_t), 1, fpointer);

  if(readit != 0)
    {
      Image_free(image);
      free(arr_Com);
      fclose(fpointer);
      return image_temp;
    }
   
  free(arr_Com);
  fclose(fpointer);
  return(image);
}

int Image_save(const char * filename, Image * image);
{
  	FILE * fpointer = fopen(filename, "w");
  	ImageHeader heading;

  	heading.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  	heading.width = image->width;
  	heading.height = image->height;
  	heading.comment_len = strlen(image->comment) + 1;

  	fwrite(&heading, sizeof(ImageHeader), 1, fptr);
  	fprintf(fpointer,"%s%c", image->comment, '\0');
  	
	if(fpointer = NULL)
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

void Image_free(Image * image);
{
  free(image->comment);
  free(image->data);
  free(image);
}

void linearNormalization(int width, int height, uint8_t * intensity);
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

