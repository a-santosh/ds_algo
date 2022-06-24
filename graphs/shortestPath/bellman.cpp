#include <bits/stdc++.h>

using namespace std;


void BellmanFord( int graph[][3], int nodes, int edges, int src ){

  int dist[nodes];
  for( int i=0; i<nodes; i++ ){
    dist[i] = INT_MAX;
  }

  dist[src] = 0;

  //relax n-1 times
  for( int i=1; i<nodes; i++ ){
    for( int j=0; j<edges; j++ ){
      if( ( dist[graph[j][0]] != INT_MAX ) &&
          ( dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]] ) ){
             dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
          }
    }
  }

  // is it negative weight cycle?
  for( int j=0; j<edges; j++ ){
    if( ( dist[graph[j][0]] != INT_MAX ) &&
        ( dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]] ) ){
           cout << "Graph contains negative weighted cycle - cannot calculate." << endl;
        }
  }

  cout << "Solution: " << endl;
  for( int i=0; i<nodes; i++ ){
    cout << i << "-> " << dist[i] << endl;
  }

}

// driver program to test above function
int main()
{

    /* Let us create the example graph discussed above */
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                           { 1, 2, 3 }, { 1, 3, 2 },
                           { 1, 4, 2 }, { 3, 2, 5 },
                           { 3, 1, 1 }, { 4, 3, -3 } };
    int edges = sizeof( graph )/sizeof( graph[0]);
    cout << "Edges are " << edges << endl;
    int nodes = 5; // 0 through 4
    int src = 0;
    BellmanFord(graph, nodes, edges, src );

    return 0;
}
