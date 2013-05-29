/*
 * HashTable.cc
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#include "HashTable.h"

#include <assert.h>

Hashtable::Hashtable() :
  	length_(0), entry_(0) {
}

Hashtable::Hashtable(int length) {
	length_ = length;
	entry_ = new LinkedList*[length_];
}

Hashtable::Hashtable(Hashtable &table)
{
	length_ = table.getLength();
	entry_ = new LinkedList *[length_];
	for(int i = 0; i < length_; ++i) {
		entry_[i] = new LinkedList(*(table.getEntry(i)));
	}
}

Hashtable::~Hashtable() {
	for(int i = 0; i < length_; ++i) {
		if(entry_[i])delete entry_[i];
	}
	if (entry_)
		delete[] entry_;
}


int Hashtable::getLength()
{
	return length_;
}
LinkedList *Hashtable::getEntry(int n)
{
	assert((n>=0) && (n<length_));
	return entry_[n];
}
