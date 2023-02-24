////////////////////////////////////////////////////////////////s
//   /   /   ///   /   ///   /   /   /   /   /   /   ///////////u
// / / //// ///// // / /// / / /// /// / // // /// /////////////m
//   /   // ///// // / /// / / ///   /   // //   / /////////////
// / /// // ///// // / /// / / /// /// / // // /// /////////////t
//   /   // ///// //   ///   / ///   / / // //   / /////////////r
//////////////////////////// ///////////////////////////////////e
//////////////////////////   ///////////////////////////////////e
// Given   a BST,  transform  it    into greater sum    tree
// where    each    node    contains sum  of all   nodes greater
//  than    that    node.
////----____````****====    ____>>>>````====____---->>>>````>>>>
////////////////////////////////////////////////////////////////
// XMPL: 1 NPUT¦ 2 OPUT; 18 16 13 7 0 XPTN= Every nod is replacd
//     :       ¦/ \    ;              wit the sum of nods greatr
//     :       /   \   ;              than itself. The resultant
//     :      1¦    6  ;              tree is: 16
//     :       ¦   / \ ;                  =   / \
//     :       ¦  3   7;                  =  /   \
//     :       ¦       ;                  = 18    7
//     :       ¦       ;                  =      / \
//     :       ¦       ;                  =     13  0
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)         =
// Expected Auxiliary Space: O(N)         =
////////////////////////////////////////////////////////////////
//     :       ¦       ;                  =
'use strict';
////////////////////////////////////////////////////////////////
class Node{constructor(x){this.data=x;this.left=null;this.right=
null;}}
////////////////////////////////////////////////////////////////
function buildTree(str){/*Corner Case*/if(str.length===0||str[0]
=='N')return null;/*Creating vector of strings from input string
after spliting by space*/let ip=new Array();let ip_str=str.split
(" ");for(let i=0;i<ip_str.length;i++)ip.push(ip_str[i]);/*Create
the root of the tree*/let root=new Node(parseInt(ip[0]));/*Push
the root to the queue*/let queue=new Array();queue.push(root);
/*Starting from the second element*/let i=1;while(queue.length!==0
&&i<ip.length){/*Get and remove the front of the queue*/let currNode
=queue[0];queue.shift();/*Get the current node's value from the
string*/let currVal=ip[i];/*If the left child is not null*/if
(currVal!="N"){/*Create the left child for the current node*/
currNode.left=new Node(parseInt(currVal));/*Push it to the queue*/
queue.push(currNode.left);}/*For the right child*/i++;if(i>=ip
.length)break;currVal=ip[i];/*If the right child is not null*/
if(currVal!="N"){/*Create the right child for the current node*/
currNode.right=new Node(parseInt(currVal));/*Push it to the queue*/
queue.push(currNode.right);}i++;}return root;}
////////////////////////////////////////////////////////////////
let s="";function printInorder(root){if(!root)return;printInorder
(root.left);s+=root.data+" ";printInorder(root.right);}
////////////////////////////////////////////////////////////////
function main(){let root=buildTree("3 2 4 1");let obj=new Solution();
obj.transformTree(root);s="";printInorder(root);console.log(s);}
////////////////////////////////////////////////////////////////
class Solution {
    transformTree( root ){
        this.sum = 0; // O(1)
        this.revs( root );
    }
    revs( root ){
        if( !root ){
            return;
        }
        this.revs( root.right );
        const data = root.data;
        root.data = this.sum;
        this.sum += data;
        this.revs( root.left );
    }
}
////////////////////////////////////////////////////////////////
main();
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    30 / 30
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1046
// Total Time Taken:                                        0.09
// Your Accuracy:                                           100%
// Attempts No.:                                               1
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
