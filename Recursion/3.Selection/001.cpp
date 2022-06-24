/* print all combinations of array */

#include<bits/stdc++.h>
using namespace std;


void printUtl( int arr[], int data[], int included[], int start, int end, int idx,  int r){
  if( idx == r ){
    for( int i=0; i<r; i++ ){
      cout << data[i] << " ";
    }
    cout << endl;
    return;
  }

  for( int i=0; (i<= end); i++ ){
    if( included[i] == 0 )  {
        data[idx] = arr[i];
        included[i] = 1;
        printUtl( arr, data, included, i+1, end, idx+1, r  );
        included[i] = 0;
    }

  }
}


void printCombination( int arr[], int n, int r ){
  int data[r];
  int included[n];
  for( int i=0; i<n;i++){
      included[i] = 0;
  }
  printUtl( arr, data, included, 0, n-1, 0, r );
}






int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
}
