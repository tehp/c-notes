#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct record record;
struct record {
    char name[32];
    int score;
};

typedef struct node node;
struct node {
  record data;
  node *next;
};

void print (node *lst) {
  node *p;

  for (p = lst; p!=0; p = p->next) {
    printf("%s %d\n", p->data.name, p->data.score);
  }
}

node *find(node *lst, const char *name) {
  node *p;

  for (p=lst; p!=0; p=p->next) {
    if (strcmp(p->data.name, name) == 0) {
      return p;
    }
  }
  return 0;
}

void destroy(node *lst) {
  node *p;
  node *q;

  for (p=lst; p!=0; p=q) {
    q = p->next;
    free(p);
  }
}

int insert(node **plst, const char *name, int score) {
  node *newnode = malloc(sizeof(node));
  if (newnode == 0) {
    return 0;
  }
  strcpy(newnode->data.name, name);
  newnode->data.score = score;

  newnode->next = *plst;
  *plst = newnode;
  return 1;
}

size_t delete_all(node **plst, const char *name) {
  node **tracer;
  size_t count = 0;

  for (tracer=plst; *tracer!=0; ) {
    if (strcmp((*tracer)->data.name, name) == 0) {
      node *tmp = *tracer;
      *tracer = tmp->next;
      free(tmp);
      count++;
    } else {
      tracer=&(*tracer)->next;
    }
  }
  return count;
}

int main(void) {
  node *head = 0;
  const char *names[] = {"homer", "bart", "lisa", "ned", "marge", "waylan", "monty"};
  int a[] = {3,2,7,2,3,1};
  size_t i;
  for (i=0; i<sizeof(a)/sizeof(a[0]); i++) {
    if (!insert(&head, names[i], a[i])) {
      return 1;
    }
  }
  print(head);
  delete_all(&head, "monty");
  puts("********");
  print(head);
  return 0;
}
