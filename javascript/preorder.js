////////////////////////////////////////////////////////////////
// Preorder traversal ( Iterative )
////////////////////////////////////////////////////////////////
// Given a binary tree. Find the preorder traversal of the tree
// without using recursion.
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:                                                   1
//                                                         / \
//                                                        /   \
//                                                       2     3
//                                                      / \
//                                                     4   5
// Output:                                             1 2 4 5 3
// Explanation:
////////////////////////////////////////////////////////////////
// Expected time complexity: O(N)
// Expected auxiliary space: O(N)
////////////////////////////////////////////////////////////////
// STK <- []
// P <- ROOT
//     +------------ P <- P.LEFT ----------+
//     V                                   | <-- PRINT P HERE
// +-> [ P = 0? ] -- NO --> [ STK.PUSH( P )] FOR PREORDER
// |   |
// |  YES -- [ STK is empty ] --> EXIT
// |   |
// |   V
// |   [ P <- STK.POP() ] -- P <- P.RYTE --+
// |                                       |
// +---------------------------------------+
////////////////////////////////////////////////////////////////
class Solution {
    preOrder( root ){
        var stk = [];
        var p = root;
        var res = [];
        while( true ){
            if( p !== null ){
                stk.push( p );
                res.push( p.key );
                p = p.left;
            } else {
                if( stk.length === 0 ){
                    break;
                }
                p = stk.pop();
                p = p.right;
            }
        }
        return res;
    }
}
////////////////////////////////////////////////////////////////
console.log( new Solution().preOrder(
    {
        key: 1,
        left:
        {
            key: 2,
            left:
            {
                key: 4,
                left: null,
                right: null
            },
            right:
            {
                key: 5,
                left: null,
                right: null
            }
        },
        right:
        {
            key: 3,
            left: null,
            right: null
        }
    }
));
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    35 / 35
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1010
// Total Time Taken:                                        1.78
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
//
//
