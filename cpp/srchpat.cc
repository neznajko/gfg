////////////////////////////////////////////////////////////////
// Search Pattern (Rabin-Karp Algorithm)
////////////////////////////////////////////////////////////////
// Medium Accuracy: 43.63% Submissions: 5763 Points: 4
// ..... ... ........ ... .. . .... ...... ... .... .. . .......
// Given two strings, one is a text string and othr is a pattern
//      .   .        .      . .               .    .  . .
// string. The task is to print the ndexes of all the occurences
//                                 .                  
// of patrn string in the text string. For printng, Startng ndex
//                       .                                  
// of a string should be taken as 1.
//                                        .                     
//////////////////////////////////////////////////////////////// 
// Example    : 1                                               
// Input      : S = "batmanandrobinarebat", pat = "bat"
// Output     : 1 18                                            
// Explanation: The string "bat" occrs twice in S, one starts at
// index 1 and the other at index 18. 
////////////////////////////////////////////////////////////////
// Example    : 2                                               
// Input      : S = "abesdu", pat = "edu"
// Output     : -1
// Explanation: There's not substring "edu" present in S.
////////////////////////////////////////////////////////////////
// Your Task: You dont need to read input or print anythng. Your
// task is to complete the functn search() which takes the strng
// S and the string pat as inputs and retrns an aray denotng the
// start indices (1-based) of substring pat in the string S. 
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(|S|*|pat|).
// Expected Auxiliary Space: O(1).
////////////////////////////////////////////////////////////////
// Constraints:                                                 
// 1<=|S|<=10^5                                                 
// 1<=|pat|<|S|                                                              
////////////////////////////////////////////////////////////////
# include <vector>
# include <string>
# include <iostream>
using namespace std;                                            
////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> search( const string &pat, const string &txt );
};
////////////////////////////////////////////////////////////////
// I'm 299.99 % sure this isn't Rabin-Karp Algorithm, but I hope
// it's working.
vector<int> Solution::search( const string &pat,
                              const string &txt ){
    // The Actors:
    int i = 0; // i the txt iterator
    int j; // j the working horse( pat's iterator )
    const int m = txt.length(); // Victoria, King's wife
    const int n = pat.length(); // LEAR, king of Britain
    int b; // DUKE OF CORNWALL, her husband
    // Most of them first enter, and than exit immediately.
    vector<int> vec; // Knights in Lear’s train, Servants,
    // Officers, Soldiers, Attendants, Gentlemen, etc.
    for(;; i = b + 1 ){
        j = 0;
        for(; i < m and txt[ i ] != pat[ j ]; i++ )
            ;
        if( i == m ) break;
        b = i;
        do {
            if( ++j == n ){
                vec.push_back( b + 1 );
                break;
            }
            if( ++i == m ) goto lab;
            if( txt[ i ] != pat[ j ]) break;
        } while( true );
    }
  lab: if( vec.empty()) {
        vec.push_back( -1 );
    }
    return vec;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 160 / 160 ////////////////////////////////
// Total Time Taken: 0.04 / 3.4 ////////////////////////////////
////////////////////////////////////////////////////////////////
int main()                                                 {
    int t                                                  ;
    cin >> t                                               ;
    while( t-- )                                           {
        string S, pat                                      ;
        cin >> S >> pat                                    ;
        Solution ob                                        ;
        vector<int> res = ob.search( pat, S )              ;
        for( int i: res ) cout << i << " "                 ;
        cout << endl                                       ;
                                                           }
                                                           }
////////////////////////////////////////////////////////////////
