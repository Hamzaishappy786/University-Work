//#include <iostream>
//#include <string>
//#include <windows.h> // for Sleep
//using namespace std;
//const int MAX_PROCESSES = 10;
//const int MAX_TIME = 5;
//struct Process {
//    int processID;
//    int Time;
//};
//class RoundRobinScheduler {
//private:
//    Process processes[MAX_PROCESSES];
//    int front, rear;
//    string processing_output[MAX_PROCESSES];   //created this for displaying output correctly, other-wise it was working like a stack
//    int output_index;   //is for the current index for output
//public:
//    RoundRobinScheduler() : front(0), rear(0), output_index(0) {}
//    void addProcess(int processID, int executionTime) { //adding processes
//        processes[rear].processID = processID;
//        processes[rear].Time = executionTime;
//        rear = (rear + 1) % MAX_PROCESSES;  //traversing processes
//    }
//    void runScheduler() {
//        int time_slicing;
//        //check for empty queue
//        if (front == rear) { cout << "No processes to schedule.\n";  return; }
//        cout << "Enter the time slicing: "; cin >> time_slicing;
//
//        while (front != rear) {
//            Process currentProcess = processes[front];
//            front = (front + 1) % MAX_PROCESSES;
//            int difference = currentProcess.Time - time_slicing;
//            if (difference < 0) { difference = 0; }
//            output_index++;
//            processing_output[output_index] = "P" + to_string(currentProcess.processID) + " for " + to_string(currentProcess.Time) + " - " + to_string(difference) + " sec";
//            
//            // Simulate execution by pausing for a specified time
//            int execution_slice;
//            //for checking the minimum among excecution time and fixed divider
//            if (currentProcess.Time < time_slicing) { execution_slice = currentProcess.Time; }
//            else { execution_slice = time_slicing; }
//            for (int i = 0; i < execution_slice; ++i) {
//                Sleep(1000);
//                //sleeping for some seconds with execution slices
//                if (i % time_slicing == 0) {
//                    cout << endl;
//                }
//                cout << ".";
//            }
//
//            //updating the remaining execution timeA
//            currentProcess.Time = currentProcess.Time - execution_slice;
//
//            if (currentProcess.Time > 0) { //check for more excecution time
//                processes[rear].processID = currentProcess.processID;
//                processes[rear].Time = currentProcess.Time;
//                rear = (rear + 1) % MAX_PROCESSES; // Add the process back to the end
//            }
//        }
//        cout << "\nActual durations are discussed below:\n";
//        for (int i = output_index; i >= 0; i--) {
//            cout << processing_output[i] << endl;
//        }
//        cout << "\nScheduler finished.\n";
//    }
//};
//int main() {
//    RoundRobinScheduler obj;
//    int processID, executionTime;
//    //number of processes
//    cout << "Enter processes (Process Id's and excecution time). Enter -1 to finish.\n";
//    while (true) {
//        cout << "P (-1 to finish): ";
//        cin >> processID;
//
//        if (processID == -1) { break; } //sentinel value
//        cout << "Time of P" << processID << " in secs: ";
//        cin >> executionTime;
//        obj.addProcess(processID, executionTime);
//    }
//    //after entering sentinel value -1, scheduler will start it's magic
//    obj.runScheduler();
//    return 0;
//}