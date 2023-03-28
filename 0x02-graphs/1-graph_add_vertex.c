#include "graphs.h"

/**
 * make_vertex - initializes a new vertex
 *
 * @string: string stored in data structure
 * @index: index number of the vertex
 * Return: a pointer to a new vertex_t* vertex
 */
static vertex_t *make_vertex(const char *string, size_t index)
{
	vertex_t *new_vertex;

	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);

	new_vertex->content = strdup(string);
	new_vertex->edges = NULL;
	new_vertex->index = index;
	new_vertex->nb_edges = 0;
	new_vertex->next = NULL;

	return (new_vertex);
}

/**
 * graph_add_vertex - adds a vertex to an existing graph
 *
 * @graph: pointer to the graph to add the vertex to
 * @str: the string to store in the new vertex
 * Return: pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t **new_vertex;

	if (graph == NULL || str == NULL)
		return (NULL);

	for (new_vertex = &graph->vertices ; *new_vertex != NULL;
		new_vertex = &(*new_vertex)->next)
		if (strcmp(str, (*new_vertex)->content) == 0)
			return (NULL);

	*new_vertex = make_vertex(str, graph->nb_vertices);
	graph->nb_vertices += 1;

	return (*new_vertex);
}
