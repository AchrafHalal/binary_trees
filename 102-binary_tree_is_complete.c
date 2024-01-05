#include "binary_trees.h"
#include <stdio.h>
int wr9a(const binary_tree_t *node);
size_t _tool(const binary_tree_t *tree);
int perfecto(const binary_tree_t *tree);
/**
 * wr9a - checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf, and 0 otherwise. If node is NULL, return 0
 */
int wr9a(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

/**
 * _tool - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */
size_t _tool(const binary_tree_t *tree)
{
	size_t L, R;

	if (!tree)
		return (0);
	L = _tool(tree->left);
	R = _tool(tree->right);
	return ((L > R) ? 1 + L : 1 + R);
}

/**
 * perfecto - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int perfecto(const binary_tree_t *tree)
{
	binary_tree_t *L, *R;

	if (!tree)
		return (1);
	L = tree->left;
	R = tree->right;
	if (wr9a(tree))
		return (1);
	if (!lisr || !limn)
		return (0);
	if (_tool(lisr) == _tool(limn))
	{
		if (perfecto(lisr) && perfecto(limn))
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	if (!tree)
		return (0);
	if (wr9a(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	l_height = _tool(l);
	r_height = _tool(r);
	if (l_height == r_height)
	{
		if (perfecto(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && perfecto(r))
			return (1);
	}
	return (0);
}
