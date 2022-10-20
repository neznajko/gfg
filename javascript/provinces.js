                            ////////
///////////////////////////////////////////////////////////////=
// Number of Provinces
////////////////////////////////////////////////////////////////
// Given an undirected graph with V vertices. We say two vertics
// u and v belong to a single province if there is a path from u
// to v or v to u. Your task is to find the number of provinces.
//////////////////////////////////////////////////////////////// 
// Note: A province is a group of directly or indirectly conectd
// cities and no other cities outside of the group.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       [0, 0, 1]
//              [0, 0, 0]
//              [1, 0, 0]
// Output:      2
// Explanation: 0   1
//              |
//              2
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(V^2)
// Expected Auxiliary Space: O(V)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ V ≤ 500
////////////////////////////////////////////////////////////////
function main() {
    // 0   2---4
    // |   
    // 3---1
    console.log(( new Solution()).numProvinces(
        4,
        [[0,0,0,1,0],  // 0
         [0,0,0,1,0],  // 1
         [0,0,0,0,1],  // 2
         [1,1,0,0,0],  // 3
         [0,0,1,0,0]]  // 4
        //0 1 2 3 4
    ));
}
///////////////////////////////////////////////////////////////=
// Test Cases Passed: 121 / 121 Even this trivial at first sight
// Total Points Scored: 4 / 4   problems like dfs/exploring stff
// Your Total Score: 898        have to be practiced on a regulr 
// Total Time Taken: 0.1        bass unless you are some kind of
// Your Accuracy: 100%          genius that remembers everything
// Attempts No.: 1
////////////////////////////////////////////////////////////////
class Solution {
    numProvinces( n, adf ){
        // tag visited towns array, initialized to false
        const tag = Array( n ).fill( false );
        // province counter
        let pc = 0;
        // the dfs loop
        for( let u = 0; u < n; u++ ){
            // skip if visited
            if( tag[u] ) continue;
            // take a ride
            explore( u );
            // next province!
            pc++;
        }
        function explore( u ){
            // tag baby
            tag[u] = true;
            // check the neighbors
            for( let v = 0; v < n; v++ ){
                // if path exists and are not visited
                if( adf[u][v] && !tag[v] ){
                    // vrooom
                    explore( v );
                }
            }
        }
        return pc;
    }
}
////////////////////////////////////////////////////////////////
// log:
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
////                                                        ////
