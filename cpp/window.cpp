/*##############################################################
# S  m  a  l  l  e  s  t d  i  s  t  i  n  c  t w  i  n  d  o  w
################################################################
# Given a string 's'. T h e task is t o find the smallest window
# length that contains all the characters of the given string at
# least one time. For e g. A = aabcbcdbca, then the result would
# b e 4 as o f the s  m  a  l  l  e  s  t window will be d b c a.
################################################################
# E x p e c t e d T   i   m   e C o m p l e x i t y: O(l e n(s))
# Expected A  u  x  i  l  i  a  r  y S    p    a    c    e: O(1)
##############################################################*/
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
//     ---      ---      ---      ---      ---      ---      ---
/*     *     *     *     ==     *     *     *     *     *     */
using namespace std;
/*   *   *   *   *   *   *   *   *   *   __   *   *   *   *   */
class Solution {
public:
    int findSubString( const string& str );
};
    //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
   //  //  //  //  //  //  //  //  //  //  //  //  //  //  //  
int main() {
    cout << Solution().findSubString( "aabcbcdbca" ) << endl;
}
////////////////////////////////////////////////////////////////
int Solution::findSubString( const string& str ){
    vector<int> ctr( 256, -1 );
    int n{};
    for( const int c: str ){
        if( ctr[ c ] == -1 ){
            ctr[ c ] = 0;
            ++n;
        }        
    }
    int i = 0;
    int j = -1;
    while( n ){
        int c{ str[ ++j ]};
        if( !ctr[ c ]){
            --n;
        }
        ++ctr[ c ];
    }
    n = str.size();
    int winSize{ n };
    while( true ){
        int c{ str[ i ]};
        if( ctr[ c ] > 1 ){
            ++i;
            --ctr[ c ];
        } else {
            winSize = min( winSize, j - i + 1 );
            if( ++j == n ){
                break;
            }
            c = str[ j ];
            ++ctr[ c ];
        }
    }
    return winSize;
}
////////////////////////////////////////////////////////////////
// Yea 5 times:), initially the code was written i n Python, but
// there is a test case with 1 million characters and I couldn't
// p a s s the tests, and optimization didn't help. T h e n I've
// m e s s e d it up vhen re-writing in C++, zo what to do, this
// things h  a  p  p  e  n from t   i   m   e to t   i   m   e:)
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  140 / 140
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1082
// Total Time Taken:                                        0.25
// Your Accuracy:                                            20%
// Attempts No.:                                               5
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
