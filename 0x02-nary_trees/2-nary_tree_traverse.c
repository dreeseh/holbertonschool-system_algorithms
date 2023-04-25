#include "nary_trees.h"

/**
 * max_depth_funct - gets the max-depth of an nary tree
 *
 * @root: root node of the tree
 * @current_depth: current depth of the tree
 * @action: is executed for each node being traversed
 *
 * Return: the max depth of the nary tree
 */
size_t max_depth_funct(nary_tree_t const *root, size_t current_depth,
		void (*action)(nary_tree_t const *node, size_t depth))
{
	nary_tree_t *children = NULL;
	size_t max_depth = 0, child_depth = 0;

	action(root, current_depth);
	children = root->children;
	max_depth = current_depth;

	while (children != NULL)
	{
		child_depth = max_depth_funct(children, current_depth + 1, action);
		if (child_depth > max_depth)
		{
			max_depth = child_depth;
		}
		children = children->next;
	}

	return (max_depth);
}

/**
 * nary_tree_traverse - goes through an N-ary tree, node by node
 *
 * @root: root node of the nary tree
 * @action: is executed for each node being traversed
 *
 * Return: the biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
		void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t max_depth;

	if (root == NULL)
		return (0);

	max_depth = max_depth_funct(root, 0, action);

	return (max_depth);
}
