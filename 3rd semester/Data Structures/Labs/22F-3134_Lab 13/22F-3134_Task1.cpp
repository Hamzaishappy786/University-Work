//#include <iostream>
//#include <string>
//using namespace std;
//struct Product {
//	int ID;
//	string name;
//	Product(int data, string& name) {
//		this->ID = data;
//		this->name = name;
//	}
//};
//class Node {
//public:
//	Product* product;
//	Node* left;
//	Node* right;
//	int height;
//	Node(Product* product) {
//		this->product = product;
//		left = nullptr;
//		right = nullptr;
//		height = 1;
//	}
//};
//class AVLTree {
//private:
//	Node* root;
//	Node* prev_root;	//made specifically for undo
//	Node* next_root;	//made specifically for redo
//
//	int height(Node* node) {	//getter for height
//		if (node == nullptr) { return 0; }
//		return node->height;
//	}
//	int balanceFactor(Node* node) {	//tells about the balacing, should be between -1 and 1
//		if (node == nullptr) { return 0; }
//		int bf = height(node->left) - height(node->right);
//		return bf;
//	}
//	int update_height(Node* node) {	//as the trees insertion and removal goes height should be updated
//		if (node == nullptr) {
//			return 0;
//		}
//		else if (node != nullptr) {
//			int max_side;
//			if (height(node->left) > height(node->right)) {
//				max_side = height(node->left);	//in case of bigger left side
//			}
//			else {
//				max_side = height(node->right);	//in case of bigger right side
//			}
//			node->height = 1 + max_side;
//		}
//		return node->height;
//	}
//	Node* rotateLeft(Node* node) {	//for full on RR rotation
//		Node* newRoot = node->right;	//data of right from given node
//		Node* oldRoot = newRoot->left;	//data from left of given node
//		newRoot->left = node;			//data of left of given node
//		node->right = oldRoot;			//data from oldroot
//		update_height(newRoot);			//updating height since rotated
//		return newRoot;
//	}
//	Node* rotateRight(Node* node) {	//for full LL rotation
//		Node* newRoot = node->left;		//data of left from the given node
//		Node* oldRoot = newRoot->right;	//data from right of given node
//		newRoot->right = node;			//data of right of given node
//		node->left = oldRoot;			//data from oldroot
//		update_height(newRoot);			//updating height since rotated
//		return newRoot;
//	}
//	Node* balance(Node* node) {
//		int bf = balanceFactor(node);
//		if (bf > 1) {	//Left cases
//			if (balanceFactor(node->left) >= 0) {	//Left-Left case
//				return rotateRight(node);
//			}
//			else {	//Left-Right case
//				node->left = rotateLeft(node->left);
//				return rotateRight(node);
//			}
//		}
//		if (bf < -1) {	//Right cases
//			if (balanceFactor(node->right) <= 0) {	//Right-Right case
//				return rotateLeft(node);
//			}
//			else {	//Right-Left case
//				node->right = rotateRight(node->right);
//				return rotateLeft(node);
//			}
//		}
//		return node;
//	}
//	Node* insertion(Node* node, Product* product) {
//		Node* newNode = new Node(product);
//		if (node == nullptr) {
//			node = newNode;
//			return node;
//		}
//		if (product->ID < node->product->ID) { node->left = insertion(node->left, product); }
//		else if (product->ID > node->product->ID) { node->right = insertion(node->right, product); }
//		else if (product->ID == node->product->ID) { return node; }
//		update_height(node);
//		int balance = balanceFactor(node);
//		balanceFactor(node);
//		return node;
//	}
//	Node* findMin(Node* node) {	//minimum number finding
//		if (node == nullptr) {
//			return nullptr;
//		}
//		while (node->left != nullptr) {
//			node = node->left;
//		}
//		return node;
//	}
//	Node* remove_nodes(Node* root, int product_id) {
//		if (root == nullptr) { return root; }
//		if (product_id < root->product->ID) {	//going for low element
//			root->left = remove_nodes(root->left, product_id);
//		}
//		else if (product_id > root->product->ID) {	//going for high element
//			root->right = remove_nodes(root->right, product_id);
//		}
//		else {	//one child case
//			if (root->left == nullptr) {
//				Node* temp = root->right;
//				delete root;
//				return temp;
//			}
//			else if (root->right == nullptr) {
//				Node* temp = root->left;
//				delete root;
//				return temp;
//			}
//			Node* temp = findMin(root->right);
//			root->product->ID = temp->product->ID;
//			root->right = remove_nodes(root->right, temp->product->ID);
//		}
//		update_height(root);
//		return balance(root);
//	}
//	void inorderRecursive(Node* root) {
//		if (root != nullptr) {
//			inorderRecursive(root->left);
//			cout << "\nProduct name: " << root->product->name << endl;
//			cout << "Product ID: " << root->product->ID << endl;
//			inorderRecursive(root->right);
//		}
//	}
//public:
//	AVLTree() {
//		root = nullptr;
//		prev_root = nullptr;
//		next_root = nullptr;
//	}
//	void insert(Product* product) {
//		prev_root = root;
//		root = insertion(root, product);
//		next_root = nullptr;
//	}
//	void remove(int product_id) {
//		prev_root = root;
//		root = remove_nodes(root, product_id);
//		next_root = nullptr;
//	}
//	void go_back() {		//function for undo
//		root = prev_root;
//	}
//	void go_forward() {		//function for redo
//		if (next_root != nullptr) {
//			if (root != nullptr) {
//				cout << "Cannot go forward after a new operation.\n";
//			}
//			else {
//				root = next_root;
//				next_root = nullptr;
//				cout << "Tree back in original state.\n";
//			}
//		}
//		else {
//			cout << "Tree forwarding not possible.\n";
//		}
//	}
//	void Traversal() {
//		inorderRecursive(root);		cout << endl;
//	}
//	~AVLTree() {
//		delete[]root;
//		delete[]prev_root;
//		delete[]next_root;
//	}
//};
//Product* create_product(int product_id, string& name) {
//	return new Product(product_id, name);
//}
//int main() {
//	AVLTree avl;
//	string product_name;
//	int product_id, choice;
//	while (true) {
//		cout << "\nEnter your choice:\n";
//		cout << "1.Insertion in database\n";
//		cout << "2.Removal from database\n";
//		cout << "3.Results of database\n";
//		cout << "4.Go back\n";
//		cout << "5.Go forward\n";
//		cout << "0.Exit\n\n";
//		cout << "Enter your choice: ";
//		cin >> choice;
//		if (choice == 1) {
//			cout << "Enter the product ID: ";	cin >> product_id;
//			cout << "Enter the name of the product: ";	cin.ignore();	getline(cin, product_name);
//			avl.insert(create_product(product_id, product_name));
//			cout << "\nProduct added successfully.\n";
//		}
//		else if (choice == 2) {
//			cout << "Enter the product ID: ";	cin >> product_id;
//			avl.remove(product_id);
//			cout << "\nProduct removed successfully.\n";
//			avl.Traversal();
//		}
//		else if (choice == 3) {
//			cout << "Products:\n";
//			avl.Traversal();
//		}
//		else if (choice == 4) {
//			avl.go_back();
//		}
//		else if (choice == 5) {
//			avl.go_forward();
//		}
//		else if (choice == 0) {
//			break;
//		}
//	}
//	return 0;
//}