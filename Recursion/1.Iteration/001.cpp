/*
s_stack implementation
Fixed size
Push
top
pop
is_full;


Insert an item at the bottom of a s_stack ??
Remove the first item?
*/

#include <bits/stdc++.h>
using namespace std;

class s_stack{
  private:
    int sz;
    int top_idx;
    int* data;
  public:
    s_stack( int );
    bool push( int );
    int top();
    bool pop();
    bool isFull();
    bool isEmpty();
    void print();

    bool insertBottom( int );
    bool removeFirst();
};

s_stack::s_stack( int sz ){
    this->sz = sz;
    this->data = new int(sz);
    memset( &(this->data), sizeof( this->data), 0 );
    this->top_idx = -1;
}

bool s_stack::push( int x ){
  if( this->isFull() ){
    return false;
  } else{
    top_idx = top_idx+1;
    this->data[top_idx] = x;
    return true;
  }
}

int s_stack::top(){
  return this->data[this->top_idx];
}

bool s_stack::pop(){
  if( this->isEmpty()){
    return false;
  } else {
    this->data[top_idx] = 0;
    top_idx--;
    return true;
  }
}

bool s_stack::isFull(){
  return (this->top_idx == (this->sz - 1));
}

bool s_stack::isEmpty(){
  return (this->top_idx == (-1));
}

void s_stack::print(){
  while(this->isEmpty() == false){
    cout << this->top() << " ";
    this->pop();
  }
}

bool s_stack::insertBottom( int x ){
  if( this->isFull()){
    return false;
  } else {
    if( this->isEmpty()){
      this->push( x );
      return true;
    } else {
      int peek = this->top();
      this->pop();
      insertBottom( x );
      this->push( peek );
    }
  }

  return true;
}

// Driver program to test above functions
int main()
{
    class s_stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.insertBottom( 5 );
    s.print();


    return 0;
}
