//#include <iostream>
//using namespace std;
//string decimalToOctalOrHexaDecimal(int decimal_number, int base) {
//    if (decimal_number == 0) { return "0"; }    // base case with 0
//    string converted = ""; // making a string for the final result
//    while (decimal_number > 0) {
//        int rem = decimal_number % base;
//        char digit; //created for the sole purpose of getting a single digit in the string
//        if (rem < 10) { //if remainder is less than 10, addition will be done with 0
//            digit = '0' + rem;
//        }
//        else {  //else with A, B, C, D, E, F
//            digit = 'A' + (rem - 10);
//        }
//        // recursing by dividing the number with the base and adding to the current digit
//        converted = digit + converted;
//        decimal_number = decimal_number / base;
//    }
//    return converted;
//}
//
//int main() {
//    int decimal_number, base;
//    cout << "Enter a decimal number: ";
//    cin >> decimal_number;
//    while (true) {
//        cout << "Enter the base (8,16): ";
//        cin >> base;
//        if (base == 8 || base == 16) {
//            cout << "Number in base " << base << ": " << decimalToOctalOrHexaDecimal(decimal_number, base);
//            break;
//        }
//        else {
//            cout << "\nWrong base. Please enter 8 or 16.\n";
//        }
//    }
//    return 0;
//}