/*
 * DoubleLinkedNode.cc
 *
 *  Created on: 2013-5-29
 *      Author: luliang
 */

#include "DoubleLinkedNode.h"
#include "DataModel.h"


DoubleLinkedNode::DoubleLinkedNode(): pre_(0), next_(0)
{

}

DoubleLinkedNode::DoubleLinkedNode(DataModel &data):pre_(0), next_(0), data_(data)
{
}

DoubleLinkedNode::DoubleLinkedNode(DoubleLinkedNode & node):pre_(0), next_(0), data_(node.getData())
{

}

DoubleLinkedNode::~DoubleLinkedNode()
{

}

bool DoubleLinkedNode::operator==(DoubleLinkedNode & node) const
{
  if(this == &node) return true;
	if(data_ == node.getData()) return true;
	return false;
}

DoubleLinkedNode *DoubleLinkedNode::getPreNode()
{
	return pre_;
}

DoubleLinkedNode *DoubleLinkedNode::getNextNode()
{
	return next_;
}

void DoubleLinkedNode::setPreNode(DoubleLinkedNode *node)
{
	pre_ = node;
	if(node->getNextNode() != this)node->setNextNode(this);
}

void DoubleLinkedNode::setNextNode(DoubleLinkedNode *node)
{
	next_ = node;
	if(node->getPreNode() != this)node->setPreNode(this);
}

DataModel &DoubleLinkedNode::getData()
{
	return data_;
}
