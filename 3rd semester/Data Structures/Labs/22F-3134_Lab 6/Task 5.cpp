//#include <iostream>
//using namespace std;
//class Queue {
//private:
//    int rear;
//    int front;
//    int size;
//    int* elements;
//public:
//    Queue(int size) : front(0), rear(-1), size(size) { elements = new int[size]; }
//    bool isEmpty() {
//        if (front > rear) { return true; }
//        else { return false; }
//    }
//    bool isFull() {
//        if (rear == size - 1) { return true; }
//        else { return false; }
//    }
//    void enqueue(int data) {
//        if (front > rear) { return; }
//        rear++;
//        elements[rear] = data;
//    }
//    int dequeue() { //wanted to check number of people in a queue
//        if (front > rear) { return 0; }
//        front++;
//        return elements[front];
//    }
//    ~Queue() { delete[] elements; }
//};
//int maximizeProfit(int* seats, int num_people, int rows) {
//    Queue obj(num_people);
//    //enqueuing people in the queue
//    for (int i = 0; i < num_people; i++) { obj.enqueue(i); }
//
//    int profit = 0; //profit will be zero in the beginning
//    while (obj.isEmpty() == true) {
//        int current = obj.dequeue() + 1;
//        //quest for finding a row with maximum seats
//        int max_seats_in_a_row = 0;
//        int max_row = -1;
//        for (int i = 0; i < rows; i++) {
//            if (seats[i] > max_seats_in_a_row) {
//                max_seats_in_a_row = seats[i];
//                max_row = i;
//            }
//        }
//        if (max_row == -1) { break; }   //check for no more empty seats
//        profit = profit + max_seats_in_a_row;
//        seats[max_row]--;   //empty seat count for row, updated
//
//        cout << "Total profit: " << profit << endl;
//        cout << "Vacant seats: ";
//        for (int i = 0; i < rows; i++) { cout << seats[i] << " "; }
//        cout << endl;
//        cout << "People in queue: " << num_people - (current) << endl << endl;
//    }
//    return profit;
//}
//int main() {
//    int size;
//    cout << "Enter the size: "; cin >> size;
//    int* seats = new int[size];
//    for (int i = 0; i < size; i++) {
//        cout << "Enter the element of the " << i + 1 << " queue: ";
//        cin >> seats[i];
//    }
//    int num_people, profit = 0;
//    cout << "Enter the number of people in the queue: "; cin >> num_people;
//    cout << "Total profit: " << profit << endl;
//    cout << "Vacant seats: ";   for (int i = 0; i < size; i++) { cout << seats[i] << " "; }
//    cout << "\nPeople in queue: " << size << endl;
//    cout << "Maximum profit: " << maximizeProfit(seats, num_people, size);
//    return 0;
//}

#include <iostream>
using namespace std;
int number(int num1, int num2) {
	if (num2 == 0 || num1 == 0) { return 0; }
	if (num2 > 0) { return num1 + number(num1, num2 - 1); }
	else { return -num1 + number(num1, num2 + 1); }
}
int main()
{
	int num1, num2;
	cin >> num1;
	cin >> num2;
	cout << number(num1, num2);
	return 0;
}