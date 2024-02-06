//#include <iostream>
//using namespace std;
//struct Node {
//    char data;
//    int height;
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
//int main()
//{
//    Node* root = nullptr;
//    root = insert(root, 'L');   //nodes inserted
//    root = insert(root, 'D');
//    root = insert(root, 'P');
//    root = insert(root, 'C');
//    root = insert(root, 'H');
//    root = insert(root, 'F');
//    root = insert(root, 'J');
//    root = insert(root, 'A');
//
//    cout << "Original Tree: ";
//    inorderTraversal(root); //printing out tree
//
//    char nodes_to_del[5] = { 'J','C','L','D','A' }; //nodes for deletion
//    cout << "\nNodes to delete: J, C, L, D, A\n";
//    for (int i = 0; i < 5; i++) {
//        root = deleteNode(root, nodes_to_del[i]);
//        cout << "Tree after deleting " << nodes_to_del[i] << ": ";
//        inorderTraversal(root);
//        cout << endl;
//    }
//	return 0;
//}