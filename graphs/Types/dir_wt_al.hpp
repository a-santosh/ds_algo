#include<bits/stdc++.h>

using namespace std;

class g_dir_wt_al{
public:
    int nodes_cnt;
    map<int, vector<pair<int,int>>> m;
    /* instead of map, this can be a list, nested vector or unordered_map etc. */

    g_dir_wt_al(int);
    void print_graph();
    void add_edge( int u, int v, int wt );
    void bfs( int start );
    void dfs( int start );
    void dfs_rec( int start );
    bool is_cycle();
    void get_short_path( int start );
};

g_dir_wt_al::g_dir_wt_al( int count ){
  this->nodes_cnt = count;
}

void g_dir_wt_al::add_edge( int u, int v, int wt ){
  auto it = this->m.find( u );
  if( it == this->m.end()){
    vector<pair<int,int>>vec;
    vec.push_back( make_pair( v, wt ));
    m.insert( make_pair( u, vec));
  } else {
    it->second.push_back( make_pair(v, wt));
  }
}

void g_dir_wt_al::print_graph(){
  for( auto it = this->m.begin(); it != this->m.end(); it++ ){
    cout << "\n" << it->first << ":";
    for( int i=0; i < it->second.size(); i++ ){
      cout << "( " << it->second[i].first << ", " << it->second[i].second << " ), ";
    }
    cout << endl;
  }
}

/*
1. Take a queue to maintain the FIFO order of nodes to visit
2. keep visiting the nodes from the connected nodes.
  ** it may be possible that all vertices may not be reached from a starting nodes in a disconnected graph
3. Mark the visited nodes to not visit/traverse them again.
*/
void g_dir_wt_al::bfs( int start ){
  cout << "\n**** BFS **** " << endl;
  static vector<bool>visited( this->nodes_cnt, false );
  queue<int>q;

  q.push( start );
  visited[start] = true;

  while( !q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " --> ";
    auto it = this->m.find( node );
    if( it == this->m.end()){ return;}
    int sz = it->second.size();
    for( int i=0; i<sz;i++){
      if( visited[it->second[i].first] == false){
        q.push( it->second[i].first );
        visited[it->second[i].first] = true;
      }
    }
  }

  cout << endl;

  /* For any disconnected vertices check
  visited[] and repeat bfs starting with
  that node.

  visited[] shall be static inorder to do this */
  for( int i=0; i<this->nodes_cnt; i++ ){
    if( visited[i] == false ){
      bfs( i );
    }
  }
}


/* Similar to DFS but in LIFO order
1. maintain  a stack to track the traversal order
2. visited[] to traverse only once
3. Mark as visited when processed instead of when added to stack
4. Similar to BFS, DFS may also not reach disconnected nodes
*/
void g_dir_wt_al::dfs( int start ){
  cout << "\n**** DFS **** " << endl;
  static vector<bool>visited( this->nodes_cnt, false );
  stack<int>st;

  st.push( start );

  while( !st.empty()){
    int node = st.top();
    st.pop();
    cout << node << " --> ";
    visited[node] = true;
    auto it = this->m.find( node );
    if( it == this->m.end()){ return;}
    int sz = it->second.size();
    for( int i=0; i<sz;i++){
      if( visited[it->second[i].first] == false){
        st.push( it->second[i].first );
      }
    }
  }

  cout << endl;

  /* For any disconnected vertices check
  visited[] and repeat bfs starting with
  that node.

  visited[] shall be static inorder to do this */
  for( int i=0; i<this->nodes_cnt; i++ ){
    if( visited[i] == false ){
      dfs( i );
    }
  }
}

/* Instead of stack we shall be able to user recusion*/
void g_dir_wt_al::dfs_rec( int start ){
  //cout << "\n**** DFS RECURSION **** " << endl;
  static vector<bool>visited( this->nodes_cnt, false );
  if( visited[start] == false ){
    cout << start << " --> ";
    visited[start] = true;
    auto it = this->m.find( start );
    if( it == this->m.end()){ return;}
    int sz = it->second.size();
    for( int i=0; i<sz;i++){
      if( visited[it->second[i].first] == false){
        dfs_rec( it->second[i].first );
      }
    }
  }

  /*visited[] shall be static inorder to do this */
  for( int i=0; i<this->nodes_cnt; i++ ){
    if( visited[i] == false ){
      cout << "Continuing from node " << "i" << " for disconnected graph." << endl;
      dfs_rec( i );
    }
  }
  cout << endl;
}



bool cycle_utl( int u, set<int>&white, set<int>&grey, set<int>&black, map<int, vector<pair<int,int>>> &m ){
  white.erase( u );
  grey.insert( u );

  auto it = m.find( u );
  int sz = it->second.size();
  for( int i=0; i<sz; i++ ){
    if( white.find( it->second[i].first ) != white.end()){
      cycle_utl( it->second[i].first, white, grey, black, m  );
    }

    if( grey.find( it->second[i].first ) != grey.end()){
      cout << "Cycle detected from " << u << " to " << i << endl;
      return true;
    }
  }

  black.insert( u );
  grey.erase( u );
  return false;

}

/* Detect cycle - White, black & grey sets
White-> all nodes stored,
pick a node, put it in grey set & dfs traversal for all adjacent nodes_cnt
when all adjacent nodes are traversed, move it to black set
While traversal if any node in grey set is revisited, cycle is present
*/
bool g_dir_wt_al::is_cycle(){
  static set<int>white;
  static set<int>grey;
  static set<int>black;

  for( auto it = this->m.begin(); it != this->m.end(); it++ ){
    white.insert( it->first );
  }

  int start = (this->m.begin())->first;
  return cycle_utl( start, white, grey, black, this->m );

}

/*
priroty queue - always pop the shortest path and among adjacent nodes and
keep updating the distances
*/
void g_dir_wt_al::get_short_path( int start ){

  priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

  vector<int> dist(this->nodes_cnt, INT_MAX );
  dist[start] = 0;

  pq.push( make_pair(0, start ));

  while( !pq.empty()){
    int node = pq.top().second;
    pq.pop();

    auto it = this->m.find( node );
    int sz = it->second.size();
    for( int i=0; i<sz; i++ ){
      int v = it->second[i].first;
      int wt = it->second[i].second;

      if( dist[v] > dist[node] + wt ){
        dist[v] = dist[node] + wt;
        pq.push( make_pair( dist[v], v));
      }
    }

  }

  for( int i = 0; i < this->nodes_cnt; i++ ){
    cout << start << " -> " << i << " : "  << dist[i] << endl;
  }
}
