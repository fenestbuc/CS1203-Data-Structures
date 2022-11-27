// Skip lists
// Basic Skip List with 2 pointers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 6

struct Node {
  int key;
  struct Node *forward[MAX_LEVEL];
};

struct SkipList {
  struct Node *header;
  int level;
};

struct SkipList *createSkipList() {
  struct SkipList *sl = malloc(sizeof(struct SkipList));
  sl->header = malloc(sizeof(struct Node));
  sl->level = 0;

  for (int i = 0; i < MAX_LEVEL; i++) {
    sl->header->forward[i] = NULL;
  }

  return sl;
}

int main() {
  srand(time(NULL));

  struct SkipList *sl = createSkipList();
  printf("Skip list created with level: %d\n", sl->level);

  return 0;
}
