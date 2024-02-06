#include <iostream>
#include <string>
using namespace std;
struct Patient {
	int condition;
	string name;
    Patient() {
        name = "";
        condition = 0;
    }
	Patient(string name, int condition) {
		this->name = name;
		this->condition = condition;
	}
};
class HospitalWaitingSystem {
private:
	Patient* patient_heap;
	int size;
	int capacity;
    void heapifyDown(int index) {
        int left_child = 2 * index;
        int right_child = 2 * index + 1;
        int largest = index;

        if (left_child <= size && patient_heap[left_child].condition > patient_heap[largest].condition) {
            largest = left_child;
        }

        if (right_child <= size && patient_heap[right_child].condition > patient_heap[largest].condition) {
            largest = right_child;
        }

        if (largest != index) {
            Patient temp = patient_heap[index];
            patient_heap[index] = patient_heap[largest];
            patient_heap[largest] = temp;

            heapifyDown(largest);
        }
    }
    void heapifyUp(int index) {
        while (index > 0) {
            int parent_index = (index - 1) / 2;
            if (patient_heap[index].condition > patient_heap[parent_index].condition) {
                int temp = patient_heap[index].condition;
                patient_heap[index].condition = patient_heap[parent_index].condition;
                patient_heap[parent_index].condition = temp;
                index = parent_index;
            }
            else {
                break;
            }
        }
    }
public:
    HospitalWaitingSystem(int capacity) {
        size = 0;
        this->capacity = capacity;
        patient_heap = new Patient[capacity];
    }
    HospitalWaitingSystem() {
        delete[] patient_heap;
    }
    void add_patient(Patient& patient) {
        if (size == capacity) {
            cout << "Waiting system is full.\n Cannot enter more.\n";
            return;
        }
        patient_heap[size] = patient;
        heapifyUp(size);
        size++;
    }
    Patient allot_bed() {
        if (size == 0) {
            cout << "No patients in the waiting system.\n";
            string names = "No patient\n";
            int patients = 0;
            return Patient(names, patients);
        }
        Patient maxPatient = patient_heap[0];
        Patient temp = patient_heap[0];
        patient_heap[0] = patient_heap[size - 1];
        patient_heap[size - 1] = temp;
        cout << "Bed alloted to patient number: " << maxPatient.name << endl;
        size--;
        heapifyDown(1);
        return maxPatient;
    }
    int num_patients() {
        return size;
    }
    void display_patients() {
        if (size == 0) {
            cout << "\nNo patients.\n";
        }
        else {
            for (int i = 0; i < size; i++) {
                cout << "Patient name: " << patient_heap[i].name << endl;
                cout << "Severity condition level: " << patient_heap[i].condition << endl << endl;
            }
        }
    }
};
int main()
{
    int hospital_beds, choice;
    cout << "Enter the capacity of the beds: "; cin >> hospital_beds;
    HospitalWaitingSystem hospital(hospital_beds);
    while (true) {
        cout << "1. Add patient\n";
        cout << "2. Allot bed\n";
        cout << "3. Get the total number of patients\n";
        cout << "4. Display all patients in waiting list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";  cin >> choice;
        if (choice == 1) {
            string name;
            int condition;
            cout << "Enter the name of the patient: ";  cin.ignore();  getline(cin, name);
            cout << "Enter the condition: ";    cin >> condition;
            Patient patient(name, condition);
            hospital.add_patient(patient);
        }
        else if (choice == 2) {
            hospital.allot_bed();
        }
        else if (choice == 3) {
            cout << "Total number of patients: " << hospital.num_patients() << endl;
        }
        else if (choice == 4) {
            hospital.display_patients();
        }
        else if (choice == 0) {
            cout << "Thank you for using our program. Good Bye.\n";
            break;
        }
    }
	return 0;
}