//#include <iostream>
//#include <string>
//using namespace std;
//struct StudentNode {
//	int student_ID;
//	string student_name, department;
//	StudentNode* left, * right;
//	int height;
//
//	StudentNode(int st_id, string& name, string& dept) {
//		student_ID = st_id;
//		student_name = name;
//		department = dept;
//		left = nullptr;	right = nullptr;
//		height = 1;
//	}
//};
//class AVLTree {
//private:
//	StudentNode* root_node;
//
//	StudentNode* insert(StudentNode* node, int st_ID, string& st_name, string& dept) { //insertion function
//		if (node == nullptr)    //check for empty tree
//			return new StudentNode(st_ID, st_name, dept);
//
//		if (st_ID < node->student_ID)    //simple BST insertion
//			node->left = insert(node->left, st_ID, st_name, dept);
//		else if (st_ID > node->student_ID)
//			node->right = insert(node->right, st_ID, st_name, dept);
//		else
//			return node;  //for no duplicates, '=' wasn't used
//
//		node->height = 1 + max_num(height(node->left), height(node->right));    //height updation
//
//		int balance = balance_factor(node); //for checking whether tree are balanced or not
//
//		if (balance > 1 && st_ID < node->left->student_ID)   //left-left case
//			return rightRotate(node);
//
//		if (balance < -1 && st_ID > node->right->student_ID) //right-right case
//			return leftRotate(node);
//
//		if (balance > 1 && st_ID > node->left->student_ID) { // left-right case
//			node->left = leftRotate(node->left);
//			return rightRotate(node);
//		}
//
//		if (balance < -1 && st_ID < node->right->student_ID) { // right-left case
//			node->right = rightRotate(node->right);
//			return leftRotate(node);
//		}
//		return node;
//	}
//	int balance_factor(StudentNode* node) {
//		if (node == nullptr) { return 0; }
//		return height(node->left) - height(node->right);
//	}
//	int height(StudentNode* node) {    //getter for height
//		if (node == nullptr) {
//			return 0;
//		}
//		return root_node->height;
//	}
//	int max_num(int num1, int num2) { //for getting maximum value
//		if (num1 > num2) {
//			return num1;
//		}
//		else {
//			return num2;
//		}
//	}
//	StudentNode* rightRotate(StudentNode* y) {    //right rotation
//		StudentNode* x = y->left;  //left of subtree
//		StudentNode* T2 = x->right;    //right of y subtree
//
//		x->right = y;   //swapping values
//		y->left = T2;   //rotation of subtree y
//
//		y->height = max_num(height(y->left), height(y->right)) + 1;
//		x->height = max_num(height(x->left), height(x->right)) + 1;
//
//		return x;
//	}
//
//	StudentNode* leftRotate(StudentNode* x) { //left rotation
//		StudentNode* y = x->right; //right of subtree
//		StudentNode* T2 = y->left; //left of x subtree
//
//		y->left = x;    //right of subtree
//		x->right = T2;  //rotation of x subtree
//
//		y->height = max_num(height(y->left), height(y->right)) + 1;
//		x->height = max_num(height(x->left), height(x->right)) + 1;
//
//		return y;
//	}
//	StudentNode* minValueNode(StudentNode* node) {    //for minimum value in tree
//		StudentNode* current = node;
//		while (current->left != nullptr)
//			current = current->left;    //traversing left till we get to null
//		return current;
//		}
//	StudentNode* deleteNode(StudentNode* root, int st_id) {
//		if (root == nullptr)
//			return root;
//
//		if (st_id < root->student_ID)
//			root->left = deleteNode(root->left, st_id);
//		else if (st_id > root->student_ID)
//			root->right = deleteNode(root->right, st_id);
//		else {
//			if (root->left == nullptr || root->right == nullptr) {
//				StudentNode* temp = nullptr; //node with no child case
//				if (root->left != nullptr) {
//					temp = root->left;
//				}
//				else if (root->right != nullptr) {//node with no child case
//					temp = root->right;
//				}
//
//				if (temp == nullptr) {
//					temp = root;
//					root = nullptr;
//				}
//				else
//					*root = *temp;  //node with only one child
//
//	            delete temp;
//		    }
//			else {
//				StudentNode* temp = minValueNode(root->right); //for getting smallest in right subtree
//	            root->student_ID = temp->student_ID;  //for changing data into child node
//		        root->right = deleteNode(root->right, temp->student_ID);   //then delete right node
//			}
//		}
//		if (root == nullptr)
//			return root;
//
//	    root->height = 1 + max_num(height(root->left), height(root->right));
//		int balance = balance_factor(root);
//		if (balance > 1 && balance_factor(root->left) >= 0) //left-left case
//			return rightRotate(root);
//
//	    if (balance > 1 && balance_factor(root->left) < 0) {    //left-right case
//		    root->left = leftRotate(root->left);
//			return rightRotate(root);
//		}
//
//	    if (balance < -1 && balance_factor(root->right) <= 0)   //right-right case
//		    return leftRotate(root);
//
//		if (balance < -1 && balance_factor(root->right) > 0) {  //right-left case
//			root->right = rightRotate(root->right);
//			return leftRotate(root);
//		}
//
//		return root;
//	}
//	void inorderTraversal(StudentNode* root) {
//		if (root != nullptr) {
//			inorderTraversal(root->left);
//			cout << "Name: " << root->student_name << endl;
//			cout << "Student ID: " << root->student_ID << endl;
//			cout << "Department: " << root->department << endl << endl;
//			inorderTraversal(root->right);
//		}
//	}
//	StudentNode* search(StudentNode* node, int st_id) {
//		if (node == nullptr || node->student_ID == st_id) {
//			return node;
//		}
//		if (st_id < node->student_ID) {
//			return search(node->left, st_id);
//		}
//		else if (st_id > node->student_ID) {
//			return search(node->right, st_id);
//		}
//	}
//public:
//	AVLTree() {
//		root_node = nullptr;
//	}
//	void insert_student_details(int st_id, string& st_name, string& dept) {
//		root_node = insert(root_node, st_id, st_name, dept);
//	}
//	void display_student_details() {
//		cout << "\nStudent's details: \n";
//		inorderTraversal(root_node);
//		cout << endl;
//	}
//	int id_setter(int student_ID, int dept) {
//		int id = 0;
//		while (student_ID != 0) {
//			int last_digit = student_ID % 10;
//			id = id * 10 + last_digit;
//			student_ID /= 10;
//		}
//		if (dept == 1) id = id * 10 + 1;
//		else if (dept == 2) id = id * 10 + 2;
//		else if (dept == 3) id = id * 10 + 3;
//		else if (dept == 4) id = id * 10 + 4;
//		else if (dept == 5) id = id * 10 + 5;
//		int reverse_id = 0;
//		while (id != 0) {
//			int last_digit = id % 10;
//			reverse_id = reverse_id * 10 + last_digit;
//			id /= 10;
//		}
//		return reverse_id;
//	}
//	int id_setter_change_dept(int st_id, int dept) {
//		int id = 0;
//		while (st_id != 0) {
//			int last_digit = st_id % 10;
//			id = id * 10 + last_digit;
//			st_id /= 10;
//		}
//		id = id / 10;
//		if (dept == 1) id = id * 10 + 1;
//		else if (dept == 2) id = id * 10 + 2;
//		else if (dept == 3) id = id * 10 + 3;
//		else if (dept == 4) id = id * 10 + 4;
//		else if (dept == 5) id = id * 10 + 5;
//		int reverse_id = 0;
//		while (id != 0) {
//			int last_digit = id % 10;
//			reverse_id = reverse_id * 10 + last_digit;
//			id /= 10;
//		}
//		return reverse_id;
//	}
//	void change_department(int st_id, string new_dept) {
//		StudentNode* node = search(root_node, st_id);
//		if (node != nullptr) {
//			node->department = new_dept;
//			cout << "Department successfully changed to: " << new_dept << endl;
//			if (new_dept == "CS" || new_dept == "cs") {
//				st_id = id_setter_change_dept(st_id, 1);
//			}
//			else if (new_dept == "SE" || new_dept == "se") {
//				st_id = id_setter_change_dept(st_id, 2);
//			}
//			else if (new_dept == "EE" || new_dept == "ee") {
//				st_id = id_setter_change_dept(st_id, 3);
//			}
//			else if (new_dept == "S&H" || new_dept == "SandH" || new_dept == "SnH" || new_dept == "SNH") {
//				st_id = id_setter_change_dept(st_id, 4);
//			}
//			else if (new_dept == "FSM" || new_dept == "fsm") {
//				st_id = id_setter_change_dept(st_id, 5);
//			}
//			node->student_ID = st_id;
//		}
//		else {
//			cout << "ID: " << node->student_ID << " not found.\n";
//		}
//	}
//	void remove_student(int st_id) {
//		root_node = deleteNode(root_node, st_id);
//		cout << "Student with " << root_node->student_ID << " has been removed.\n";
//	}
//};
//int main()
//{
//	int choice;
//	int student_ID, id, st_id;
//	string name, dept;
//	AVLTree students;
//	while (true) {
//		cout << "\n1. Add a student\n";
//		cout << "2. Change student department\n";
//		cout << "3. Remove student\n";
//		cout << "4. Display student deatils\n";
//		cout << "0. Exit\n";
//		cout << "\nEnter your choice: ";	cin >> choice;
//		if (choice == 1) {
//			cout << "Enter the roll number of the student: ";	cin >> student_ID;
//			cout << "Enter the name of the student: ";	cin.ignore();	getline(cin, name);
//			cout << "Enter the deptartment of the student: ";	getline(cin, dept);
//			id = 0;
//			if (dept == "CS" || dept == "cs") {
//				student_ID = students.id_setter(student_ID, 1);
//			}
//			else if (dept == "SE" || dept == "se") {
//				student_ID = students.id_setter(student_ID, 2);
//			}
//			else if (dept == "EE" || dept == "ee") {
//				student_ID = students.id_setter(student_ID, 3);
//			}
//			else if (dept == "S&H" || dept == "S and H" || dept == "SnH" || dept == "SNH") {
//				student_ID = students.id_setter(student_ID, 4);
//			}
//			else if (dept == "FSM" || dept == "fsm") {
//				student_ID = students.id_setter(student_ID, 5);
//			}
//			students.insert_student_details(student_ID, name, dept);
//		}
//		else if (choice == 2) {
//			cout << "Enter the roll number of the student: ";	cin >> student_ID;
//			cout << "Enter the deptartment of the student: ";	cin.ignore();	getline(cin, dept);
//			students.change_department(student_ID, dept);
//		}
//		else if (choice == 3) {
//			cout << "Enter the roll number of the student: ";	cin >> student_ID;
//			students.remove_student(student_ID);
//		}
//		else if (choice == 4) {
//			students.display_student_details();
//		}
//		else if (choice == 0) {
//			cout << "Thank you for using our program. Good Bye.\n";
//			break;
//		}
//	}
//	return 0;
//}