#include "heap.h"

/**
 * swap - swaps nodes
 *
 * @first: first node to swap
 * @second: second node to swap
 * Return: pointer to the first node
 */
binary_tree_node_t *swap(binary_tree_node_t *first, binary_tree_node_t *second)
{
	void *temp;

	temp = second->data;
	second->data = first->data;
	first->data = temp;
	first = second;

	return (first);
}

/**
 * bubble_up - allows places node to work up to its place
 *
 * @data_cmp: pointer to a comparison function
 * @node: pointer to inserted node
 * Return: pointer to the inserted node's data value or NULL
 */
binary_tree_node_t *bubble_up(int (*data_cmp)(void *, void*),
				binary_tree_node_t *node)
{
	if (!data_cmp || !node)
		return (NULL);
	while (node->parent && data_cmp(node->data, node->parent->data) < 0)
		node = swap(node, node->parent);
	return (node);
}

/**
 * nth_node - finds the n'th node of a tree
 *
 * @node: pointer to root node
 * @n: the node to find
 * Return: pointer to the nth node or NULL
 */
binary_tree_node_t *nth_node(binary_tree_node_t *node, int n)
{
	int index = 0, mask;

	if (!node || n < 0)
		return (NULL);

	while (1 << (index + 1) <= n)
		++index;

	for (--index ; index >= 0 ; --index)
	{
		mask = 1 << index;
		if (n & mask)
		{
			if (node->right)
				node = node->right;
			else
				break;
		}
		else
		{
			if (node->left)
				node = node->left;
			else
				break;
		}
	}
	return (node);
}

/**
 * heap_insert - inserts a value in a Min Binary Heap
 *
 * @heap: pointer to the heap in which the node has to be inserted
 * @data: pointer containing the data to store in the new node
 * Return: a pointer to the created node containing data, or NULL
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node;

	if (!heap || !data)
		return (NULL);

	if (!heap->root)
	{
		new_node = binary_tree_node(NULL, data);
		heap->root = new_node;
		if (!new_node)
			return (NULL);
		++heap->size;
	}
	else
	{
		new_node = nth_node(heap->root, ++heap->size);
		if (!new_node->left)
			new_node = new_node->left = binary_tree_node(new_node, data);
		else
			new_node = new_node->right = binary_tree_node(new_node, data);
	}

	return (bubble_up(heap->data_cmp, new_node));
}
