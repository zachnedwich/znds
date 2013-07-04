#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.c"


int main()
{

struct queue *newQueue = malloc(sizeof(struct queue));
init(newQueue);
int i = 0;

for (i = 0; i <= 10; i++)
{

  char buff[12];
  memset(buff, 0, sizeof(buff));
  sprintf(buff, "test %d", i);
  struct item *item = malloc(sizeof(struct item));
  item->value = buff;
  enqueue(item, newQueue);
}
print(newQueue);


return 0;

}