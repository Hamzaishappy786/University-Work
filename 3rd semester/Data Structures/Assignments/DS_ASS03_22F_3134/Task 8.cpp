//#include <iostream>
//#include <string>
//using namespace std;
//struct SongNode {
//	string song_name;
//	int frequency;
//	SongNode* left, * right;
//	SongNode* next;
//	SongNode(string song_name, int freq) {
//		this->song_name = song_name;
//		this->frequency = freq;
//		left = nullptr;		right = nullptr;	next = nullptr;
//	}
//};
//class AVLTree {
//private:
//	SongNode* root_node;
//
//	SongNode* insert(SongNode* node, string song, int freq) { //insertion function
//		if (node == nullptr)    //check for empty tree
//			return new SongNode(song, freq);
//
//	    if (freq < node->frequency)    //simple BST insertion
//		    node->left = insert(node->left, song, freq);
//		else if (freq > node->frequency)
//	        node->right = insert(node->right, song, freq);
//		if (freq == node->frequency) {
//			SongNode* current = node;
//			while (current->next != nullptr) {
//				current = current->next;
//			}
//			current->next = new SongNode(song, freq);
//			return node;
//		}
//
//	    node->frequency = 1 + max_num(height(node->left), height(node->right));    //height updation
//
//	    int balance = balance_factor(node); //for checking whether tree are balanced or not
//
//	    if (balance > 1 && freq < node->left->frequency)   //left-left case
//		    return rightRotate(node);
//
//	    if (balance < -1 && freq > node->right->frequency) //right-right case
//		    return leftRotate(node);
//
//		if (balance > 1 && freq > node->left->frequency) { // left-right case
//			node->left = leftRotate(node->left);
//			return rightRotate(node);
//		}
//
//		if (balance < -1 && freq < node->right->frequency) { // right-left case
//			node->right = rightRotate(node->right);
//			return leftRotate(node);
//		}
//		return node;
//	}
//	int balance_factor(SongNode* node) {
//		if (node == nullptr) { return 0; }
//		return height(node->left) - height(node->right);
//	}
//	int height(SongNode* node) {    //getter for height
//		if (node == nullptr) {
//			return 0;
//		}
//		return max_num(height(node->left), height(node->right)) + 1;
//	}
//	int max_num(int num1, int num2) { //for getting maximum value
//	    if (num1 > num2) {
//		    return num1;
//		}
//		else {
//	        return num2;
//		}
//	}
//	SongNode* rightRotate(SongNode* y) {    //right rotation
//		SongNode* x = y->left;  //left of subtree
//		SongNode* T2 = x->right;    //right of y subtree
//
//		x->right = y;   //swapping values
//		y->left = T2;   //rotation of subtree y
//
//		y->frequency = 1 + max_num(height(y->left), height(y->right));
//		x->frequency = 1 + max_num(height(x->left), height(x->right));
//		return x;
//	}
//
//	SongNode* leftRotate(SongNode* x) { //left rotation
//		SongNode* y = x->right; //right of subtree
//		SongNode* T2 = y->left; //left of x subtree
//
//		y->left = x;    //right of subtree
//		x->right = T2;  //rotation of x subtree
//
//		x->frequency = 1 + max_num(height(x->left), height(x->right));
//		y->frequency = 1 + max_num(height(y->left), height(y->right));
//		return y;
//	}
//	SongNode* findSong(SongNode* node, string song_name) {
//		if (node == nullptr) {
//			return nullptr;
//		}
//		SongNode* current_song = node;
//		while (current_song != nullptr) {
//			if (current_song->song_name == song_name) {
//				return current_song;
//			}
//			current_song = current_song->next;
//		}
//		SongNode* left = findSong(node->left, song_name);
//		if (left != nullptr) { return left; }
//		SongNode* right = findSong(node->right, song_name);
//		if (right != nullptr) { return right; }
//
//		return nullptr;
//	}
//	SongNode* playSong(SongNode* node, string song_name) {
//		if (node == nullptr) {
//			return nullptr;
//		}
//		SongNode* current_song_node = node;
//		while (current_song_node != nullptr) {
//			if (current_song_node->song_name == song_name) {
//				current_song_node->frequency++;
//				cout << "\nSong '" << current_song_node->song_name << "' has been played.\n";
//				cout << "New frequency: " << current_song_node->frequency << endl;
//				return current_song_node;
//			}
//			current_song_node = current_song_node->next;
//		}
//		SongNode* left = playSong(node->left, song_name);
//		if (left != nullptr) { return left; }
//		SongNode* right = playSong(node->right, song_name);
//		if (right != nullptr) { return right; }
//		return nullptr;
//	}
//	void inorderTraversal(SongNode* root) {
//		if (root != nullptr) {
//			inorderTraversal(root->left);
//			SongNode* current = root;
//			while (current != nullptr) {
//				cout << "\nSong name: " << current->song_name << endl;
//				cout << "Frequency: " << current->frequency << endl;
//				current = current->next;
//			}
//			inorderTraversal(root->right);
//		}
//	}
//
//public:
//	AVLTree() {
//		root_node = nullptr;
//	}
//
//	void play_song(string song_name) {
//		playSong(root_node, song_name);
//	}
//	void insert_song(string song_name, int freq) {
//		root_node = insert(root_node, song_name, freq);
//	}
//	void display_plalist() {
//		cout << "\nPlaylist: ";
//		inorderTraversal(root_node);
//		cout << endl;
//	}
//};
//int main()
//{
//	int choice, frequency;
//	string song_name;
//	AVLTree playlist;
//	playlist.insert_song("Song_A", 1);
//	playlist.insert_song("Song_B", 5);
//	playlist.insert_song("Song_C", 9);
//	playlist.insert_song("Song_D", 2);
//	playlist.insert_song("Song_E", 4);
//	playlist.insert_song("Song_F", 6);
//	playlist.insert_song("Song_G", 8);
//	playlist.insert_song("Song_H", 3);
//	playlist.insert_song("Song_I", 7);
//	playlist.insert_song("Song_J", 9);
//	playlist.insert_song("Song_K", 5);
//	while (true) {
//		cout << "1. Insert songs in the playlist\n";
//		cout << "2. Display songs\n";
//		cout << "3. Play songs\n";
//		cout << "0. Exit\n";
//		cout << "Enter your choice: ";	cin >> choice;
//		if (choice == 1) {
//			cout << "Enter the name: ";	cin >> song_name;
//			cout << "Enter the frequency of your song: ";	cin >> frequency;
//			playlist.insert_song(song_name, frequency);
//		}
//		else if (choice == 2) {
//			playlist.display_plalist();
//		}
//		else if (choice == 3) {
//			cout << "Enter the song to play: ";	cin.ignore();	getline(cin, song_name);
//			playlist.play_song(song_name);
//		}
//		else if (choice == 0) {
//			cout << "Thanks for using our program. Good Bye.\n";
//			break;
//		}
//	}
//	return 0;
//}