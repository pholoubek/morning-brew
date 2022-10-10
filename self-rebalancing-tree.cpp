/* Node is defined as :
typedef struct node
{
	int val;
	struct node* left;
	struct node* right;
	int ht;
} node; */

int ht(node *n)
{
	if (n)
	{
		return 1 + max(ht(n->left), ht(n->right));
	}

	return -1;
}

void updateHt(node *n)
{
	if (n)
	{
		n->ht = 1 + max(ht(n->left), ht(n->right));
	}
}

node *rotateL(node *n)
{
	node *x = n->right;
	node *T2 = x->left;

	x->left = n;
	n->right = T2;

	updateHt(x);
	updateHt(n);

	return x;
}

node *rotateR(node *n)
{
	node *x = n->left;
	node *T2 = x->right;

	x->right = n;
	n->left = T2;

	updateHt(x);
	updateHt(n);

	return x;
}

node *insertNewNode(int val)
{
	node *newNode = new node;
	newNode->val = val;
	newNode->ht = 0;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

node *insert(node *root, int val)
{
	if (root == NULL)
	{
		return insertNewNode(val);
	}

	// left subtree
	if (val < root->val)
	{
		root->left = insert(root->left, val);
		// right subtree
	}
	else if (val > root->val)
	{
		root->right = insert(root->right, val);
		// AVL tree only allows unique values
	}
	else
	{
		return root;
	}

	// update height after each insertion
	updateHt(root);
	int balance = ht(root->left) - ht(root->right);

	// int balance = getBF(root);

	// LL case
	if (balance > 1 && val < root->left->val)
	{
		root = rotateR(root);
	}

	// LR case
	if (balance > 1 && val > root->left->val)
	{
		root->left = rotateL(root->left);
		root = rotateR(root);
	}

	// RR case
	if (balance < -1 && val > root->right->val)
	{
		root = rotateL(root);
	}

	if (balance < -1 && val < root->right->val)
	{
		root->right = rotateR(root->right);
		root = rotateL(root);
	}

	return root;
}