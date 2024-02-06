									//================================================================//
									//				Discrete Structures Project BY:	    			  //
									//				*Muhammad Hamza and Abdul Hanan*				  //
									//					**22F-3134 and 22F-3104**					  //
									//================================================================//
#include <iostream>
#include <Windows.h>
using namespace std;
//COLOR SCHEMES
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[33m"
#define BLUE "\033[34m"
#define SKY_BLUE "\033[36m"

//Struct created for identifying first and second
struct Relation {
	string first;
	string second;
};

//variables for identifying number of relations
int symmetricrelations = 0;
int reflexiverelations = 0;
int antisymmetric_relation = 0;
//function for finding cartesian product
void simpleLoadingScreen() {
	cout << "\n\n\t\t\t";
	cout << SKY_BLUE <<  "Loading";
	for (int i = 0; i < 3; ++i) {
		cout << ".";
		// Adjust the sleep duration as needed
		// This is a simple delay using a loop, not as precise as using threads and chrono
		Sleep(100);
	}
	cout << RESET << endl << endl;
}
void cartesian_product(int set1_size, int set2_size, string* set1, string* set2) {
	cout << ORANGE << "\nCartesian product: {";
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			if (i != set1_size - 1 || j != set2_size - 1) {
				cout << "(" << set1[i] << "," << set2[j] << "),";
			}
			else cout << "(" << set1[i] << "," << set2[j] << ")";
		}
	}
	cout << "}\n" << RESET;
}
//function for taking inputs of sets
//A set does not take repeated values
void inputs_of_sets(int set1_size, int set2_size, string* set1, string* set2) {
	for (int i = 0; i < set1_size; i++) {
		bool repeated_value;
		do {
			repeated_value = false;
			cout << RED << "Enter number " << i + 1 << " of the set: " << RESET;
			cin >> set1[i];
			for (int j = 0; j < i; j++) {
				if (set1[i] == set1[j]) {
					repeated_value = true;
					cout << RED << "\nElement already in the set.\n";
					cout << "Enter again.\n\n";
					break;
				}
			}
		} while (repeated_value == true);
	}
	for (int i = 0; i < set2_size; i++) {
		bool repeated_value;
		do {
			repeated_value = false;
			cout << RED << "Enter number " << i + 1 << " of the set: " << RESET;
			cin >> set2[i];
			for (int j = 0; j < i; j++) {
				if (set2[i] == set2[j]) {
					repeated_value = true;
					cout << RED << "\nElement already in the set.\n";
					cout << "Enter again.\n\n" << RESET;
					break;
				}
			}
		} while (repeated_value == true);
	}
	cartesian_product(set1_size, set2_size, set1, set2);
}
int total_number_of_relations(int set1_size, int set2_size) {
	cout << RED << "\nTotal number of realtions: 2^(" << set1_size << "*" << set2_size << ")->";
	int num_of_relations = 2;
	for (int i = 0; i < (set1_size * set2_size) - 1; i++) {
		num_of_relations *= 2;
	}
	return num_of_relations;
}
void actual_relations_of_sets(int set1_size, int set2_size, string* set1, string* set2) {
	cout << "\nRelations: " << RED;
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			if (i == set1_size - 1 && j == set2_size - 1) {
				cout << set1[i] << "R" << set2[j];
			}
			else cout << set1[i] << "R" << set2[j] << ", ";
		}
	}
	cout << "\n" << RESET;
}
bool contains(string* arr, int size, string value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}
bool is_reflexive(int size, string* set, Relation* relation) {
	for (int i = 0; i < size; i++) {
		bool found = false;
		for (int j = 0; relation[j].first != ""; j++) {
			if (relation[j].first == set[i] && relation[j].second == set[i]) {
				found = true;
				break;
			}
		}
		if (found == false) {
			return false;
		}
	}
	for (int i = 0; i < size; i++) {
		bool found = false;
		for (int j = 0; relation[j].first != ""; j++) {
			if (relation[j].first == set[i]) {
				found = true;
				break;
			}
		}
		if (found == false) {
			return false;
		}
	}
	return true;
}
bool is_symmetric(Relation* relation) {
	for (int i = 0; relation[i].first != ""; i++) {
		bool reverse_located = false;
		for (int j = 0; relation[j].first != ""; j++) {
			if (relation[i].first == relation[j].second && relation[i].second == relation[j].first) {
				reverse_located = true;
				break;
			}
		}
		if (!reverse_located) {
			return false;
		}
	}

	return true;
}
bool is_antiSymmetric(Relation* relation) {
	for (int i = 0; relation[i].first != ""; i++) {
		for (int j = 0; relation[j].first != ""; j++) {
			if (i != j && relation[i].first == relation[j].second && relation[i].second == relation[j].first) {
				return false;
			}
		}
	}
	return true;
}
void reflexive_relations(int set1_size, int set2_size, string* set1, string* set2) {
	Relation* cartesianProduct = new Relation[set1_size * set2_size];
	int productIndex = 0;
	
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			cartesianProduct[productIndex].first = set1[i];
			cartesianProduct[productIndex].second = set2[j];
			productIndex++;
		}
	}
	cout << ORANGE << "\nCartesian product: {";
	for (int i = 0; i < productIndex; i++) {
		cout << "(" << cartesianProduct[i].first << "," << cartesianProduct[i].second << ")";
		if (i != productIndex - 1)
			cout << ",";
	}
	cout << "}\n" << RESET;
	cout << RED << "\nReflexive relation: {";
	bool reflexive = true;
	for (int i = 0; i < set1_size; i++) {
		string currentElement = set1[i];
		bool found = false;
		for (int j = 0; j < productIndex; j++) {
			if (cartesianProduct[j].first == currentElement && cartesianProduct[j].second == currentElement) {
				found = true;
				break;
			}
		}
		if (!found) {
			reflexive = false;
			break;
		}
	}
	if (reflexive == true) {
		for (int i = 0; i < set1_size; i++) {
			for (int j = 0; j < set2_size; j++) {
				if (set1[i] == set2[j]) {
					cout << "(" << set1[i] << "," << set2[j] << ")";
					reflexiverelations++;
					if (i != set1_size - 1 && j != set2_size)
						cout << ",";
				}
			}
		}
	}
	cout << "}\n" << RESET;
	if (reflexive == true) {
		cout << SKY_BLUE << "Total number of reflexive relations: " << reflexiverelations << endl << endl << RESET;
	}
	else {
		cout << SKY_BLUE << "The relation is not reflexive.\n\n" << RESET;
	}

	
	delete[] cartesianProduct;
	reflexiverelations = 0;
}
static void Symmetric_realtions(int set1_size, int set2_size, string* set1, string* set2) {
	cartesian_product(set1_size, set2_size, set1, set2);
	cout << RED << "Symmetric relations from Cartesian product: {";
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			string a = set1[i];
			string b = set2[j];

			if (a != b) {
				if (find(set1, set1 + set1_size, b) != set1 + set1_size && find(set2, set2 + set2_size, a) != set2 + set2_size) {
					cout << "(" << a << "," << b << ")";
					symmetricrelations++;

					if (i != set1_size - 1 || j != set2_size - 1) {
						cout << ",";
					}
				}
			}
		}
	}

	cout << "}\n" << RESET;
	cout << SKY_BLUE << "Total number of symmetric relations: " << symmetricrelations << endl << endl;
	symmetricrelations = 0;
}
void reflexive_and_symmetric_relations(int set1_size, int set2_size, string* set1, string* set2) {
	cartesian_product(set1_size, set2_size, set1, set2);
	cout << RED << "Reflexive and Symmetric relations: {";
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			if (set1[i] == set2[j]) {
				cout << "(" << set1[i] << "," << set2[j] << ")";
				reflexiverelations++;
				if (i != set1_size - 1 && j != set2_size)
					cout << ",";
			}
		}
	}
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			string a = set1[i];
			string b = set2[j];

			bool foundAB = false;
			bool foundBA = false;

			if (a != b) {
				for (int x = 0; x < set1_size; x++) {
					for (int y = 0; y < set2_size; y++) {
						if (set1[y] == a && set2[x] == b) {
							foundAB = true;
						}
						if (set1[y] == b && set2[x] == a) {
							foundBA = true;
						}
					}
				}
				if (foundAB == true && foundBA == true) {
					cout << "(" << a << "," << b << ")";
					symmetricrelations++;
				}
				if ((i != set1_size - 1 || j != set2_size - 1) && foundAB && foundBA) {
					cout << ",";
				}
			}
		}
	}

	cout << "}\n" << RESET;
	cout << SKY_BLUE << "Total number of reflexive relations: " << reflexiverelations << endl;
	cout << "Total number of symmetric relations: " << symmetricrelations << endl << endl << RESET;
	reflexiverelations = 0;
	symmetricrelations = 0;
}
void anti_symmetric_relations(int set1_size, int set2_size, string* set1, string* set2) {
	cartesian_product(set1_size, set2_size, set1, set2);
	int anti_symmetric_relation = 0;
	cout << RED << "Anti-symmetric relations: {";
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			if (set1[i] != set2[j]) {
				bool foundBA = false;
				for (int x = 0; x < set1_size; x++) {
					for (int y = 0; y < set2_size; y++) {
						if (set1[x] == set2[j] && set2[y] == set1[i]) {
							foundBA = true;
							break;
						}
					}
					if (foundBA) { break; }
				}
				if (foundBA == false) {
					if (i != 0 || j != 0) {
						cout << ",";
					}
					cout << "(" << set1[i] << "," << set2[j] << ")";
					antisymmetric_relation++;
				}
			}
		}
	}
	cout << "}\n" << RESET;
	cout << SKY_BLUE << "Total anti-symmetric relations: " << antisymmetric_relation << endl << endl << RESET;
	antisymmetric_relation = 0;
}
void symmetric_and_anti_symmetric_relations(int set1_size, int set2_size, string* set1, string* set2) {
	cartesian_product(set1_size, set2_size, set1, set2);
	cout << RED << "Symmetric and anti-symmetric relations: {";
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			string a = set1[i];
			string b = set2[j];

			bool foundAB = false;
			bool foundBA = false;

			if (a != b) {
				for (int x = 0; x < set1_size; x++) {
					for (int y = 0; y < set2_size; y++) {
						if (set1[y] == a && set2[x] == b) {
							foundAB = true;
						}
						if (set1[y] == b && set2[x] == a) {
							foundBA = true;
						}
					}
				}
				if (foundAB == true && foundBA == true) {
					cout << "(" << a << "," << b << ")";
					symmetricrelations++;
				}
				if ((i != set1_size - 1 || j != set2_size - 1) && foundAB && foundBA) {
					cout << ",";
				}
			}
		}
	}
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			if (set1[i] != set2[j]) {
				bool foundBA = false;
				for (int x = 0; x < set1_size; x++) {
					for (int y = 0; y < set2_size; y++) {
						if (set1[x] == set2[j] && set2[y] == set1[i]) {
							foundBA = true;
							break;
						}
					}
					if (foundBA) { break; }
				}
				if (foundBA == false) {
					if (i != 0 || j != 0) {
						cout << ",";
					}
					cout << "(" << set1[i] << "," << set2[j] << ")";
					antisymmetric_relation++;
				}
			}
		}
	}
	cout << "}\n" << RESET;
	cout << SKY_BLUE << "Number of symmetric relations: " << symmetricrelations << endl;
	cout << "Number of anti-symmetric realtions: " << antisymmetric_relation << endl << endl << RESET;
	symmetricrelations = 0;
	antisymmetric_relation = 0;
}
int main()
{
	bool program = true;
	int option;
	int set1_size, set2_size;
	cout << ORANGE << "Enter the number of elements you want to add in the first set: ";	cin >> set1_size;
	cout << "Enter the number of elements you want to add in the second set: ";	cin >> set2_size; cout << RESET;
	Relation* relations = new Relation[set1_size * set2_size * 2 + 1];
	string* set1, * set2;
	set1 = new string[set1_size];
	set2 = new string[set2_size];
	inputs_of_sets(set1_size, set2_size, set1, set2);
	int index = 0;
	for (int i = 0; i < set1_size; i++) {
		for (int j = 0; j < set2_size; j++) {
			relations[index].first = set1[i];
			relations[index].second = set2[j];
			index++;
		}
	}
	// Add sentinel value to the end of the relations array
	relations[index].first = "";
	relations[index].second = "";
	
	while (program) {
		cout << GREEN << "\n1.See total number of realtions\n";
		cout << "2.See relations of sets inside of the cartesian product\n";
		cout << "3.Reflexive relations\n";
		cout << "4.Symmetric relations\n";
		cout << "5.Anti-symmetric relations\n";
		cout << "6.Reflexive and symmetric relations\n";
		cout << "7.Symmetric and anti-symmetric relations\n";
		cout << "8.If you want to change your sets\n";
		cout << "9.Exit\n" << RESET;
		cout << "Enter your choice: ";	cin >> option;
		switch (option) {
		case 1:
			simpleLoadingScreen();
			cout << total_number_of_relations(set1_size, set2_size) << endl << RESET;
			cout << "\nPress any key to continue.\n";
			break;
		case 2:
			simpleLoadingScreen();
			actual_relations_of_sets(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 3:
			simpleLoadingScreen();
			if (is_reflexive(set1_size, set1, relations))	cout << "\n\nThe relation is reflexive.\n";
			else cout << "\n\nThe relation is not reflexive.\n";
			reflexive_relations(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 4:
			simpleLoadingScreen();
			if (is_symmetric(relations)) cout << "\n\nThe relation is symmetric.\n";
			else cout << "\n\nThe relations is not symmetric.\n";
			Symmetric_realtions(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 5:
			simpleLoadingScreen();
			if (is_antiSymmetric(relations)) cout << "\n\nThe relation is anti-symmetric.\n";
			else cout << "\n\nThe relation is not anti-symmetric.\n";
			anti_symmetric_relations(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 6:
			simpleLoadingScreen();
			reflexive_and_symmetric_relations(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 7:
			simpleLoadingScreen();
			symmetric_and_anti_symmetric_relations(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 8:
			simpleLoadingScreen();
			symmetricrelations = 0;
			reflexiverelations = 0;
			cout << ORANGE << "Enter the number of elements you want to add in the first set: " << RESET;	cin >> set1_size;
			cout << ORANGE << "Enter the number of elements you want to add in the second set: " << RESET;	cin >> set2_size;
			set1 = new string[set1_size];
			set2 = new string[set2_size];
			inputs_of_sets(set1_size, set2_size, set1, set2);
			cout << "\nPress any key to continue.\n";
			break;
		case 9:
			simpleLoadingScreen();
			program = false;
			cout << "\nPress any key to close.\n";
			break;
		default:
			cout << "Invalid key.\n";
		}
		system("pause>3");
		system("cls");
	}
	delete[]set1; delete[]set2;
	return 0;
}