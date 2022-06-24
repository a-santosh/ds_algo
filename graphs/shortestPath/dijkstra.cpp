#include <iostream>
#include <limits.h>

using namespace std;

#define v 9
/*
Dijkstra - Single source shortest path algorithm for weighted Graphs
Find shortest path from given node to all num_nodes

** Relaxation - updating the distances after finding a closer node

Design: two sets -> one with all nodes ; one for shortest path;
update the shortest path set using algotithm
dist[] -> to track distances

1. Initially sptSet is empty
2. Assign values to the graph;
    - distance value for source - 0
    - Connected to start -> valid
    - Others - set to Infinite.
3. While (sptSet.size != num_nodes)
  - pick vertex u not present in sptSet and has min distance
  - include u in sptSet
  - Apply Relaxation
*/

int minDistanceNode( int dist[], bool sptSet[]){
    int min = INT_MAX;
    int min_idx = -1;
    for( int i=0; i<v; i++){
      if( sptSet[i] == false && dist[i] <= min ){
        min = dist[i];
        min_idx = i;
      }
    }

    return min_idx;
}

void print_soln( int dist[] ){
  cout << "Vertex \t Distance from source" << endl;
  for( int i=0; i<v; i++){
    cout << i << "\t\t" << dist[i] << endl;
  }
}

void dijkstra ( int g[v][v], int src ){
  int dist[v];
  for( int i=0; i<v; i++ ){ dist[i] = 1000; }
  dist[src] = 0;

  bool sptSet[v];
  for( int i=0; i<v; i++ ){ sptSet[i] = false; }


  for( int i = 0; i < v-1; i++ ){
    int min_node = minDistanceNode( dist, sptSet );
    sptSet[min_node] = true;
    for( int j=0; j<v; j++){
      if( ( sptSet[j] == false )
        && ( g[min_node][j] != 0 )
        && ( dist[min_node] != 1000 ) // is this required?
        && ( (dist[min_node] + g[min_node][j]) < dist[j] ) ) // Relaxation check
        {
          dist[j] = dist[min_node] + g[min_node][j];
        }
    }
  }

  print_soln( dist );
}

// driver program to test above function
int main()
{

    /* Let us create the example graph discussed above */
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}
