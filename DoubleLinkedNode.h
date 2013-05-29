/*
 * DoubleLinkedNode.h
 *
 *  Created on: 2013-5-29
 *      Author: luliang
 */

#ifndef DOUBLELINKEDNODE_H_
#define DOUBLELINKEDNODE_H_

#include "DataModelHeader.h"

class DoubleLinkedNode {
public:
  DoubleLinkedNode();
	DoubleLinkedNode(DataModel &);
	explicit DoubleLinkedNode(DoubleLinkedNode &);
	~DoubleLinkedNode();

	bool operator==(DoubleLinkedNode &) const;
	DoubleLinkedNode *getPreNode();
	DoubleLinkedNode *getNextNode();
	void setPreNode(DoubleLinkedNode *);
	void setNextNode(DoubleLinkedNode *);
	DataModel &getData();
private:
	void operator=(const DoubleLinkedNode &);
	DoubleLinkedNode *pre_;
	DoubleLinkedNode *next_;
	DataModel data_;
};


#endif /* DOUBLELINKEDNODE_H_ */
