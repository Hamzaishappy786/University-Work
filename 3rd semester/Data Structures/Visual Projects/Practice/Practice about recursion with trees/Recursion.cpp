#include <iostream>
using namespace std;
struct Node {
	int data;	Node* left;	Node* right;
};
Node* newNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->left = nullptr;
	node->right = nullptr;
	return (node);
}
void traversePreOrder(Node* temp) {
	if (temp != nullptr) {
		cout << temp->data << " ";
		traversePreOrder(temp->left);
		traversePreOrder(temp->right);
	}
}
void traverseInOrder(Node* temp) {
	if (temp != nullptr) {
		traverseInOrder(temp->left);
		cout << temp->data << " ";
		traverseInOrder(temp->right);
	}
}
void traversePostOrder(Node* temp) {
	if (temp != nullptr) {
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout << temp->data << " ";
	}
}
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	cout << "Pre-order traversal: ";
	traversePreOrder(root);
	cout << "\nIn-order traversal: ";
	traverseInOrder(root);
	cout << "\nPost-order traversal: ";
	traversePostOrder(root);
	return 0;
}