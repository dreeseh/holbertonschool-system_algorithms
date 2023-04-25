# 0x02. C - N-ary trees

## General Learning Objectives:

* What is a N-ary tree
* What are the most common usage of N-ary trees
* How to represent an N-ary tree in C in at least two different ways
* What is the diameter of an N-ary tree

## General Requirements:

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project, is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called nary_trees.h
* Don’t forget to push your header file
* All your header files should be include guarded

## Data Structures

Please use the following data structures and types for this project. Don’t forget to include them in your header file.

```
/**
 * struct nary_tree_s - N-ary tree node structure
 *
 * @content: Content of the node
 * @parent: Pointer to the parent node
 * @nb_children: Number of children
 * @children: Pointer to the head node of the children linked list
 * @next: Pointer to the next child in the parent's children linked list
 */
typedef struct nary_tree_s
{
    char            *content;
    struct nary_tree_s  *parent;
    size_t          nb_children;
    struct nary_tree_s  *children;
    struct nary_tree_s  *next;
} nary_tree_t;
```

## Tasks

### 0. Insert

Write a function that inserts a node in a N-ary tree.

* Prototype: nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str);
* Where parent is a pointer to the parent node.
* str is the string to be stored in the created node. It must be duplicated.
* If parent is not NULL, the created node must be added at the beginning of the parent’s children linked list.
* Your function must return a pointer to the created node, or NULL on failure.

```
$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic -o 0-nary_tree_insert 0-nary_tree_insert.c 0-main.c
$ ./0-nary_tree_insert ; echo $?
0
$
```

### 1. Delete

Write a function that deallocates an entire N-ary tree

* Prototype: void nary_tree_delete(nary_tree_t *tree);

```
$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic -o 1-nary_tree_delete 1-nary_tree_delete.c 0-nary_tree_insert.c 1-main.c
$ valgrind ./1-nary_tree_delete
==26867== Memcheck, a memory error detector
==26867== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==26867== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==26867== Command: ./1-nary_tree_delete
==26867== 
==26867== 
==26867== HEAP SUMMARY:
==26867==     in use at exit: 0 bytes in 0 blocks
==26867==   total heap usage: X allocs, X frees, Y bytes allocated
==26867== 
==26867== All heap blocks were freed -- no leaks are possible
==26867== 
==26867== For counts of detected and suppressed errors, rerun with: -v
==26867== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$ 
```

### 2. Traversal

Write a function that goes through an N-ary tree, node by node.

* Prototype: size_t nary_tree_traverse(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth));
* Where root is a pointer to the root node of the tree to traverse
* action is a pointer to a function to execute for each node being traversed. Its arguments are:
	* node is a pointer to the node being traversed
	* depth is the depth of the node being traversed
* Your function must return the biggest depth of the tree pointed to by root

```
$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_traverse(root, &print_node);

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
$ gcc -Wall -Wextra -Werror -pedantic -o 2-nary_tree_traverse 2-nary_tree_traverse.c 1-nary_tree_delete.c 0-nary_tree_insert.c 2-main.c
$ ./2-nary_tree_traverse
/
  home
    alex
      Applications
      Documents
      Movies
      Pictures
      Downloads
      Desktop
  opt
    Betty
      betty-doc.pl
      betty-style.pl
  var
    www
  tmp
    tmp_file
$ 
```