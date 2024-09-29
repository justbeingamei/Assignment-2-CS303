// Assignment 2 CS303.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Amei Ayuel
// CS303
// Assignment 2 Due 9/30/2024

#include "Assignment2CS303.h"

using namespace KW;

int main()
{
// question 1 : testing code
	Single_Linked_List<int> list;

	// push items to the front and back
	list.push_front(10);
	list.push_back(20);
    list.push_front(5);
    list.push_back(35);
    list.push_back(14);
    list.push_back(88);
    list.push_front(25);

    // Display front and back items
    std::cout << "Front: " << list.front() << std::endl; // Should print 25
    std::cout << "Back: " << list.back() << std::endl;  // Should print 88

    // Remove front and back items
    list.pop_front();
    std::cout << "After pop_front, Front: " << list.front() << std::endl; // Should print 5
    list.pop_back();
    std::cout << "After pop_back, Back: " << list.back() << std::endl; // Should print 14

    // Insert at index and display size
    list.insert(1, 15);
    std::cout << "Size after insert: " << list.size() << std::endl; // Should print 6
    std::cout << "Item at index 1: " << list.find(15) << std::endl; // Should print 1

    // Remove an item and check size
    list.remove(0);
    std::cout << "Size after remove: " << list.size() << std::endl; // Should print 5

    // Test IntStack
    IntStack stack;

    // Check if stack is empty
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Should print Yes

    // Push items onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);
    stack.push(25);
    stack.push(30);

    // Display top value
    std::cout << "Top of stack: " << stack.top() << std::endl; // Should print 30

    // Pop an item and display top again
    stack.pop();
    std::cout << "Top after pop: " << stack.top() << std::endl; // Should print 25

    // Calculate average
    std::cout << "Average of stack: " << stack.average() << std::endl; // Should print 7.5

    return 0;

	

}
