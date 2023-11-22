# Data Structures

This repository contains implementations of various data structures in C++. Each data structure is organized into separate modules for clarity and ease of use.

## Binary Search Tree

A binary search tree (BST) is a binary tree data structure where each node has at most two child nodes, arranged in such a way that the value in each node is greater than or equal to the values in its left subtree and less than or equal to the values in its right subtree.

## Graph

A graph is a collection of nodes connected by edges. The nodes may represent entities, and the edges represent relationships between these entities. Graphs are widely used in computer science for modeling various scenarios, such as social networks, transportation systems, and more.

## Heap

A heap is a specialized tree-based data structure that satisfies the heap property. In a max heap, the value of each node is greater than or equal to the values of its children. In a min heap, the value of each node is less than or equal to the values of its children. This repository includes implementations of both max heaps and min heaps.

### Max Heap

A max heap is a binary heap in which the value of each node is greater than or equal to the values of its children. This data structure is often used in priority queues and is efficient for finding the maximum element.

### Min Heap

A min heap is a binary heap in which the value of each node is less than or equal to the values of its children. Min heaps are commonly used in implementing priority queues, and they allow for efficient retrieval of the minimum element.

### Binomial Heap

A binomial heap is a more advanced type of heap that supports efficient merging of heaps. It is composed of a collection of binomial trees, each satisfying the heap property. Binomial heaps are known for their efficient merge and decrease-key operations.

## Linked List

A linked list is a linear data structure where elements are stored in nodes, and each node points to the next node in the sequence. Linked lists come in various forms, and this repository includes implementations of singly linked lists (SLL) and doubly linked lists (DLL).

### Singly Linked List (SLL)

A singly linked list is a linked list in which each node points to the next node in the sequence. It is a simple and straightforward data structure that allows for efficient insertion and deletion of elements.

### Doubly Linked List (DLL)

A doubly linked list is a linked list in which each node points to both the next and the previous nodes in the sequence. This additional link makes it easier to traverse the list in both directions, but it comes with the cost of increased memory usage.

## Queue

A queue is a linear data structure that follows the First In, First Out (FIFO) principle. Elements are added to the rear (enqueue) and removed from the front (dequeue). This repository includes a simple implementation of a queue.

## Stack

A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. Elements are added and removed from the same end, typically referred to as the "top." This repository includes a basic implementation of a stack.

Feel free to explore the source code of each data structure for a better understanding of their implementation and usage. If you have any suggestions or improvements, please don't hesitate to contribute or open an issue. Happy coding!
