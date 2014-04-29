#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node {
    int data;
    int time;
    char* type;
    struct node* next;
}node_t;

typedef struct head {
    node_t* dog_queue;
    node_t* cat_queue;
}head_t;

node_t* new_node(int value, char* kind)
{
    node_t* tmp = (node_t*)malloc(sizeof(node_t));
    tmp->data = value;
    tmp->type = kind;
    tmp->time = 0;
    tmp->next = NULL;

    return tmp;
}

void enqueue(head_t* p_queue, node_t* animal)
{
    static node_t* dog_tail = NULL;
    static node_t* cat_tail = NULL;
    static int count = 0;

    if (strcmp(animal->type, "dog") == 0)
    {
        if (p_queue->dog_queue == NULL)
	{
	    animal->time = count++;
	    p_queue->dog_queue = animal;
	    dog_tail = animal;
	} else {
	    animal->time = count++;
	    dog_tail->next = animal;
	    dog_tail = dog_tail->next;
	}
    }
    else if (strcmp(animal->type, "cat") == 0) 
    {
        if (p_queue->cat_queue == NULL)
	{
	    animal->time = count++;
	    p_queue->cat_queue = animal;
	    cat_tail = animal;
	} else {
	    animal->time = count++;
	    cat_tail->next = animal;
	    cat_tail = cat_tail->next;
	}
    }
    else
    {
        printf("Unkown animal\n");
	assert(0);
    }
}

node_t* dequeue_dog(head_t* p_queue)
{
    node_t* ret = NULL;
    if (p_queue->dog_queue == NULL)
        return NULL;
    else
    {
        ret = p_queue->dog_queue;
        p_queue->dog_queue = (p_queue->dog_queue)->next;
	return ret;
    }
}

node_t* dequeue_cat(head_t* p_queue)
{
    node_t* ret = NULL;
    if (p_queue->cat_queue == NULL)
        return NULL;
    else
    {
        ret = p_queue->cat_queue;
        p_queue->cat_queue = (p_queue->cat_queue)->next;
	return ret;
    }
}

node_t* dequeue_any(head_t* p_queue)
{
    node_t* ret = NULL;

    if (p_queue->dog_queue == NULL && p_queue->cat_queue == NULL)
        return NULL;
    else if (p_queue->cat_queue == NULL)
	return dequeue_dog(p_queue);
    else if (p_queue->dog_queue == NULL)
	return dequeue_cat(p_queue);
    else
    {
        if ((p_queue->dog_queue)->time > (p_queue->cat_queue)->time)
	    return dequeue_cat(p_queue);
	else
	    return dequeue_dog(p_queue);
    }
}

void test()
{
    head_t queue;
    queue.dog_queue = NULL;
    queue.cat_queue = NULL;

    enqueue(&queue, new_node(3, "dog"));
    enqueue(&queue, new_node(5, "cat"));
    enqueue(&queue, new_node(23, "dog"));
    enqueue(&queue, new_node(35, "cat"));
    enqueue(&queue, new_node(77, "cat"));
    enqueue(&queue, new_node(45, "dog"));
    enqueue(&queue, new_node(5444, "dog"));
    enqueue(&queue, new_node(4, "cat"));
    
    node_t* ret = NULL;
    
    ret = dequeue_any(&queue);
    if (ret != NULL)
        printf("data %d, time %d, type %s\n", ret->data, ret->time, ret->type);
    
    ret = dequeue_any(&queue);
    if (ret != NULL)
        printf("data %d, time %d, type %s\n", ret->data, ret->time, ret->type);
    
    ret = dequeue_any(&queue);
    if (ret != NULL)
        printf("data %d, time %d, type %s\n", ret->data, ret->time, ret->type);
    
    ret = dequeue_any(&queue);
    if (ret != NULL)
        printf("data %d, time %d, type %s\n", ret->data, ret->time, ret->type);
    
    ret = dequeue_dog(&queue);
    if (ret != NULL)
        printf("data %d, time %d, type %s\n", ret->data, ret->time, ret->type);
    
    ret = dequeue_cat(&queue);
    if (ret != NULL)
        printf("data %d, time %d, type %s\n", ret->data, ret->time, ret->type);


}

int main()
{
    test();
}


