//#include <iostream>
//#include <string>
//using namespace std;
//string finding_uppercase(string& st, int start, int end) {
//	if (start == end) { return "Not found."; }	//in the end
//	//checking in between A and Z
//	if (st[start] >= 'A' && st[start] <= 'Z') { cout << "First uppercase character: " << st[start] << endl;	return "Found"; }
//	else { return finding_uppercase(st, start + 1, end); }
//	//traversing
//}
//int main()
//{
//	string st;
//	cout << "Enter the string: ";	getline(cin, st);
//	int st_length = 0;
//	for (int i = 0; i != NULL; i++, st_length++) { st_length = i; }
//	cout << "Status: " << finding_uppercase(st, 0, st.length());
//	return 0;
//}