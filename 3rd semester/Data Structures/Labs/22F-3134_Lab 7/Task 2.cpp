//#include <iostream>
//using namespace std;
//int GCD(int num1, int num2, int traversing_value) {
//	int lowest = num1;	//for checking what's the lowest value
//	int done;	//the highest value in division
//	//setting value of lowest number so that it goes there
//	if (num1 < num2) { lowest = num1; }
//	else { lowest = num2; }
//    if (lowest % traversing_value == 0) { done = traversing_value; }
//    if (traversing_value == lowest) {
//		return done;	//base case
//    }else if (lowest != traversing_value) { return GCD(num1, num2, traversing_value + 1); }
//	//traversing
//}
//int main()
//{
//	int num1, num2;
//	cout << "Enter the first number: ";		cin >> num1;
//	cout << "Enter the second number: ";	cin >> num2;
//	int result = GCD(num1, num2, 1);
//	cout << "Greatest common divisor: " << result;
//}