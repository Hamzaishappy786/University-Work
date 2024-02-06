//#include "DS_ASS02_22F-3134 task 4.h"
//#include <iostream>
//using namespace std;
//template<typename Q>
//Double_ended_queue<Q>::Double_ended_queue(int size) {
//	front = -1;	rear = -1;	capacity = size;
//	arr = new Q[size];
//}
//template<typename Q>
//Double_ended_queue<Q>::~Double_ended_queue() { delete[]arr; }
//template<typename Q>
//bool Double_ended_queue<Q>::isEmpty() {
//	if (front >= rear) {
//		return true;
//	}
//	return false;
//}
//template<typename Q>
//bool Double_ended_queue<Q>::isFull() {
//	if (rear == capacity - 1) {
//		return true;
//	}
//	return false;
//}
//template<typename Q>
//void Double_ended_queue<Q>::insert_from_front(Q data) {
//	if (isFull()) {
//		cout << "Queue is already full.\n";	return;
//	}
//	if (isEmpty()) {
//		front = 0;	rear = 0;
//	}
//	else {
//		front = (front - 1 + capacity) % capacity;
//	}
//	arr[front] = data;
//}
//template<typename Q>
//void Double_ended_queue<Q>::insert_from_back(Q data) {
//	if (isFull()) {
//		cout << "Queue is already full.\n";	return;
//	}
//	if (isEmpty()) {
//		front = 0;	rear = 0;
//	}
//	else {
//		rear = (rear + 1) % capacity;
//	}
//	arr[rear] = data;
//}
//template<typename Q>
//void Double_ended_queue<Q>::remove_from_front() {
//	if (isEmpty()) {
//		cout << "Queue is already empty.\n";	return;
//	}
//	if (front == rear) {
//		front = -1;	rear = -1;
//	}
//	else {
//		front = (front + 1) % capacity;
//	}
//}
//template<typename Q>
//void Double_ended_queue<Q>::remove_from_back() {
//	if (isEmpty()) {
//		cout << "Queue is already empty.\n";	return;
//	}
//	if (front == rear) {
//		front = -1;	rear = -1;
//	}
//	else {
//		rear = (rear - 1 + capacity) % capacity;
//	}
//}
//template<typename Q>
//void Double_ended_queue<Q>::display() {
//	if (isEmpty()) {
//		cout << "Double ended queue is empty.\n";	return;
//	}
//	int i = front;
//	do {
//		cout << arr[i] << " ";
//		i = (i + 1) % capacity;
//	} while ((rear + 1) % capacity);
//}