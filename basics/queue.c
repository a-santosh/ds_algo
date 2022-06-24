#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

typedef struct q_type q_type;
struct q_type{
  uint cap;
  int front;
  int rear;
  int size;
  int* arr;

}

q_type* create_q( int cap ){
  q_type* s = (q_type*) malloc( sizeof( q_type ) );
  s->cap = cap;
  s->front = -1;
  s->rear = -1;
  s->size = 0;
  s->arr = (int*)malloc( sizeof( int) * cap );
  for( int i=0; i<cap; i++ ){
    s->arr[i] = -1;
  }

  return s;
}


bool is_full( q_type* s ){
   return ( s->size == s->cap);
}

bool is_empty( q_type* s ){
   return ( s->front == -1);
}

void push ( q_type* s, int  num ){
  if( is_full(s )){ return;}
  if( is_empty(s)){ s->front = 0;}

  s->rear = (s->rear + 1)%(s->cap);
  s->arr[s->rear] = num;
  s->size = s->size+1;
}

int pop( q_type* s ){
  if( is_empty(s)){ return -1;}
  int num = s->arr[s->front];
  s->arr[s->front] = -1;
  s->front = (s->front + 1 )%(s->cap);
  s->size = (s->size)-1;
  return num;
}

int peek_front(q_type* s ){
  if( is_empty(s)){ return -1;}
  else{ return s->arr[s->front];}
}

int peek_rear(q_type* s ){
  if( is_empty(s)){ return -1;}
  else{ return s->arr[s->rear];}
}
