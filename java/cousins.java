////////////////////////////////////////////////////////////////
// Check if two Nodes are Cousins
////////////////////////////////////////////////////////////////
// Given a binary tree (having distinct node values) and two
// node values. Check whether the two node values are cousins of
// each other or not.
// Note: Two nodes of a binary tree are cousins if they have the
// same depth with different parents
////////////////////////////////////////////////////////////////
// Input: 1
//       / \
//      2   3
// a = 2, b = 3
// Output: false
// Explanation: Here, nodes 2 and 3 areat the same level but
// have same parent nodes
////////////////////////////////////////////////////////////////
// Input: 1
//       / \ 
//      2   3
//     /     \
//    5       4 
// a = 5, b = 4
// Output: True
// Explanation: Here, nodes 5 and 4 areat the same level and 
// have differentparent nodes. Hence, they both are cousins 
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(Number of Nodes)
// Expected Auxiliary Space: O(Number of Nodes)
////////////////////////////////////////////////////////////////
// 1 <= Number of Nodes <= 10^5
////////////////////////////////////////////////////////////////
import java.io                                               .*;
import java.util                                             .*;
////////////////////////////////////////////////////////////////
class Node{ int data; Node left; Node right;Node(int data){this.
data = data ; left=  null ; right  =  null;  }  }
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class GfG{static Node buildTree(String str){if(str.length()==0||
str.charAt(0)=='N'){return null;}String ip[]=str.split(" ");Node 
root=new Node( Integer.parseInt( ip[0])); Queue <Node> queue=new 
LinkedList<>();queue.add(root);int i=1; while(queue.size()>0&&i<
ip.length){ Node currNode = queue.peek(); queue.remove(); String 
currVal=ip[i];if(!currVal.equals("N")){currNode.left = new Node(
Integer.parseInt(currVal));queue.add( currNode.left);}i++;if(i>= 
ip.length)break;currVal=ip[i];if(!currVal.equals("N")){currNode.
right= new Node( Integer.parseInt( currVal));queue.add(currNode.
right); }i++;}return root;} static void printInorder(Node root){
if(root==null) return; printInorder(root.left);System.out.print(
root.data+" ");printInorder(root.right);}public static void main
( String [   ] args ) throws Exception { BufferedReader br = new 
BufferedReader( new InputStreamReader(System.in)); int t=Integer
.parseInt(br.readLine());while(t>0){ String s=br.readLine();Node 
root = buildTree( s );Solution g = new Solution(); String X = br
.readLine();String arr[]=X.split(" ");int x,y;x=Integer.parseInt
( arr[0] );y=Integer.parseInt(arr[1]); if(g.isCousins(root,x,y))
System.out.println(  1  );else System.out.println( 0 ); t--; }}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Task { // 4 Queuing
    Node parent;
    Node child;
    Task( Node parent, Node child )
    {
        this.parent = parent;
        this.child = child;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {
    Queue <Task> queue = new LinkedList <> ();
    void enqueue( Node parent, Node child )
    {
        if( child != null ){
            queue.offer( new Task( parent, child ));
        }
    }
    Task dequeue()
    {
        return queue.poll();
    }
    //////////////////////// I 4hink this should be areCousins:)
    public boolean isCousins( Node root, int a, int b ){
        enqueue( null, root );
        while(! queue.isEmpty()){
            Node p = null; // cousins' ancestor
            for( int n = queue.size(); n > 0; --n ){
                Task t = dequeue();
                Node node = t.child;
                if( node.data == a || node.data == b ){
                    if( p == null ){
                        p = t.parent;
                    } else {
                        return p != t.parent;
                    }
                }
                enqueue( node, node.left );
                enqueue( node, node.right );
            }
            if( p != null ){
                break;
            }
        }
        return false;
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//  1. のむ trinken 飲 のみます、のみません
//  2. きく Hören 聞 ききます、ききません
//  3. みる sehen 見る みます、みません
//  4. する Tun します、しません
//  5. はなす sprechen 話 はなします、はなしません
//  6. いく gehen 行 いきます、いきません
//  7. くる kommen 来 きます、きません
//  8. かえる zurückkehren 帰 かえります、かえりません
//  9. ねる schlafen 寝 ねます、ねません
// 10. よむ lessen 読 よみます、よみません
// 11. おきる aufstehen 起 おきます、おきません
// 12. べんきょうする Studie 勉強 べんきょうします、べんきょうしません
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                1114 / 1115
// Points Scored:                                          4 / 4
// Your Total Score:                                        1806 
// Time Taken:                                              0.98
