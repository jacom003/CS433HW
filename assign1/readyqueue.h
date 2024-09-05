/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author ??? (TODO: your name)
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient comments to your code
#pragma once

#include "pcb.h"

/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */
class ReadyQueue {
private:
    // TODO: add your private member variables here
    // choose a data structure for the ReadyQueue. No STL class is allowed.
    PCB** queue; // Array of PCB pointers
    int capacity; // Max capacity of the queue
    int count; // Current number of PCBs in the queue

    // Helper functions for maintaining the heap property
    void bubbleUp(int index);
    void bubbleDown(int index);
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return (index * 2) + 1; }
    int rightChild(int index) { return (index * 2) + 2; }
    void swap(int index1, int index2);

public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */
    ReadyQueue(int capacity = 500);

    /**
     * @brief Destructor
     */
    ~ReadyQueue();

     ReadyQueue(const ReadyQueue&) = delete; // Prevent copying

    ReadyQueue& operator=(const ReadyQueue&) = delete; // Prevent assignment

	// You may add additional member functions, but don't change the definitions of the following four member functions.

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
	void addPCB(PCB* pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
	PCB* removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
	int size() const;

     /**
      * @brief Display the PCBs in the queue.
      */
	void displayAll() const;

};