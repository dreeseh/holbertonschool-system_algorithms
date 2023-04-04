# 0x00. C - Huffman coding

## More Info

### Data structures

Please use the following data structures and types for this project. Don’t forget to include them in your header file(s). You’ll have to declare the following data structures in your header file heap.h in the folder 0x00-huffman_coding/heap

```
/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
    void *data;
    struct binary_tree_node_s *left;
    struct binary_tree_node_s *right;
    struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
    size_t size;
    int (*data_cmp)(void *, void *);
    binary_tree_node_t *root;
} heap_t;
```

You’ll have to declare the following data structures in your header file huffman.h in the folder 0x00-huffman_coding

```
/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
} symbol_t;
```

## Tasks

### 0. Min Binary Heap - Create heap

Write a function that creates a Heap data structure

* Prototype: heap_t *heap_create(int (*data_cmp)(void *, void *));
* Where data_cmp is a pointer to a comparison function
	* This function takes two void * parameters, each one being the data stored in a node.
	* This function will return the difference between the two data stored at those pointers.
	* It will be used to determine if a node’s value is greater or lower than another, so we can build our heap
* Your function must return a pointer to the created heap_t structure, or NULL if it fails
* root must be set to NULL
* size must be set to 0

```
$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);
    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 0-main.c -o heap_create
$ ./heap_create
Heap size: 0
Heap root: (nil)
$
```
