#pragma once
#include "AVLnode.h"
#include <iostream>
using namespace std;


template <typename T>
class AVLTree
{
private:


	AVLNode<T>* root;

	int height(AVLNode<T>* n)
	{
		if (n == nullptr)
		{
			return 0;
		}
		else
		{
			return n->height;
		}
	}
	
	int balanceFactor(AVLNode<T>* n)
	{
		if (n == nullptr)
		{
			return 0;
		}

		return height(n->left) - height(n->right);

	}


	AVLNode<T>* insert(AVLNode<T>* n, T data)
	{
		int bf = 0;

		if (n == nullptr)
		{
			return new AVLNode<T>(data);
		}



		if (data > n->data)
		{
			n->right = insert(n->right, data);
		}
		else if (data < n->data)
		{
			n->left = insert(n->left, data);
		}
		else
		{
			return n;
		}

		n->height = max(height(n->left), height(n->right)) + 1;

		bf = balanceFactor(n);

		if (bf > 1 && data < n->left->data)
		{
			return rotateR(n);
		}
		
		if (bf < -1 && data > n->right->data)
		{
			return rotateL(n);
		}

		if (bf > 1 && data > n->left->data)
		{
			n->left = rotateL(n->left);
			return rotateR(n);
		}

		if (bf < -1 && data < n->right->data)
		{
			n->right = rotateL(n->right);
			return rotateL(n);
		}

		return n;

	}

	AVLNode<T>* rotateL(AVLNode<T>* n)
	{
		AVLNode<T>* temp1 = n->right;

		if (!temp1)
		{
			return n;
		}

		n->right = temp1->left;

		temp1->left = n;
		//AVLNode<T>* temp2 = temp1->left;

	//	temp1->left = n;
		//n->right = temp2;

		n->height = 1 + std::max(height(n->left), height(n->right));
		temp1->height = 1 + std::max(height(temp1->left), height(temp1->right));

		return temp1;
	}

	AVLNode<T>* rotateR(AVLNode<T>* n)
	{
		AVLNode<T>* temp1 = n->left;
		if (!temp1)
		{
			return n;
		}

		n->left = temp1->right;

		temp1->right = n;
		/*
		AVLNode<T>* temp2 = temp1->right;

		temp1->right = n;
		n->left = temp2;
		*/
		n->height = max(height(n->left), height(n->right)) + 1;
		temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

		return temp1;
	}

	int contains(AVLNode<T>* n, T data)
	{
		if (n == nullptr)
		{
			return 0;
		}
		if (data == n->data)
		{
			return 1;
		}
		else if (data < n->data)
		{
			return contains(n->left, data);
		}
		else
		{
			return contains(n->right, data);
		}
	}

	bool validated(AVLNode<T>* n)
	{
		if (n == nullptr)
		{
			return true;
		}

		int balance = balanceFactor(n);

		if (abs(balance) > 1) 
		{
			return false;
		}

		return validated(n->left) && validated(n->right);
	}


public:




	AVLTree() :
		root(nullptr) {}

	void insertion(T data)
	{
		root = insert(root, data);
	}

	int getHeight()
	{
		return height(root);
	}

	int contain(T data)
	{
		return contains(root, data);
	}
	
	int validate()
	{
		if (validated(root))
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	


};

