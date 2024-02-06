//#include <iostream>
//#include <string>
//using namespace std;
//bool palindrome(string st, int start, int end) {
//    if (start >= end) { return true; }  //base case, ending
//    if (st[start] != st[end]) { return false; } //even if one is wrong, then false
//    else { return palindrome(st, start + 1, end - 1); } //recursive case
//}
//int main()
//{
//	string check;   //string for checking
//    int length_of_string = 0;
//    cout << "Enter the string: ";   getline(cin, check);
//    //for getting length of string
//    for (int i = 0; check[i] != NULL; i++, length_of_string++) {}
//    bool palin = palindrome(check, 0, length_of_string);
//    if (palin == true) { cout << "String is plaindrome.\n"; }
//    else { cout << "String is not a palindrome.\n"; }
//	return 0;
//}