#include "graphs.h"

/**
 * dft_helper - depth first traversal
 *
 * @current: current vertex
 * @visited: visited array
 * @depth: current depth
 * @action: function to be used on first visit
 * Return: largest depth or 0
 */
size_t dft_helper(const vertex_t *current, int *visited, size_t depth,
		void (*action)(const vertex_t *, size_t))
{
	edge_t *current_edge;
	size_t max, temp;

	max = depth;

	if (visited[current->index] == 0)
	{
		action(current, depth);
		visited[current->index] = 1;
	}

	current_edge = current->edges;
	while (current_edge != NULL)
	{
		if (visited[current_edge->dest->index] == 0)
		{
			temp = dft_helper(current_edge->dest, visited, depth + 1, action);
			if (max < temp)
				max = temp;
		}
		current_edge = current_edge->next;
	}

	return (max);
}

/**
 * depth_first_traversal - goes through a graph using the depth-first algorithm
 *
 * @graph: the graph to traverse
 * @action: a function to be called for each visited vertex
 * Return: the biggest vertex depth (See example), or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
				void (*action)(const vertex_t *, size_t))
{
	int *visited;
	size_t max_depth = 0;

	if (graph == NULL || action == NULL || graph->vertices == NULL)
		return (0);

	visited = malloc(sizeof(int) * graph->nb_vertices);
	if (visited == NULL)
		return (0);

	while (max_depth < graph->nb_vertices)
		visited[max_depth++] = 0;

	max_depth = dft_helper(graph->vertices, visited, 0, action);

	free(visited);

	return (max_depth);
}

