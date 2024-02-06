#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;
	int height;
	Node(int value) {
		data = value;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};
class AVLTree {
private:
	Node* root;
	int height(Node* node) {	//getter for height
		if (node == nullptr) { return 0; }
		return node->height;
	}
	int balanceFactor(Node* node) {	//tells about the balacing, should be between -1 and 1
		if (node == nullptr) { return 0; }
		int bf = height(node->left) - height(node->right);
		return bf;
	}
	int update_height(Node* node) {	//as the trees insertion and removal goes height should be updated
		if (node == nullptr) {
			return 0;
		}else if (node != nullptr) {
			int max_side;
			if (height(node->left) > height(node->right)) {
				max_side = height(node->left);	//in case of bigger left side
			}
			else {
				max_side = height(node->right);	//in case of bigger right side
			}
			node->height = 1 + max_side;
		}
		return node->height;
	}
	Node* rotateLeft(Node* node) {	//for full on RR rotation
		Node* newRoot = node->right;	//data of right from given node
		Node* oldRoot = newRoot->left;	//data from left of given node
		newRoot->left = node;			//data of left of given node
		node->right = oldRoot;			//data from oldroot
		update_height(newRoot);			//updating height since rotated
		return newRoot;
	}
	Node* rotateRight(Node* node) {	//for full LL rotation
		Node* newRoot = node->left;		//data of left from the given node
		Node* oldRoot = newRoot->right;	//data from right of given node
		newRoot->right = node;			//data of right of given node
		node->left = oldRoot;			//data from oldroot
		update_height(newRoot);			//updating height since rotated
		return newRoot;
	}
	Node* balance(Node* node) {
		int bf = balanceFactor(node);
		if (bf > 1) {	//Left cases
			if (balanceFactor(node->left) >= 0) {	//Left-Left case
				return rotateRight(node);
			}
			else {	//Left-Right case
				node->left = rotateLeft(node->left);
				return rotateRight(node);
			}
		}
		if (bf < -1) {	//Right cases
			if (balanceFactor(node->right) <= 0) {	//Right-Right case
				return rotateLeft(node);
			}
			else {	//Right-Left case
				node->right = rotateRight(node->right);
				return rotateLeft(node);
			}
		}
		return node;
	}
	Node* insert(Node* node, int key) {
		Node* newNode = new Node(key);
		if (node == nullptr) {
			node = newNode;
			return node;
		}
		if (key < node->data) { node->left = insert(node->left, key); }
		else { node->right = insert(node->right, key); }
		update_height(node);
		int balance = balanceFactor(node);
		balanceFactor(node);
		return node;
	}
	Node* findMin(Node* node) {
		if (node == nullptr) {
			return nullptr;
		}
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	Node* remove(Node* node, int key) {
		if (node == nullptr) { return node; }
		if (key < node->data) {	//going for low element
			node->left = remove(node->left, key);
		}
		else if (key > node->data) {	//going for high element
			node->right = remove(node->right, key);
		}
		else {	//one child case
			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
			Node* temp = findMin(node->right);
			node->data = temp->data;
			node->right = remove(node->right, temp->data);
		}
		update_height(node);
		return balance(node);
	}
	void inorderRecursive(Node* root) {
		if (root != nullptr) {
			inorderRecursive(root->left);
			cout << root->data << " ";
			inorderRecursive(root->right);
		}
	}
	void preorderRecursive(Node* root) {
		if (root != nullptr) {
			cout << root->data << " ";
			preorderRecursive(root->left);
			preorderRecursive(root->right);
		}
	}
	void postorderRecursive(Node* root) {
		if (root != nullptr) {
			postorderRecursive(root->left);
			postorderRecursive(root->right);
			cout << root->data << " ";
		}
	}
	void inorder_insertion_for_union(Node* node) {
		if (node == nullptr) { return; }
		inorder_insertion_for_union(node->left);	//traversing to left
		insert(node->data);	//inserting and making a new tree
		inorder_insertion_for_union(node->right);	//traversing to the right
	}
	void destroy_tree(Node* node) {
		if (node == nullptr) { return; }
		destroy_tree(node->left);
		destroy_tree(node->right);
		delete node;
	}
public:
	AVLTree() {
		root = nullptr;
	}
	void insert(int key) {
		root = insert(root, key);
	}
	void remove(int key) {
		root = remove(root, key);
	}
	void Traversal() {
		cout << "In order: ";	inorderRecursive(root);		cout << endl;
		cout << "Pre order: ";	preorderRecursive(root);	cout << endl; 
		cout << "Post order: ";	postorderRecursive(root);	cout << endl;
	}
	void union_avl_trees(AVLTree avl, AVLTree avl2) {
		inorder_insertion_for_union(avl.root);	//sending avl's roots
		inorder_insertion_for_union(avl2.root);	//sending second avl's roots
	}
	~AVLTree() {
		destroy_tree(root);
	}
};
int main() {
	AVLTree avl, avl2, avl_union;
	int root_data, choice;
	while (true) {
		cout << "\nEnter your choice:\n";
		cout << "1.Insertion in tree\n";
		cout << "2.Removal from tree\n";
		cout << "3.Printing of tree\n";
		cout << "4.Union of trees\n";
		cout << "0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			while (true) {
				cout << "Enter your data (-1 to stop): ";	cin >> root_data;
				if (root_data == -1) {
					break;
				}
				avl.insert(root_data);
			}
		}
		else if (choice == 2) {
			cout << "Enter the data to be removed: ";
			cin >> root_data;
			avl.remove(root_data);
			avl.Traversal();
		}
		else if (choice == 3) {
			cout << "Traversing of trees:\n";
			avl.Traversal();
		}
		else if (choice == 4) {
			while (true) {	//for insertion of nodes for second tree
				cout << "Enter the elements of the second tree:\n";
				cout << "Enter your data (-1 to stop): ";	cin >> root_data;
				if (root_data == -1) {
					break;
				}
				avl2.insert(root_data);
			}
			avl_union.union_avl_trees(avl, avl2);
			avl_union.Traversal();
		}
		else if (choice == 0) {
			break;
		}
	}
	//Calculating destructor
	avl.~AVLTree();
	avl2.~AVLTree();
	avl_union.~AVLTree();
	return 0;
}