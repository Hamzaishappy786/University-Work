//#include <iostream>
//using namespace std;
//struct Node {
//    int data;
//    int height;
//    Node* left;
//    Node* right;
//    Node(int data) : data(data), height(1), left(nullptr), right(nullptr) {}
//};
//class AVLTree {
//    Node* root;
//    int total_nodes;
//    int height(Node* node){
//        if (node == nullptr)    return 0;
//        return node->height;
//    }
//    int balanceFactor(Node* node) {
//        if (node == nullptr)    return 0;
//        return height(node->left) - height(node->right);
//    }
//    Node* rightRotation(Node* node) {
//        if (node == nullptr || node->left == nullptr) {
//            return node;
//        }
//        Node* temp = node->left;
//        Node* temp2 = temp->right;
//
//        temp->right = node;
//        node->left = temp2;
//
//        node->height = max(height(node->left), height(node->right)) + 1;
//        temp->height = max(height(temp->left), height(temp->right)) + 1;
//
//        return temp;
//    }
//
//    Node* leftRotation(Node* node) {
//        if (node->right == nullptr || node == nullptr) {
//            return node;
//        }
//        Node* temp = node->right;
//        Node* temp2 = temp->left;
//
//        temp->left = node;
//        node->right = temp2;
//
//        node->height = max(height(node->left), height(node->right)) + 1;
//        temp->height = max(height(temp->left), height(temp->right)) + 1;
//
//        return temp;
//    }
//    Node* insert(int data, Node* node) {
//        if (node == nullptr) {
//            return new Node(data);
//        }
//        if (data < node->data) {
//            node->left = insert(data, node->left);
//        }
//        else if (data > node->data) {
//            node->right = insert(data, node->right);
//        }
//        else if (data == node->data) {
//            cout << "Insertion not possible. Same element detected.";
//            return node;
//        }
//        int h = 0;
//        if (height(node->left) > height(node->right)) {
//            h = height(node->left) + 1;
//        }
//        else if (height(node->left) < height(node->right)) {
//            h = height(node->right) + 1;
//        }
//        node->height = h;
//
//        int balance_factor = balanceFactor(node);
//        if (balance_factor > 1 && data < node->left->data) {
//            return rightRotation(node);
//        }
//        else if (balance_factor > 1 && data > node->left->data) {
//            node->left = leftRotation(node->left);
//            return rightRotation(node);
//        }
//        else if (balance_factor > -1 && data < node->right->data) {
//            return leftRotation(node);
//        }
//        else if (balance_factor > -1 && data > node->right->data) {
//            node->right = rightRotation(node->right);
//            return leftRotation(node);
//        }
//        return node;
//    }
//
//    Node* deletion(int data, Node* root) {
//        if (root == nullptr) {
//            return root;
//        }
//        if (data < root->data) {
//            root->left = deletion(data, root->left);
//        }
//        else if (data > root->data) {
//            root->right = deletion(data, root->right);
//        }
//        else {
//            if (root->left == nullptr || root->right == nullptr) {
//                Node* temp = nullptr;
//                if (root->left != nullptr) {
//                    temp = root->left;
//                }
//                else if (root->right != nullptr ) {
//                    temp == root->right;
//                }
//                if (temp == nullptr) {
//                    temp = root;
//                    root = nullptr;
//                }
//                else {
//                    *root = *temp;
//                }
//                delete temp;
//            }
//            else {
//                Node* temp = minValueNode(root->right);
//                root->data = temp->data;
//                root->right = deletion(temp->data, root->right);
//            }
//        }
//        if (root == nullptr) {
//            return root;
//        }
//        root->height = 1 + max(height(root->left), height(root->right));
//        int balance = balanceFactor(root);
//        if (balance > 1 && balanceFactor(root->left) > 0) {
//            return rightRotation(root);
//        }
//        if (balance > 1 && balanceFactor(root->left) < 0) {
//            root->left = leftRotation(root->left);
//            return rightRotation(root);
//        }
//        if (balance < -1 && balanceFactor(root->right) < 0) {
//            return leftRotation(root);
//        }
//        if (balance < -1 && balanceFactor(root->right) > 0) {
//            root->right = rightRotation(root->right);
//            return leftRotation(root);
//        }
//
//        return root;
//    }
//
//
//    Node* minValueNode(Node* node) {
//        if (node == nullptr) {
//            return node;
//        }
//        Node* current = node;
//        while (current->left != nullptr) {
//            current = current->left;
//        }
//        return current;
//    }
//
//    void inorderTraversal(Node* node) {
//        if (node != nullptr) {
//            inorderTraversal(node->right);
//            total_nodes += 1;
//            cout << node->data << " ";
//            inorderTraversal(node->left);
//        }
//    }
//    int second_highest(Node* node, int& total) {
//        if (node == nullptr) {
//            return -1;
//        }
//        int result = second_highest(node->right, total);
//        if (total == 0) {
//            return result;
//        }
//        total--;
//        if (total == 1) {
//            return node->data;
//        }
//        return second_highest(node->left, total);
//    }
//public:
//    AVLTree() :root(nullptr), total_nodes(0) {}
//    void insertion(int data) {
//        root = insert(data, root);
//    }
//    int second_highest_taken() {
//        int total = total_nodes;
//        int data = second_highest(root, total);
//        return data;
//    }
//    void remove(int data) {
//        root = deletion(data, root);
//    }
//    void display() {
//        inorderTraversal(root);
//    }
//};
//
//int main() {
//    AVLTree avl;
//    avl.insertion(26);  avl.insertion(31);  avl.insertion(23);  avl.insertion(34);  avl.insertion(41);
//    avl.display();
//    cout << endl;
//    cout << avl.second_highest_taken();
//    cout << endl;
//    avl.remove(34);
//    avl.display();
//    return 0;
//}