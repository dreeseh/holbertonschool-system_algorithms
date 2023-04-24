#include "huffman.h"
#include "heap/heap.h"

/**
* symbol_compare - compares two symbols that are leaves of independent trees
* @node_a: node a
* @node_b: node b
*
* Return: difference between a and b's leaf freq value
*/
int symbol_compare(void *node_a, void *node_b)
{
	binary_tree_node_t *n_a, *n_b;
	symbol_t *a, *b;

	n_a = (binary_tree_node_t *)node_a;
	n_b = (binary_tree_node_t *)node_b;

	a = (symbol_t *)n_a->data;
	b = (symbol_t *)n_b->data;

	return (a->freq - b->freq);
}

/**
 * huffman_priority_queue - creates a priority queue
 * for the Huffman coding algorithm
 *
 * @data: the data
 * @freq: the freq
 * @size: the size
 * Return: new heap_t*
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t i = 0;
	symbol_t *sym;
	binary_tree_node_t *node;
	heap_t *out;

	out = heap_create(symbol_compare);
	if (out == NULL)
		return (NULL);

	while (i < size)
	{
		sym = symbol_create(data[i], freq[i]);
		if (sym == NULL)
		{
			heap_delete(out, free);
			return (NULL);
		}
		node = binary_tree_node(NULL, (void *)sym);
		if (node == NULL)
		{
			free(sym);
			heap_delete(out, free);
			return (NULL);
		}
		heap_insert(out, (void *)node);
		i++;
	}

	return (out);
}
