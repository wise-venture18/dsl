// Write C++ program for storing binary number using doubly linked lists. Write 
// functions 
// a) to compute 1„s and 2„s complement 
// b) add two binary numbers 


#include <iostream>
#include <string>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to print the binary number
void printBinary(Node* head) {
    if (head == nullptr) {
        cout << "Empty binary number." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Function to compute 1's complement
Node* onesComplement(Node* head) {
    if (head == nullptr) return nullptr;
    Node* newHead = nullptr;
    Node* temp = head;
    while (temp != nullptr) {
        newHead = insertAtEnd(newHead, 1 - temp->data);
        temp = temp->next;
    }
    return newHead;
}

// Function to compute 2's complement
Node* twosComplement(Node* head) {
    Node* onesComp = onesComplement(head);
    if (onesComp == nullptr) return nullptr;

    Node* newHead = nullptr;
    int carry = 1;
    Node* temp = onesComp;

    while (temp != nullptr) {
        int sum = temp->data + carry;
        newHead = insertAtEnd(newHead, sum % 2);
        carry = sum / 2;

        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    if (carry) {
        newHead = insertAtEnd(newHead, carry);
    }
    return newHead;
}

// Function to add two binary numbers
Node* addBinary(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    Node* newHead = nullptr;
    int carry = 0;

    // Reverse the linked lists (without using std::reverse)
    Node* revHead1 = nullptr;
    Node* curr = head1;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = revHead1;
        curr->prev = nullptr;
        if (revHead1 != nullptr){
            revHead1->prev = curr;
        }
        revHead1 = curr;
        curr = next;
    }
    Node* revHead2 = nullptr;
    curr = head2;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = revHead2;
        curr->prev = nullptr;
        if (revHead2 != nullptr){
            revHead2->prev = curr;
        }
        revHead2 = curr;
        curr = next;
    }

    Node* temp1 = revHead1;
    Node* temp2 = revHead2;

    while (temp1 != nullptr || temp2 != nullptr || carry) {
        int val1 = (temp1 != nullptr) ? temp1->data : 0;
        int val2 = (temp2 != nullptr) ? temp2->data : 0;
        int sum = val1 + val2 + carry;

        newHead = insertAtEnd(newHead, sum % 2);
        carry = sum / 2;

        if (temp1 != nullptr) temp1 = temp1->next;
        if (temp2 != nullptr) temp2 = temp2->next;
    }

    //Reverse the result
    Node* finalHead = nullptr;
    curr = newHead;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = finalHead;
        curr->prev = nullptr;
        if (finalHead != nullptr){
            finalHead->prev = curr;
        }
        finalHead = curr;
        curr = next;
    }
    return finalHead;
}

int main() {
    Node* binary1 = nullptr;
    Node* binary2 = nullptr;

    string num1, num2;
    cout << "Enter the first binary number: ";
    cin >> num1;
    for (int i = 0; i < num1.length(); i++) { // Simple for loop
        binary1 = insertAtEnd(binary1, num1[i] - '0');
    }

    cout << "Enter the second binary number: ";
    cin >> num2;
    for (int i = 0; i < num2.length(); i++) { // Simple for loop
        binary2 = insertAtEnd(binary2, num2[i] - '0');
    }

    cout << "Binary 1: ";
    printBinary(binary1);

    cout << "1's complement of Binary 1: ";
    printBinary(onesComplement(binary1));

    cout << "2's complement of Binary 1: ";
    printBinary(twosComplement(binary1));

    cout << "Binary 2: ";
    printBinary(binary2);

    cout << "1's complement of Binary 2: ";
    printBinary(onesComplement(binary2));

    cout << "2's complement of Binary 2: ";
    printBinary(twosComplement(binary2));

    cout << "Sum of Binary 1 and Binary 2: ";
    printBinary(addBinary(binary1, binary2));

    return 0;
}
