#include "heap.h"

/**
 * free_binary_tree - recursively frees a binary tree
 *
 * @root: pointer to the root of the tree to free
 * @free_data: pointer to the freeing function
 * Return: is void
 */
void free_binary_tree(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (!root)
		return;

	free_binary_tree(root->left, free_data);
	free_binary_tree(root->right, free_data);

	if (free_data)
		free_data(root->data);

	free(root);
}


/**
 * heap_delete - deallocates a heap
 *
 * @heap: a pointer to the heap to delete
 * @free_data: a pointer to the function that will free the node's content
 * Return: is void
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;

	free_binary_tree(heap->root, free_data);

	free(heap);
}
