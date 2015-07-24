#include<stdlib.h>
#include<stdio.h>

#include "answer06.h"





SparseNode * SparseNode_create(int index, int value);
{
	if(value == 0)
	{    	
	return NULL;
  	{
	SparseNode * group = malloc(sizeof(SparseNode));  
  	group->index = index;
  	group->value = value;
  	group->right = NULL;
  	group->left = NULL;
  	return spot;
}


SparseNode * SparseArray_insert(SparseNode * array, int index, int value);
{	
  	if(value == 0)
	{
 	return array;
	}
  	if(array == NULL) 
	{
	return SparseNode_create(index, value);
	{
  	if(array->index == index)
	{
    	array->value = value;
	return array;
  	}
  	if(array->index > index)
	{
        array->left = SparseArray_insert(array->left, index, value);
  	}
  	else if(array->index < index)
	{
        array->right = SparseArray_insert(array->right, index, value);
  	}
  	return array;
}


SparseNode * SparseArray_build(int * indices, int * values, int length);
{
  	SparseNode * group = NULL;
  	int i;
	i=0;
  	//for(i=0;i<length;i++)
	while(i<length)
    	{
      	if(values[i] != 0)
	{
	group = SparseArray_insert(group, indices[i], values[i]);
	}
	i++;
    	}
  	return group;
}

void SparseArray_destroy(SparseNode * array); 
{
  	if(array == NULL) 
	{	
	return;
	}
  	SparseArray_destroy(array->right);
  	SparseArray_destroy(array->left);
  	free(array);
}

int SparseArray_getMin(SparseNode * array);
{
  	if(array->left == NULL) 
	{	
	return (array->index);
	}  	
	return SparseArray_getMin(array->left);
}

int SparseArray_getMax(SparseNode * array);
{
  	if(array->right == NULL) 
	{	
	return (array->index);
	}  	
	return SparseArray_getMax(array->right);
}

SparseNode * SparseArray_getNode(SparseNode * array, int index);
{
  	if(array == NULL) 
	{	
	return NULL;
  	}
	if(array->index == index) 
	{
	return array;
 	} 	
	if(array->index > index)
	{
    	return SparseArray_getNode(array->left, index);
  	}
    	return SparseArray_getNode(array -> right, index);  	
}

SparseNode * SparseArray_remove(SparseNode * array, int index);
{
  	if(array == NULL) 
	{
	return NULL;
	}
  	if(array -> index > index)
	{
   	array -> left = SparseArray_remove(array -> left, index);
  	}
  	else if(array -> index < index)
	{
        array -> right = SparseArray_remove(array -> right, index);
  	}
  	if(array -> index == index)
	{
    		if((array -> left == NULL) && (array -> right == NULL))
		{
      		free(array);
      		return NULL;
    		}
    		else if((array -> left != NULL) && (array -> right == NULL))
		{
        	array = array -> left;
      		return array;
    		}
    		else if((array -> left == NULL) && (array -> right != NULL))
		{
   	      	array = array -> right;
      		return array;
    		}
    		else if((array -> left != NULL) && (array -> right != NULL))
		{
      		SparseNode * temp = NULL;
      		temp = SparseArray_getNode(array -> right, SparseArray_getMin(array -> right));
            	temp -> left = array -> left;
      		return temp;
    		}  
  	}
	return array;
}

SparseNode * SparseArray_copy(SparseNode * array);


SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2);
