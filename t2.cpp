#if 1
#include<iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node
{
	long long int data;
	bool color;
	Node *left, *right, *parent;
	long long int index; // number of noodes on the left side tree of this node.
	// Constructor
	Node(long long int data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		this->color = RED;
	}

	Node()
	{
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		this->color = RED;
	}
};

// Class to represent Red-Black Tree
class RBTree
{
private:
	long long int size;
	Node *root;
protected:
	void rotateLeft(Node *&, Node *&);
	void rotateRight(Node *&, Node *&);
	void fixRBTree(Node *&, Node *&);
	void BSTInsert(Node* data);
	void updateIndex();
public:
	// Constructor
	RBTree() { root = nullptr; }
	void insert(const long long int &n);
	long long int getIndex(long long int data);
};

/* A utility function to insert a new node with given key
   in BST */
void RBTree::BSTInsert(Node* data)
{
	size++;
	if (root == nullptr) {
		root = data;
		return;
	}

	Node* cur = root;

	while (1) { // only breaks when the node is allocated in its right place
		if (data->data <= cur->data) {
			if (cur->left == nullptr) {
				// allocates as the left node
				cur->left = data;
				cur->left->parent = cur;
				return;
			}
			// go deeper
			cur = cur->left;
		}
		else if (data->data > cur->data) {
			if (cur->right == nullptr) {
				// allocate as the right node
				cur->right = data;
				cur->right->parent = cur;
				return;
			}
			// go deeper
			cur = cur->right;
		}
	}
}

void RBTree::rotateLeft(Node *&root, Node *&pt)
{
	Node *pt_right = pt->right;

	pt->right = pt_right->left;

	if (pt->right != nullptr)
		pt->right->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == nullptr)
		root = pt_right;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_right;

	else
		pt->parent->right = pt_right;

	pt_right->left = pt;
	pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt)
{
	Node *pt_left = pt->left;

	pt->left = pt_left->right;

	if (pt->left != nullptr)
		pt->left->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == nullptr)
		root = pt_left;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;

	else
		pt->parent->right = pt_left;

	pt_left->right = pt;
	pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
void RBTree::fixRBTree(Node *&root, Node *&pt)
{
	Node *parent_node = nullptr;
	Node *grand_parent_noded = nullptr;

	while ((pt != root) && (pt->color != BLACK) &&
		(pt->parent->color == RED))
	{
		parent_node = pt->parent;
		grand_parent_noded = pt->parent->parent;

		/*  Case : A
			Parent of pt is left child of Grand-parent of pt */
		if (parent_node == grand_parent_noded->left)
		{

			Node *uncle_pt = grand_parent_noded->right;

			/* Case : 1
			   The uncle of pt is also red
			   Only Recoloring required */
			if (uncle_pt != nullptr && uncle_pt->color == RED)
			{
				grand_parent_noded->color = RED;
				parent_node->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_noded;
			}

			else
			{
				/* Case : 2
				   pt is right child of its parent
				   Left-rotation required */
				if (pt == parent_node->right)
				{
					rotateLeft(root, parent_node);
					pt = parent_node;
					parent_node = pt->parent;
				}

				/* Case : 3
				   pt is left child of its parent
				   Right-rotation required */
				rotateRight(root, grand_parent_noded);
				swap(parent_node->color, grand_parent_noded->color);
				pt = parent_node;
			}
		}

		/* Case : B
		   Parent of pt is right child of Grand-parent of pt */
		else
		{
			Node *uncle_pt = grand_parent_noded->left;

			/*  Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if ((uncle_pt != nullptr) && (uncle_pt->color == RED))
			{
				grand_parent_noded->color = RED;
				parent_node->color = BLACK;
				uncle_pt->color = BLACK;
				pt = grand_parent_noded;
			}
			else
			{
				/* Case : 2
				   pt is left child of its parent
				   Right-rotation required */
				if (pt == parent_node->left)
				{
					rotateRight(root, parent_node);
					pt = parent_node;
					parent_node = pt->parent;
				}

				/* Case : 3
				   pt is right child of its parent
				   Left-rotation required */
				rotateLeft(root, grand_parent_noded);
				swap(parent_node->color, grand_parent_noded->color);
				pt = parent_node;
			}
		}
	}
	root->color = BLACK;
}

// Function to insert a new node with given data
void RBTree::insert(const long long int &data)
{
	Node *pt = new Node(data);

	// Do a normal BST insert
	BSTInsert(pt);

	// fix Red Black Tree violations
	fixRBTree(root, pt);
	updateIndex();
}


// a function uses the index variable in each node to get the general inde of a node in the full tree
long long int RBTree::getIndex(long long int data)
{
	Node* cur = root;
	long long int index = 0;
	long long int offset = 0;
	while (cur != nullptr) {
		if (data < cur->data) {
			if (cur->left == nullptr) {
				return -1;
			}
			//index = cur->left->index;
			cur = cur->left;
		}
		else if (data > cur->data) {
			if (cur->right == nullptr) {
				return -1;
			}
			offset += cur/*->right*/->index;
			cur = cur->right;
		}
		else {
			return size + 1 - (offset + index + cur->index);
		}
	}
	return -1;
}


long long int allRightNodes(Node*node) {
	if (node == nullptr) {
		return 0;
	}
	return node->index + allRightNodes(node->right);
}
// this function recursively update index of each node correctly.
long long int updateIndexHelper(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	node->index = 1 + updateIndexHelper(node->left);
	updateIndexHelper(node->right);
	if (node->right == nullptr) {
		return node->index;
	}
	return node->index + allRightNodes(node->right);//node->right->index;
}

void RBTree::updateIndex()
{
	updateIndexHelper(root);
}

int main() {
	long long int op;
	long long int elem;
	RBTree bst;
	long long int res;
	long long int n;
	cin >> n;
	while (n--) {
		cin >> op;
		cin >> elem;
		switch (op)
		{
		case 1:
			bst.insert(elem);
			break;
		case 2:
			res = bst.getIndex(elem);
			if (res != -1) {
				cout << res << endl;
			}
			else {
				cout << "Data tidak ada" << endl;
			}
			break;
		}
	}
	return 0;
}

#endif