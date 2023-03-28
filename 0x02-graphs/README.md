# 0x02. C - Graphs

## General
* What is a graph
* What are vertices and edges
* What are the different types of graphs (directed, weighted, …)
* What are the most common ways used to represent graphs in C
* How to traverse a graph using DFS and BFS

## TASKS:

### 0. Create graph

Write a function that allocates memory to store a graph_t structure, and initializes its content.

* Prototype: graph_t *graph_create(void);
* Your function must return a pointer to the allocated structure, or NULL on failure

```
$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    printf("Successfully created graph\n");

    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-graph_create.c -o 0-graph_create
$ ./0-graph_create
Successfully created graph
$
```

### 1. Add Vertex

Write a function that adds a vertex to an existing graph

* Prototype: vertex_t *graph_add_vertex(graph_t *graph, const char *str);
* Where graph is a pointer to the graph to add the vertex to, and str is the string to store in the new vertex
* Your function must return a pointer to the created vertex, or NULL on failure
* The vertex must store a copy of the string str
* If a vertex in graph already stores the string str, your function must fail, and there must be no leak

```
$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_vertex(graph, "San Francisco"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    if (!graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    if (!graph_add_vertex(graph, "San Francisco"))
        fprintf(stderr, "Failed to add \"San Francisco\"\n");

    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic -g3 1-main.c graph_create.c 1-graph_add_vertex.c graph_display.c -o 1-graph_add_vertex
$ ./1-graph_add_vertex
Number of vertices: 1
[0] San Francisco
Number of vertices: 8
[0] San Francisco
[1] Seattle
[2] New York
[3] Miami
[4] Chicago
[5] Houston
[6] Las Vegas
[7] Boston
Failed to add "San Francisco"
$
```

### 2. Add an edge

Write a function that adds an edge between two vertices to an existing graph

* Prototype: int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type);
* Where:
* graph is a pointer to the graph to add the edge to
* src is the string identifying the vertex to make the connection from
* dest is the string identifying the vertex to connect to
* type is the type of edge
* UNIDIRECTIONAL: Only one edge is created connecting src to dest
* BIDIRECTIONAL: Two edges are created, connecting src to dest AND dest to src.
* Your function must return 1 on success, or 0 on failure. On failure, no edge must have be created, and there must be no memory leak.
* If either src or dest are not found in any vertex of graph, your function must fail, and there must be no leak

```
$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_vertex(graph, "San Francisco") ||
        !graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    if (!graph_add_edge(graph, "San Francisco", "Las Vegas", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Boston", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Miami", "San Francisco", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Houston", "Seattle", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Chicago", "New York", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Las Vegas", "New York", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Chicago", UNIDIRECTIONAL) ||
        !graph_add_edge(graph, "New York", "Houston", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "Seattle", "Miami", BIDIRECTIONAL) ||
        !graph_add_edge(graph, "San Francisco", "Boston", BIDIRECTIONAL))
    {
        fprintf(stderr, "Failed to add edge\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic -g3 2-main.c graph_create.c graph_add_vertex.c 2-graph_add_edge.c graph_display.c -o 2-graph_add_edge
$ ./2-graph_add_edge
Number of vertices: 8
[0] San Francisco ->6->3->7
[1] Seattle ->4->3
[2] New York ->4->5
[3] Miami ->0->1
[4] Chicago ->2
[5] Houston ->1->2
[6] Las Vegas ->0->2
[7] Boston ->2->0
$
```