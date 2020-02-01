#if 1
#include<iostream>
using namespace std;

class Node
{
public:
	Node * left;
	Node *right;
	long long int data;
	long long int index = 0;
	Node()
	{
		left = nullptr;
		right = nullptr;

	}
};

class BST
{
private:
	Node *root;
	long long int size;
public:

	BST() : root(nullptr), size(0) {};
	void insert(long long int data);
	long long int getIndex(long long int data);
};

void BST::insert(long long int data)
{
	size++;
	if (root == nullptr) {
		root = new Node();
		root->data = data;
		root->index = 1;
		return;
	}

	Node* cur = root;

	while (1) {
		if (data <= cur->data) {
			cur->index++;
			if (cur->left == nullptr) {
				cur->left = new Node();
				cur->left->data = data;
				cur->left->index = 1;
				return;
			}
			cur = cur->left;
		}

		else if (data > cur->data) {
			if (cur->right == nullptr) {
				cur->right = new Node();
				cur->right->data = data;
				cur->right->index = 1;
				return;
			}
			cur = cur->right;
		}
	}
}

long long int BST::getIndex(long long int data)
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


int main() {
	long long int op;
	long long int elem;
	BST bst;
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
				cout << res<< endl;
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