#include <iostream>
using namespace std;
int check_for_intrusion = -2000;
struct Event {  //struct for representing event
    float event_ID;
    int priority;
    int start_time;
    int end_time;
    Event() {   //initiliazing id and priority to -1 but 0 to time
        event_ID = -1;
        priority = -1;
        start_time = 0;
        end_time = 0;
    }
    Event(float ID, int priority, int start, int end) { //parameterized constructor
        event_ID = ID;
        this->priority = priority;
        start_time = start;
        end_time = end;
    }
};
class Heap {    //class for heap
private:
    Event* events_heap; //heap for storing events
    Event event_history[100];   //for events history
    Event completed_events[100];    //for checking complete events
    int capacity;
    int size;
    int history_size;
    int completed_size;

public:
    Heap(int capacity) {    //constructor for heap
        this->capacity = capacity + 1;
        events_heap = new Event[this->capacity];
        size = 0;
    }
    void heapifyUp(int i) { //shifting the element up the heap
        while (i > 0 && events_heap[(i - 1) / 2].priority > events_heap[i].priority) {
            int temp = events_heap[(i - 1) / 2].priority;
            events_heap[(i - 1) / 2].priority = events_heap[i].priority;
            events_heap[i].priority = temp;
            i = (i - 1) / 2;
        }
    }
    void heapifyDown(int i) {   //shifting the element down
        int smallest_index = i;
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (left_child <= size && events_heap[left_child].priority < events_heap[smallest_index].priority) {
            smallest_index = left_child;
        }
        if (right_child <= size && events_heap[right_child].priority < events_heap[smallest_index].priority) {
            smallest_index = right_child;
        }
        if (i != smallest_index) {
            Event temp = events_heap[i];
            events_heap[i] = events_heap[smallest_index];
            events_heap[smallest_index] = temp;
            heapifyDown(smallest_index);
        }
    }
    void insert(Event* event) { //will insert the event details
        for (int i = 0; i < size; i++) {
            if (event_overlap(*event, events_heap[i])) {    //for checking if the events overlap
                event->priority++;  //if they do one of them will get their prioriy up a notch
                events_heap[i].priority++;
                heapifyUp(i);   //and then arranging the heap according to it's rules
                return;
            }
        }
        event_adding();
        events_heap[size] = *event;
        heapifyUp(size);
        size++;
    }
    void display_events() { //event details for a single day
        cout << "Events:\n";
        for (int i = size - 1; i >= 0; i--) {
            if (events_heap[i].priority > check_for_intrusion) {
                cout << "\nEvent ID: " << events_heap[i].event_ID << endl;
                cout << "Event priority: " << events_heap[i].priority << endl;
                if (events_heap[i].start_time >= 0 && events_heap[i].start_time <= 24) {
                    cout << "Starting time: " << (events_heap[i].start_time % 12 == 0 ? 12 : events_heap[i].start_time % 12) << ":00 ";
                    cout << (events_heap[i].start_time < 12 ? "A.M" : "P.M") << endl;

                    if (events_heap[i].end_time >= 0 && events_heap[i].end_time <= 24) {
                        cout << "Ending time: " << (events_heap[i].end_time % 12 == 0 ? 12 : events_heap[i].end_time % 12) << ":00 ";
                        cout << (events_heap[i].end_time < 12 ? "A.M" : "P.M") << endl;
                    }
                    else {
                        cout << "Invalid ending time.\n";
                    }
                }
                else {
                    cout << "Invalid starting time.\n";
                }
            }
        }
        cout << endl;
    }
    //Scenario 1:
    //this function is responsible for resizing the heap when the number of events reaches the current capacity.It doubles the capacity and
    //allocates new memory for more events. Then, it deallocates the memory of the old heap and updates the pointer to the new heap.
    void event_adding() {   //resizing the heap if the events are more to handle
        if (size == capacity) {
            capacity = capacity * 2;
            Event* newEvent = new Event[capacity];
            for (int i = 0; i < size; i++) {
                newEvent[i] = events_heap[i];   //memory allocation for more events
            }
            delete[] events_heap;
            events_heap = newEvent;
        }
    }
    //Scenario 2:
    //function cancel_events, was designed to cancel an event with an ID. It iterates through the events in the heap and after finding the event with 
    //a matching ID, lowers its priority to a predefined value (check_for_intrusion = -2000). This effectively removes the event from being displayed 
    // in display_events function.

