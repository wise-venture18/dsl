// A double-ended queue (deque) is a linear list in which additions and deletions may 
// be made at either end. Obtain a data representation mapping a deque into a 
// onedimensional array. Write C++ program to simulate deque with functions to add 
// and delete elements from either end of the deque. 

#include <iostream>
using namespace std;

#define MAX 5  // Define the maximum size of the deque

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    // Constructor to initialize the deque
    Deque() {
        front = -1;
        rear = -1;
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the deque is full
    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    // Function to add an element at the front
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element at the front." << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            front = (front - 1 + MAX) % MAX;  // Circular decrement
        }
        arr[front] = value;
        cout << "Added " << value << " at the front." << endl;
    }

    // Function to add an element at the rear
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element at the rear." << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;  // Circular increment
        }
        arr[rear] = value;
        cout << "Added " << value << " at the rear." << endl;
    }

    // Function to delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element from the front." << endl;
            return;
        }

        cout << "Deleted " << arr[front] << " from the front." << endl;

        if (front == rear) {
            front = rear = -1;  // Reset if only one element was present
        } else {
            front = (front + 1) % MAX;  // Circular increment
        }
    }

    // Function to delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element from the rear." << endl;
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear." << endl;

        if (front == rear) {
            front = rear = -1;  // Reset if only one element was present
        } else {
            rear = (rear - 1 + MAX) % MAX;  // Circular decrement
        }
    }

    // Function to display the elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << arr[rear] << endl;
    }
};

// Main function to test the deque
int main() {
    Deque dq;
    int choice, value;

    do {
        cout << "\nMenu: " << endl;
        cout << "1. Add Front" << endl;
        cout << "2. Add Rear" << endl;
        cout << "3. Delete Front" << endl;
        cout << "4. Delete Rear" << endl;
        cout << "5. Display Deque" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add at front: ";
            cin >> value;
            dq.addFront(value);
            break;
        case 2:
            cout << "Enter value to add at rear: ";
            cin >> value;
            dq.addRear(value);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
