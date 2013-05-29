/*
 * DoubleLinkedList.h
 *
 *  Created on: 2013-5-29
 *      Author: luliang
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

class DoubleLinkedNode;

class DoubleLinkedList {
public:
  DoubleLinkedList();
	explicit DoubleLinkedList(DoubleLinkedList &);
	~DoubleLinkedList();

	int getLength();
	DoubleLinkedNode * getFirst();
	DoubleLinkedNode * getLast();
	void add(DoubleLinkedNode *);
	DoubleLinkedNode *find(DoubleLinkedNode *);
	void findAndDelete(DoubleLinkedNode *);

private:
	void operator=(DoubleLinkedList &);
	void operator==(DoubleLinkedList &);
	int length_;
	DoubleLinkedNode * head_;
	DoubleLinkedNode * tail_;
};


#endif /* DOUBLELINKEDLIST_H_ */
