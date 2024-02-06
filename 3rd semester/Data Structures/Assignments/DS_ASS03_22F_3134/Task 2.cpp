//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* left;
//	Node* right;
//	Node(int value) {
//		data = value;
//		left = nullptr;
//		right = nullptr;
//	}
//	Node* insert(Node* root, int data) {
//		if (root == nullptr) {
//			return new Node(data);
//		}
//		if (data < root->data) {
//			root->left = insert(root->left, data);
//		}
//		else if (data >= root->data) {
//			root->right = insert(root->right, data);
//		}
//		return root;
//	}
//	void displayTree(Node* root) {
//		if (root == nullptr) {
//			return;
//		}
//		displayTree(root->left);
//		cout << root->data << " ";
//		displayTree(root->right);
//	}
//};
//
//Node* convertBSTtoGreaterTree(Node* root, int& sum) {
//	if (root == nullptr) {
//		return nullptr;
//	}
//	convertBSTtoGreaterTree(root->right, sum);
//	sum = sum + root->data;
//	root->data = sum;
//	convertBSTtoGreaterTree(root->left, sum);
//	return root;
//}
//int main()
//{
//	Node* current = nullptr;
//	int num_of_nodes, sum = 0;
//	cout << "Enter the number of nodes in the tree: ";
//	cin >> num_of_nodes;
//	int* arr = new int[num_of_nodes];
//	for (int i = 0; i < num_of_nodes; i++) {
//		cout << "Enter the " << i + 1 << " node data of the tree: ";
//		cin >> arr[i];
//		current = current->insert(current, arr[i]);
//	}
//	Node* greaterTree = convertBSTtoGreaterTree(current, sum);
//	cout << "\nNew tree: ";
//	greaterTree->displayTree(greaterTree);
//	delete[] arr;
//	return 0;
//}