#include<stdlib.h>
#include<stdio.h>

#include "answer06.h"





SparseNode * SparseNode_create(int index, int value);
{
	if(value == 0)
	{    	
	return NULL;
  	{
	SparseNode * spot = malloc(sizeof(SparseNode));  
  	spot->index = index;
  	spot->value = value;
  	spot->right = NULL;
  	spot->left = NULL;
  	return spot;
}


SparseNode * SparseArray_insert(SparseNode * array, int index, int value);


SparseNode * SparseArray_build(int * indices, int * values, int length);


void SparseArray_destroy(SparseNode * array);


int SparseArray_getMin(SparseNode * array);


int SparseArray_getMax(SparseNode * array);


SparseNode * SparseArray_getNode(SparseNode * array, int index);


SparseNode * SparseArray_remove(SparseNode * array, int index);


SparseNode * SparseArray_copy(SparseNode * array);


SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2);
