/*
 * DoubleLinkedList.cc
 *
 *  Created on: 2013-5-29
 *      Author: luliang
 */

#include "DoubleLinkedList.h"
#include "DoubleLinkedNode.h"

DoubleLinkedList::DoubleLinkedList() :
  	length_(0), head_(0), tail_(0) {
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &list) {
	length_ = list.getLength();
	DoubleLinkedNode *node = list.getFirst();
	if (node == 0) {
		head_ = 0;
		tail_ = 0;
		return;
	}

	//add first node
	head_ = new DoubleLinkedNode(*node);
	DoubleLinkedNode *pre_node = getFirst();
	node = node->getNextNode();

	for (int i = 1; i < length_ && node; ++i) {
		DoubleLinkedNode *temp_node = new DoubleLinkedNode(*node);
		pre_node->setNextNode(temp_node);
		pre_node = pre_node->getNextNode();
		node = node->getNextNode();
	}
	tail_ = pre_node;
}

DoubleLinkedList::~DoubleLinkedList() {
	DoubleLinkedNode *temp_node;
	for (DoubleLinkedNode *node = getFirst(); node;) {
		temp_node = node;
		node = node->getNextNode();
		delete temp_node;
	}
}

int DoubleLinkedList::getLength() {
	return length_;
}

DoubleLinkedNode * DoubleLinkedList::getFirst() {
	return head_;
}

DoubleLinkedNode * DoubleLinkedList::getLast() {
	return tail_;
}

void DoubleLinkedList::add(DoubleLinkedNode *node) {
	node->setNextNode(getFirst());
	head_ = node;
}

DoubleLinkedNode *DoubleLinkedList::find(DoubleLinkedNode *target_node) {
	DoubleLinkedNode *node = getFirst();
	for (int i = 0; i < length_ && node; ++i) {
		if (*node == *target_node)
			return node;
		node = node->getNextNode();
	}
	return 0;
}

void DoubleLinkedList::findAndDelete(DoubleLinkedNode *target_node) {
	DoubleLinkedNode *node = getFirst();
	if (node == 0)
		return;
	if (*node == *target_node) {
		head_ = node->getNextNode();
		delete node;
		return;
	}
	DoubleLinkedNode *pre_node = node;
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
