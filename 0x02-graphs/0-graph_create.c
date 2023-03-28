#include "graphs.h"

/**
 * graph_create - allocates memory to store a graph_t
 * structure, and initializes its content
 *
 * Return: pointer to the allocated structure, or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *new_graph;

	new_graph = malloc(sizeof(graph_t));
	if (!new_graph)
		return (NULL);

	new_graph->nb_vertices = 0;
	new_graph->vertices = NULL;

	return (new_graph);
}
