////////////////////////////////////////////////////////////////
// Sum Tree
////////////////////////////////////////////////////////////////
// Medium Accuracy: 33.33% Submissions: 100k+ Points: 4
////////////////////////////////////////////////////////////////````````
// Given a Binary Tree. Return true if, for every node X in the ``ţŔęę``
// other than the leaves, its value is equal to the sum of its l``ęƑţ```
// subtree's value and its right subtree's value. Else return fa``ĺƧę.``
////////////////////////////////////////////////////////////////````````
// An empty tree is also a Sum Tree as the sum of an empty tree ``ĆÄń```
// be considered to be 0. A leaf node is also considered a Sum T``Ŕęę.``
///////////////////////////////////////////////////// Example 1:````````
// Input: 3
//       / \    
//      1   2
// Output: 1
// Explanation: The sum of left subtree and right subtree is 1 +,,,,,,,,,,
// 2 = 3, which is the value of the root node. Therefore, the gi,,Yęń,,,,,
// binary tree is a sum tree.                                   ,,,,,,,,,,
////////////////////////////////////////////////////////////////,,,,,,,,,,
// Your Task: You don't need to read input or print anything. Co,,ɱƥĺęţę,,
// the function isSumTree() which takes root node as input param,,ęţęŔ,,,,
// and returns true if the tree is a SumTree else it returns fal,,Ƨę.,,,,,
////////////////////////////////////////////////////////////////,,,,,,,,,,
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of the Tree)
////////////////////////////////////////////////////////////////
// Constraints:
// 1 ≤ number of nodes ≤ 10^4
////////////////////////////////////////////////////////////////
import java.io.*;
import java.util.*;
////////////////////////////////////////////////////////////////
class Node {
    int  data;
    Node left;
    Node right;
    Node( int data ){
        this.data = data;
        left      = null;
        right     = null;
    }
}
////////////////////////////////////////////////////////////////
class GfG { static Node buildTree(String str)                  {
    if(str.length()  ==  0                                    ||
       str.charAt(0) == 'N')                    { return null; }
    String ip[]                                = str.split(" ");
    // Create the root of the tree
    Node root        =        new Node(Integer.parseInt(ip[0]));
    // Push the root to the queue
    Queue<Node> queue   =   new LinkedList<>(); queue.add(root);
    // Starting from the second element
    int i = 1; while(queue.size() > 0 && i < ip.length)        {
        // Get and remove the front of the queue
        Node currNode                            = queue.peek();
        queue.remove();
        // Get the current node's value from the string
        String currVal =                                  ip[i];
        // If the left child is not null
        if(!currVal.equals("N"))                               {
            // Create the left child for the current node
            currNode.left = new Node(Integer.parseInt(currVal));
            // Push it to the queue
            queue.add(currNode.left)                          ;}
        // For the right child
        i++; if(i >= ip.length) break; currVal = ip[i]         ;
        // If the right child is not null
        if(!currVal.equals("N"))                               {
            // Create the right child for the current node
            currNode.right= new Node(Integer.parseInt(currVal));
            // Push it to the queue
            queue.add(currNode.right); } i++; } return   root; }
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
                            new InputStreamReader(System.in  ));
        int t=Integer.parseInt(br.readLine(                  ));
        while(t > 0)                                           {
            String                            s = br.readLine();
            Node                            root = buildTree(s);
            Solution                         g = new Solution();
            if                       (g.isSumTree(root) == true)
                                          System.out.println(1);
            else 
                                          System.out.println(0);
                                                            t--;
                                                             }}}
////////////////////////////////////////////////////////////////
//               12
//          5          2
//        3   1      N   N
//       N N 1 N
//
// 12 5 2 3 1 N N N N 1 N
class Solution {
    int check( Node root ) throws Exception {
        if( root == null ) return 0;
        // check if leaf
        if( root.left == root.right ) return root.data;
        int sum = ( check( root.left  ) +
                    check( root.right ));
        if( root.data != sum ){
            throw new Exception( ":)" );
        }
        return root.data + sum;        
    }
    boolean isSumTree( Node root ){
        try {
            check( root );
        } catch( Exception e ){
            return false;
        }            
        return true;
    }
}
////////////////////////////////////////////////////////////////
// Test Cases Passed: 223 / 223
// Total Time Taken: 0.22 / 1.11
