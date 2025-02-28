
# Linked List Implementation in C++

## **What is a Singly Linked List?**
A linked list is a data structure that consists of nodes. Each node contains:
1. **Data**: The value stored in the node.
2. **Pointer/Link**: A pointer that points to the next node in the sequence (or `NULL` if it’s the last node).

## **Types of Linked Lists**
1. **Singly Linked List**: Each node points to the next node.
2. **Doubly Linked List**: Each node has two pointers, one pointing to the next node and the other to the previous node.
3. **Circular Linked List**: The last node points back to the first node, forming a circle.

---

## **Implementation of a Singly Linked List**

### **Step 1: Define the Node Structure**
```cpp
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node
    Node(int val) : data(val), next(nullptr) {}
};
```

### **Step 2: Define the Linked List Class**
The linked list class manages the nodes. It typically has:
1. A pointer to the head node.
2. Methods to manipulate the list (e.g., insertion, deletion, traversal).

```cpp
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
```

---

### **Step 3: Using the Linked List**
Below is an example of how to use the `LinkedList` class in a `main` function.

```cpp
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
```

---

## **Key Points**
1. **Dynamic Memory Management**:
   - Use `new` to allocate memory for nodes.
   - Use `delete` to free memory when nodes are removed.

2. **Edge Cases to Handle**:
   - Inserting into an empty list.
   - Deleting the head node.
   - Deleting a non-existent node.
   - Traversing an empty list.

3. **Advantages**:
   - Dynamic size (no fixed array size needed).
   - Efficient insertion/deletion (especially compared to arrays).

4. **Disadvantages**:
   - Overhead of pointers.
   - Sequential access (no random access like arrays).

---
---
---



# Doubly Linked List Implementation in C++

## **What is a Doubly Linked List?**
A **doubly linked list** is a data structure where each node contains:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A pointer to the next node in the list.
3. **Previous Pointer**: A pointer to the previous node in the list.

This two-way linkage makes certain operations (like backward traversal) more efficient compared to a singly linked list.

---

## **Implementation of Doubly Linked List**

### **Step 1: Define the Node Structure**
We’ll define a `Node` structure with three components: `data`, `next`, and `prev`.

```cpp
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a node
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
```

---

### **Step 2: Define the Doubly Linked List Class**
The doubly linked list class will have:
1. A pointer to the head of the list.
2. A pointer to the tail (optional but useful).
3. Methods for insertion, deletion, and traversal.

```cpp
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
```

---

### **Step 3: Using the Doubly Linked List**
Below is an example of how to use the `DoublyLinkedList` class in a `main` function.

```cpp
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
```

---

## **Key Points**

1. **Dynamic Memory Management**:
   - Use `new` to allocate memory for nodes.
   - Use `delete` to free memory when nodes are removed.

2. **Edge Cases to Handle**:
   - Inserting into an empty list.
   - Deleting the head node.
   - Deleting the tail node.
   - Deleting a non-existent node.

3. **Advantages**:
   - Supports bidirectional traversal.
   - Efficient insertion and deletion at both ends.

4. **Disadvantages**:
   - Uses more memory compared to singly linked list (extra `prev` pointer).
   - Slightly more complex implementation.

Implementation can be found in Linked_list_101 folder