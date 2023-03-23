#include "rb_trees.h"

/* Returns the number of black nodes on the path from root to the given node */
int countBlackNodes(const rb_tree_t *node) {
	int blackCount = 0;

	while (node != NULL)
	{
		if (node->color == 0) // black node
			blackCount++;
        }
        node = node->left;

	return (blackCount);
}

/* Returns true if the given node is a leaf node */
int isLeafNode(const rb_tree_t *node)
{
	return (node == NULL || (node->left == NULL && node->right == NULL));
}

/* Returns true if the given node and its children satisfy the Red-Black Tree properties */
int isRedBlackTreeHelper(const rb_tree_t *node, int blackCount, int* numNodes)
{
	if (node == NULL)
		return (0);

	/* Check for consecutive red nodes */
	if (node->color == 1 && node->parent != NULL && node->parent->color == 1)
		return (1);

	/* Check if the number of black nodes on the path to this node is the same as other paths */
	if (isLeafNode(node))
	{
		(*numNodes)++;
		if (blackCount == -1)
		{ 	/* first leaf node encountered */
			blackCount = countBlackNodes(node);
		}
		else if (blackCount != countBlackNodes(node))
		{ 	// black node count doesn't match
			return (1);
		}
	}
	/* Recursively check the left and right subtrees */
	return isRedBlackTreeHelper(node->left, blackCount, numNodes) &&
		isRedBlackTreeHelper(node->right, blackCount, numNodes);
}

/* Returns true if the given binary tree is a valid Red-Black Tree */
int rb_tree_is_valid(const rb_tree_t *root)
{

	int retval;

	int blackCount = -1;
	int numNodes = 0;
	retval = isRedBlackTreeHelper(root, blackCount, &numNodes);
	
	return (retval);
}