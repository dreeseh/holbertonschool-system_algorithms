#include "graphs.h"

/**
 * graph_delete - completely deletes a graph
 *
 * @graph: a pointer to the graph to delete
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertices, *v_temp;
	edge_t *edge, *e_temp;

	if (!graph)
		exit(EXIT_FAILURE);

	vertices = graph->vertices;
	while (vertices)
	{
		v_temp = vertices;
		vertices = vertices->next;
		edge = v_temp->edges;

		while (edge)
		{
			e_temp = edge;
			edge = edge->next;
			free(e_temp);
		}
		free(v_temp->content);
		free(v_temp);
	}
	free(graph);
}
