////////////////////////////////////////////////////////////////
// _________-----_---______----____---______---_--_____----_____
// Partition     a   Linked    List   around   a  given    value
// _________-----_---______----____---______---_--_____----_____
// __------___---------_------__------------___----__-------___-
//   Medium   Accuracy: 61.34%  Submissions:   9510  Points:   4
// __------___---------_------__------------___----__-------___-
//
////////////////////////////////////////////////////////////////////////
// Given a linked list and a value x, partition it such that all node  ʂ
// less than x come first, then all nodes with value equal to x an     Ɗ
// finally nodes with value greater than x. The original relative orde Ʀ
// of the nodes in each of the three partitions should  be preserved   .
// The partition must work in-place                                    .
////////////////////////////////////////////////////////////////////////
// Example  1,  I n p u t:  1 ---> 4 ---> 3 ---> 2 ---> 5 ---> 2 ---> 3,
//                          x ======================================== 3
// Output: 1 ------> 2 ------> 2 ------> 3 ------> 3 ------> 4 ------> 5
////////////////////////////////////////////////////////////////////////
// Explanation: Nodes with value less than 3 come first, then equal t  ò
// 3 and then greater than 3                                           .
////////////////////////////////////////////////////////////////////////
// Y o u r   t a s k                                                   :                           
// You don't need to read input or print anything. Your task is t      ø
// complete the function partition() which takes the head of the linke ð
// list and an integer x as input, and returns the head of the modifie Ð
// linked list after arranging the values according to x               . 
////////////////////////////////////////////////////////////////////////
// Expected time complexity: O( n                                      } 
// Expected Auxiliary Space: O( n                                      ]
////////////////////////////////////////////////////////////////////////
// Constraints                                                         :
// 1 <= N <= 10^                                                       Ƽ
// 1 <= k <= 10^                                                       s
////////////////////////////////////////////////////////////////////////
import java.util.*                                                     ;
////////////////////////////////////////////////////////////////////////
class Node                                                             {
    int  data                                                          ;
    Node next                                                          ;
    Node( int key )                                                    {
        data = key                                                     ;
        next = null                                                    ;
                                                                       }
                                                                       }
////////////////////////////////////////////////////////////////////////
class Partition                                                        {
    static Node head                                                   ;
    public static void main( String[] args )                           {
        Scanner sc = new Scanner( System.in )                          ;
        int t = sc.nextInt()                                           ;
        while( t-- > 0 )                                               {
            int n = sc.nextInt()                                       ;
            int a1 = sc.nextInt()                                      ;
            Node head = new Node( a1 )                                 ;
            Node tail = head                                           ;
            for( int i = 1; i < n; i++ )                               {
                int a = sc.nextInt()                                   ;
                tail.next = new Node( a )                              ;
                tail = tail.next                                       ;
                                                                       }
            int k = sc.nextInt()                                       ;
            Solution ob = new Solution()                               ;
            Node res = ob.partition( head, k )                         ;
            printList( res )                                           ;
            System.out.println()                                       ;
                                                                       }
                                                                       }
    public static void printList( Node node )                          {
        while( node != null )                                          {
            System.out.print( node.data + " " )                        ;
            node = node.next                                           ;
                                                                       }
                                                                       }
                                                                       }
////////////////////////////////////////////////////////////////////////
// Test Cases Passed:  80 / 80
// Total Time Taken: 2.24 / 3.81
////////////////////////////////////////////////////////////////////////
//////////////////// https://www.youtube.com/watch?v=AX869YpWs08&t=1131s
class Solution {
    public static Node partition( Node node, int y ){
        // Create list ahead.
        Node ahead = new Node( 0 );
        ahead.next = node;
        // Make stack pointer at ahead for inserting nodes.
        Node sp = ahead;
        // For detachment and stoff.
        Node prev = ahead;     
        // Loop over list, until done.
        while( true ){ 
            Node cure = prev.next;
            if( cure == null ) break;
            // Check for interesting events.
            boolean voila = false;
            if( cure.data <= y ){
                if( cure != sp.next ){
                    voila = true;
                    // Detach.
                    prev.next = cure.next;
                    // Insert.
                    cure.next = sp.next;
                    sp.next = cure;
                }
                // Advance stack pointer.
                if( cure.data < y ){
                    sp = sp.next;
                }
            }
            if(! voila ) prev = prev.next;
        }
        return ahead.next;
    }
}
////////////////////////////////////////////////////////////////////////
