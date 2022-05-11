#include <bits/stdc++.h>
using namespace std;

class PathOptimization_DS {
  private:
    vector<int>root;
  public:
    //QuickFind_DS( int sz): root( sz ){
    PathOptimization_DS( int sz){
      for( int i=0; i<sz; i++ ){
        root.push_back( i );
      }
    }

    int findRoot( int x ){
      if( x == root[x]){
        return x;
      }

      return root[x] = findRoot( root[x]);
    }

    void unionSet( int x, int y ){
      int rootX = findRoot( x );
      int rootY = findRoot( y );
      //no need to update if already have same root
      if( rootX != rootY ){
        root[rootY] = rootX;
      }
    }

    bool isConnected( int x, int y ){
      return ( findRoot(x) == findRoot( y ));
    }

};


// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    PathOptimization_DS uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.isConnected(1, 5) << endl;  // true
    cout << uf.isConnected(5, 7) << endl;  // true
    cout << uf.isConnected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.isConnected(4, 9) << endl;  // true

    return 0;
}
