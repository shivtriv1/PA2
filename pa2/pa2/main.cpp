#include "AVLnode.h"
#include "AVLTree.h"
#include <iostream>
using namespace std;


int main(void)
{
	AVLTree<int> ascendingTree, descendingTree, randomTree;

	int ascending[50] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99 };
	int descending[50] = { 99, 97, 95, 93, 91, 89, 87, 85, 83, 81, 79, 77, 75, 73, 71, 69, 67, 65, 63, 61, 59, 57, 55, 53, 51, 49, 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1 };
	int random[50] = { 51, 65, 11, 21, 59, 95, 9, 37, 27, 81, 17, 3, 55, 77, 47, 71, 13, 87, 5, 75, 69, 63, 33, 31, 49, 85, 7, 57, 93, 19, 61, 15, 67, 35, 53, 41, 91, 23, 79, 73, 25, 43, 1, 83, 99, 89, 29 };

	for (int i = 0; i < 50; i++)
	{
		ascendingTree.insertion(ascending[i]);
		descendingTree.insertion(descending[i]);
		randomTree.insertion(random[i]);
	}

	cout << "ascending tree height: " << ascendingTree.getHeight() << endl;	
	cout << "descending tree height: " << descendingTree.getHeight() << endl;
	cout << "random tree height: " << randomTree.getHeight() << endl<<endl;

	cout << "validate ascending tree: " << ascendingTree.validate() << endl;
	cout << "validate descending tree: " << descendingTree.validate() << endl;
	cout << "validate random tree: " << randomTree.validate() << endl<<endl;

	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
		{
			if (!ascendingTree.contain(i) && !descendingTree.contain(i) && !randomTree.contain(i))
			{
				cout << "My AVL tree implementation is wrong" << endl;
			}
		}
	}

}