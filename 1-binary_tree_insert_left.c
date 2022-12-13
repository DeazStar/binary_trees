#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as the left child of another node
 * @parent: a pointer to the node to insert the left child in
 * @value: the value to store in the new node
 * Description: If parent already has a left-child, the new node must take
 *   its place, and the old left-child must be set as the
 *   left-child of the new node.
 *
 * Return: the pointer to created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));
	binary_tree_t *tmpNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL)
	{
		return (NULL);
	}

	if (!parent)
	{
		return (NULL);
	}

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = parent;

	if (!parent->left)
	{
		parent->left = newNode;
	}
	else
	{
		tmpNode = parent->left;
		parent->left = newNode;
		parent->left->left = tmpNode;
		tmpNode->parent = newNode;
	}

	return (newNode);
}
