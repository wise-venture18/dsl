// Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. 
// Create a class that includes the data items (which should be template) and the priority (which should be int). The inorder list should contain these objects, 
// with operator <= overloaded so that the items with highest priority appear at the start of the list (which will make it relatively easy to retrieve the highest item.

#include <iostream>
using namespace std;

// Define the PriorityQueueItem class template
template <typename T>
class PriorityQueueItem {
public:
    T data;         // The data in the queue
    int priority;   // The priority of the item
    
    // Constructor
    PriorityQueueItem(T data, int priority) : data(data), priority(priority) {}

    // Default constructor to avoid issues during array allocation
    PriorityQueueItem() : data(T()), priority(0) {}

    // Overloading the <= operator to compare the priorities
    bool operator<=(const PriorityQueueItem<T>& other) const {
    return this->priority >= other.priority; // Change <= to >=
    }

};

// Define the PriorityQueue class
template <typename T>
class PriorityQueue {
private:
    PriorityQueueItem<T>* queue;   // Dynamic array to store items
    int size;                      // Current size of the queue
    int capacity;                  // Maximum capacity of the queue

public:
    // Constructor to initialize the queue
    PriorityQueue(int capacity) : capacity(capacity), size(0) {
        queue = new PriorityQueueItem<T>[capacity]; // Allocate memory for the queue
    }

    // Destructor to free allocated memory
    ~PriorityQueue() {
        delete[] queue;
    }

    // Method to insert an item into the queue
    void insert(T data, int priority) {
        if (size >= capacity) {
            cout << "Queue is full!" << endl;
            return;
        }

        PriorityQueueItem<T> item(data, priority);

        // Insert the item in the sorted position (highest priority first)
        int i = size - 1;
        while (i >= 0 && queue[i] <= item) {
            queue[i + 1] = queue[i];
            i--;
        }
        queue[i + 1] = item;
        size++;
    }

    // Method to retrieve the highest priority item
    T getHighestPriorityItem() {
        if (size == 0) {
            throw out_of_range("Queue is empty");
        }
        return queue[0].data; // Return the first item (highest priority)
    }

    // Method to remove the highest priority item
    void removeHighestPriorityItem() {
        if (size == 0) {
            throw out_of_range("Queue is empty");
        }
        // Shift all items one position left to remove the first item
        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        size--;
    }

    // Method to check if the queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Method to display the queue (for debugging)
    void display() const {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << "Data: " << queue[i].data << ", Priority: " << queue[i].priority << endl;
        }
    }
};

// Test the PriorityQueue implementation
int main() {
    // Create a priority queue with a capacity of 10 items
    PriorityQueue<string> pq(10);

    // Inserting items with different priorities
    pq.insert("Item 1", 3);
    pq.insert("Item 2", 10);
    pq.insert("Item 3", 1);
    pq.insert("Item 4", 7);

    // Displaying the queue
    cout << "Priority Queue after insertions:" << endl;
    pq.display();

    // Retrieving the highest priority item
    cout << "\nHighest Priority Item: " << pq.getHighestPriorityItem() << endl;

    // Removing the highest priority item
    pq.removeHighestPriorityItem();

    // Displaying the queue after removal
    cout << "\nPriority Queue after removal:" << endl;
    pq.display();

    return 0;
}
