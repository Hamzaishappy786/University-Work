//#include <iostream>
//using namespace std;
//int binary_checker(int num) {
//	//base case
//	if (num == 1 || num == 0) { return true; }
//	int zero = num % 10;	//shortning num
//	if (zero != 0 && zero != 1) { return false; }	//instant false
//	else if (zero == 0 || zero == 1) { binary_checker(num % 10); }
//	return true;	//if nothing is done, return false
//}
//int binary_to_decimal_recursion(int num, int position) {
//	if (num == 0) { return 0; }
//	else {
//		int last_index = num % 10;
//		return (last_index * pow(2, position) + binary_to_decimal_recursion(num / 10, position + 1));
//	}
//}
//int binary_to_decimal(int num) { return binary_to_decimal_recursion(num, 0); }
//int main()
//{
//	int binary_number;
//	cout << "Enter the binary number: ";	cin >> binary_number;
//	bool binary_or_not = binary_checker(binary_number);
//	if (binary_or_not == true) { cout << binary_number << " is a binary number.\n"; }
//	else { cout << binary_number << " is not a binary number.\n"; }
//
//	if (binary_or_not == true) {
//		cout << "Decimal: " << binary_to_decimal(binary_number);
//	}
//	return 0;
//}