/*
 * HashTable.h
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

class LinkedList;

class Hashtable {
public:
  Hashtable();
	Hashtable(int);
	explicit Hashtable(Hashtable &);
	~Hashtable();

	int getLength();
	LinkedList *getEntry(int);
private:
	void operator=(const Hashtable &);
	void operator==(const Hashtable &);
	int length_;
	LinkedList **entry_;
};

#endif /* HASHTABLE_H_ */
