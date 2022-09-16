#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H 

struct LinkedList
{
    struct Node* head;
    struct Node* tail;
    int length;
    int isDoublyLinked;
};

struct LinkedList* LinkedListConstructor();
void LinkedListDestructor(struct LinkedList* linked_list);
void append(struct LinkedList* linked_list, int index, int data);
void delete(struct LinkedList* linked_list, int index);
void ConvertToDoublyLinkedList(struct LinkedList* linked_list);
void ConvertToSinglyLinkedList(struct LinkedList* linked_list);
void printList(struct LinkedList* linked_list);

#endif