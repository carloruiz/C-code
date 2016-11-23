
typedef struct tNode {
	void *data;
	int count;
	struct tNode *left;
	struct tNode *right;
} TreeNode;

/* node is the root of the Binary Tree,
 * data is a pointer to the data being added/removed to the tree
 * size is the size in bytes  of object pointed to by data
 * cmp is a pointer to a comparator function
 */

TreeNode *insertTreeNode(TreeNode *node, void *data, int size, int (*cmp)(const TreeNode *, const void*));

TreeNode *removeTreeNode(TreeNode *node, void *data, int (*cmp)(const TreeNode *, const void *));

void traverseBinaryTree(TreeNode *node, int (*f)(TreeNode*));

TreeNode *findTreeNode(TreeNode *node, void *data, int (*cmp)(const TreeNode *, const void *));

TreeNode *releaseBinaryTree(TreeNode *node);

static TreeNode *createTreeNode(void *data, int size);

static TreeNode *findMinTreeNode(TreeNode *node);

static int freeTreeNode(TreeNode *node);


