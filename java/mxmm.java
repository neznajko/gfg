////////////////////////////////================================
////////========________````````-------->>>>>>>>--------////////
//       Maximum     sum    leaf      to    root    path
//       #######     ###    ####      ##    ####    ####
//       =======     ===    ====      ==    ====    ====
//       -------     ---    ----      --    ----    ----
//       :::::::     :::    ::::      ::    ::::    ::::
//       ```````     ```    ````      ``    ````    ````
////////        ,,,,,,,,--------********________]]]]]]]]________
// Given       a  Binary    Tree,   find     the maximum     sum
// #####       #  ######    #####   ####     ### #######     ###
// =====       =  ======    =====   ====     === =======     ===
// -path    from  -----a    leaf-   --to    root.-------     ---
// :####    ####  :::::#    ####:   ::##    #####:::::::     :::
// `====    ====  `````=    ====`   ``==    =====```````     ```
//  ----    ----       -    ----      --    -----
//  ::::    ::::       :    ::::      ::    :::::
//  ````    ````       `    ````      ``    `````
////////////////////////////////===============================_
//
//                    Example: 2
//                  Input: 10
//                         / \ 
//                        /   \
//                      -2     7
//                      / \   
//                     8  -4    
//                    Output: 17
//     Expected Time Complexity:                            O(n)
//     Expected Auxiliary Space:                            O(1)
////////////////////////////////================================
import java.util.LinkedList;import java.util.Queue;import java.io.*;
import java.util.*;class Node{int data;Node left;Node right;Node
(int data){this.data=data;left=null;right=null;}}class Tree{static
Node buildTree(String str){if(str.length()==0||str.charAt(0)=='N')
{return null;}String ip[]=str.split(" ");Node root=new Node(Integer
.parseInt(ip[0]));Queue<Node> queue=new LinkedList<>();queue.add(root);
int i=1;while(queue.size()>0&&i<ip.length){Node currNode=queue.peek();
queue.remove();String currVal=ip[i];if(!currVal.equals("N")){
currNode.left=new Node(Integer.parseInt(currVal));queue.add(currNode.left);
}i++;if(i>=ip.length)break;currVal=ip[i];if(!currVal.equals("N")){
currNode.right=new Node(Integer.parseInt(currVal));queue.add(currNode.right);
}i++;}return root;}static void printInorder(Node root){if(root==null)
return;printInorder(root.left);System.out.print(root.data+" ");
printInorder(root.right);}public static void main(String[] args)throws
IOException{Node root=buildTree("1 2 3 4");Solution g=new Solution();
System.out.println(g.maxPathSum(root));}}
////////////////////////////////////////////////////////////////
class Solution {
    private static int m; // maximum sum
    private static int c; // current sum
    private static void mxmm( Node root ){
        if( root == null ){
            return;
        }
        c += root.data;
        if( root.left == root.right ){ // leaf?
            m = Math.max( m, c );
        } else {
            mxmm( root.left );
            mxmm( root.right );
        }
        c -= root.data;
    }
    public static int maxPathSum( Node root ){
        m = Integer.MIN_VALUE;
        c = 0;
        mxmm( root );
        return m;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                  116 / 116
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1042
// Total Time Taken:                                        0.37
// Your Accuracy:                                            50%
// Attempts No.:                                               2
////////////////////////////////////////////////////////////////
