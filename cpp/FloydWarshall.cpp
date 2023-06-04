////////////////////////////////////////////////////////////////
// Floyd Warshall
////////////////////////////////////////////////////////////////
// The problem is to find the shortest distances between every 
// pair of vertices in a given edge-weighted directed graph.
// The graph is represented as an adjacency matrix of size n*n.
// Matrix[i][j] denotes the weight of the edge from i to j. If 
// Matrix[i][j] = -1, it means there is no edge from i to j.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O( n3 )
// Expected Space Complexity: O( 1 )
////////////////////////////////////////////////////////////////
# include <vector>
# include <iostream>
# include <utility>
# include <queue>
////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
public:
    void shortest_distance( vector<vector<int>>& matrix );
};
////////////////////////////////////////////////////////////////
int main(){int n;cin>>n;vector<vector<int>>matrix(n,vector<int>(
n,-1));for(int i=0;i<n;i++){for(int j=0;j<n;j++){cin>>
matrix[i][j];}}Solution obj;obj.shortest_distance(matrix);for(
int i=0;i<n;i++){for(int j=0;j<n;j++){cout<<matrix[i][j]<<" ";}
cout<<"\n";}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
typedef vector<vector<int>> WECTOR;
////////////////////////////////////////////////////////////////
const int INF{ -1 };
////////////////////////////////////////////////////////////////
struct Node {
    int vrtx;
    int dist; 
};
////////////////////////////////////////////////////////////////
class FakeFloydWarshall {
    WECTOR& w;
    const int n;
    WECTOR adj;
    WECTOR dist;
public:
    FakeFloydWarshall( WECTOR& matrix ):
        w( matrix ),
        n( static_cast<int>( matrix.size())),
        adj( WECTOR( n )),
        dist( WECTOR( n, vector<int>( n, INF ))){
        for( int i{}; i < n; ++i ){
            for( int j{}; j < n; ++j ){
                if( w[ i ][ j ] > 0 ){
                    adj[ i ].push_back( j );
                }
            }
        }
    }
    void ShotDist( int src );
    void ShotDist();
};
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    90 / 90
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1126
// Total Time Taken:                                        0.35
////////////////////////////////////////////////////////////////
# define U( x ) static_cast<unsigned int>( x )
# define GT( x, y ) U( x ) > U( y )
# define LT( x, y ) U( x ) < U( y )
////////////////////////////////////////////////////////////////
void FakeFloydWarshall::ShotDist( int src ){
    dist[ src ][ src ] = 0;
    queue<Node> q;
    q.push({ src, 0 });
    while( !q.empty()){
        auto front{ q.front()};
        q.pop();
        int u{ front.vrtx };
        int d{ front.dist };
        // check if outdated, so to speak
        if( GT( d, dist[ src ][ u ])){
            continue;
        }
        for( int v: adj[ u ]){
            if( LT( d + w[ u ][ v ], dist[ src ][ v ])){
                dist[ src ][ v ] = d + w[ u ][ v ];
                q.push({ v, dist[ src ][ v ]});
            } 
        }
    }
}
////////////////////////////////////////////////////////////////
void FakeFloydWarshall::ShotDist(){
    for( int u{}; u < n; ++u ){
        ShotDist( u );
    }
    w = move( dist );
}
////////////////////////////////////////////////////////////////
void Solution::shortest_distance( vector<vector<int>>& matrix ){
    FakeFloydWarshall( matrix ).ShotDist();
}
////////////////////////////////////////////////////////////////
// [I] don|t know what Floyd-Warshall algorithm is have 2 figure
// , but vhen I,ve studied Dijkstra|s algorithm at one point was
// fhinkng why priority queue and not normal? pro[B]ably because
// of the update method and secondly because vheneva destination
// vertex is reached,, that`s it ve"re done. w[I]th normal queue
// there is no update but there is a trick for that if vertex is
// outdated simply put in the queue the vertex plus distance and
// vhen popping, compare with the current value. bu[T] to figure
// the shortest path we have to exhaust all variants; t[H]e plus
// is that, that will find all shortest paths, starting from the
// source, and it will work with negative weights as well.
////////////////////////////////////////////////////////////////
