#pragma once

#ifndef AVLNODE_H
#define AVLNODE_H


template <typename T>
class AVLNode
{
public:

	AVLNode(T data) :
		data(data), left(nullptr), right(nullptr), height(1) {}

	~AVLNode()
	{
		delete left; delete right;
	}

	T data;
	AVLNode<T>* left;
	AVLNode<T>* right;
	int height;

};


#endif // ! AVLNODE_H
