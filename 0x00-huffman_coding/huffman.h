#ifndef HUFFMAN_H
#define HUFFAMN_H

/* LIBRARIES */
#include <stdlib.h>
#include <stdio.h>

/* DATA STRUCTURES */
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

/* PROTOTYPES */
symbol_t *symbol_create(char data, size_t freq);

#endif /* HUFFMAN_H */