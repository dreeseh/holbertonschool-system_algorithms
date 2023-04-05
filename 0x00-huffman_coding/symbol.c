#include "huffman.h"

/**
 * symbol_create - creates a symbol_t data structure
 *
 * @data: the data to be stored in the structure
 * @freq: its associated frequency
 * Return: a pointer to the created structure, or NULL if it fails
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new_symbol;

	new_symbol = malloc(sizeof(symbol_t));
	if (!new_symbol)
		return (NULL);

	new_symbol->data = data;
	new_symbol->freq = freq;

	return (new_symbol);
}
