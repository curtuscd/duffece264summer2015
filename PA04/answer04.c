#include "answer04.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>




Image * Image_load(const char * filename);
{
  FILE * fptr = NULL;
  int var_read;
  ImageHeader head;

  size_t Num_bytes = 0;
  Image * image = NULL;
  Image * image_temp = NULL;
  
  fptr = fopen(filename, "r");
  if(fptr == NULL)
    {
      return image;
    }
  
  var_read = fread(&head, sizeof(ImageHeader),1,fptr);
  if(var_read == 0){
    fclose(fptr);
    return image;
  }

  if(head.height == 0 || head.width == 0)
    {
      fclose(fptr);
      return image;
    }

  if(ECE264_IMAGE_MAGIC_NUMBER != head.magic_number)
    {
      fclose(fptr);
      return image;
    }

  if(head.comment_len == 0)
    {
      fclose(fptr);
      return image;
    }
  
  char * arr_Com = malloc(head.comment_len * sizeof(char));
  if(arr_Com == NULL)
    {
      fclose(fptr);
      free(arr_Com);
      return image_temp;
    }
  
  var_read = fread(arr_Com, head.comment_len, 1, fptr);
  if(head.comment_len != var_read)
    {
      fclose(fptr);
      free(arr_Com);
      return image_temp;
    }
  
  if(arr_Com[head.comment_len - 1] != '\0')
    {
      fclose(fptr);
      free(arr_Com);
      return image;
    }
  
  Num_bytes = sizeof(uint8_t) * head.height * head.width;
  image = malloc(sizeof(Image));
  image->comment = malloc(sizeof(char)*(strlen(arr_Com) + 1));
  image->height = head.height;
  image->width = head.width;
  strcpy(image->comment, arr_Com);
  image->data = malloc(Num_bytes);
  if(image->data == NULL)
    {
      Image_free(image);
      fclose(fptr);
      return image_temp;
    } 
  
  var_read = fread(image->data, sizeof(uint8_t), Num_bytes, fptr);

  if(var_read != Num_bytes)
    {
      Image_free(image);
      free(arr_Com);
      fclose(fptr);
      return image_temp;
    }

  uint8_t bytes;
  
  var_read = fread(&bytes, sizeof(uint8_t), 1, fptr);

  if(var_read != 0)
    {
      Image_free(image);
      free(arr_Com);
      fclose(fptr);
      return image_temp;
    }
   
  free(arr_Com);
  fclose(fptr);
  return(image);
}

int Image_save(const char * filename, Image * image);
{
  FILE * fptr = fopen(filename, "w");
  ImageHeader head;

  head.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  head.width = image->width;
  head.height = image->height;
  head.comment_len = strlen(image->comment) + 1;

  fwrite(&head, sizeof(ImageHeader), 1, fptr);
  fprintf(fptr,"%s%c", image->comment, '\0');
  

  int i;
  for(i = 0; i < image->width * image->height; i++)
    {
      fprintf(fptr, "%c", image->data[i]);
    }
  
  fclose(fptr);
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
  uint8_t max;
  uint8_t min;

  max = intensity[0];
  min = max;
  
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
}

