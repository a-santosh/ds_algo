/*
check if a string is palindrome
*/

#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(string str, int start, int end )
{
    int len = str.length();

    if( end >= start ) { return true; }

    if( str[start] != str[end]){ return false; }
    else { return ( isPalindrome( str, start+1, end-1) ); }
}


// Driver code
int main()
{
    string str = "abcba";
    cout<<boolalpha<<isPalindrome(str, 0, 4);
    return 0;
}
