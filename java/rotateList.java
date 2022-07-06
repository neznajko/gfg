
/***____````----,,,,==== * *----, , ````::::. . ;;;;
Rotate a Linked List 
Medium Accuracy: 33.33% Submissions: 100k+ Points: 4
   
Given a singly linked list of size N. The task is to
left-shift the lnkd list by k nods, whre k is a givn
positiv integer smallr than or equal to lngth of the
linked list.
                                           Example 1:
Input:       N = 5
             value[] = {2, 4, 7, 8, 9}
             k = 3
Output:      8 9 2 4 7
Explanation: Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
             Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
             Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Your Tsk: You dn't need to read nput or prnt anythng.
Your task is to complete the function rotate() which
takes a head reference as the frst argument and k as
the snd argument, and returns the head of the rotatd
linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^3
1 <= k <= N
*///////////////////////////////////////////////////
import java.util.Scanner;
////////////////////////////////////////////////////
class Node { int  data;
Node next;
                                      Node( int d ){
data = d;
next = null;
    }} 
////////////////////////////////////////////////////
// t
// n
// a1 a2 ... an
// k
class 
Main 
{
    public 
    static 
    void 
    main
    ( 
    String
    [
    ]
    args
    )
    {
        Scanner 
        sc 
        = 
        new 
        Scanner
        ( 
        System.in 
        )
        ;
        int 
        t 
        = 
        sc.nextInt()
        ;
        while
        ( 
        t--
        >
        0
        )
        {
            int 
            n 
            = 
            sc.nextInt()
            ;
            int
            a
            =
            sc.nextInt()
            ;
            Node
            head 
            = 
            new
            Node
            (
            a
            )
            ;
            Node
            tail
            =
            head
            ;
            for
            (
            int
            i
            =
            0
            ;
            i
            <
            n
            -
            1
            ;
            i++
            )
            {
                a
                =
                sc.nextInt()
                ;
                tail.next
                =
                new
                Node
                (
                a
                )
                ;
                tail
                =
                tail.next
                ;
            }
            int
            k
            =
            sc.nextInt()
            ;
            Solution
            ob
            =
            new
            Solution()
            ;
            head
            =
            ob.rotate
            (
            head
            ,
            k
            )
            ;
            printList
            (
            head
            )
            ;
        }
    }
    public 
    static
    void
    printList
    (
    Node
    n
    )
    {
        while
        (
        n
        !=
        null
        )
        {
            System.out.print
            (
            n.data
            +
            " "
            )
            ;
            n
            =
            n.next
            ;
        }
        System.out.println
        (
        )
        ;
    }
}
////////////////////////////////////////////////////
class Solution {
    // Get the length of a linked list.
    static int getLength( Node a ){
        int len = 0;
        for(; a != null; a = a.next ){
            len++;
        }
        return len;
    }
    // a = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    // k = 5
    public Node rotate( Node a, int k ){ // Debug zone
        int n = getLength( a );          // n: 8
        k %= n;                          // k: 5
        if( k == 0 ) return a;           //
        // detach first k nodes          //
        Node p = a;                      // p: 1
        for( int j = 1; j < k; j++) {    // j: 1,2,3,4,5
            p = p.next;                  // p: 2,3,4,5
        }                                //
        Node q = p.next;                 // q: 6
        p.next = null;                   // p: 5->null
        // find the tail                 // 
        Node t = q;                      // t: 6
        for(; t.next != null; t = t.next)// t: 7,8
            ;                            //
        // re-link                       // 
        t.next = a;                      // t: 8->1
        // gerout                        //
        return q;                        // q: 6->7->8->1->2->3->4->5
    }
}
////////////////////////////////////////////////////
// Test Cases Passed: 2113 / 2113
// Total Time Taken:  2.98 / 6.36
