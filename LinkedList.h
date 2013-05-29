/*
 * LinkedList.h
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedNode;

class LinkedList {
public:
  LinkedList();
	explicit LinkedList(LinkedList &);
	~LinkedList();

	int getLength();
	LinkedNode * getFirst();
	void add(LinkedNode *);
	LinkedNode *find(LinkedNode *);
	void findAndDelete(LinkedNode *);

private:
	void operator=(LinkedList &);
	void operator==(LinkedList &);
	int length_;
	LinkedNode * head_;
};


#endif /* LINKEDLIST_H_ */
