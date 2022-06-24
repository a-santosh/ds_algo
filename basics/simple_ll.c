#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node node;
struct node{
  int val;
  node* next;
}

node* newNode( int a ){
  node* newN = (node*)malloc( sizeof(node));
  newN->val = a;
  return newN;
}

void print_ll( node* head ){
  if( head == NULL ){ return; }
  printf( "%d", head->val);
  print_ll( head->next );
}

void print_ll_rev( node* head ){
  if( head == NULL ){ return; }
  print_ll_rev( head->next );
  printf( "%d", head->val);
}

//0 - front, 1 - back
node* insert_node( node* head, int val, int pos ){
  node* new_n = newNode( val );
  if( pos == 0 ){
    new_n->next = head;
    head = new_n;

  } else {
    while( head->next != NULL ){
      head = head->next;
    }

    head->next = new_n;
  }

  return head;
}
