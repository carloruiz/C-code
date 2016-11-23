
typedef struct tNode {
	void *data;
	int count;
	struct tNode *left;
	struct tNode *right;
} TreeNode;

static TreeNode *createTreeNode(void *data, int size);

static TreeNode *findMinTreeNode(TreeNode *node);

TreeNode *findTreeNode(TreeNode *node, void *data, int (*cmp)(const TreeNode *, const void *));

TreeNode *insertTreeNode(TreeNode *node, void *data, int size, int (*cmp)(const TreeNode *, const void*));

TreeNode *removeTreeNode(TreeNode *node, void *data, int (*cmp)(const TreeNode *, const void *));

static int freeTreeNode(TreeNode *node);

// in order traversal
void traverseBinaryTree(TreeNode *node, int (*f)(TreeNode*));

TreeNode *releaseBinaryTree(TreeNode *node);


