#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

// Global pointers for the queue
Node* front = NULL;
Node* rear = NULL;

// Function to insert at the beginning (Enqueue)
void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = front; // Point new node to the current front

    // If queue is empty, new node is also the rear
    if (front == nullptr) {
        rear = newNode;
    }
    
    front = newNode; // Move front to the new node
    cout << value << " enqueued successfully.\n";
}

// Function to delete from the end (Dequeue)
void dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow! The queue is empty.\n";
        return;
    }

    // Case 1: Only one element in the queue
    if (front == rear) {
        cout << "Dequeued element: " << rear->data << "\n";
        delete rear;
        front = nullptr;
        rear = nullptr;
        return;
    }

    // Case 2: Multiple elements, traverse to find the second-to-last node
    Node* temp = front;
    while (temp->next != rear) {
        temp = temp->next;
    }

    cout << "Dequeued element: " << rear->data << "\n";
    delete rear;       // Free the memory of the last node
    rear = temp;       // Update rear to the second-to-last node
    rear->next = nullptr; 
}

// Function to display the queue elements
void display() {
    if (front == nullptr) {
    cout << "Queue is empty.\n";
        return;
    }
    
    Node* temp = front;
    cout << "Queue (Front to Rear): ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value;

    while (1) {
    cout << "\n--- Queue Operations ---\n";
    cout << "1. Enqueue (Insert at Begin)\n";
    cout << "2. Dequeue (Delete at End)\n";
    cout << "3. Display Queue\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
            cout << "Exiting program.\n";
                return 0;
            default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}
