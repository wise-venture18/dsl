// Pizza parlor accepting maximum M orders. Orders are served in first come 
// first served basis. Order once placed cannot be cancelled. Write C++ program 
// to simulate the system using circular queue using array.

#include <iostream>
#define MAX 5 // Maximum number of orders the pizza parlor can handle
using namespace std;

class CircularQueue {
private:
    int front, rear, count;
    int orders[MAX]; // Array to store orders

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0; // To keep track of the number of orders
    }

    // Function to add an order
    void addOrder(int order) {
        if (count == MAX) { // Check if the queue is full
            cout << "Order queue is full. Cannot accept more orders.\n";
            return;
        }
        rear = (rear + 1) % MAX; // Update rear in a circular manner
        orders[rear] = order;
        count++;
        if (front == -1) { // If adding the first order
            front = 0;
        }
        cout << "Order " << order << " added to the queue.\n";
    }

    // Function to serve (remove) an order
    void serveOrder() {
        if (count == 0) { // Check if the queue is empty
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Order " << orders[front] << " is served.\n";
        front = (front + 1) % MAX; // Update front in a circular manner
        count--;
        if (count == 0) { // Reset front and rear if queue is empty
            front = -1;
            rear = -1;
        }
    }

    // Function to display current orders
    void displayOrders() {
        if (count == 0) { // Check if the queue is empty
            cout << "No pending orders.\n";
            return;
        }
        cout << "Current Orders: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX; // Calculate the circular index
            cout << orders[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, order;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter order ID to add: ";
            cin >> order;
            cq.addOrder(order);
            break;

        case 2:
            cq.serveOrder();
            break;

        case 3:
            cq.displayOrders();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
