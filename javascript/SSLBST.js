///////////////////////////////////////////////////////////////=
//                                       Sorted Link List to BST
////////////////////////////////////////////////////////////////
//
//     [ T r a m p o l i n e    C h a m p i o n s h i p ]
//
// G                                h      a          o     i 
//  i  n     n      n     i          a    t       r           
//       a  i  l         L      i                         d   
//    e    S  g      k d    t  h c           m   e   s   e   n
//                L   e           h     d     e b  s    t     
//   v          y  i       s  w       s  a     m       r      
// ##### # ###### ###### #### ##### ### #### ####### ###### ## 
// asc ndin  ord r. Cons ru t a Balan ed Bin ry Se
// hasesamegdataememberstascthe givenclinkedalist.arch Tree whic
////////////////////////////////////////////////////////////////
// Example:                                                    1
// Input:                       Linked List: 1->2->3->4->5->6->7
// Output:                                         4 2 1 3 6 5 7
// Explanation: The BST formed using elements of the linked listh
//                                                            is,
//                                                        4
//                                                       / \
//                                                      /   \
//                                                     2     6
//                                                    / \   / \
//                                                   1   3 5   7
////////////////////////////////////////////////////////////////
// Example:                                                    2
// Input: Linked List:                                1->2->3->4
// Ouput:                                                3 2 1 4
// Explanation: The BST formed using elements of the linked list
//                                                            is,
//                                                          3
//                                                         / \
//                                                        /   \  
//                                                       2     4 
//                                                      / 
//                                                     1
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)                               
////////////////////////////////////////////////////////////////
'use strict';
function LNode( x ) { // List Node
    this.data = x;
    this.next = null;
}
////////////////////////////////////////////////////////////////
function TNode( y ){ //Tree Node
    this.data  = y;
    this.left  = null;
    this.right = null;
}
////////////////////////////////////////////////////////////////
var s;
////////////////////////////////////////////////////////////////
function preorder( root ){
    if(! root )return;
    s += root.data + " ";
    preorder( root.left );
    preorder( root.right );
}
////////////////////////////////////////////////////////////////
function main() {
    const list = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 ];
    const head = new LNode( list[ 0 ]);
    var tail = head;
    for( let j = 1, n = list.length; j < n; ++j, tail = tail.next ){
        tail.next = new LNode( list[ j ]);
    }
    const obj = new Solution();
    const root = obj.sortedListToBST( head );
    s = "";
    preorder( root );
    console.log( s );
}
////////////////////////////////////////////////////////////////
class Solution {
    static listToArray( p ){
        var a = [];
        while( p ){
            a.push( p.data );
            p = p.next;
        }
        return a;
    }
    consTree( l, r ){
        if( l > r ) return null;
        if( l === r ) return new TNode( this.a[ l ]);
        const n = r - l + 1; // number of nodes
        const e = Math.log2( n ); // tree depth
        const w = 1 << e; // tree width
        const f = n + 1 - w; // number of last depth nodes
        const b = Math.ceil( f/ 2 ) + ( w >> 1 ) - 1; //
        // number of nodes before root node
        const m = l + b; // Middle Earth
        const root = new TNode( this.a[ m ]);
        root.left  = this.consTree( l, m - 1 );
        root.right = this.consTree( m + 1, r );
        return root;
    }
    sortedListToBST( head ){
        this.a = this.constructor.listToArray( head );
        return this.consTree( 0, this.a.length - 1 );
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  175 / 175
// Total Points Scored:                                    8 / 8
// Your Total Score:                                        1022
// Total Time Taken:                                        0.88
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////                                                        ////

