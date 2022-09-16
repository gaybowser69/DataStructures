#include "linkedlist.h"
#include <stdio.h>

struct LinkedList* LinkedListConstructor()
{
    struct LinkedList* linked_list = malloc(sizeof(struct LinkedList));

    if (linked_list == NULL)
    {
        free(linked_list);
        return NULL;
    }

    linked_list->head = linked_list->tail = NULL;

    linked_list->length = 0;
    linked_list->isDoublyLinked = 0;

    return linked_list;
}

void LinkedListDestructor(struct LinkedList* linked_list)
{
    if (linked_list == NULL)
    {
        return;
    }

    struct Node* temp;
    while (linked_list->head != NULL) /* Copying head to temp. Then after moving head to tne next node, temp is freed. */
    {
        temp = linked_list->head;
        linked_list->head = linked_list->head->next;
        NodeDestructor(temp);
    }

    linked_list->length = 0;
    linked_list->isDoublyLinked = 0;

    linked_list->head = linked_list->tail = NULL;
}

void append(struct LinkedList* linked_list, int index, int data)
{
    assert(linked_list != NULL && index >= 0 && index <= linked_list->length); 
    /* 
    The length of the linked list is incremented at the end of the function. Hence a new element that can be added at the end of
       the list will have the current length of the list for highest index value.  
    */

    struct Node* node = NodeConstructor(data); 

    if (index == 0)
    {   
        node->next = linked_list->head;
        linked_list->head = node;

        if (linked_list->isDoublyLinked == 1)
        {
            linked_list->head->previous = node;
            linked_list->head = node;
        }

        if (linked_list->length == 0)
        {
            linked_list->tail = node;
        }

        linked_list->length++;
        return;
    }

    struct Node* temp = linked_list->head;
    
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    node->next = temp->next;

    if (index == linked_list->length) 
    /* Length is incremented at the end. Since length value has not changed yet, the new node will have same index as length. */
    {   
        if (linked_list->isDoublyLinked == 1)
        {
            node->previous = linked_list->tail;
            linked_list->tail->next = node;
        }

        linked_list->tail = node; 
    }

    else if (linked_list->isDoublyLinked == 1)
    {
        temp->next->previous = node;
        node->previous = temp;
    }

    temp->next = node;

    linked_list->length++;

    /* 
    Do not attempt to save memory by freeing node. The memory allocated must not be freed unless the node is to be deleted
       since otherwise, a missing node will be present in the linked list and operations on that will be unpredicatble.
       This means the data is no longer valid and the pointers stored in the node can no longer be used, if node is freed.
    */
}

void delete(struct LinkedList* linked_list, int index)
{
    struct Node* temp = linked_list->head;

    if (index == 0)
    {
        linked_list->head = temp->next;
        NodeDestructor(temp);

        linked_list->length--;
        return;
    }

    struct Node* temp2 = linked_list->head;

    for (int i = 0; i < index - 1; i++)
    {
        temp2 = temp2->next;
    }

    if (index == linked_list->length - 1) /* If last element is removed, move tail backwards by one element. */
    {
        linked_list->tail = temp2;
    }

    temp = temp2->next;
    temp2->next = temp->next;

    linked_list->length--;
    NodeDestructor(temp);
    /* Do not free temp2. Freeing is only done for manually allocated memory. */
}   

void ConvertToDoublyLinkedList(struct LinkedList* linked_list)
{
    if (linked_list->isDoublyLinked == 1)
    {
        return;
    }

    struct Node* node = linked_list->head;

    for (int i = 0; i < linked_list->length - 1; i++)
    {
        node->next->previous = node;
        node = node->next;
    }

    linked_list->isDoublyLinked = 1;
}

void printList(struct LinkedList* linked_list)
{
    struct Node* temp = linked_list->head;

    for (int i = 0; i < linked_list->length; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    if (linked_list->isDoublyLinked == 1)
    {
        temp = linked_list->tail;
        for (int i = 0; i < linked_list->length ; i++)
        {
            printf("%d ", temp->data);
            temp = temp->previous;
        }
        printf("\n");
    }    
}


int LinearSearchOnLinkedList(struct LinkedList* linked_list , int search_element){
    struct Node* temp = linked_list->head;
    for(int i=0;i<linked_list->length;i++){
        if(temp->data == search_element){
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

void ReverseLinkedList(struct LinkedList* linked_list){
    struct Node *current_node = linked_list->head;
    struct Node *last_node =NULL;
    struct Node *next1 = current_node;
    struct Node *another_head = linked_list->head;

    while (current_node != linked_list->tail)
    {
        next1 = current_node->next;
        current_node->next=last_node;
        last_node= current_node ;
        current_node = next1;
        
    }

    current_node->next = last_node;
    last_node = current_node;

    linked_list->head = last_node;
    linked_list->tail = another_head;
}


void main()
{
    struct LinkedList* ll = LinkedListConstructor();

    for (int i = 12; i < 15; i++)
    {
        append(ll, ll->length, i);
    }

    //ConvertToDoublyLinkedList(ll);
    //append(ll, 1, 3);
    //append(ll, 1, 4);
    printList(ll);
    printf("*%d*\n ",LinearSearchOnLinkedList(ll,4));
    ReverseLinkedList(ll);
    printList(ll);
    printf("%d\n", ll->tail->data);
    LinkedListDestructor(ll);
}