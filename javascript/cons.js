                            ////////
///////////////////////////////////////////////////////////////=
// Count Smaller elements
////////////////////////////////////////////////////////////////
// Givn an array Arr of size N containing positve intgers. Count
// number of smaller elemnts on right side of each array elemnt.
////////////////////////////////////////////////////////////////
// Example:     1
// Input:       N = 7
//              Arr[] = {12, 1, 2, 3, 0, 11, 4}
// Output:      6 1 1 1 0 1 0
// Explanation: ..
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤   N ≤ 10^6
// 0 ≤ Arr ≤ 10^8
////////////////////////////////////////////////////////////////
function main() {
    console.log(( new Solution()).constructLowerArray(
        [6,2,1,3],
        4
    ));
}
///////////////////////////////////////////////////////////////_
////////////////////////////////////////////////////////////////
function Node( key ){
    this.key  = key; // an array value
    this.val  = 0;   // noof left nodes
    this.left = null;
    this.ryte = null;
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 212 / 212 Ok don't remember very well, but
// Total Points Scored: 8 / 8   I think this is called inversion
// Your Total Score: 906        table in Knuth book bout sorting
// Total Time Taken: 0.2        otherwise the algorithm is using
// Your Accuracy: 100%          BST(Binary Search Tree) modified
// Attempts No.: 1              insertion method.
////////////////////////////////////////////////////////////////
class Solution {
    insert( root, j ){
        if( root == null ){
            return new Node( this.a[j] );
        }
        if( this.a[j] > root.key ){
            this.invs[j] += root.val + 1;
            root.ryte = this.insert( root.ryte, j );
        } else {
            root.val++;
            root.left = this.insert( root.left, j );
        }
        return root;
    }
    constructLowerArray( a, n ){
        this.a = a;
        this.invs = Array(n).fill(0);
        let root = this.insert( null, n - 1 );
        for( let j = n - 2; j >= 0; j-- ){
            this.insert( root, j );
        }
        return this.invs;
    }
}
////////////////////////////////////////////////////////////____
// log:
////////////////////////////////////////////////////////////====
main();
////////////////////////////////////////////////////////////////
////                                                        ////
