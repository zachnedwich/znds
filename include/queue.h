#ifndef ZN_QUEUE_H
#define ZN_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LENGTH 10

struct item
{
  void* value;
};

struct queue
{
  struct item *items[LENGTH];
  struct item* head;
  struct item* tail;
  int size;
};

void init(struct queue *q);
void enqueue(struct item *toAdd, struct queue *q);
void dequeue(struct queue *q);
void print(struct queue *q);
bool isFull(struct queue *q);
bool isEmpty(struct queue *q);

#endif
