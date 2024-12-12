////////////////////////////////////////////////////////////////
// Minimum sum partition
////////////////////////////////////////////////////////////////
// Given an array arr[] containing non-negative integers, the
// task is to divide it into two sets set1 and set2 such that
// the absolute difference between their sums is minimum and
// find the minimum difference
////////////////////////////////////////////////////////////////
// Input: arr[] = [1, 6, 11, 5]
// Output: 1
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.  
// Input: arr[] = [1, 4]
// Output: 3
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4
// Hence, minimum difference is 3.
// Input: arr[] = [1]
// Output: 1
// Explanation:   
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {}, sum of Subset2 = 0
// Hence, minimum difference is 1.
////////////////////////////////////////////////////////////////
// 1 ≤ arr.size()*|sum of array elements| ≤ 10^5
// 1 <= arr[i] <= 10^5
////////////////////////////////////////////////////////////////
// 2.1.5. What force acts in the cross-section of a uniform bar
// of length l at a distance x from the end to which a force F
// is applied along the bar?
////////////////////////////////////////////////////////////////
//                 <      x      >
// +---------------+-------------+
// |               |             |----> F
// +---------------+-------------+
// <             l               >
// m = ρl - mass of the bar
// F = ma, a = F/ρl
// M = ρ( l - x ) - mass of the bar before the cross-section
// f = Ma = ρ( l - x )F/ρl = F( l - x )/l                      «
////////////////////////////////////////////////////////////////
# include <vector>
# include <iostream>
# include <sstream>
# include <numeric>
# include <utility>
# include <cstdlib>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
// 昔 妖狐ありけり｡
////////////////////////////////////////////////////////////////
//////////&&&& &&&""" """"//@@@@ @@         // ### ##         //
//////////                //@@@ @@@@### ####//# # ### == ==== //
//////////&&&& &&&""" """"//        ### ####//## #### == ==== //
//////////                //@ @@@# @       #//# # ### == ==== //
//////////////////++++++++// ---- --''' ''''// | | || 22 2222 //
////////// ///////+++++++ //-- - ---'' ' '''//| || || 22 2222 //
//////////                //---  ---' ''' ''//|||| || 22 2 22 //
////////// ///////+++++++ //-- --- - ''''' '//||  || |22  2 2 //
////////////////////////////////////////////////////////////////
// log: Ok this is a beautiful problem and I was happy to find a
class Solution {
    int n;
    vector <int> a;
    vector <vector <int>> pos;
    vector <vector <int>> neg;
    vector <vector <int>> make_cache( int s ){
        return vector <vector <int>> ( s + 1, vector <int> ( n ));
    }
    int dp( int s, int j ){
        if( j == n ) return s;
        if( s > 0 and pos[ s ][ j ]) return pos[ s ][ j ];
        if( s < 0 and neg[-s ][ j ]) return neg[-s ][ j ];
        int tk = dp( s + a[ j ], j + 1 );
        int sk = dp( s - a[ j ], j + 1 );
        int rs = min( abs( tk ), abs( sk ));
        if( rs == 0 ) throw "volley";
        if( s > 0 ) return pos[ s ][ j ] = rs;
        if( s < 0 ) return neg[-s ][ j ] = rs;
    }
public:
    int minDifference( vector <int> &a ){
        n = a.size();
        int s = accumulate( a.begin(), a.end(), 0 );
        pos = make_cache( s );
        neg = make_cache( s );
        this->a = move( a );
        try {
            return dp( 0, 0 );
        } catch( ... ){
            return 0;
        }
     }
};
////////////////////////////////////////////////////////////////
// むかし ようこありけり。
////////////////////////////////////////////////////////////////
int main(){string ts;getline(cin,ts);int t=stoi(ts); while(t--){
vector<int> arr;string input;getline(cin,input);stringstream ss(
input);int number;while( ss >>number){ arr.push_back( number );}
Solution ob;int ans=ob.minDifference( arr ); cout <<ans<<endl;}}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1111 / 1111
// Points Scored:                                          8 / 8
// Your Total Score:                                        1894 
// Time Taken:                                              0.13
