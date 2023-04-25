#include "nary_trees.h"

/**
 * nary_tree_insert - a function that inserts a node in a N-ary tree
 *
 * @parent: a pointer to the parent node
 * @str: string to be stored in the created node. It must be duplicated
 *
 * Return: a pointer to the created node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node = malloc(sizeof(nary_tree_t));
	char *string_copy = strdup(str);

	if (!new_node)
		return (NULL);

	if (!string_copy)
	{
		free(new_node);
		fprintf(stderr, "tree insert error: srtdup didn't work\n");
		return (NULL);
	}

	new_node->content = string_copy;
	new_node->parent = parent;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;

	if (parent)
	{
		new_node->next = parent->children;
		parent->children = new_node;
		parent->nb_children++;
	}

	return (new_node);
}
