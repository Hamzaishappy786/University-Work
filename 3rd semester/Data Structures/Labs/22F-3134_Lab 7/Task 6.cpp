//#include <iostream>
//#include <string>
//using namespace std;
//bool elfish(const string word, int index, bool hasE, bool hasL, bool hasF) {
//    int length = 0;	//length for string
//	for (int i = 0; word[i] != NULL; i++) { length++; }
//	//ending
//    if (index == length) { return (hasE == true && hasL == true && hasF == true); }
//    char indexs = word[index];
//    if (indexs == 'e') { hasE = true; }
//    else if (indexs == 'l') { hasL = true; }
//    else if (indexs == 'f') { hasF = true; }
//	//recursive case, just traversing forward by one step
//    return elfish(word, index + 1, hasE, hasL, hasF);
//}
//int main() {
//	//Nothing was changed in here
//	string word;
//	cout << "Enter a word: ";
//	cin >> word;
//	bool isElfish = elfish(word, 0, false, false, false);
//	if (isElfish == true) {
//		cout << word << " is elfish." << endl;
//	}
//	else {
//		cout << word << " is not elfish." << endl;
//	}
//	return 0;
//}