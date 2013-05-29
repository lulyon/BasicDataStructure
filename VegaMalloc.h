/*
 * VegaMalloc.h
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#ifndef VEGAMALLOC_H_
#define VEGAMALLOC_H_

void *vegaMalloc(size_t size);
void vegaFree(void *ptr);
void *vegaCalloc(size_t nmemb, size_t size);
void *vegaRealloc(void *ptr, size_t size);

#endif /* VEGAMALLOC_H_ */
