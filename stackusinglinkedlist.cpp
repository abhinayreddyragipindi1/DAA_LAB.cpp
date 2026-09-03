
 #include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Global top pointer initialized to NULL (Empty Stack)
Node* top = NULL;

// Function to push an element onto the stack
void push(int val) {
    
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = top; // Point new node to the current top
    top = newNode;       // Make new node the top
    cout << val << " pushed into the stack.\n";
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow! The stack is empty.\n";
        return;
    }
    Node* temp = top;    // Hold the current top
    top = top->next;     // Move top to the next node
    cout << temp->data << " popped from the stack.\n";
    delete temp;         // Free memory of the old top
}

// Function to display the stack elements
void display() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
