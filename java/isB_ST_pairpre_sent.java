////////////////////////////////////////////////////////////////
// Find a pair with given target in BST
////////////////////////////////////////////////////////////////
// Given a Binary Search Tree and a target sum. Check whether 
// there's a pair of Nodes in the BST with value summing up to
// the target sum
////////////////////////////////////////////////////////////////
// Input: 2
//       / \
//      1   3, sum = 5
// Output: 1 
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(Height of the BST)
////////////////////////////////////////////////////////////////
// 1 ≤ Number of Nodes ≤ 10^5
// 1 ≤ Sum ≤ 10^6
////////////////////////////////////////////////////////////////
import java.io                                               .*;
import java.util                                             .*;
////////////////////////////////////////////////////////////////
class Node{ int data;Node left,right;public Node(int d){ data=d;
left=right=null;}}//////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class GFG{static Node buildTree(String str){if(str.length()==0||
str.equals('N'))return null; String[] s=str.split(" ");Node root
=new Node( Integer.parseInt(s[0])); Queue<Node> q=new LinkedList
<Node>();q.add(root);int i=1;while( !q.isEmpty() &&i <s.length){
Node currNode=q.remove();String currVal=s[i];if(!currVal.equals(
"N")){currNode.left =new Node( Integer.parseInt(currVal));q.add(
currNode.left ) ; } i++;if( i >=s.length)break;currVal=s[i];if(!
currVal.equals("N")){ currNode.right =new Node(Integer.parseInt(
currVal));q.add(currNode.right);}i++;}return root;}public static
void main(String args[])throws IOException{BufferedReader br=new
BufferedReader(new InputStreamReader(System.in)); int t=Integer.
parseInt(br.readLine().trim());while(t>0){String s=br.readLine()
;Node root=buildTree(s);int target=Integer.parseInt(br.readLine(
).trim() ); Solution T = new Solution(); System.out.println ( T.
isPairPresent(root,target));t--;}}}/////////////////////////////
////////////////////////////////////////////////////////////////
class Solution
{
    HashMap <Integer,Boolean> _set = new HashMap <> ();
    int _tar_getsum = -1;
    //
    void checkB_ST( Node root )
    {
        if( root == null ){
            return;
        }
        if( _set.containsKey( root.data )){
            throw new RuntimeException( "boom" );
        }
        _set.put( _tar_getsum - root.data, true );
        checkB_ST( root.left );
        checkB_ST( root.right );
    }
    int isPairPresent( Node root, int target_sum )
    {
        _tar_getsum = target_sum;
        try {
            checkB_ST( root );
        } catch( RuntimeException e ){
            return 1;
        }
        return 0;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 十一時に寝ます。
// Ich werde um elf ins Bett gehen.
////////////////////////////////////////////////////////////////
// 日曜日に京都に行きます。
// Ich werde am Sonntag nach Kyoto fahren.
////////////////////////////////////////////////////////////////
// わたしはうちに帰ります。
// Ich werde nach House zurückkehren.
////////////////////////////////////////////////////////////////
// 私は今日学校にいきません。
// Ich werde heute nicht zur Schule gehen.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                    41 / 41
// Points Scored:                                          4 / 4
// Your Total Score:                                        1794
// Time Taken:                                              2.49
