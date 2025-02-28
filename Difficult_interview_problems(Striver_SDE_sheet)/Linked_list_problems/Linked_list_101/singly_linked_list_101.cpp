#include<iostream>
using namespace std;

struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node
    Node(int val) : data(val), next(nullptr) {}
};


class LinkedList {
private:
    Node* head; // Pointer to the first node

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current; // Free the current node
            current = next;
        }
    }

    // Method to insert at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val); // Create a new node
        newNode->next = head;          // Link new node to current head
        head = newNode;                // Update head to new node
    }

    // Method to insert at the end
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) { // If the list is empty
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }

    // Method to delete a node by value
    void deleteNode(int val) {
        if (head == nullptr) return; // List is empty

        // If the node to delete is the head
        if (head->data == val) {
            Node* temp = head;
            head = head->next; // Update head
            delete temp;       // Free the old head
            return;
        }

        // Traverse the list to find the node
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return; // Node not found

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // Update link to skip the node
        delete nodeToDelete;             // Free the memory
    }

    // Method to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};


int main() {
    LinkedList list;

    list.insertAtHead(10); // Insert 10 at the beginning
    list.insertAtHead(20); // Insert 20 at the beginning
    list.insertAtTail(30); // Insert 30 at the end
    list.insertAtTail(40); // Insert 40 at the end

    std::cout << "Linked List: ";
    list.display(); // Output: 20 -> 10 -> 30 -> 40 -> NULL

    list.deleteNode(10); // Delete node with value 10
    std::cout << "After deleting 10: ";
    list.display(); // Output: 20 -> 30 -> 40 -> NULL

    return 0;
}