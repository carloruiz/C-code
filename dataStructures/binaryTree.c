#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"

static TreeNode *createTreeNode(void *data, int size)
{
	TreeNode *new = malloc(sizeof(TreeNode));
	void *newdata = malloc(size);
	memcpy(newdata, data, size);
	new->data = newdata;
	new->count = 1;
	new->left = new->right = NULL;
	return new;
}

TreeNode *findTreeNode(TreeNode *node, void *data, int (*cmp)(const TreeNode *, const void *))
{
	if (!node)
		return NULL;
	if ((*cmp)(node, data) > 0) 
		return findTreeNode(node->right, data, cmp);
	else if ((*cmp)(node, data) < 0)
		return findTreeNode(node->left, data, cmp);
	else
		return node;
}

TreeNode *insertTreeNode(TreeNode *node, void *data, int size, int (*cmp)(const TreeNode *, const void *))
{
	int val;
	if (!node) 
	    return createTreeNode(data, size);
	else if ((val = (*cmp)(node, data)) > 0)
		node->right = insertTreeNode(node->right, data, size, cmp);
	else if (val < 0)
		node->left = insertTreeNode(node->left, data, size, cmp);
	else
		node->count++;
	return node;
}
 
TreeNode *findMinTreeNode(TreeNode *node) 
{
	while (node->left)
		node = node->left;
	return node; 
}

TreeNode *removeTreeNode(TreeNode *node, void *data, int (*cmp)(const TreeNode *, const void *data))
{
	if (!node) return 0;
	
	int val;
	if ((val = cmp(node, data)) > 0)
		node->right = removeTreeNode(node->right, data, cmp);
	else if (val < 0)
		node->left = removeTreeNode(node->left, data, cmp);
	else {
		if (node->left == NULL) {
			TreeNode *right = node->right;
			freeTreeNode(node);
			return right;
		} else if (node->right == NULL) {
			TreeNode *left = node->left;
			freeTreeNode(node);
			return left; 	
		} 
		else {
			void *tmpData = node->data;
			TreeNode *min = findMinTreeNode(node->right);
			node->data = min->data;
			node->count = min->count;
			if (min->right) {
				min->data = min->right->data;
				min->count = min->right->count;
				min->right->data = tmpData;
				freeTreeNode(min->right);
				min->right = NULL;
			} else {
				min->data = tmpData;
				freeTreeNode(min);
				node->right = NULL;	
			}
		}
	}
	return node;
}

static int freeTreeNode(TreeNode *node)
{
	free(node->data);
	free(node);
	return 1;
}

void traverseBinaryTree(TreeNode *node, int (*f)(TreeNode *))
{
	if (node->left)
		traverseBinaryTree(node->left, f);
	(*f)(node);
	if (node->right)
		traverseBinaryTree(node->right, f);
}


TreeNode *releaseBinaryTree(TreeNode *node)
{
	if (node->left)
		node->left = releaseBinaryTree(node->left);
	if (node->right)
		node->right = releaseBinaryTree(node->right);
	freeTreeNode(node);
	return NULL;	
}

