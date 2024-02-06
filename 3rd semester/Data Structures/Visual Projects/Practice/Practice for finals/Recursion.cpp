//#include <iostream>
//#include <string>
//using namespace std;
////				Task 1:
////bool palindrome(string str, int start, int end) {
////	if (start >= end) {
////		cout << "Palindrome.";
////		return true;
////	}
////	else {
////		if (str[start] == str[end]) {
////			palindrome(str, start + 1, end - 1);
////		}
////		else if (str[start] != str[end]) {
////			cout << "Not a palindrome.";
////			return false;
////		}
////	}
////}
////palindrome(str, 0, str.length() - 1);
//
////					Task 2:
////int binary_to_decimal(string binary_num, int index) {
////	if (index < 0) {
////		return 0;
////	}
////	int current_bit = binary_num[index] - '0';
////	int position_value = pow(2, binary_num.length() - index - 1);
////	int current_decimal = current_bit * position_value;
////	int rem_decimal = binary_to_decimal(binary_num, index - 1);
////	int decimal = current_decimal + rem_decimal;
////	return decimal;
////}
//
////					Task 3:
////bool firstUppercase(string str, int index) {
////	if (index == str.length() - 1) {
////		return false;
////	}
////	else {
////		if (str[index] >= 65 && str[index] <= 90) {
////			cout << "First upper case letter is " << str[index];
////			return true;
////		}
////		else {
////			firstUppercase(str, index + 1);
////		}
////	}
////}
//
////						Task 4:
////int smallest_value(int* arr, int smallest, int length, int current_index) {
////	if (current_index == length) {
////		return smallest;
////	}
////	else {
////		if (smallest > arr[current_index]) {
////			smallest = arr[current_index];
////		}
////		smallest_value(arr, smallest, length, current_index + 1);
////	}
////}
//
////						Task 5:
////void decimalToBase(int decimal, int base) {
////	if (decimal == 0) {
////		return;
////	}
////	else {
////		int rem = decimal % base;
////		decimalToBase(decimal / base, base);
////		if (rem >= 10) {
////			cout << char('A' + rem - 10);
////		}
////		else {
////			cout << rem;
////		}
////	}
////}
//		
////					Task 6:
////int factorial(int num, int fact, int factorials) {
////	if (fact - 1 == num) {
////		return factorials;
////	}
////	return factorial(num, fact + 1, factorials * fact);
////}
//
//int main()
//{
//	
//	return 0;
//}