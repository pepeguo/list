
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#define test(fn) \
  puts("... test " # fn "()"); \
  test_##fn();

void
test_ListNode_new() {
  char *val = "some value";
  ListNode *node = ListNode_new(val);
  assert(node->val == val);
}

void
test_List_push() {
  // Setup
  List *list = List_new();
  ListNode *a = ListNode_new("a");
  ListNode *b = ListNode_new("b");
  ListNode *c = ListNode_new("c");

  // a b c 
  List_push(list, a);
  List_push(list, b);
  List_push(list, c);

  // Assertions
  assert(list->head == a);
  assert(list->tail == c);
  assert(list->len == 3);
  assert(a->next == b);
  assert(a->prev == NULL);
  assert(b->next == c);
  assert(b->prev == a);
  assert(c->next == NULL);
  assert(c->prev == b);
}

void
test_List_unshift() {
  // Setup
  List *list = List_new();
  ListNode *a = ListNode_new("a");
  ListNode *b = ListNode_new("b");
  ListNode *c = ListNode_new("c");

  // c b a 
  List_push(list, a);
  List_unshift(list, b);
  List_unshift(list, c);

  // Assertions
  assert(list->head == c);
  assert(list->tail == a);
  assert(list->len == 3);
  assert(a->next == NULL);
  assert(a->prev == b);
  assert(b->next == a);
  assert(b->prev == c);
  assert(c->next == b);
  assert(c->prev == NULL);
}

void
test_List_destroy() {
  
}

int
main(int argc, const char **argv){
  putchar('\n');
  test(ListNode_new);
  test(List_push);
  test(List_unshift);
  test(List_destroy);
  puts("... done\n");
  return 0;
}