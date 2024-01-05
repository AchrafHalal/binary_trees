#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *casa;
	binary_tree_t *dakhla;

	if (!first || !second)
		return (NULL);

	if (second == first)
		return ((binary_tree_t *)second);

	dakhla = first->parent;
	casa = second->parent;

	if (first == casa || !dakhla || (!dakhla->parent && casa))
		return (binary_trees_ancestor(first, casa));
	else if (second == dakhla || !casa || (!casa->parent && dakhla))
		return (binary_trees_ancestor(second, dakhla));

	return (binary_trees_ancestor(dakhla, casa));
}
