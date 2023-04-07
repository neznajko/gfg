////////////////////////////////////////////////////////////////
// N     e     e     m     a     n     '     s S   h   o   e   s
////////////////////////////////////////////////////////////////
// Due to t h e second w a v e of Gorona virus, Geekland imposed 
// another lockdown and Geek has gained s o m e wieght. Now Geek 
// h a s decided to exercise. There are N intersections in t h e
// city numbered f r o m 0 to N-1 and M bidirectional roads each 
// r o a d connecting two intersections. A l l the intersections
// are connected t o each-other through some set of roads, i t h
// road connect intersections A[i][0] a n d A[i][1] a n d is o f 
// length A[i][2]. Every morning Geek will start at intersection
// src and will run/walk upto intersection dest. Geek only h a s 
// one hour in the m o r n i n g so he will choose t o cover the 
// shortest path from src to dest. After planning his exercising 
// schedule, Geek wants to buy the perfect shoes to walk/run i n
// the morning. He g o e s to Neeman's Shoe factory which is the 
// National Shoe factory of Geekland. Geek sees that there a r e 
// t w o types o f shoes "Neeman's Wool Joggers" a n d "Neeman's 
// C o t t o n Classics", "Neeman's Wool Joggers" a r e good for 
// running and "Neeman's Cotton Classics" are good f o r walking.
// G e e k is confused which shoes to buy, so he comes up with a 
// strategy. If the distance he h a s to cover in the morning is 
// less than or e q u a l to X, then he will walk t h e distance, 
// therefore he w i l l buy "Neeman's Cotton Classics". If t h e 
// d i s t a n c e is g r e a t e r than X, he w   i   l   l buy 
// "Neeman's Wool Joggers". Geek is too lazy t o calculate t h e 
// shortest distance between t w o intersections src and d e s t. 
// H    e    l    p him d e c i d e which s  h  o  e  s to b u y.
////////////////////////////////////////////////////////////////
// Example: 1
// Input: N = 3, M = 2, src = 0, dest = 2, X = 5, A = {{0, 1, 3},
//                                                     {1, 2, 3}}
// Output: Neeman's Wool Joggers
// Explanation: Shortest path f r o m src to dest i s 6 which is 
// greater than X, hence Geek will b u y "Neeman's Wool Joggers".
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(( N + M )* Log( M ))
// Expected Auxiliary Space: O( N + M )
////////////////////////////////////////////////////////////////
// Test Cases Passed:                              10104 / 10104
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1066
// Total Time Taken:                                        0.48
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
# include <iostream>
# include <vector>
# include <queue>
# include <climits>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
const string NeemansShoes[] = {
    "Neeman's Cotton Classics",
    "Neeman's Wool Joggers",
};
////////////////////////////////////////////////////////////////
struct Alarm {
    int vertex;
    int distance;
};
bool operator<( const Alarm& lhs, const Alarm& rhs ){
    return rhs.distance < lhs.distance;
}
////////////////////////////////////////////////////////////////
class Solution {
public:
    string exercise
    ( int N, // nf intersections 
      int M, // nf roads
      const vector<vector<int>>& A, // [ from, to, length ]
      int src, // 
      int dest, // 
      int X // Cotton Classics vs. Wool Joggers
    );
};
////////////////////////////////////////////////////////////////
string Solution::exercise
( int N, 
  int M, 
  const vector<vector<int>>& A,
  int src, 
  int dest, 
  int X ){
////////////////////////////////////////////////////////////////
    // length[ u ][ v ] vill be the l  e  n  g  t  h of the road
    // connecting u and v
    vector<vector<int>> length( N, vector<int>( N ));
    // represent the graph in a d j a c a n c y list f o r m a t 
    vector<vector<int>> adj( N );
    for( int j{}; j < M; j++ ){
        int from{ A[ j ][ 0 ]};
        int to{   A[ j ][ 1 ]};
        length[ from ][ to ] = length[ to ][ from ] = A[ j ][ 2 ];
        adj[ from ].push_back( to );
        adj[ to ].push_back( from );
    }
    // s  h  o  r  t  e  s  t path distance from src v e r t e x
    vector<int> dist( N, INT_MAX );
    dist[ src ] = 0;
    // Ok vhen r   e   a   c   h   i   n   g dest v e ' r e done
    priority_queue<Alarm> pq;
    pq.push({ src, 0 });
    while( !pq.empty() ){
        const auto& alarm{ pq.top() };
        int u{ alarm.vertex };
        int d{ alarm.distance };
        if( u == dest ){
            break;
        }
        pq.pop();
        // thats s o m e trick i've read at Stack Overflow about 
        // the l   a   c   k of u  p  d  a  t  e method i  n std
        if( d != dist[ u ]){
            continue;
        }
        for( int v: adj[ u ]){
            d = dist[ u ] + length[ u ][ v ];
            if( d < dist[ v ]){
                dist[ v ] = d;
                pq.push({ v, d });
            }
        }
    }
    return NeemansShoes[ dist[ dest ] > X ];
}
////////////////////////////////////////////////////////////////
int main() {
    int N, M, src, dest, X;
    cin >> N >> M >> src >> dest >> X;
    vector<vector<int>> A( M, vector<int>( 3 ));
    for( int i = 0; i < M; i++ ){
        cin >> A[ i ][ 0 ] >> A[ i ][ 1 ] >> A[ i ][ 2 ];
    }
    cout << Solution().exercise( N, M, A, src, dest, X ) << endl;
}
////////////////////////////////////////////////////////////////
