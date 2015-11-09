#include "binary_tree.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv)
{
	BinarySearchTree test_tree;
	int array[10] = {5,9,4,1,7,8,2,3,6,10};
	int len = 0;
	while(len != 10)
	{
		test_tree.insert(array[len]);
		len++;
	}
	test_tree.display();
}
