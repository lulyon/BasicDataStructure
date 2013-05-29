/*
 * LinkedNode.cc
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */


#include "LinkedNode.h"
#include "DataModel.h"

LinkedNode::LinkedNode(): next_(0)
{

}

LinkedNode::LinkedNode(DataModel &data):next_(0), data_(data)
{
}

LinkedNode::LinkedNode(LinkedNode & node):next_(0), data_(node.getData())
{

}

LinkedNode::~LinkedNode()
{

}

bool LinkedNode::operator==(LinkedNode & node) const
{
  if(this == &node) return true;
	if(data_ == node.getData()) return true;
	return false;
}

LinkedNode *LinkedNode::getNextNode()
{
	return next_;
}

void LinkedNode::setNextNode(LinkedNode *node)
{
	next_ = node;
}

DataModel &LinkedNode::getData()
{
	return data_;
}
