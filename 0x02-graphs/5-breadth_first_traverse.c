#include "graphs.h"

/**
 * bft_helper - breadth first traversal helper function
 *
 * @current_v: current vertex
 * @visited: vertex visited array
 * @number: number to reach array
 * @depth: the current depth
 * @action: function to use on vertex's first visit
 * Return: if visited, 1 otherwise 0
 */
int bft_helper(const vertex_t *current_v, int *visited, int number, int depth,
		void (*action)(const vertex_t *, size_t))
{
	int found = 0;
	edge_t *current_edge;

	if (number > depth)
		return (found);

	if (number == depth)
	{
		if (visited[current_v->index] == 0)
		{
			visited[current_v->index] = 1;
			action(current_v, depth);
			return (1);
		}
		return (0);
	}

	current_edge = current_v->edges;
	while (current_edge != NULL)
	{
		found += bft_helper(current_edge->dest, visited, number + 1, depth, action);
		current_edge = current_edge->next;
	}

	return (found);
}

/**
 * breadth_first_traverse - traverse a graph using the breadth-first algorithm
 *
 * @graph: the graph to traverse
 * @action: function to call on visited vertex
 * Return: max vertex depth or 0
 */
size_t breadth_first_traverse(const graph_t *graph,
				void (*action)(const vertex_t *, size_t))
{
	int *visited;
	size_t i = 0, depth = 0;
	vertex_t *start;

	if (graph == NULL || action == NULL || graph->vertices == NULL)
		return (0);

	visited = malloc(sizeof(int) * graph->nb_vertices);
	if (visited == NULL)
		return (0);

	while (i < graph->nb_vertices)
		visited[i++] = 0;

	start = graph->vertices;
	while (bft_helper(start, visited, 0, depth, action))
		depth++;

	free(visited);
	return (depth - 1);
}
