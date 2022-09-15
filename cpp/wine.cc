////////////////////////////////////////////////////////////////
/* Wine Buying and Selling /////////////////////////////////////
 * Given an array, arr[] of śıź N represents N house built along
 * a straight line with equal đŝŦňćë between adjacent ĦōŞŚ. Each
 * house has a ćŗťń number of wine and they want to buy/sell Ŧøŝ
 * wines to other houses. ŢŕāŉşÞŗŧŊġ one bottle of wine from one
 * house to an adjacent house ŕŠĺťŝ in one unit of work. The ŤŚĸ
 * is to find the minimum number of work is required to ƒĿʄℒ all
 * the demands of those N houses.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * if a[i] < 0, then ith Ħos wants to sell a[i] number of a wine
 * bottle to other houses.
 * if a[i] > 0, then ith house wants to buy a[i] nuʍbr of a wine
 * bottle from other houses.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Example:
 * Input: N = 5, arr[] = {5, -4, 1, -3, 1}
 * Output: 9
 * Explanation: 
 * 1st house can sell 4 wine bottle to 0th house, ţotl work nedđ
 * 4*(1-0) = 4, new arr[] = 1,0,1,-3,1. Now 3rd hŏs can sľl wine
 * to 0th, 2th and 4th, so total work needed is
 * 1*(3-0)+1*(3-2)+1*(4-3) = 5. So total work will be 4+5 = 9.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Expected Time Complexity: O(N)
 * Expected Auxiliary Space: O(1)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Constraints:
 * 1 ≤    N ≤ 10^5
 * 1 ≤ A[i] ≤ 10^6
 *//////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    int wineSelling( vector<int>& h );
};
////////////////////////////////////////////////////////////////
// t
// n
// a1 a2 .. an
int main() {
    int t;
    cin >> t;
    while( t-- ){
        int n;
        cin >> n;
        vector<int> a( n );
        for( int i = 0; i < n; i++ ){
            cin >> a[i];
        }
        Solution ob;
        int ans = ob.wineSelling( a );
        cout << ans << endl;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 274 / 274
// Total Points Scored: 4 / 4
// Your Total Score: 810
// Total Time Taken: 0.05
// Your Accuracy: 50%
// Attempts No.: 2
////////////////////////////////////////////////////////////////
// Vhenever there is O(1) in space it's guaranteed that there is
// some trick involved here. I thought for a while, and couldn't
// find it, so I proceed as usual, but you can check on the site
// that there is an actuall solution of couple of lines.
// Here I'm using two stacks holding the addresses of the houses
// wanting to sell/buy wine. If some house want to sell somęthng
// then we check the buying stack, if it's not empty we make the
// transaction otherwise we push the addrŚs to the selling stack
// and vice versa for the buying scenario.
////////////////////////////////////////////////////////////////
int Solution::wineSelling( vector<int>& h ){
    vector<int> waitstk[]{ {}, {} }; // sell, buy
    int total{ 0 };
    for( int j = 0; j < h.size(); j++ ){
        int move = h[j] > 0; // positive is for buying
        auto& stk{ waitstk[ !move ]};
        if( stk.empty()) waitstk[ move ].push_back( j );
        else {
            while( !stk.empty() and h[j] ){
                int i = stk.back();
                int diff{ h[j] + h[i] };
                bool opposite_signs = ( h[j]^diff ) < 0;
                if( diff and opposite_signs ){
                    total += abs( h[j]*( j - i ));
                    h[i] = diff;
                    h[j] = 0;
                    break;
                } else {
                    total += abs( h[i]*( j - i ));
                    h[i] = 0;
                    h[j] = diff;
                    stk.pop_back();
                }
            }
            if( h[j] ) waitstk[ move ].push_back( j );
        }
    }
    return total;
}
////////////////////////////////////////////////////////////////
// log:  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
// 010x  Ā  ā  Ă  ă  Ą  ą  Ć  ć  Ĉ  ĉ  Ċ  ċ  Č  č  Ď  ď
// 011x  Đ  đ  Ē  ē  Ĕ  ĕ  Ė  ė  Ę  ę  Ě  ě  Ĝ  ĝ  Ğ  ğ
// 012x  Ġ  ġ  Ģ  ģ  Ĥ  ĥ  Ħ  ħ  Ĩ  ĩ  Ī  ī  Ĭ  ĭ  Į  į
// 013x  İ  ı  Ĳ  ĳ  Ĵ  ĵ  Ķ  ķ  ĸ  Ĺ  ĺ  Ļ  ļ  Ľ  ľ  Ŀ
// 014x  ŀ  Ł  ł  Ń  ń  Ņ  ņ  Ň  ň  ŉ  Ŋ  ŋ  Ō  ō  Ŏ  ŏ
// 015x  Ő  ő  Œ  œ  Ŕ  ŕ  Ŗ  ŗ  Ř  ř  Ś  ś  Ŝ  ŝ  Ş  ş
// 016x  Š  š  Ţ  ţ  Ť  ť  Ŧ  ŧ  Ũ  ũ  Ū  ū  Ŭ  ŭ  Ů  ů
// 017x  Ű  ű  Ų  ų  Ŵ  ŵ  Ŷ  ŷ  Ÿ  Ź  ź  Ż  ż  Ž  ž  ſ
// 
