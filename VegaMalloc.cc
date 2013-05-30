/*
 * VegaMalloc.cc
 *
 *  Created on: 2013-5-30
 *      Author: luliang
 */

#include <stdlib.h>

void *vegaMalloc(size_t size)
{
  return malloc(size);
}
void vegaFree(void *ptr)
{
	free(ptr);
}
void *vegaCalloc(size_t nmemb, size_t size)
{
	return calloc(nmemb, size);
}
void *vegaRealloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}

