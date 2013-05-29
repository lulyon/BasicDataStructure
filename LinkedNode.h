/*
 * LinkedNode.h
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */

#ifndef LINKEDNODE_H_
#define LINKEDNODE_H_

#include "DataModelHeader.h"

class LinkedNode {
public:
  LinkedNode();
	LinkedNode(DataModel &);
	explicit LinkedNode(LinkedNode &);
	~LinkedNode();

	bool operator==(LinkedNode &) const;
	LinkedNode *getNextNode();
	void setNextNode(LinkedNode *);
	DataModel &getData();
private:
	void operator=(const LinkedNode &);
	LinkedNode *next_;
	DataModel data_;
};


#endif /* LINKEDNODE_H_ */