    //Also, the function includes error handling.If the loop completes without finding the specified event ID, it prints an error message indicating 
    //that the event was not found.The heapifyUp and heapifyDown functions are called to maintain the heap's property after intrusing(-2000) the 
    // priority of the canceled event.
    void cancel_events(float id) {  //for cancelling events
        bool event_found = false;   //check for finding event
        for (int i = 0; i < size; i++) {    //checking if the events match
            if (events_heap[i].event_ID == id) {
                events_heap[i].priority = check_for_intrusion;    //lowing their priority so that they cannot be shown
                heapifyUp(i);   //resetting the heap
                heapifyDown(i); //shifting the low priority down
                event_found = true;
                break;
            }
            else if (i < size - 1) {    //if the heap ends
                cout << "Error: Event not found!!!\n";
            }
        }
        if (event_found == false) {
            cout << "Event not found.\n";
        }
    }
    int current_event() {
        return events_heap[0].event_ID;
    }
    //Scenario 3:
    //function checks if two events overlap in terms of starting time and ending time. It takes two Event objects as parameters and returns a true and false 
    //indicating whether there is an overlap. The overlap is determined by comparing the starting and ending times of the two events. If the starting 
    //time of event1 is less than or equal to the starting time of event2, and the ending time of event1 is greater than or equal to the ending time 
    //of event2, it returns true, indicating an overlap. Otherwise, it returns false. Then the insertion will increment the priority by 1.

    bool event_overlap(Event& event1, Event& event2) {  //for checking if events overlap
        if (event1.start_time <= event2.start_time && event1.end_time >= event2.end_time)
            return true;
        else
            return false;
    }
    void display_history() {
        cout << "Event History:\n";
        for (int i = 0; i < history_size; i++) {    //this case includes cancelled and historical events
            cout << "\nEvent ID: " << event_history[i].event_ID << endl;
            cout << "Event priority: " << event_history[i].priority << endl;
            cout << "Starting time: " << (event_history[i].start_time % 12 == 0 ? 12 : event_history[i].start_time % 12) << ":00 " << (event_history[i].start_time < 12 ? "A.M" : "P.M") << endl;
            cout << "Ending time: " << (event_history[i].end_time % 12 == 0 ? 12 : event_history[i].end_time % 12) << ":00 " << (event_history[i].end_time < 12 ? "A.M" : "P.M") << endl;
            cout << "Completed Events:\n";
            for (int i = 0; i < completed_size; i++) {  //also displaying completed for history events
                cout << "\nEvent ID: " << completed_events[i].event_ID << endl;
                cout << "Event priority: " << completed_events[i].priority << endl;
                cout << "Starting time: " << (completed_events[i].start_time % 12 == 0 ? 12 : completed_events[i].start_time % 12) << ":00 " << (completed_events[i].start_time < 12 ? "A.M" : "P.M") << endl;
                cout << "Ending time: " << (completed_events[i].end_time % 12 == 0 ? 12 : completed_events[i].end_time % 12) << ":00 " << (completed_events[i].end_time < 12 ? "A.M" : "P.M") << endl;
            }
            cout << endl;
        }
        cout << endl;
    }
    void mark_as_done(float id) {
        for (int i = 0; i < history_size; i++) {
            if (event_history[i].event_ID == id) {
                completed_events[completed_size++] = event_history[i];
                for (int j = i; j < history_size - 1; j++) {    //shifting the remaining events in history array
                    event_history[j] = event_history[j + 1];
                }
                history_size--;
                break;
            }
        }
    }
    ~Heap() {
        delete[]events_heap;
    }
};
Event* creating_event(float id, int priority, int start, int end) {
    return new Event(id, priority, start, end); //for allocating events
}
int main()
{
    int choice, priority;
    int starting_time, ending_time;
    float id;
    Heap event_heap(0);
    while (true) {
        cout << "\n1.Inserting an event\n";
        cout << "2.Cancelling an event\n";
        cout << "3.Displying all events\n";
        cout << "4.Current Event\n";
        cout << "5.Check History\n";
        cout << "6.Mark event as done\n";
        cout << "0.Exit\n";
        cout << "Enter your choice: ";  cin >> choice;
        if (choice == 1) {
            cout << "Enter the ID of the event: "; cin >> id;
            cout << "Enter the priority of the event: ";   cin >> priority;
            cout << "Enter the starting hour: ";    cin >> starting_time;
            cout << "Enter the ending hour: ";  cin >> ending_time;
            event_heap.insert(creating_event(id, priority, starting_time, ending_time));
        }
        else if (choice == 2) {
            cout << "Enter the event ID: "; cin >> id;
            event_heap.cancel_events(id);
        }
        else if (choice == 3) {
            event_heap.display_events();
        }
        else if (choice == 4) {
            cout << "Current event: " << event_heap.current_event() << endl;
        }
        else if (choice == 5) {
            event_heap.display_history();
        }
        else if (choice == 6) {
            cout << "Enter the id of the event: ";  cin >> id;
            event_heap.mark_as_done(id);
        }
        else if (choice == 0) {
            cout << "Thank you for using our program. Good bye.\n";
            break;
        }
    }
    return 0;
}