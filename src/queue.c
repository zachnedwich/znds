#include <stdio.h>
#include "queue.h"
#include <string.h>



void init(struct queue *q)
{
  int i;
  for(i = 0; i < LENGTH; i++)
  {
    struct item *blank = malloc(sizeof(struct item));
    if(blank == NULL)
    {
      fprintf (stderr, "Out of memory.\n");
    }
    q->items[i] = blank;
  }
  q->head = q->tail = malloc(sizeof(struct item));

}

void dequeue(struct queue *q)
{
  if(q->size == 0)
  {
    fprintf (stderr, "Queue is empty.\n");
  }
  else{
    q->size--;
    q->items[0] = q->items[1];
    q->head = q->items[0];
  }

}

void enqueue(struct item *toAdd, struct queue *q)
{
  if(q->size > LENGTH)
  {
    fprintf (stderr, "Queue is full.\n");
  }
  if(q->size == 0)
  {
    q->items[q->size]->value = toAdd->value;
    q->size++;
  }
  else
  {

    q->items[q->size]->value = toAdd->value;
    q->tail = q->items[q->size];
    q->size++;
  }
}

bool isFull(struct queue *q)
{
  if(q->size > LENGTH)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

bool isEmpty(struct queue *q)
{
  if(q->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void print(struct queue *q)
{
int j ;
if(q->size == 0)
  {
    fprintf (stderr, "Queue is empty.\n");
  }
  printf("----------\n");
  for(j = 0; j < q->size; j++)
  {

      printf("%s \n", (char*) q->items[j]->value);
  }
  printf("----------\n");
}