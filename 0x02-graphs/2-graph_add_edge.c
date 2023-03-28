#include "graphs.h"

/**
 * make_edge - originates & initializes a new edge
 *
 * @dest: vertex's destination
 * @source: the original vertex
 * Return: 1 on success, 0 upon failure
 */
int make_edge(vertex_t *source, vertex_t *dest)
{
	edge_t *new_edge, **edge_pointer;

	if (dest == NULL || source == NULL)
		return (0);

	for (edge_pointer = &source->edges ; *edge_pointer;
		edge_pointer = &(*edge_pointer)->next)
		if ((*edge_pointer)->dest == dest)
			return (0);

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);

	new_edge->dest = dest;
	new_edge->next = NULL;

	*edge_pointer = new_edge;

	source->nb_edges += 1;

	return (1);
}

/**
 * find_vertex - searches & finds a vertex in a graph
 *
 * @graph: pointer to the graph
 * @content: content of a vertex
 * Return: a pointer to our vertex or NULL
 */
vertex_t *find_vertex(graph_t *graph, const char *content)
{
	vertex_t *vertex_pointer;

	for (vertex_pointer = graph->vertices ; vertex_pointer;
		vertex_pointer = vertex_pointer->next)
		if (strcmp(vertex_pointer->content, content) == 0)
			return (vertex_pointer);

	return (0);
}

/**
 * graph_add_edge - adds an edge between two vertices
 *
 * @graph: pointer to the graph to add the edge to
 * @src: the string identifying the vertex to make the connection from
 * @dest: the string identifying the vertex to connect to
 * @type: the type of edge
 * Return: 1 on success, or 0 on failure
 **/
int graph_add_edge(graph_t *graph, const char *src,
	const char *dest, edge_type_t type)
{
	vertex_t *v_source, *v_dest;

	if (!graph || !src || !dest || type > BIDIRECTIONAL)
		return (0);

	v_source = find_vertex(graph, src);
	if (!v_source)
		return (0);

	v_dest = find_vertex(graph, dest);
	if (!v_dest)
		return (0);

	if (type == UNIDIRECTIONAL)
		return (make_edge(v_source, v_dest));

	make_edge(v_source, v_dest);
	make_edge(v_dest, v_source);

	return (1);
}
