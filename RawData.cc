/*
 * RawData.cc
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#include "RawData.h"

#include <string.h>
#include <assert.h>

#include "VegaMalloc.h"

RawData::RawData():length_(0), ptr_(0)
{

}

RawData::RawData(const void *ptr, int length)
{
  length_ = length;
	ptr_ = vegaMalloc(length_);
	assert(ptr_);

	memcpy(ptr_, ptr, length_);
}

RawData::RawData(const RawData & data)
{
	if(this == &data) {
		length_ = 0;
		ptr_ = 0;
		return;
	}
	length_ = data.getLength();
	ptr_ = vegaMalloc(length_);
	assert(ptr_);

	memcpy(ptr_, data.getData(), length_);
}

RawData::~RawData()
{
	if(ptr_ ) vegaFree(ptr_);
}

void RawData::operator=(const RawData &data)
{
	if(this == &data) return;

	if(ptr_) vegaFree(ptr_);

	length_ = data.getLength();
	ptr_ = vegaMalloc(length_);
	assert(ptr_);

	memcpy(ptr_, data.getData(), length_);
}

bool RawData::rawCompare(const void *ptr1, const void *ptr2, int length) const
{
	const char * p1 = static_cast<const char *>(ptr1);
	const char * p2 = static_cast<const char *>(ptr2);
	for(int i = 0; i < length; ++i) {
		if(!p1 || !p2 || p1 != p2)return false;
		++p1;
		++p2;
	}
	return true;
}

bool RawData::operator==(const RawData &data) const
{
	if(this == &data) return true;
	if(length_ != data.getLength()) return false;
	return rawCompare(ptr_, data.getData(), length_);
}

int RawData::getLength() const
{
	return length_;
}

const void *RawData::getData() const
{
	return ptr_;
}

bool RawData::isEmpty() const
{
	if(ptr_)return false;
	return true;
}
