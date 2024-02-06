//#include <iostream>
//using namespace std;
//struct AVLNode {
//	int key;
//	AVLNode* left, * right;
//	int height;
//};
//int height(AVLNode* N) {
//	if (N == NULL) {
//		return 0;
//	}
//	return N->height;
//}
//int getBalanceFactor(AVLNode* N) {
//	if (N == NULL) {
//		return 0;
//	}
//	return height(N->left) - height(N->right);
//}
//bool isAVLTree(AVLNode* root) {
//	if (root == nullptr) {
//		return true;
//	}
//	int balance = getBalanceFactor(root);
//	balance = abs(balance);
//	return balance <= 1 && isAVLTree(root->left) && isAVLTree(root->right);
//}
//AVLNode* LCA(AVLNode* root, int low, int high) {
//	while (root != nullptr) {
//		if (root->key > high) {
//			root = root->left;
//		}
//		else if (root->key < low) {
//			root = root->right;
//		}
//		else {
//			break;
//		}
//	}
//	return root;
//}
//bool checkSubtreeAVLTree(AVLNode* root, int low, int right) {
//	AVLNode* subTree = LCA(root, low, right);
//	return isAVLTree(subTree);
//}
//AVLNode* LLRotation(AVLNode* root) {
//	AVLNode* newRoot = root->left;
//	root->left = newRoot->right;
//	newRoot->right = root;
//	int maximum, newrootmax;
//	if (height(root->left) > height(root->right)) {
//		maximum = root->left->key;
//	}
//	else {
//		maximum = root->right->key;
//	}
//	if (height(root->left) > height(root->right)) {
//		newrootmax = root->left->key;
//	}
//	else {
//		newrootmax = root->right->key;
//	}
//	root->height = 1 + maximum + newrootmax;
//	return newRoot;
//}
//AVLNode* RRRotation(AVLNode* root) {
//	AVLNode* newRoot = root->right;
//	root->left = newRoot->left;
//	newRoot->left = root;
//	int maximum, newrootmax;
//	if (height(root->left) > height(root->right)) {
//		maximum = root->left->key;
//	}
//	else {
//		maximum = root->right->key;
//	}
//	if (height(root->left) > height(root->right)) {
//		newrootmax = root->left->key;
//	}
//	else {
//		newrootmax = root->right->key;
//	}
//	root->height = 1 + maximum + newrootmax;
//	return newRoot;
//}
//AVLNode* LRRotation(AVLNode* root) {
//	root->left = RRRotation(root->left);
//	return LLRotation(root);
//}
//AVLNode* RLRotation(AVLNode* root) {
//	root->left = LLRotation(root->left);
//	return RRRotation(root);
//}
//AVLNode* insert(AVLNode* root, int data) {
//	if (root == nullptr) {
//		AVLNode* newNode = new AVLNode();
//		newNode->key = data;
//		newNode->left = nullptr;
//		newNode->right = nullptr;
//		newNode->height = 1;
//		return newNode;
//	}
//	if (data < root->key) {
//		root->left = insert(root->left, data);
//	}
//	else if (data > root->key) {
//		root->right = insert(root->right, data);
//	}
//	else {
//		return root;
//	}
//	int maximum, newrootmax, balance;
//	if (height(root->left) > height(root->right)) {
//		maximum = root->left->key;
//	}
//	else {
//		maximum = root->right->key;
//	}
//	root->height = 1 + maximum;
//	balance = getBalanceFactor(root);
//	if (balance > 1) {
//		if (data < root->left->key) {
//			return LLRotation(root);
//		}
//		else {
//			return LRRotation(root);
//		}
//	}
//	else if (balance < -1) {
//		if (data > root->right->key) {
//			return RRRotation(root);
//		}
//		else {
//			return RLRotation(root);
//		}
//	}
//	return root;
//}
//void deleteTree(AVLNode* root) {
//	if (root != nullptr) {
//		deleteTree(root->left);
//		deleteTree(root->right);
//		delete root;
//	}
//}
//int main()
//{
//	AVLNode* tree = nullptr;
//	int choice;
//	while (true) {
//		cout << "1.Insert node\n";
//		cout << "2.Check if the entire tree is AVL\n";
//		cout << "3.Check if subtree is AVL\n";
//		cout << "0.Exit\n";
//		cout << "\nEnter your choice: ";	cin >> choice;
//		if (choice == 1) {
//			int data;
//			cout << "Enter the data of the node: ";	cin >> data;
//			insert(tree, data);
//		}
//		else if (choice == 2) {
//			if (isAVLTree(tree) == true) {
//				cout << "This is an AVL tree.\n";
//			}
//			else {
//				cout << "This is not an AVL tree.\n";
//			}
//		}
//		else if (choice == 3) {
//			int low, high;
//			cout << "Enter the low value of the subtree: ";	cin >> low;
//			cout << "Enter the high value of the subtree: ";	cin >> high;
//			if (checkSubtreeAVLTree(tree, low, high)) {
//				cout << "The subtree within range [" << low << ", " << high << "] is an AVL tree.\n";
//			}
//			else {
//				cout << "The subtree within range [" << low << ", " << high << "] is an not AVL tree.\n";
//			}
//		}
//		else if (choice == 0) {
//			cout << "Thank you for using our program. Good bye.";
//			break;
//		}
//	}
//	deleteTree(tree);
//	return 0;
//}