#include "Assignment2CS303.h"

namespace KW {

    // Constructor for the linked list
    template<typename Item_Type>
    Single_Linked_List<Item_Type>::Single_Linked_List()
        : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor for the linked list
    template<typename Item_Type>
    Single_Linked_List<Item_Type>::~Single_Linked_List() {
        while (!empty()) {
            pop_front(); // Remove all items
        }
    }

    // Add an item to the front of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
        Node<Item_Type>* newNode = new Node<Item_Type>(item); // Create new node
        newNode->next = head; // Point new node to old head
        head = newNode; // Update head to new node
        if (tail == nullptr) { // If list was empty, update tail
            tail = newNode;
        }
        num_items++; // Increment item count
    }

    // Add an item to the back of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
        Node<Item_Type>* newNode = new Node<Item_Type>(item); // Create new node
        if (tail) { // If list is not empty
            tail->next = newNode; // Link old tail to new node
        }
        else { // If list is empty
            head = newNode; // New node is also head
        }
        tail = newNode; // Update tail to new node
        num_items++; // Increment item count
    }

    // Remove the front item of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::pop_front() {
        if (empty()) return; // Do nothing if list is empty
        Node<Item_Type>* temp = head; // Store old head
        head = head->next; // Update head to next node
        delete temp; // Delete old head
        num_items--; // Decrement item count
        if (empty()) { // If list is empty, update tail
            tail = nullptr;
        }
    }

    // Remove the back item of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::pop_back() {
        if (empty()) return; // Do nothing if list is empty
        if (head == tail) { // If there's only one element
            delete head; // Delete the only node
            head = tail = nullptr; // Update both to nullptr
        }
        else {
            Node<Item_Type>* current = head; // Start at head
            while (current->next != tail) { // Find the second last node
                current = current->next;
            }
            delete tail; // Delete the last node
            tail = current; // Update tail to second last
            tail->next = nullptr; // Nullify the next pointer
        }
        num_items--; // Decrement item count
    }

    // Get the front item
    template<typename Item_Type>
    Item_Type Single_Linked_List<Item_Type>::front() const {
        if (empty()) throw std::out_of_range("List is empty."); // Check if empty
        return head->data; // Return the data at head
    }

    // Get the back item
    template<typename Item_Type>
    Item_Type Single_Linked_List<Item_Type>::back() const {
        if (empty()) throw std::out_of_range("List is empty."); // Check if empty
        return tail->data; // Return the data at tail
    }

    // Check if the list is empty
    template<typename Item_Type>
    bool Single_Linked_List<Item_Type>::empty() const {
        return num_items == 0; // True if no items
    }

    // Insert item at specific index
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
        if (index == 0) {
            push_front(item); // Insert at front
        }
        else if (index >= num_items) {
            push_back(item); // Insert at back if index is too large
        }
        else {
            Node<Item_Type>* newNode = new Node<Item_Type>(item); // Create new node
            Node<Item_Type>* current = head; // Start at head
            for (size_t i = 0; i < index - 1; ++i) { // Traverse to one before index
                current = current->next;
            }
            newNode->next = current->next; // Link new node
            current->next = newNode; // Link current to new node
            num_items++; // Increment item count
        }
    }

    // Remove item at specific index
    template<typename Item_Type>
    bool Single_Linked_List<Item_Type>::remove(size_t index) {
        if (index >= num_items) return false; // Index out of range
        if (index == 0) { // If removing from front
            pop_front();
        }
        else {
            Node<Item_Type>* current = head; // Start at head
            for (size_t i = 0; i < index - 1; ++i) { // Traverse to one before index
                current = current->next;
            }
            Node<Item_Type>* temp = current->next; // Node to be deleted
            current->next = temp->next; // Link around the node
            if (temp == tail) { // If removing last node
                tail = current; // Update tail
            }
            delete temp; // Delete the node
            num_items--; // Decrement item count
        }
        return true; // Successful removal
    }

    // Find the position of an item
    template<typename Item_Type>
    size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
        Node<Item_Type>* current = head; // Start at head
        size_t index = 0; // Index tracker
        while (current) { // Traverse the list
            if (current->data == item) return index; // Item found
            current = current->next; // Move to next node
            index++; // Increment index
        }
        return num_items; // Return size if not found
    }

    // Push value onto stack
    void IntStack::push(int value) {
        stack.push_back(value); // Add value to the end of the vector
    }

    // Pop value from stack
    void IntStack::pop() {
        if (!isEmpty()) {
            stack.pop_back(); // Remove last element
        }
    }

    // Get top value of stack
    int IntStack::top() const {
        if (isEmpty()) throw std::out_of_range("Stack is empty."); // Check if empty
        return stack.back(); // Return last element
    }

    // Check if stack is empty
    bool IntStack::isEmpty() const {
        return stack.empty(); // True if no elements
    }

    // Calculate average of stack values
    double IntStack::average() const {
        if (isEmpty()) return 0.0; // Return 0 if empty
        double sum = 0; // Sum of values
        for (int value : stack) {
            sum += value; // Accumulate sum
        }
        return sum / stack.size(); // Return average
    }

} // namespace KW
