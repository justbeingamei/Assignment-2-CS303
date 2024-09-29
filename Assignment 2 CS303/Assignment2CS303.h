#pragma once

//Q1 : Build a single linked list class. Should have data members: head, tail, and num_itms. Write the following
// operations : push_front, push_back, pop_front, pop_back, front_back, empty, void insert, bool remove, size_t_find

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <stdexcept> // For std::out_of_range

namespace KW {

    // node structure for the linked list
    template<typename Item_Type>
    struct Node {
        Item_Type data; // data stored in the node
        Node* next;     // pointer to the next node in the list

        // constructor to initialize a node with data
        Node(const Item_Type& data) : data(data), next(nullptr) {}
    };

    // Single Linked List Class
    template<typename Item_Type>
    class Single_Linked_List {
    private:
        Node<Item_Type>* head; // pointer to the first node (head) of the list
        Node<Item_Type>* tail; // pointer to the last node (tail) of the list
        size_t num_items;      // number of items currently in the list

    public:
        // constructor to initialize the linked list
        Single_Linked_List();
        // destructor to clean up the list
        ~Single_Linked_List();

        // member functions to manipulate the list
        void push_front(const Item_Type& item); // add item to the front of the list
        void push_back(const Item_Type& item);  // add item to the back of the list
        void pop_front();                        // remove the front item
        void pop_back();                         // remove the back item
        Item_Type front() const;                 // get the front item
        Item_Type back() const;                  // get the back item
        bool empty() const;                      // check if the list is empty
        void insert(size_t index, const Item_Type& item); // insert item at a specific index
        bool remove(size_t index);               // remove item at a specific index
        size_t find(const Item_Type& item) const; // find the index of the item
        size_t size() const { return num_items; } // get the current size of the list return num items
    };

    // function definitions for Single_Linked_List

    // constructor implementation
    template<typename Item_Type>
    Single_Linked_List<Item_Type>::Single_Linked_List()
        : head(nullptr), tail(nullptr), num_items(0) {} // initialize head and tail to nullptr and num_items to 0

    // destructor implementation
    template<typename Item_Type>
    Single_Linked_List<Item_Type>::~Single_Linked_List() {
        while (!empty()) {
            pop_front(); // remove all items from the front until empty
        }
    }

    // add an item to the front of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
        Node<Item_Type>* newNode = new Node<Item_Type>(item); // create a new node with the given item
        newNode->next = head; // link the new node to the current head
        head = newNode; // update head to point to the new node
        if (tail == nullptr) { // if the list was empty
            tail = newNode; // the new node is also the tail
        }
        num_items++; // increment the number of items
    }

    // add an item to the back of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
        Node<Item_Type>* newNode = new Node<Item_Type>(item); // create a new node
        if (tail) { // if the list is not empty
            tail->next = newNode; // link old tail to new node
        }
        else { // if the list is empty
            head = newNode; // new node becomes head
        }
        tail = newNode; // update tail to point to the new node
        num_items++; // increment the number of items
    }

    // remove the front item of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::pop_front() {
        if (empty()) return; // do nothing if the list is empty
        Node<Item_Type>* temp = head; // store the current head
        head = head->next; // move head to the next node
        delete temp; // delete the old head
        num_items--; // decrement the number of items
        if (empty()) { // if the list is now empty
            tail = nullptr; // update tail to nullptr
        }
    }

    // Remove the back item of the list
    template<typename Item_Type>
    void Single_Linked_List<Item_Type>::pop_back() {
        if (empty()) return; // Do nothing if the list is empty
        if (head == tail) { // If there's only one item
            delete head; // Delete the only node
            head = tail = nullptr; // Set both head and tail to nullptr
        }
        else {
            Node<Item_Type>* current = head; // Start at head
            while (current->next != tail) { // Find the second last node
                current = current->next; // Traverse to the second last node
            }
            delete tail; // Delete the last node
            tail = current; // Update tail to point to the second last node
            tail->next = nullptr; // Nullify the next pointer of the new tail
        }
        num_items--; // Decrement the number of items
    }

    // Get the front item
    template<typename Item_Type>
    Item_Type Single_Linked_List<Item_Type>::front() const {
        if (empty()) throw std::out_of_range("List is empty."); // Check if the list is empty
        return head->data; // Return the data at head
    }

    // Get the back item
    template<typename Item_Type>
    Item_Type Single_Linked_List<Item_Type>::back() const {
        if (empty()) throw std::out_of_range("List is empty."); // Check if the list is empty
        return tail->data; // Return the data at tail
    }

    // Check if the list is empty
    template<typename Item_Type>
    bool Single_Linked_List<Item_Type>::empty() const {
        return num_items == 0; // Return true if no items
    }

    // Insert an item at a specific index
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
                current = current->next; // Move to next node
            }
            newNode->next = current->next; // Link new node to the current's next
            current->next = newNode; // Link current node to the new node
            num_items++; // Increment the number of items
        }
    }

    // Remove an item at a specific index
    template<typename Item_Type>
    bool Single_Linked_List<Item_Type>::remove(size_t index) {
        if (index >= num_items) return false; // Return false if index is out of range
        if (index == 0) { // If removing from front
            pop_front(); // Call pop_front function
        }
        else {
            Node<Item_Type>* current = head; // Start at head
            for (size_t i = 0; i < index - 1; ++i) { // Traverse to one before index
                current = current->next; // Move to next node
            }
            Node<Item_Type>* temp = current->next; // Node to be deleted
            current->next = temp->next; // Link around the node
            if (temp == tail) { // if removing last node
                tail = current; // update tail
            }
            delete temp; // delete the node
            num_items--; // decrement num items
        }
        return true; // Successfully removed 
    }

    // Find the position of an item
    template<typename Item_Type>
    size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
        Node<Item_Type>* current = head; // start at head
        size_t index = 0; // index tracker
        while (current) { // go thru the list
            if (current->data == item) return index; // item found, return index
            current = current->next; // move to next node
            index++; // increment index
        }
        return num_items; // return size if not found
    }

    // stack class using vector
    class IntStack {
    private:
        std::vector<int> stack; // vector to store stack elements

    public:
        void push(int value); // Push value onto the stack
        void pop();           // Pop value from the stack
        int top() const;      // Get top value of the stack
        bool isEmpty() const; // Check if the stack is empty
        double average() const; // Calculate the average of stack values
    };

    // intStack function definitions

    // push value onto stack
    void IntStack::push(int value) {
        stack.push_back(value); // add value to the end of the vector
    }

    // Pop value from stack
    void IntStack::pop() {
        if (!isEmpty()) { // check if stack is not empty
            stack.pop_back(); // remove the last value
        }
    }

    // get top value of stack
    int IntStack::top() const {
        if (isEmpty()) throw std::out_of_range("Stack is empty."); // check if stack is empty
        return stack.back(); // return the last value
    }

    // check if stack is empty
    bool IntStack::isEmpty() const {
        return stack.empty(); // return true if vector is empty
    }

    // calculate average of stack values
    double IntStack::average() const {
        if (isEmpty()) return 0.0; // return 0 if stack is empty
        double sum = 0; // initialize sum
        for (int value : stack) { // loop through each value in the stack
            sum += value; // add to sum
        }
        return sum / stack.size(); // return average
    }

} // namespace KW


#endif // HEADER_H

