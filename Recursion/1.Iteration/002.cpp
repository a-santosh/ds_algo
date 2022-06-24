/*
print all subsequences of a string
*/

#include <bits/stdc++.h>
using namespace std;


void printSubSeqRec( string str, int n, int idx = -1, string curr = ""){

  if( idx == n ){
    return;
  }

  if( !curr.empty()){
    cout << curr << endl;
  }

  for( int i=idx+1; i < n; i++ ){
    curr += str[i];
    cout << "temp: " << curr << endl;
    printSubSeqRec( str, n, i, curr ); //repeat
    curr = curr.erase( curr.size() - 1 ); //Backtracking
  }

  return;
}



void printSubSeq(string str)
{
    printSubSeqRec(str, str.size());
}


// Driver code
int main()
{
    string str = "abc";
    printSubSeq(str);
    return 0;
}
