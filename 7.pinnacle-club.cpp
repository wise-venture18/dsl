// Department of Computer Engineering has student's club named 'Pinnacle Club'. 
// Students of second, third and final year of department can be granted 
// membership on request. Similarly one may cancel the membership of club. First 
// node is reserved for president of club and last node is reserved for secretary of 
// club. Write C++ program to maintain club member‘s information using singly 
// linked list. Store student PRN and Name. Write functions to:  
// a) Add and delete the members as well as president or even secretary.  
// b) Compute total number of members of club 
// c) Display members  
// d) Two linked lists exists for two divisions. Concatenate two lists

#include <iostream>
#include <string>
using namespace std;

// Node structure for storing each member's information
struct Node {
    int prn;
    string name;
    Node* next;

    // Constructor to initialize a new node
    Node(int memberPrn, string memberName) {
        prn = memberPrn;
        name = memberName;
        next = nullptr;
    }
};

// Class for managing the linked list of club members
class PinnacleClub {
private:
    Node* head; // President
    Node* tail; // Secretary

public:
    PinnacleClub() {
        head = nullptr;
        tail = nullptr;
    }

    // Add the president
    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head; // If the list was empty, head is also the tail
        }
        cout << "President added: " << name << endl;
    }

    // Add the secretary
    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = tail; // If the list was empty, tail is also the head
        }
        cout << "Secretary added: " << name << endl;
    }

    // Add a regular member
    void addMember(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Member added: " << name << endl;
    }

    // Delete a member by PRN
    void deleteMember(int prn) {
        if (head == nullptr) {
            cout << "List is empty. No members to delete.\n";
            return;
        }

        // Delete president
        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            cout << "President removed.\n";
            return;
        }

        // Traverse the list to find the member to delete
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->prn != prn) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Member with PRN " << prn << " not found.\n";
            return;
        }

        // Delete secretary
        if (current == tail) {
            tail = previous;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            cout << "Secretary removed.\n";
        } else {
            previous->next = current->next;
            cout << "Member removed.\n";
        }

        delete current;
    }

    // Count total members
    int countMembers() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display all members
    void displayMembers() const {
        if (head == nullptr) {
            cout << "No members in the club.\n";
            return;
        }
        Node* temp = head;
        cout << "Club Members:\n";
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name;
            if (temp == head) {
                cout << " (President)";
            } else if (temp == tail) {
                cout << " (Secretary)";
            }
            cout << "\n";
            temp = temp->next;
        }
    }

    // Concatenate another list
    void concatenate(PinnacleClub& other) {
        if (head == nullptr) {
            head = other.head;
            tail = other.tail;
        } else if (other.head != nullptr) {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = nullptr;
        other.tail = nullptr;
    }
};

// Main program
int main() {
    PinnacleClub divisionA, divisionB;

    // Adding members to division A
    divisionA.addPresident(101, "Alice");
    divisionA.addMember(102, "Bob");
    divisionA.addSecretary(103, "Charlie");

    // Adding members to division B
    divisionB.addPresident(201, "David");
    divisionB.addMember(202, "Eva");
    divisionB.addSecretary(203, "Frank");

    cout << "\nDivision A Members:\n";
    divisionA.displayMembers();

    cout << "\nDivision B Members:\n";
    divisionB.displayMembers();

    // Concatenate division A and B
    divisionA.concatenate(divisionB);
    cout << "\nAfter concatenating Division A and B:\n";
    divisionA.displayMembers();

    // Display total members
    cout << "\nTotal Members in Club: " << divisionA.countMembers() << endl;

    // Remove a member and display updated list
    divisionA.deleteMember(102);
    cout << "\nAfter removing a member:\n";
    divisionA.displayMembers();

    return 0;
}
