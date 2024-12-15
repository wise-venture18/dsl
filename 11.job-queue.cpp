// Queues are frequently used in computer programming, and a typical example 
// is the creation of a job queue by an operating system. If the operating system 
// does not use priorities, then the jobs are processed in the order they enter the 
// system. Write C++ program for simulating job queue. Write functions to add 
// job and delete job from queue. 

// SAMPLE INPUT:
// 1. Add Job
// 2. Delete Job
// 3. Display Queue
// 4. Exit
// Enter your choice: 1
// Enter job ID to add: 101


#include <iostream>
#define MAX 100 // Maximum size of the queue
using namespace std;

class JobQueue {
private:
    int front, rear;
    int queue[MAX]; // Array to store jobs

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    // Function to add a job to the queue
    void addJob(int job) {
        if (rear == MAX - 1) { // Check if queue is full
            cout << "Queue is full. Cannot add job.\n";
        } else {
            if (front == -1) { 
                front = 0; // Initialize front if adding the first job
            }
            rear++;
            queue[rear] = job;
            cout << "Job " << job << " added to the queue.\n";
        }
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (front == -1 || front > rear) { // Check if queue is empty
            cout << "Queue is empty. No jobs to delete.\n";
        } else {
            cout << "Job " << queue[front] << " deleted from the queue.\n";
            front++;
        }
    }

    // Function to display the current queue
    void displayQueue() {
        if (front == -1 || front > rear) { // Check if queue is empty
            cout << "Queue is empty.\n";
        } else {
            cout << "Current Job Queue: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    JobQueue jq;
    int choice, job;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter job ID to add: ";
            cin >> job;
            jq.addJob(job);
            break;

        case 2:
            jq.deleteJob();
            break;

        case 3:
            jq.displayQueue();
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
