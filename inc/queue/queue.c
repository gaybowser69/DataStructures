#include "queue.h"

//Data added at the tail and removed from the head.

struct Queue* QueueConstructor()
{
    struct Queue* queue = malloc(sizeof(struct Queue));

    if (queue == NULL)
    {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;

    queue->size = 0;

    return queue;
}

void QueueDestructor(struct Queue* queue)
{
    if (queue == NULL)
    {
        return;
    }

    struct Node* temp = queue->front;

    while (temp->next != NULL)
    {
        temp = queue->front;
        queue->front = temp->next;
        NodeDestructor(temp);
    }

    queue->size = 0;

    free(queue);
    queue = NULL;
}

void enQ(struct Queue* queue, int data)
{
    assert(queue != NULL);

    struct Node* temp = NodeConstructor(data);

    //If queue is empty, the only node that is added will be front and rear nodes.
    if (queue->rear == NULL)
    {
        queue->front = temp;
        queue->rear = temp;
        return;
    }

    //Add new node to temp and change temp to that node.
    queue->rear->next = temp;
    queue->rear = temp;
    //NodeDestructor(temp);
    queue->size++;
}

void deQ(struct Queue* queue)
{
    assert(queue != NULL);

    //Check if queue is empty.
    if (queue->front == NULL)
    {
        return;
    }

    struct Node* temp = queue->front; //Return data from temp if needed by using another int.
    queue->front = queue->front->next;

    //If queue is empty, set rear pointer to NULL.
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    NodeDestructor(temp);
    queue->size--;
}

/*void main()
{
    struct Queue* q = QueueConstructor();
    enQ(q, 1);
    enQ(q, 2);
    printf("%d\n", q->front->next->data);
    QueueDestructor(q);
}*/
