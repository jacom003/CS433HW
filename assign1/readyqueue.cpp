#include <iostream>
#include "readyqueue.h"

using namespace std;

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */
 ReadyQueue::ReadyQueue(int capacity) : capacity(capacity), count(0) {
    queue = new PCB*[this->capacity];
    for (int i = 0; i < capacity; ++i) {
        queue[i] = nullptr; // Initialize the array elements to nullptr
    }
 }

/**
 *@brief Destructor
*/
ReadyQueue::~ReadyQueue() {
    delete[] queue; // Deleting the array itself
}

/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB *pcbPtr) {
    if (count < capacity) {
        queue[count] = pcbPtr; // Place the new PCB at the end
        pcbPtr->setState(ProcState::READY); // Set its state to READY
        bubbleUp(count); // Adjust its position to maintain heap property
        count++; // Increase the count of PCBs
 }
    // Handle the case when the queue is full (not shown for brevity)
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    if (count == 0) return nullptr; // Queue is empty
    PCB* removedPCB = queue[0]; // Highest priority PCB
    removedPCB->setState(ProcState::RUNNING); // Set its state to RUNNING
    queue[0] = queue[count - 1]; // Move the last PCB to the root
    count--; // Decrease the count of PCBs
    bubbleDown(0); // Adjust the new root's position to maintain heap property

    return removedPCB;
}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() const {
    return count; // Return the current number of PCBs in the queue
}

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() const {
    // Loop through all PCBs in the queue and call their display method to print their details
    for (int i = 0; i < count; i++) {
        queue[i]->display(); //Dislpay each PCB
    }
}

void ReadyQueue::bubbleUp(int index) {
    // Modify to ensure max-heap logic for priority comparison
    while (index > 0 && queue[parent(index)]->getPriority() < queue[index]->getPriority()) {
        swap(index, parent(index));
        index = parent(index);
    }
}

void ReadyQueue::bubbleDown(int index) {
    int largest = index; // Assume the current node is the largest
    int left = leftChild(index); // Index of the left child
    int right = rightChild(index); // Index of the right child

    // Check if the left child exists and has a higher priority than the current node
    if (left < count && queue[left]->getPriority() > queue[largest]->getPriority()) {
        largest = left; // Update largest to be the left child
    }

    // Check if the right child exists and has a higher priority than the largest found so far
    if (right < count && queue[right]->getPriority() > queue[largest]->getPriority()) {
        largest = right; // Update largest to be the right child
    }

    // If the largest is not the current node, swap and recursively bubble down
    if (largest != index) {
        swap(index, largest); // Swap the node with the largest child
        bubbleDown(largest); // Recursively ensure the heap property in the affected subtree
    }
}

void ReadyQueue::swap(int index1, int index2) {
    PCB* temp = queue[index1]; // Temporarily hold the first node
    queue[index1] = queue[index2]; // Swap the first node with the second node
    queue[index2] = temp; // Place the first node in the position of the second node
}