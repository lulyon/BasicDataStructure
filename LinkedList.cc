/*
 * LinkedList.cc
 *
 *  Created on: 2013-5-28
 *      Author: luliang
 */
#include "LinkedList.h"
#include "LinkedNode.h"

LinkedList::LinkedList() :
  	length_(0), head_(0) {
}

LinkedList::LinkedList(LinkedList &list) {
	length_ = list.getLength();
	LinkedNode *node = list.getFirst();
	if (node == 0) {
		head_ = 0;
		return;
	}
	//add first node
	head_ = new LinkedNode(*node);
	LinkedNode *pre_node = getFirst();
	node = node->getNextNode();

	for (int i = 1; i < length_ && node; ++i) {
		LinkedNode *temp_node = new LinkedNode(*node);
		pre_node->setNextNode(temp_node);
		pre_node = pre_node->getNextNode();
		node = node->getNextNode();
	}
}

LinkedList::~LinkedList() {
	LinkedNode *temp_node;
	for (LinkedNode *node = getFirst(); node;) {
		temp_node = node;
		node = node->getNextNode();
		delete temp_node;
	}
}

int LinkedList::getLength() {
	return length_;
}

LinkedNode * LinkedList::getFirst() {
	return head_;
}

void LinkedList::add(LinkedNode *node) {
	node->setNextNode(getFirst());
	head_ = node;
}

LinkedNode *LinkedList::find(LinkedNode *target_node) {
	LinkedNode *node = getFirst();
	for (int i = 0; i < length_ && node; ++i) {
		if (*node == *target_node)
			return node;
		node = node->getNextNode();
	}
	return 0;
}

void LinkedList::findAndDelete(LinkedNode *target_node) {
	LinkedNode *node = getFirst();
	if (node == 0)
		return;
	if (*node == *target_node) {
		head_ = node->getNextNode();
		delete node;
		return;
	}
	LinkedNode *pre_node = node;
	node = node->getNextNode();
	for (int i = 1; i < length_ && node; ++i) {
		if (*node == *target_node) {
			pre_node->setNextNode(node->getNextNode());
			delete node;
			return;
		}
		pre_node = node;
		node = node->getNextNode();
	}
}
