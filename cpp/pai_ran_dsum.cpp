////////////////////////////////////////////////////////////////
// Sum of Products
////////////////////////////////////////////////////////////////
// Given an array arr[] of size n. Calculate the sum of Bitwise 
// ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs 
// in the given array arr[] where i < j.
////////////////////////////////////////////////////////////////
// Input: n = 3
//        arr = {5, 10, 15}
// Output: 15
// Explanation: The bitwise Ands of all pairs where i<j are 
// (5&10) = 0, (5&15) = 5 and (10&15) = 10. Therefore, the total
// sum = (0+5+10) = 15
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxillary Space: O(1)
////////////////////////////////////////////////////////////////
// 1 <= n <= 10^5
// 1 <= arr[i] <= 10^8
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
typedef long long i64;
////////////////////////////////////////////////////////////////
ostream& operator<<( ostream& os, const vector <int> & vec )
{
  os << "[ ";
  for( auto ban: vec ){
    os << ban << " ";
  }
  return os << "]";
}
////////////////////////////////////////////////////////////////
class Solution {
public:
  i64 pairAndSum( int n, i64* arr );
};
////////////////////////////////////////////////////////////////
// I'm fat, but I know math
////////////////////////////////////////////////////////////////
// 5 10 15
//    3 2 1 0
//    8 4 2 1
// 5  0 1 0 1 4 * 2 + 1 * 2 = 10
// 10 1 0 1 0 8 * 2 + 2 * 2 = 20
// 15 1 1 1 1 8 * 2 + 4 * 2 + 2 * 2 + 1 * 2 = 30
//    2 2 2 2
//
// ( 30 + 20 + 10 - ( 5 + 10 + 15 ))/ 2 = 15
////////////////////////////////////////////////////////////////
# define NBITS 64
i64 Solution::pairAndSum( int n, i64* arr )
{
  vector <int> chart( NBITS );
  i64 arr_sum = 0;
  for( int i = 0; i < n; ++i ){
    arr_sum += arr[ i ];
    i64 bit = 1;
    for( int j = 0; j < NBITS; ++j ){
      chart[ j ] += !!( bit & arr[ i ]);
      bit <<= 1;
    }
  }
  i64 all_pairs_sum = 0;
  for( int i = 0; i < n; ++i ){
    i64 bit = 1;
    for( int j = 0; j < NBITS; ++j ){
      all_pairs_sum += ( bit & arr[ i ]) * chart[ j ];
      bit <<= 1;
    }
  }
  return ( all_pairs_sum - arr_sum ) / 2;
}
////////////////////////////////////////////////////////////////
int main(){int t;cin>>t;while(t--){int N;cin>>N;long long Arr[N]
; for ( int i=0;i<N;i++){ cin>>Arr[i]; } Solution ob; cout << ob
.pairAndSum(N,Arr)<<endl;}}/////////////////////////////////////
// 毎晩テレビをみます。
// Jeden Abend sehe ich fern.( tha'ts false )
////////////////////////////////////////////////////////////////
// いつ行きますか。
// Wann gehst du?
////////////////////////////////////////////////////////////////
// 朝（に）新聞うぉ読みます。
// Ich lese morgens die Zeitung.
////////////////////////////////////////////////////////////////
// 週末（に）何をしますか。
// Was machst do am Wochenende?
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1115 / 1115
// Points Scored:                                          4 / 4
// Your Total Score:                                        1802 
// Time Taken:                                              0.36

