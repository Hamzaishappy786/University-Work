//#include <iostream>
//using namespace std;
//int recursive_binary_search(int* array, int target, int left, int right) {
//    if (left > right) { return -1; } //target element not found
//    int middle_element = left + (right - left) / 2;
//    if (array[middle_element] > target) { return recursive_binary_search(array, target, left, middle_element - 1); }
//    else if (array[middle_element] < target) { return recursive_binary_search(array, target, middle_element + 1, right); }
//    else if (array[middle_element] == target) {
//        return middle_element; //target element found
//    }
//}
//int main()
//{
//    int size = 0, target;
//    cout << "enter the size of the array: ";	cin >> size;
//    int* array = new int[size];
//    for (int i = 0; i < size; i++) { cout << "Enter the element at index " << i + 1 << ": "; cin >> array[i]; }
//    cout << "Entered array: ";
//    for (int i = 0; i < size; i++) { cout << array[i] << " "; }
//    cout << "\nSorted array: ";
//    for (int i = 0; i < size - 1; ++i) {    //Bubble sorting
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (array[j] > array[j + 1]) {
//                int temp = array[j];
//                array[j] = array[j + 1];    //Swapping
//                array[j + 1] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < size; i++) { cout << array[i] << " "; }
//    cout << "\nEnter the target element: ";   cin >> target;
//    cout << "\nElement found at: " << recursive_binary_search(array, target, 0, size);
//    delete[]array;
//    return 0;
//}