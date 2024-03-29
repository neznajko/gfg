////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
//
//          ````````````````\
//          ````````````````\\
//          `````\``````````\\\
//          `````\\`````````\\\\
//          ````````````````\\\\\
//          ````````````````\\\\\\
//          `````\``````````\\\\\\\
//          `````\\`````````\\\\\\\\
//          ````````````````\\\\\\\\\
//          ````````````````\\\\\\\\\\
//          `````\``````````\\\\\\\\\\\
//          `````\\``````````\\\\\\\\\\\
//           `````\\``````````\\\\\\\\\\\
//            `````\\``````````\\\\\\\\\\\
//             `````\\``````````\\\\\\\\\\\
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Find the Safe Position
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// There are n people standing in a circle (numbered clockwise 1 to n) 
// waiting to be executed. The counting begins at point 1 in the 
// circle and proceeds around the circle in a fixed direction (clockwise).
// In each step, a certain number of people are skipped and the next 
// person is executed. The elimination proceeds around the circle
// (which is becoming smaller and smaller as the executed people are
// removed), until only the last person remains, who is given freedom.
// Given the total number of persons n and a number k which indicates 
// that k-1 persons are skipped and kth person is killed in circle.
// The task is to choose the place in the initial circle so that
// you are the last one remaining and so survive.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Input: n = 2, k = 1 Output: 2
// Explanation: Here, n = 2 and k = 1, then safe position is 2 as
// the person at 1st position will be killed.
////////////////////////////////////////////////////////////////
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
import java.io.*; import java.util.*;
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class GFG { public static void main(String args[]) throws IOException {
BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
int t = Integer.parseInt(read.readLine()); while (t-- > 0) { String 
S[] = read.readLine().split(" "); int n = Integer.parseInt(S[0]);
int k = Integer.parseInt(S[1]); Solution ob = new Solution();
System.out.println(ob.safePos(n,k)); }}}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Solution {////////////////////////////////////////////////
    static int safePos( int n, int k ){
        Circle circ = new Circle( n );
        for( Node node = circ.tail;
             node.prev != node;
             node = node.next ){
            for( int j = 1; j < k; ++j ){
                node = node.next;
            }
            circ.Unlink( node );
        }
        return circ.tail.pos;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Node {
    int pos;
    Node prev;
    Node next;
    Node( int pos ){
        this.pos = pos;
        prev = next = null;
    }
};
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
class Circle {
    Node tail;
    Circle( int n ) {
        tail = new Node( 1 );
        tail.prev = tail.next = tail;
        for( int pos = 2; pos <= n; ++pos ){
            Insert( pos );
        }
    }
    Node Insert( int pos ){
        Node node = new Node( pos );
        tail.prev.next = node;
        node.prev = tail.prev;
        tail.prev = node;
        node.next = tail;
        return node;
    }
    void Unlink( Node node ){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        if( node == tail ){
            tail = tail.prev;
        }
    }
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node node = tail;
        do {
            sb.append( node.pos + " " );
            node = node.next;
        } while( node != tail );
        return sb.toString();
    }
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// 1. wakaru( understand )　　　 わかる
// 2. rekishi( history )　　　　 れきし
// 3. me wo samasu( wake up )　　めをさます
// 4. riron( theory )　　　　　　りろん
// 5. rainen( next year )　　　　らいねん
// 6. han ei( prosperity )　　　 はんえい
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// Test Cases Passed:                                2095 / 2095
// Total Points Scored:                                    4 / 4
// Your Total Score:                                        1314
// Total Time Taken:                                        0.44
