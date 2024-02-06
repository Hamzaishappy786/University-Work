#include <iostream>
using namespace std;
int minimum(int *arr, int size, int index) {
	//starting from the last value
    if (index == size - 1) { return arr[index]; }
	//storing value when found smaller
    if (arr[index] < minimum(arr, size, index + 1)) { return arr[index]; }
	else { return minimum(arr, size, index + 1); }	//traversing
}
int main()
{
	int size;
	cout << "Enter the size of the array: ";	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cout << "Enter the " << i + 1 << " value of the array: ";
		cin >> *(arr + i);
	}
	cout << "Minimum value of array: " << minimum(arr, size, 0);
	delete[] arr;
}