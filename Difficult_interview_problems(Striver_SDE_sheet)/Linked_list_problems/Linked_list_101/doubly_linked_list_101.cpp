#include<iostream>
using namespace std;

struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList {
private:
    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node (optional but convenient)

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current; // Free the current node
            current = next;
        }
    }

    // Method to insert at the head
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) { // List is empty
            head = tail = newNode; // Both head and tail point to the new node
        } else {
            newNode->next = head;  // Link the new node to the current head
            head->prev = newNode; // Link the current head to the new node
            head = newNode;       // Update head to the new node
        }
    }

    // Method to insert at the tail
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) { // List is empty
            head = tail = newNode; // Both head and tail point to the new node
        } else {
            newNode->prev = tail;  // Link the new node to the current tail
            tail->next = newNode; // Link the current tail to the new node
            tail = newNode;       // Update tail to the new node
        }
    }

    // Method to delete a node by value
    void deleteNode(int val) {
        if (head == nullptr) return; // List is empty

        // Traverse the list to find the node to delete
        Node* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) return; // Node not found

        // If the node is the head
        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr; // Update head's prev if head is not null
            else tail = nullptr; // If the list becomes empty
        }
        // If the node is the tail
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // If the node is in the middle
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp; // Free the memory of the deleted node
    }

    // Method to display the list forward
    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Method to display the list backward
    void displayBackward() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }
};


int main() {
    DoublyLinkedList list;

    // Insert nodes
    list.insertAtHead(10); // Insert 10 at the beginning
    list.insertAtHead(20); // Insert 20 at the beginning
    list.insertAtTail(30); // Insert 30 at the end
    list.insertAtTail(40); // Insert 40 at the end

    // Display the list forward
    std::cout << "List Forward: ";
    list.displayForward(); // Output: 20 <-> 10 <-> 30 <-> 40 <-> NULL

    // Display the list backward
    std::cout << "List Backward: ";
    list.displayBackward(); // Output: 40 <-> 30 <-> 10 <-> 20 <-> NULL

    // Delete a node
    list.deleteNode(10); // Delete the node with value 10
    std::cout << "After Deleting 10: ";
    list.displayForward(); // Output: 20 <-> 30 <-> 40 <-> NULL

    return 0;
}