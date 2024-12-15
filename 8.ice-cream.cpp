// Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. 
// Write C++ program to store two sets using linked list. compute and display-
// a)	Set of students who like both vanilla and butterscotch
// b)	Set of students who like either vanilla or butterscotch or not both
// c)	Number of students who like neither vanilla nor butterscotch


#include <iostream>
using namespace std;

// Function to find the intersection of two sets
void findIntersection(int setA[], int sizeA, int setB[], int sizeB, int result[], int &sizeResult) {
    sizeResult = 0;
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                result[sizeResult++] = setA[i];
                break;
            }
        }
    }
}

// Function to find the symmetric difference of two sets
void findSymmetricDifference(int setA[], int sizeA, int setB[], int sizeB, int result[], int &sizeResult) {
    sizeResult = 0;

    // Add elements in setA but not in setB
    for (int i = 0; i < sizeA; i++) {
        bool found = false;
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[sizeResult++] = setA[i];
        }
    }

    // Add elements in setB but not in setA
    for (int i = 0; i < sizeB; i++) {
        bool found = false;
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[sizeResult++] = setB[i];
        }
    }
}

// Function to find the union of two sets
void findUnion(int setA[], int sizeA, int setB[], int sizeB, int result[], int &sizeResult) {
    sizeResult = 0;

    // Add all elements of setA
    for (int i = 0; i < sizeA; i++) {
        result[sizeResult++] = setA[i];
    }

    // Add elements of setB that are not already in setA
    for (int i = 0; i < sizeB; i++) {
        bool found = false;
        for (int j = 0; j < sizeA; j++) {
            if (setB[i] == setA[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result[sizeResult++] = setB[i];
        }
    }
}

int main() {
    int totalStudents;
    int vanilla[100], butterscotch[100];
    int sizeVanilla, sizeButterscotch;

    // Input the total number of students
    cout << "Enter total number of students in the class: ";
    cin >> totalStudents;

    // Input the students who like vanilla
    cout << "Enter number of students who like Vanilla: ";
    cin >> sizeVanilla;
    cout << "Enter roll numbers of students who like Vanilla: ";
    for (int i = 0; i < sizeVanilla; i++) {
        cin >> vanilla[i];
    }

    // Input the students who like butterscotch
    cout << "Enter number of students who like Butterscotch: ";
    cin >> sizeButterscotch;
    cout << "Enter roll numbers of students who like Butterscotch: ";
    for (int i = 0; i < sizeButterscotch; i++) {
        cin >> butterscotch[i];
    }

    // Find the students who like both vanilla and butterscotch
    int both[100], sizeBoth;
    findIntersection(vanilla, sizeVanilla, butterscotch, sizeButterscotch, both, sizeBoth);
    cout << "\nStudents who like both Vanilla and Butterscotch: ";
    for (int i = 0; i < sizeBoth; i++) {
        cout << both[i] << " ";
    }
    cout << endl;

    // Find the students who like either vanilla or butterscotch but not both
    int eitherOr[100], sizeEitherOr;
    findSymmetricDifference(vanilla, sizeVanilla, butterscotch, sizeButterscotch, eitherOr, sizeEitherOr);
    cout << "Students who like either Vanilla or Butterscotch but not both: ";
    for (int i = 0; i < sizeEitherOr; i++) {
        cout << eitherOr[i] << " ";
    }
    cout << endl;

    // Find the number of students who like neither vanilla nor butterscotch
    int unionSet[200], sizeUnion;
    findUnion(vanilla, sizeVanilla, butterscotch, sizeButterscotch, unionSet, sizeUnion);
    int neither = totalStudents - sizeUnion;
    cout << "Number of students who like neither Vanilla nor Butterscotch: " << neither << endl;

    return 0;
}
