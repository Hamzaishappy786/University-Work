//#include<iostream>
//using namespace std;
//bool isPalindrome(string s, int str1, int element) {
//	if (s[str1] != s[element]) { return false; }
//	else if (str1 == element) { return true; }
//	return isPalindrome(s, str1 + 1, element - 1);
//}
//int main()
//{
//	string lol = "lol";
//	cout << isPalindrome(lol, 0, lol.length() - 1);
//	return 0;
//}
#include <iostream>

const int MAX_SIZE = 100; // Maximum size of the queue

class Queue {
private:
    int front, rear;
    int elements[MAX_SIZE];

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }

        elements[rear] = data;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Return a sentinel value or handle error as needed.
        }

        int data = elements[front];

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }

        return data;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Return a sentinel value or handle error as needed.
        }

        return elements[front];
    }
    void insert_at_front(int data) {
        front--;
        elements[front] = data;
    }
    void insert_at_back(int data) {
        rear++;
        elements[rear] = data;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        int i = front;
        while (i != rear + 1) {
            std::cout << elements[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Front of the queue: " << myQueue.getFront() << std::endl;
    myQueue.display();

    myQueue.dequeue();
    myQueue.insert_at_front(1);
    myQueue.insert_at_back(4);
    std::cout << "Front of the queue after dequeue: " << myQueue.getFront() << std::endl;
    myQueue.display();

    return 0;
}

//#include <iostream>
//using namespace std;
//struct Node {
//	int data;
//	Node* next;
//};
//class Queue{
//private:
//	Node* front;
//	Node* rear;
//public:
//	Queue() :front(nullptr), rear(nullptr) {}
//	bool isEmpty(){
//		if (front == nullptr) {
//			return true;
//		}
//		return false;
//	}
//	void enqueue(int data) {
//		Node* newNode = new Node{ data, nullptr };
//		if (isEmpty()) {
//			front = rear = newNode;
//		}
//		else {
//			rear->next = newNode;
//			rear = newNode;
//		}
//		//cout << front->data << "\t" << rear->data << endl;
//	}
//	int dequeue() {
//		if (isEmpty()) {
//			return -1;
//		}
//		int data = front->data;
//		Node* temp = front;
//		if (front == rear) {
//			front = nullptr;
//			rear = nullptr;
//		}
//		else {
//			front = front->next;
//		}
//		return data;
//	}
//	void display() {
//		Node* temp = front;
//		while (temp != nullptr) {
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//	}
//	~Queue() {
//		while (front != nullptr) {
//			Node* temp = front;
//			front = front->next;
//			delete temp;
//		}
//	}
//};
//int main() {
//	Queue obj;
//	obj.enqueue(12);
//	obj.enqueue(24);
//	obj.enqueue(36);
//	obj.enqueue(48);
//	obj.display();
//	obj.dequeue();
//	obj.display();
//	obj.~Queue();
//	return 0;
//}