////////////////////////////////////////////////////////////////
// ʂmallest φositive ɪnteger, ʈhat ɔan ɳot ƀe Ѷepresented ɐs ʓum 
// Hard Accuracy  : 49.71  %  Submissions  :  28380 Points  :  8
//  ----____--____----____----__----____--__----________--__----
//  ________--____________----______----________--------________
//  Given   an    array   of  size  N,  find    the     smallest
//  ----------________--------______--------____------------____
//  positive  integer value   that  cannot  be  represented as
//  ----____------____________------____------------------------
//  sum of  some  elements    from  the array.
////////////////////////////////////////////////////////////////
// Example: 1
// Input: N = 6, array[] = {1, 10, 3, 11, 6, 15}
// Output: 2
// Explanation: ____----____----____----____----____----____----
//              %%%%::::****============,,,,,,,,````````,,,,,,,,
//              2   is  the smallest    integer value   that
//              >>>>>>>>,,,,````````````____----====************
//              cannot  be  represented as  sum of  elements
//              ,,,,,,,,````____________________________________
//              from    the array.
///////////////\Black\//////////////\Light\/////////////////////
//  Your Task:  
//  You dont nee     read input or pr     nything. Complete the
//  function sma     positive() which     s the array and N as
//  input parame     and returns the      est positive integer
//  value that c      be represented      m of some elements
//  from the arr   
////////////////     ////////////////     //////////////////////
// Expected Time     lexity: O(N * Lo     
// Expected Auxi      Space: O(1)
////////////////     ////////////////     //////////////////////
// Constraints:
// 1 ≤ N ≤ 10^6
// 1 ≤ array[i]      
// Array may con     duplicates.
// _____________=====________________=====______________________
// _____________refra________________ctors______________________
# include <vector>
# include <iostream>
# include <algorithm>
using namespace std; 
// Test Cases Passed: 167 / 167            
// Total Time Taken: 1.75 / 4.98           
////////////////////////////////////////////////////////////////
typedef long long __ong;
class Solution { // command center
public:
    __ong smallestpositive( vector<__ong> &a, int n ){ 
        if( n == 0 ) return 1;
        sort( a.begin(), a.end());
        if( a[0] != 1 ) return 1;
        int j = 1;
        for(; j < n; j++ ){
            if( a[j] - a[j - 1] > 1 ){
                break;
            }
            a[j] += a[j - 1];
        }
        return a[j - 1] + 1;
    } 
};
////////////////////////////////////////////////////////////////
//__,,``-->>%%  __,,::oo__==,,``>><<--<<,,..::""''``**,,))((__>>
int main()  { 
    int t;
    cin >>  t;
    while(  t-- ){
        int n;
        cin >>  n;
        vector<__ong> array(  n );
        for(  int i  =  0;  i < n;  ++i ){
            cin >>  array[  i ];
        }
        Solution  ob;
        cout  <<  ob.smallestpositive(  array,  n)  <<  "\n";
    }
}
////////////////////////////////////////////////////////////////
//  ----____--____----____----__----____--__----________--__----
//  ________--____________----______----________--------________
//  ----------________--------______--------____------------____
//  ----____------____________------____------------------------
//              ____----____----____----____----____----____----
//              %%%%::::****============,,,,,,,,````````,,,,,,,,
//              >>>>>>>>,,,,````````````____----====************
//              ,,,,,,,,````____________________________________
// _____________=====________________=====______________________
//__,,``-->>%%  __,,::oo__==,,``>><<--<<,,..::""''``**,,))((__>>
////////////////////////////////////////////////////////////////
