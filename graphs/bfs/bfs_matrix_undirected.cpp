#include <iostream>
#include <queue>
using namespace std;

/*
 BFS for graph is same as BFS for tree except
 we need to avoid traversing the same nodes again and again.
 Graphs can have cycles, to avoid it we use another array to track
 which nodes are already visited.

1. Start from a node, put it in a queue
2. While( q is not empty ) -> get the node, mark as visited
3. get the adjacent nodes that are connected put them in queue, mark as visited
4. When the queue is empty return

** If this is a connected graph, all nodes will be visited.
** otherwise, based on the starting node we may not visit all the nodes.
*/


#define num_nodes 7
void bfs( int g[][7], int start ){
  bool visited[7];
  for( int i=0; i<7; i++){
    visited[i] = false;
  }

  queue<int>q;
  q.push( start );
  visited[start] = true;

  while( !q.empty()){
    int node = q.front();
    cout << node << " ";
    q.pop();

    for( int i=0; i<7; i++ ){
      if( g[node][i] == 1 && visited[i] == false ){
        q.push( i );
        visited[i] = true;
      }
    }
  }
}

int main (){

    int A[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    cout << "\nVertex: 1 -> " << flush;
    bfs(A, 1);

    cout << "\nVertex: 4 -> " << flush;
    bfs(A, 4);


    return 0;
}
