#include "rb_trees.h"

/**
 * rb_tree_node - creates a Red-Black Tree node
 * 
 * @parent: pointer to the parent of the node to create
 * @value: the value to put into the new node
 * @color: the color of the node
 * Return: the new rb_tree_t* node
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node;

	new_node = malloc(sizeof(rb_tree_t));
	if (!new_node)
		return NULL;

	new_node->n = value;
	new_node->color = color;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}