// The ticket booking system of Cinemax Theater has to be implemented using C++ program. There are 10 rows and 7 seats in each row. A doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand
// a)	The list of available seats is to be displayed
// b)	The seats are to be booked
// c)The booking can be canceled.

#include <iostream>
using namespace std;

// Node structure representing a seat
struct Node {
    int seatNumber;
    bool isBooked;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int seatNumber) {
    Node* newNode = new Node();
    newNode->seatNumber = seatNumber;
    newNode->isBooked = false;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to initialize a doubly circular linked list for a row
Node* initializeRow(int seats) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 1; i <= seats; i++) {
        Node* newNode = createNode(i);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Make it circular
    tail->next = head;
    head->prev = tail;
    return head;
}

// Function to display available seats in a row
void displayAvailableSeats(Node* head) {
    if (head == nullptr) return;
    Node* temp = head;
    bool hasAvailable = false;

    do {
        if (!temp->isBooked) {
            cout << temp->seatNumber << " ";
            hasAvailable = true;
        }
        temp = temp->next;
    } while (temp != head);

    if (!hasAvailable) {
        cout << "No available seats.";
    }
    cout << endl;
}

// Function to book a seat in a row
void bookSeat(Node* head, int seatNumber) {
    if (head == nullptr) return;
    Node* temp = head;

    do {
        if (temp->seatNumber == seatNumber) {
            if (!temp->isBooked) {
                temp->isBooked = true;
                cout << "Seat " << seatNumber << " successfully booked." << endl;
            } else {
                cout << "Seat " << seatNumber << " is already booked." << endl;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Invalid seat number." << endl;
}

// Function to cancel a booking in a row
void cancelBooking(Node* head, int seatNumber) {
    if (head == nullptr) return;
    Node* temp = head;

    do {
        if (temp->seatNumber == seatNumber) {
            if (temp->isBooked) {
                temp->isBooked = false;
                cout << "Seat " << seatNumber << " booking canceled." << endl;
            } else {
                cout << "Seat " << seatNumber << " is not booked." << endl;
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Invalid seat number." << endl;
}

int main() {
    const int rows = 10;
    const int seats = 7;
    Node* theater[rows];

    // Initialize rows
    for (int i = 0; i < rows; i++) {
        theater[i] = initializeRow(seats);
    }

    // Simulate some random bookings
    theater[0]->isBooked = true;
    theater[0]->next->isBooked = true;
    theater[1]->next->next->isBooked = true;

    int choice, row, seatNumber;
    do {
        cout << "\nCinemax Theater Ticket Booking System\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter row number (1-10): ";
                cin >> row;
                if (row < 1 || row > rows) {
                    cout << "Invalid row number." << endl;
                } else {
                    cout << "Available seats in row " << row << ": ";
                    displayAvailableSeats(theater[row - 1]);
                }
                break;

            case 2:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seatNumber;
                if (row < 1 || row > rows || seatNumber < 1 || seatNumber > seats) {
                    cout << "Invalid row or seat number." << endl;
                } else {
                    bookSeat(theater[row - 1], seatNumber);
                }
                break;

            case 3:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seatNumber;
                if (row < 1 || row > rows || seatNumber < 1 || seatNumber > seats) {
                    cout << "Invalid row or seat number." << endl;
                } else {
                    cancelBooking(theater[row - 1], seatNumber);
                }
                break;

            case 4:
                cout << "Exiting the system." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
