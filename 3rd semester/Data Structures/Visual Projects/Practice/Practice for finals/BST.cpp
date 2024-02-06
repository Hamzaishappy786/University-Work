//#include <iostream>
//using namespace std;
//struct Node {
//    int data;
//    Node* left;
//    Node* right;
//    Node(int data) : data(data), left(nullptr), right(nullptr) {}
//};
//class BST {
//    Node* head;
//    int total_nodes;
//    Node* insert_recursion(int data, Node* node) {
//        if (node == nullptr) {
//            return new Node(data);
//        }
//        if (data < node->data) {
//            node->left = insert_recursion(data, node->left);
//        }
//        else if (data > node->data) {
//            node->right = insert_recursion(data, node->right);
//        }
//        else if (node->data == data) {
//            cout << "Equal elements cannot be added.";
//        }
//        return node;
//    }
//
//    void inorder_traversal(Node* node) {
//        if (node != nullptr) {
//            total_nodes += 1;
//            inorder_traversal(node->left);
//            cout << node->data << " ";
//            inorder_traversal(node->right);
//        }
//    }
//
//    void preorder_traversal(Node* node) {
//        if (node != nullptr) {
//            cout << node->data << " ";
//            preorder_traversal(node->left);
//            preorder_traversal(node->right);
//        }
//    }
//
//    void postorder_traversal(Node* node) {
//        if (node != nullptr) {
//            postorder_traversal(node->left);
//            postorder_traversal(node->right);
//            cout << node->data << " ";
//        }
//    }
//
//    int height_bst(Node* node) {
//        if (node == nullptr) {
//            return 0;
//        }
//        int left = height_bst(node->left);
//        int right = height_bst(node->right);
//        return max(left, right) + 1;
//    }
//
//    Node* minValueNode(Node* root) {
//        Node* current = root;
//        while (current->left != nullptr) {
//            current = current->left;
//        }
//        return current;
//    }
//    Node* deletion(Node* root, int data) {
//        if (root == nullptr) {
//            return root;
//        }
//        if (data < root->data) {
//            root->left = deletion(root->left, data);
//        }
//        else if (data > root->data) {
//            root->right = deletion(root->right, data);
//        }
//        else if (root->data == data) {
//            if (root->left == nullptr) {
//                Node* temp = root->right;
//                delete root;
//                return temp;
//            }
//            else if (root->right == nullptr) {
//                Node* temp = root->left;
//                delete root;
//                return temp;
//            }
//            Node* temp = minValueNode(root->right);
//            root->data = temp->data;
//            root->right = deletion(root->right, temp->data);
//        }
//        return root;
//    }
//
//    void deleteTree(Node* node) {
//        if (node != nullptr) {
//            deleteTree(node->left);
//            deleteTree(node->right);
//            delete node;
//        }
//    }
//
//    bool equal(Node* node, Node* second_node) {
//        if (node == nullptr && second_node == nullptr) {
//            return true;
//        }
//        if (node == nullptr || second_node == nullptr) {
//            return false;
//        }
//        if (node->data != second_node->data) {
//            return false;
//        }
//        return (equal(node->left, second_node->left) && equal(node->right, second_node->right));
//    }
//
//public:
//    BST() : head(nullptr), total_nodes(0) {}
//
//    void insert(int data) {
//        head = insert_recursion(data, head);
//    }
//
//    void inorder() {
//        inorder_traversal(head);
//    }
//
//    void preorder() {
//        preorder_traversal(head);
//    }
//
//    void postorder() {
//        postorder_traversal(head);
//    }
//
//    void total_node() {
//        cout << "Total number of nodes are: " << total_nodes << endl;
//    }
//
//    void height() {
//        int heights = height_bst(head);
//        cout << "Height of the tree is: " << heights << endl;
//    }
//
//    int minimum() {
//        Node* current = head;
//        while (current->left != nullptr) {
//            current = current->left;
//        }
//        return current->data;
//    }
//
//    int maximum() {
//        Node* current = head;
//        while (current->right != nullptr) {
//            current = current->right;
//        }
//        return current->data;
//    }
//
//    void deletion_of_node(int data) {
//        head = deletion(head, data);
//    }
//
//    bool equal_or_not(BST& second) {
//        return equal(head, second.head);
//    }
//
//    ~BST() {
//        deleteTree(head);
//    }
//};
//
//int main() {
//    BST tree, tree2;
//    tree.insert(12);    tree2.insert(12);
//    tree.insert(8); tree2.insert(8);
//    tree.insert(26);    tree2.insert(26);
//    tree.insert(24);    tree2.insert(24);
//    tree.insert(28);    tree2.insert(28);
//
//    cout << "Inorder Traversal: ";
//    tree.inorder();
//    cout << endl;
//
//    cout << "Preorder Traversal: ";
//    tree.preorder();
//    cout << endl;
//
//    cout << "Postorder Traversal: ";
//    tree.postorder();
//    cout << endl;
//
//    tree.total_node();
//
//    cout << "Height of the Tree: ";
//    tree.height();
//
//    cout << "Minimum value in the tree: " << tree.minimum() << endl;
//    cout << "Maximum value in the tree: " << tree.maximum() << endl;
//
//    cout << "Deletion of node with data 2" << endl;
//    tree.deletion_of_node(27);
//
//    cout << "Inorder Traversal after deletion: ";
//    tree.inorder(); cout << endl;
//    tree.preorder();     cout << endl;
//    tree.postorder();    cout << endl;
//    cout << endl;
//    cout << tree.equal_or_not(tree2);
//    return 0;
//}
