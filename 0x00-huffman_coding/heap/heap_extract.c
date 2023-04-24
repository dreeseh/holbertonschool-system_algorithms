#include "heap.h"

/**
 * find_parent - finds the new node's parent
 *
 * @heap: pointer to the heap
 * @idx: value describing left / right
 * @dest: where the new node goes
 * Return: pointer to new node's parent or NULL
 */
binary_tree_node_t *find_parent(heap_t *heap, size_t idx, size_t dest)
{
	binary_tree_node_t *current;

	if (idx == 1 && idx == dest)
		return (NULL);

	if (idx == 1)
		return (heap->root);

	current = find_parent(heap, idx / 2, dest);

	if (idx == dest)
		return (current);

	if (idx % 2 == 0)
		return (current->left);
	return (current->right);
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 *
 * @heap: pointer to the heap from which to extract the value
 * Return: is void
 */
void *heap_extract(heap_t *heap)
{
	void *data, *temp;
	binary_tree_node_t *new_node, *swap, *last_node;

	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->data;
	new_node = heap->root;
	last_node = find_parent(heap, heap->size, heap->size);
	if (last_node == NULL)
		last_node = heap->root;
	else if (heap->size % 2 == 0)
	{
		last_node = last_node->left;
		last_node->parent->left = NULL;
	}
	else
	{
		last_node = last_node->right;
		last_node->parent->right = NULL;
	}
	new_node->data = last_node->data;
	while (new_node->left != NULL)
	{
		swap = new_node->left;
		if (new_node->right != NULL &&
				heap->data_cmp(swap->data, new_node->right->data) > 0)
			swap = new_node->right;
		if (heap->data_cmp(new_node->data, swap->data) < 0)
			break;
		temp = new_node->data;
		new_node->data = swap->data;
		swap->data = temp;
		new_node = swap;
	}
	free(last_node);
	heap->size = heap->size - 1;
	if (heap->size == 0)
		heap->root = NULL;
	return (data);
}
