#include "nary_trees.h"

/**
 * nary_tree_delete - deallocates an entire N-ary tree
 *
 * @tree: the tree to deallocate
 *
 * Return: is void
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *temp;

	while (tree)
	{
		temp = tree;
		tree = tree->next;
		nary_tree_delete(temp->children);
		free(temp->content);
		free(temp);
	}
}
