////////////////////////////////////////////////////////////////
// Possible paths between 2 vertices
///////////////////////////////////////////////////////////////_
// Givn a Directed Graph having V nodes numbered from 0 to V - 1,
// and E directed edges. Given two nodes, source and destination,
// count the number of ways or pths between thse two vertices in
// the directed graph. These paths should not contain any cycles.
////////////////////////////////////////////////////////////////
// Nte: Grph dsn't contain multiple edges, self-loop, and cycles.
////////////////////////////////////////////////////////////////
// Example: 1
// Input: V = 5, E = 7, Edges of Graph = {{ 0, 1 },
//   0---------->----------1              { 0, 2 },
//   |\ ,------<---,      /|              { 0, 4 },
//   | `--->--,     \____/ v              { 1, 3 },
//   v/        \           |              { 1, 4 },
//   4-----<----2-------<--3              { 2, 4 },
//                                        { 3, 2 }},
// source = 0, destination = 4
// Output: 4
// Explanation: There are 4 paths from 0 to 4:
// 0 -> 4
// 0 -> 1 -> 4
// 0 -> 2 -> 4
// 0 -> 1 -> 3 -> 2 -> 4
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(V!)                          << ?
// Expected Auxiliary Space: O(V)
////////////////////////////////////////////////////////////////
# include <vector>
# include <iostream>
///////////////////////////////////////////////////////////////_
using namespace std;
////////////////////////////////////////////////////////////////
class Solution {
private:
    int dst;
    vector<int>* adj;
    vector<int> numberf_paths;
    int dfs( int vtx );
public:
    int countPaths( int v, vector<int> adj[], int src, int dst );
};
///////////////////////////////////////////////////////////////=
int Solution::dfs( int vtx ){
    if( vtx == dst ){
        return 1;
    }
    if( numberf_paths[ vtx ] > 0 ){
        return numberf_paths[ vtx ];
    }
    numberf_paths[ vtx ] = -1;
    int sum{};
    for( int nbor: adj[ vtx ]){
        if( numberf_paths[ nbor ] == -1 ){
            continue;
        }
        sum += dfs( nbor );
    }
    return numberf_paths[ vtx ] = sum;
}
////////////////////////////////////////////////////////////////
int Solution::countPaths( int v, vector<int> adj[], int src,
                          int dst ){
    this->dst = dst;
    this->adj = adj;
    numberf_paths = vector<int>( v ); // cache
    return dfs( src );
}
////////////////////////////////////////////////////////////////
int main() {////////////////////////////////////////////   V   E
    int V, E;/////////////////////////////////////////// u_1 v_1
    cin >> V >> E;////////////////////////////////////// u_2 v_2
    vector<int> adj[ V ];/////////////////////////////// ... ...
    for( int i{}; i < E; i++ ){///////////////////////// u_E v_E
        int u, v;/////////////////////////////////////// src dst
        cin >> u >> v;//////////////////////////////////////////
        adj[ u ].push_back( v );////////////////////////////////
    }///////////////////////////////////////////////////////////
    int source, destination;////////////////////////////////////
    cin >> source >> destination;///////////////////////////////
    Solution obj;///////////////////////////////////////////////
    cout << obj.countPaths( V, adj, source, destination )///////
         << endl;///////////////////////////////////////////////
}///////////////////////////////////////////////////////////////
// Test Cases Passed:                                  202 / 202
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1062
// Total Time Taken:                                        0.01
// Your Accuracy:                                           100%
// Attempts No.:                                               1
///////////////////////////////////////////////////////////////_
