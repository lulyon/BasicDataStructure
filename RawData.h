/*
 * RawData.h
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#ifndef RAWDATA_H_
#define RAWDATA_H_

class RawData {
public:
  RawData();
	RawData(const void *, int);
	explicit RawData(const RawData &);
	~RawData();

	void operator=(const RawData &);
	bool operator==(const RawData &) const;

	int getLength() const;
	const void *getData() const;
	bool isEmpty() const;

	static bool rawCompare(const void *, const void *, int) const;
private:
	int length_;
	void *ptr_;
};


#endif /* RAWDATA_H_ */
