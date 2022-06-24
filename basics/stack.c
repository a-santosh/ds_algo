#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

using namespace std;

typedef struct stack_type stack_type;
struct stack_type{
  uint cap;
  int top;
  int* arr;
}

stack_type* create_stack( int cap ){
  stack_type* s = (stack_type*) malloc( sizeof( stack_type ) );
  s->cap = cap;
  s->top = -1;
  s->arr = (int*)malloc( sizeof( int) * cap );
  for( int i=0; i<cap; i++ ){
    s->arr[i] = -1;
  }

  return s;
}


bool is_full( stack_type* s ){
   return ( s->top == ((s->cap)-1);
}

bool is_empty( stack_type* s ){
   return ( s->top == -1);
}

void push ( stack_type* s, int  num ){
  if( is_full(s )){ return;}
  s->top = s->top + 1;
  s->arr[s->top] = num;
}

int pop( stack_type* s ){
  if( is_empty(s)){ return -1;}
  int num = s->arr[s->top];
  s->arr[s->top] = -1;
  s->top = (s->top)-1;
}

int peek(stack_type* s ){
  if( is_empty(s)){ return -1;}
  else{ return s->arr[s->top];}
}
