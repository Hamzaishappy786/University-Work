#include <iostream>
using namespace std;
class Building {
public:
    int ID;
    int floors;
    Building() {
        ID = 0;
        floors = 0;
    }
    Building(int id, int floors) {
        ID = id;
        this->floors = floors;
    }
};
class BuildingHeap {
public:
    Building* heap;
    int capacity;
    int size;
    

public:
    BuildingHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heap = new Building[capacity + 1];
    }
    void addBuilding(int id, int floors) {
        if (size < capacity) {
            Building newBuilding(id, floors);
            size++;
            heap[size] = newBuilding;

            int index = size;   //doing the process of heapifying up
            while (index > 1 && heap[index].floors > heap[index / 2].floors) {
                Building temp = heap[index];    //swapping parent with last node
                heap[index] = heap[index / 2];
                heap[index / 2] = temp;
                index = index / 2;  //updating the parent node
            }
        }
        else {
            cout << "Heap is full. Cannot add more buildings." << endl;
        }
    }
    void constructBuilding() {
        if (size > 0) {
            Building temp = heap[1];
            heap[1] = heap[size];
            heap[size] = temp;
            size--;
            heapifyDown(1);
        }
        else {
            cout << "No buildings to construct." << endl;
        }
    }
    int getHighestPriorityBuilding() {
        if (size > 0) { //just to get the first element in the heap
            return heap[1].ID;
        }
        else {
            cout << "No buildings in the queue." << endl;
            return -1;  //-1 is for no error or no building
        }
    }
    ~BuildingHeap() {
        delete[] heap;
    }
};

int main() {
    int size, choice = 0;
    cout << "Enter the size of the building: "; cin >> size;
    BuildingHeap building(size);
    int ID, floors;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Building\n";
        cout << "2. Construct Building\n";
        cout << "3. Get Highest Priority Building ID\n";
        cout << "0. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter building ID: ";        cin >> ID;
            cout << "Enter the number of floors: "; cin >> floors;
            building.addBuilding(ID, floors);
        }
        else if (choice == 2) {
            building.constructBuilding();
        }
        else if (choice == 3) {
            if (building.getHighestPriorityBuilding() != -1) {
                cout << "\nHighest Priority Building ID: " << building.getHighestPriorityBuilding() << endl;
            }
            else {
                cout << "No building left.\n";
            }
        }
        else if (choice == 0) {
            cout << "Exiting program.\n";
            break;
        }
    }
    return 0;
}