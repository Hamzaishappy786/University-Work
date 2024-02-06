//#include <iostream>
//using namespace std;
//
////AVL Tree node struct
//struct Node {
//    int data, height;
//    Node* left;
//    Node* right;
//};
//int height(Node* node) {    //getter for height
//    if (node == nullptr)
//        return 0;
//    return node->height;
//}
//int total_nodes(Node* root) {
//    if (root == nullptr) {
//        return 0;
//    }
//    int left_node = total_nodes(root->left);
//    int right_node = total_nodes(root->right);
//    return 1 + left_node + right_node;
//}
//int max_num(int num1, int num2) { //for getting maximum value
//    if (num1 > num2) {
//        return num1;
//    }
//    else {
//        return num2;
//    }
//}
//Node* newNode(int key) {    //for the making of a new node
//    Node* node = new Node();    //does the work of the constructor
//    node->data = key;
//    node->left = nullptr;
//    node->right = nullptr;
//    node->height = 1;   //starting height of nodes is 1
//    return node;
//}
//Node* rightRotate(Node* y) {    //right rotation
//    Node* x = y->left;  //left of subtree
//    Node* T2 = x->right;    //right of y subtree
//
//    x->right = y;   //swapping values
//    y->left = T2;   //rotation of subtree y
//
//    y->height = max_num(height(y->left), height(y->right)) + 1; //updation of height in subtrees
//    x->height = max_num(height(x->left), height(x->right)) + 1;
//    return x;
//}
//
//// Left rotate subtree rooted with x
//Node* leftRotate(Node* x) { //left rotation
//    Node* y = x->right; //right of subtree
//    Node* T2 = y->left; //left of x subtree
//
//    y->left = x;    //right of subtree
//    x->right = T2;  //rotation of x subtree
//
//    x->height = max_num(height(x->left), height(x->right)) + 1; //updation of height in subtrees
//    y->height = max_num(height(y->left), height(y->right)) + 1;
//    return y;
//}
//int getBalance(Node* node) {    //getter for balance factor
//    if (node == nullptr)
//        return 0;
//    return height(node->left) - height(node->right);
//}
//
//Node* insert(Node* node, int key) { //insertion function
//    if (node == nullptr)    //check for empty tree
//        return newNode(key);
//
//    if (key < node->data)    //simple BST insertion
//        node->left = insert(node->left, key);
//    else if (key > node->data)
//        node->right = insert(node->right, key);
//    else
//        return node;  //for no duplicates, '=' wasn't used
//
//    node->height = 1 + max_num(height(node->left), height(node->right));    //height updation
//
//    int balance = getBalance(node); //for checking whether tree are balanced or not
//
//    if (balance > 1 && key < node->left->data)   //left-left case
//        return rightRotate(node);
//
//    if (balance < -1 && key > node->right->data) //right-right case
//        return leftRotate(node);
//
//    if (balance > 1 && key > node->left->data) { // left-right case
//        node->left = leftRotate(node->left);
//        return rightRotate(node);
//    }
//
//    if (balance < -1 && key < node->right->data) { // right-left case
//        node->right = rightRotate(node->right);
//        return leftRotate(node);
//    }
//    return node;
//}
//Node* minValueNode(Node* node) {    //for minimum value in tree
//    Node* current = node;
//    while (current->left != nullptr)
//        current = current->left;    //traversing left till we get to null
//    return current;
//}
//Node* deleteNode(Node* root, int key) {
//    if (root == nullptr)
//        return root;
//
//    if (key < root->data)
//        root->left = deleteNode(root->left, key);
//    else if (key > root->data)
//        root->right = deleteNode(root->right, key);
//    else {
//        if (root->left == nullptr || root->right == nullptr) {
//            Node* temp = nullptr; //node with no child case
//            if (root->left != nullptr) {
//                temp = root->left;
//            }
//            else if (root->right != nullptr) {//node with no child case
//                temp = root->right;
//            }
//
//            if (temp == nullptr) {
//                temp = root;
//                root = nullptr;
//            }
//            else
//                *root = *temp;  //node with only one child
//
//            delete temp;
//        }
//        else {
//            Node* temp = minValueNode(root->right); //for getting smallest in right subtree
//            root->data = temp->data;  //for changing data into child node
//            root->right = deleteNode(root->right, temp->data);   //then delete right node
//        }
//    }
//    if (root == nullptr)
//        return root;
//
//    root->height = 1 + max_num(height(root->left), height(root->right));
//    int balance = getBalance(root);
//    if (balance > 1 && getBalance(root->left) >= 0) //left-left case
//        return rightRotate(root);
//
//    if (balance > 1 && getBalance(root->left) < 0) {    //left-right case
//        root->left = leftRotate(root->left);
//        return rightRotate(root);
//    }
//
//    if (balance < -1 && getBalance(root->right) <= 0)   //right-right case
//        return leftRotate(root);
//
//    if (balance < -1 && getBalance(root->right) > 0) {  //right-left case
//        root->right = rightRotate(root->right);
//        return leftRotate(root);
//    }
//
//    return root;
//}
//void inorderTraversal(Node* root) {
//    if (root != nullptr) {
//        inorderTraversal(root->left);
//        cout << root->data << " ";
//        inorderTraversal(root->right);
//    }
//}
//Node* kthLargestNode(Node* node, int& k)
//{
//    if (node == nullptr) {
//        return nullptr;
//    }
//    Node* right = kthLargestNode(node->right, k);
//
//    if (right != nullptr) {
//        return right;
//    }
//    k--;
//    if (k == 0) {
//        return node;
//    }
//    return kthLargestNode(node->left, k);
//}
//
//Node* deleteKthLargest(Node* root, int kth_term)
//{
//    int count = kth_term;
//    Node* kthLargest = kthLargestNode(root, count);
//
//    if (kthLargest == nullptr)
//    {
//        return root;
//    }
//    root = deleteNode(root, kthLargest->data);
//    return root;
//}
//int main() {
//    int n;
//    cout << "Enter the number of elements: ";
//    cin >> n;
//    Node* root = nullptr;
//
//    cout << "Enter the elements: \n";
//    for (int i = 0; i < n; ++i) {
//        int data;
//        cout << "Enter the element " << i + 1 << ": ";  cin >> data;
//        root = insert(root, data);
//    }
//    cout << "Inorder traversal of the AVL tree: ";
//    inorderTraversal(root);
//    cout << endl;
//    while (true) {
//        int kth_term;
//        cout << "\nEnter the value of k to delete the kth largest element(press 0 to exit): ";
//        cin >> kth_term;
//        if (kth_term > 0 && kth_term <= n && kth_term < total_nodes(root)) {    //k cannot be higher than n or less than that of 0
//            cout << "Inorder traversal after deleting the kth largest element: ";
//            deleteKthLargest(root, kth_term);
//            inorderTraversal(root);
//            cout << endl;
//        }
//        else if (kth_term == 0) {
//            cout << "Thanks for using our code. Good Bye.\n";
//            break;
//        }
//        else {
//            cout << "\nInvalid value of k. Please enter a value between 1 and " << total_nodes(root);
//        }
//    }
//    return 0;
//}