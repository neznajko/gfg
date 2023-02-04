////////////////////////////////////////////////////////////////
//                        Construct Tree from Inorder & Preorder
////////////////////////////////////////////////////////////////
// 
//                                                            
// Given             Inorder                                   
// ..... 2           .......              traversal            .
// """"" "        of """""""              """""""""            "
// ----- - Arrays -- ------- and          --------- .     tree -
// ===== = ====== == ======= ===          ========= =     ==== =
// ##### # ###### ## ####### ###          ######### # The #### #
// $$$$$ $ $$$$$$ $$ $$$$$$$ $$$ preorder $$$$$$$$$ $ $$$ $$$$ $
// %%%%% % %%%%%% %% %%%%%%% %%% %%%%%%%% %%%%%%%%% % %%% %%%% %
// @@@@@ @ @@@@@@ @@ @@@@@@@ @@@ @@@@@@@@ @@@@@@@@@ @ @@@ @@@@ @
////////////////////////////////////////////////////////////////
//    can contain duplicate elements. Construct a tree and print
//                                       the Postorder traversal.
////////////////////////////////////////////////////////////////
// Example:                                                    2
// Input:                                                  N = 6
//                                   inorder[] = { 3 1 4 0 5 2 }
//                                  preorder[] = { 0 1 3 4 2 5 }
// Output:                                           3 4 1 5 2 0
// Explanation:                          The tree will look like
//                                                          0
//                                                         / \
//                                                        /   \
//                                                       1     2
//                                                      / \   /
//                                                     3   4 5
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N*N)
// Expected Auxiliary Space: O(N)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 <= Number of Nodes <= 1000
////////////////////////////////////////////////////////////////
'use strict';
////////////////////////////////////////////////////////////////
function Node( key ){
    this.key   = key;
    this.left  = null;
    this.right = null;
}
////////////////////////////////////////////////////////////////
let s = "";
function postOrder( root ){
    if(! root ) return;
    postOrder( root.left );
    postOrder( root.right );
    s += root.key + " ";
}
////////////////////////////////////////////////////////////////
//                                                          0
//                                                         / \
//                                                        /   \
//                                                       1     2
//                                                      / \   /
//                                                     3   4 5
// Test Cases Passed:                                  305 / 305
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1014
// Total Time Taken:                                        0.19
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
function main() {
    let obj = new Solution();
    const I = [ 3, 1, 4, 0, 5, 2 ];
    const P = [ 0, 1, 3, 4, 2, 5 ];
    let root = obj.buildTree( I, P, I.length );
    s = "";
    postOrder( root );
    console.log( s );
}
////////////////////////////////////////////////////////////////
class Solution {
    cons( l, r ){
        if( l > r ) return null;
        const key = this.P[ this.j++ ];
        const node = new Node( key );
        if( l < r ){
            let i = l;
            for(; this.I[ i ] !== key; ++i ){
            }
            node.left  = this.cons( l, i - 1 );
            node.right = this.cons( i + 1, r );
        }
        return node;
    }
    buildTree( I, P, n ){
        this.I = I;
        this.P = P;
        this.j = 0;
        return this.cons( 0, n - 1 );
    }
}
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
//         .`.       .`.                 .`.       .`.
//       .`   `.   .`   `.             .`   `.   .`   `.
//     .`       `.`       `.         .`       `.`       `.
//   .`        .` `.        `.     .`        .` `.        `.
// .`        .`     `.        `. .`        .`     `.        `. .
//`.       .`         `.       .`.       .`         `.       .`.
//  `.   .`             `.   .`   `.   .`             `.   .`
//    `.`                 `.`       `.`                 `.`
////////////////////////////////////////////////////////////////
