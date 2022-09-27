#include "datastructures.h"

/* Test file */
void main()
{
    struct LinkedList* ll = LinkedListConstructor();

    for (int i = 0; i < 3; i++)
    {
        append(ll, i, i);
    }

    ConvertToDoublyLinkedList(ll);
    append(ll, 1, 3);
    append(ll, 1, 4);
    
    printList(ll);

    ConvertToSinglyLinkedList(ll);
    printList(ll);
    printf("%d\n", ll->tail->data);
    LinkedListDestructor(ll);

    
    struct Stack* s = StackConstructor();
    
    for (int i = 0; i < 10; i++)
    {
        push(s, i);
    }
    for (int i = 0; i < 5; i++)
    {
        pop(s);
    }
    setStackLimit(s, 5);
    printf("%d\nSize: %d\nMax size: %d\n", peek(s), s->size, s->max_size);
    struct Node* temp = s->top;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    StackDestructor(s);
    

   
    struct Queue* q = QueueConstructor();
    enQ(q, 1);
    enQ(q, 2);
    printf("%d\n", q->front->next->data);
    QueueDestructor(q);
    
}