/*
 * DataModel.cc
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */
#include "DataModel.h"
#include "RawData.h"

KeyValue::KeyValue()
{
}

KeyValue::KeyValue(RawData &key, RawData &value): key_(key), value_(value)
{
}

KeyValue::KeyValue(KeyValue &kv): key_(kv.getKey()), value_(kv.getValue())
{
}

KeyValue::~KeyValue()
{
}

RawData & KeyValue::getKey()
{
  return key_;
}

RawData & KeyValue::getValue()
{
	return value_;
}

bool KeyValue::operator==(KeyValue &kv) const
{
	if(this == &kv) return true;
	if(kv.getKey() == key_) return true;
	return false;
}
