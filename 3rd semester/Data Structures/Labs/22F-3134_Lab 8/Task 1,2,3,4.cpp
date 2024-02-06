#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
	}
};
class BinarySearchTree {
private:
	Node* root;
public:
	BinarySearchTree() {
		root = nullptr;
	}
	// Insert a value into the BST
	void insert(int value) {
		root = insertRecursive(root, value);
	}
	// Search for a value in the BST
	bool search(int value) {
		return searchRecursive(root, value);
	}
	void deleteNode(int value) {
		root = deleteNodeRecursive(root, value);
	}
	// In-order traversal of the BST
	void inorderTraversal() {
		inorderRecursive(root);
	}
	// Pre-order traversal of the BST
	void preorderTraversal() {
		preorderRecursiveORDisplay(root);
	}
	// Post-order traversal of the BST
	void postorderTraversal() {
		postorderRecursive(root);
	}
	// Calculate the height of the BST
	int getHeight() {
		return calculateHeight(root);
	}
	// Count the total number of nodes in the BST
	int countNodes() {
		return countNodesRecursive(root);
	}
	// Find of Lowest Common Ancestor of given nodes in the BST
	Node* findLCA(int n1, int n2) {
		if (findRLCA(root, n1, n2) == nullptr) {
			cout << "Nullptr";
		}
		else {
			cout << root->data << endl;
		}
		return findRLCA(root, n1, n2);
	}
	// Destructor
	~BinarySearchTree() {
		destroyTree(root);
	}
private:
	// Function for inserting node in BST
	Node* insertRecursive(Node* root, int value) {
		if (root == nullptr) {
			Node* newNode = new Node(value);
			return newNode;
		}
		if (value < root->data) {
			root->left = insertRecursive(root->left, value);
		}
		else if (value >= root->data) {
			root->right = insertRecursive(root->right, value);
		}
		return root;
	}
	// Function for searching value in BST
	bool searchRecursive(Node* root, int value) {
		if (root == nullptr) { return false; }
		if (root->data == value) { return true; }
		searchRecursive(root->left, value);
		searchRecursive(root->right, value);
	}
		// Function to delete node according to value in BST
	Node* deleteNodeRecursive(Node* root, int value) {
		if (root == nullptr) { return root; }
		if (root->data < value) {
			deleteNodeRecursive(root->left, value);
		}
		else if (root->data > value) {
			deleteNodeRecursive(root->right, value);
		}
		else {
			if (root->left == nullptr) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			Node* temp = root->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			root->data = value;
			root->right = deleteNodeRecursive(root->right, temp->data);
		}
		return root;
	}
	// Function for Inorder Traversal in BST
	void inorderRecursive(Node* root) {
		if (root == nullptr) { return; }
		inorderRecursive(root->left);
		cout << root->data << " ";
		inorderRecursive(root->right);
	}
	// Function for Pre-Order Traversal in BST
	void preorderRecursiveORDisplay(Node* root) {
		if (root == nullptr) { return; }
		cout << root->data << " ";
		preorderRecursiveORDisplay(root->left);
		preorderRecursiveORDisplay(root->right);
	}
	// Function for PostOrder Traversal in BST
	void postorderRecursive(Node* root) {
		if (root == nullptr) { return; }
		postorderRecursive(root->left);
		postorderRecursive(root->right);
		cout << root->data << " ";
	}
	// Function to calculate the height of BST
	int calculateHeight(Node* root) {
		if (root == nullptr) { return 0; }
		int leftHeight = calculateHeight(root->left);
		int rightHeight = calculateHeight(root->right);
		return leftHeight < rightHeight ? 1 + rightHeight : 1 + leftHeight;
	}
	// Function to count number of nodes in BST
	int countNodesRecursive(Node* root) {
		if (root == nullptr) { return 0; }
		int sum = countNodesRecursive(root->left) + countNodesRecursive(root->right);
		return 1 + sum;
	}
	// Function to find LCA of provided nodes in BST
	Node* findRLCA(Node* root, int n1, int n2) {
		if (root == nullptr) { return nullptr; }
		if (n1 < root->data && n2 < root->data) {
			return findRLCA(root->left, n1, n2);
		}
		else if (n1 > root->data && n2 > root->data) {
			return findRLCA(root->right, n1, n2);
		}
		else {
			return root;
		}
	}
	void destroyTree(Node* root) {
		if (root == nullptr) {
			return;
		}
		destroyTree(root->left);
		destroyTree(root->right);
		Node* temp = root;
		root = nullptr;
		delete temp;
	}
	
};
// Main function have menu driven interface
int main() {
	int choice, node_data;
	int element1, element2;
	BinarySearchTree bst;
	while (true) {
		cout << "1. Insertion\n";
		cout << "2. Searching\n";
		cout << "3. Deleting\n";
		cout << "4. Inorder Traversal\n";
		cout << "5. Preorder Traversal\n";
		cout << "6. Post Traversal\n";
		cout << "7. Calculate Height\n";
		cout << "8. Calculate number of nodes\n";
		cout << "9. Lowest Common Ancestor\n";
		cout << "10. Delete Tree\n";
		cout << "-1. Exit\n";
		cout << "Enter your choice: ";	cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the node: ";
			cin >> node_data;
			bst.insert(node_data);
			break;
		case 2:
			cout << "Enter the node: ";
			cin >> node_data;
			if (bst.search(node_data) == true) { cout << "Node found.\n"; }
			else{cout << "Node not found.\n"; }
			break;
		case 3:
			cout << "Enter the node: ";
			cin >> node_data;
			bst.deleteNode(node_data);
			break;
		case 4:
			cout << "\nInorder traversal: ";
			bst.inorderTraversal();
			break;
		case 5:
			cout << "\nProrder traversal: ";
			bst.preorderTraversal();
			break;
		case 6:
			cout << "\nPostorder traversal: ";
			bst.postorderTraversal();
			break;
		case 7:
			cout << "Height of your Binary Search Tree: " << bst.getHeight() - 1;
			break;
		case 8:
			cout << "Number of nodes of your Binary Search Tree: " << bst.countNodes();
			break;
		case 9:
			cout << "Enter the first element: ";	cin >> element1;
			cout << "Enter the second element: ";	cin >> element2;
			bst.findLCA(element1, element2);
			break;
		case 10:
			bst.~BinarySearchTree();
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
		if (choice == -1) { break; }
	}
	return 0;
}