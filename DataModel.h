/*
 * DataModel.h
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#ifndef DATAMODEL_H_
#define DATAMODEL_H_

class RawData;

class KeyValue {
public:
  KeyValue();
	KeyValue(RawData &, RawData &);
	explicit KeyValue(KeyValue &);
	~KeyValue();

	bool isEmpty();
	RawData & getKey();
	RawData & getValue();

	bool operator==(KeyValue &) const;
private:
	void operator=(const KeyValue &);
	RawData key_;
	RawData value_;
};


#endif /* DATAMODEL_H_ */
