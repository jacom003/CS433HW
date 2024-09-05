/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author ??? (TODO: your name)
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"

/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) : capacity(size), count(0) {
   // // Allocate memory for an array of PCB pointers with the given capacity.
    table = new PCB*[capacity];

    // Initialize each element of the array to nullptr to signify that
    // there are no PCBs currently in the table.
    for (int i = 0; i < capacity; ++i) {
        table[i] = nullptr;
    }
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
   // Iterate through each PCB pointer in the table and delete the allocated
    // PCB objects to prevent memory leaks.
    for (int i = 0; i < capacity; ++i) {
        delete table[i];
    }
   // Delete all the PCBs in the table
    delete[] table;
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    // Check if the provided index is within bounds, and return the PCB at that index; otherwise, return nullptr
    if (idx < capacity) {
        return table[idx];
    }
    return nullptr;
}

/**
 * @brief Add a PCB pointer to the PCBTable at index idx.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB *pcb, unsigned int idx) {
    // Add the PCB pointer to the table at the specified index if within bounds; otherwise, print an error message.
    if (idx < capacity) {
        table[idx] = pcb;
        ++count;
    }
    // Add a PCB pointer to the PCBTable at index idx.
}
