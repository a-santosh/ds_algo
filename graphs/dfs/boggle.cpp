#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

int row[] = { -1, -1, -1,
              0,       0,
              1,   1,  1 };

int col[] = { -1, 0, 1,
              -1,    1,
              -1, 0, 1 };

bool isValidFurther( int x, int y, auto &processed ){
  return( (x >= 0 && x < processed.size()) && (y >= 0 && y < processed[0].size()) && !processed[x][y]);
}


void searchBoggle( auto const &board, auto const & words, auto &result, auto &processed, int i, int j, string path){
  processed[i][j] = true;

  path += board[i][j];

  if( words.find(path) != words.end()){
    result.insert( path );
  }

  for( int k=0; k<8; k++){
    if( isValidFurther( i+row[k], j+col[k], processed)){
      searchBoggle( board, words, result, processed, i+row[k], j+col[k], path);
    }
  }

  processed[i][j] = false;
}


unordered_set<string> searchBoggle( auto const & board, auto const &words){
  unordered_set<string> result;
  if( board.size() == 0){ return result;}
  int M = board.size();
  int N = board[0].size();

  vector<vector<bool>>processed( M, vector<bool>(N));
  for( int i=0; i<M;i++){
    for( int j=0; j<N; j++){
      searchBoggle( board, words, result, processed, i, j, "");
    }
  }

  return result;
}

template<typename T>
void printSet( unordered_set<T> const &input ){
  cout << "{";
  int n = input.size();
  for( auto const &i: input){
    cout << i;
    if( --n){
      cout << ", ";
    }
  }
  cout << "}";
}


int main(){
  vector<vector<char>> board = {
                    {'M', 'S', 'E', 'F'},
                    {'R', 'A', 'T', 'D'},
                    {'L', 'O', 'N', 'E'}
                };

    unordered_set<string> words = { "START", "NOTE", "SAND", "STONED" };

    unordered_set<string> output = searchBoggle(board, words);
    printSet(output);

    return 0;
}
