// File:	my_pthread.c
// Author:	Yujie REN
// Date:	09/23/2017

// name:
// username of iLab:
// iLab Server:

#include "my_pthread_t.h"

void queue_init(queue *q)
{
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
}

int enqueue(queue *q, my_pthread_t *thread)
{
	node *temp = (node*) malloc(sizeof(node))
	if (temp == NULL)
	{
		return 0;
	}
	temp->data = thread;
	temp->next = NULL;

	if(q->rear)
	{
		q->rear->next = temp;
		q->rear = temp;
	}
	else
	{
		q->rear = temp;
		q->front = temp;
	}
	q->count++;

	return 1;
}

my_pthread_t* dequeue(queue *q)
{
	if (q->fornt == NULL)
		return 0;
	node* temp = (node*) malloc(sizeof(node));
	temp = q->front;
	q->front = q->front->next;
	my_pthread_t *thread = temp->data;
	free(temp);
	q->count--;
	return thread;

}

int get_queue_size(queue *q)
{
	return q->count;
}

/* create a new thread */
int my_pthread_create(my_pthread_t * thread, pthread_attr_t * attr, void *(*function)(void*), void * arg) {
	return 0;
};

/* give CPU pocession to other user level threads voluntarily */
int my_pthread_yield() {
	return 0;
};

/* terminate a thread */
void my_pthread_exit(void *value_ptr) {
};

/* wait for thread termination */
int my_pthread_join(my_pthread_t thread, void **value_ptr) {
	return 0;
};

/* initial the mutex lock */
int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr) {
	mutex->lock = 0;
	return 0;
};

/* aquire the mutex lock */
int my_pthread_mutex_lock(my_pthread_mutex_t *mutex) {
	while(mutex->lock !=0)
	{
		my_pthread_yield();
	}

	mutex->lock = 1;
	return 0;
};

/* release the mutex lock */
int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex) {
	mutex->lock = 0;
	return 0;
};

/* destroy the mutex */
int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex) {
	mutex = NULL;
	return 0;
};

